#include "convert.h"
#include "receive_data.h"
#include "ros/ros.h"
#include <vector>
#include "std_msgs/Float64MultiArray.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using namespace ros;
using namespace std;
using namespace boost::asio;
int main(int argc, char **argv)
{
    
    ros::init(argc, argv, "data");
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<std_msgs::Float64MultiArray>("mmwave", 1000);
    ros::Rate loop_rate(20);
    
    io_service iosev;
    serial_port sp(iosev,"/dev/ttyACM0");//定义传输的串口
	sp.set_option(serial_port::baud_rate(460800));
	sp.set_option(serial_port::flow_control());
	sp.set_option(serial_port::parity());
	sp.set_option(serial_port::stop_bits());
	sp.set_option(serial_port::character_size());
	unsigned char buff[200];    
	int cnt=0;

	list<unsigned char> OneFrame;
	unsigned char frame_header[20];
	unsigned char frame_data[20];




while(ros::ok()){
	cout<<cnt++<<endl;
	read(sp,buffer(buff));
	// program start

	MovingData(JudgeFrameHead(buff),buff,OneFrame); //input data
	
	vector<float> data;
	if(OneFrame.size()>(4020))
	{
		int target_number = DataToArrayHead(OneFrame , frame_header);
		for(int i = 0 ; i<target_number ; i++)
		{       
			float * a;
			a = DataToArrayPointData(OneFrame , frame_data);
			data.push_back(i);
			for (int j = 0 ; j < 5 ; j++)
				{
					data.push_back(a[j]);
				}	
		}	
	}

	std_msgs::Float64MultiArray msg;
	
	for(int k=0; k < data.size() ; k++)
		{
			msg.data.resize( data.size() );
			msg.data[k] = data[k];
		}
	if(data.size())
	chatter_pub.publish(msg);
	ros::spinOnce();
	
	bool met = loop_rate.sleep();
}
    
	iosev.run();
	return 0;
}
