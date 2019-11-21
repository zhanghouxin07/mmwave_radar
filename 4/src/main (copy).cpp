#include "convert.h"
#include "receive_data.h"
#include "ros/ros.h"
#include <vector>;
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
    ros::Publisher chatter_pub = n.advertise<std_msgs::Float64MultiArray>("chatter", 1000);
    ros::Rate loop_rate(10);
    
    io_service iosev;
    serial_port sp(iosev,"/dev/ttyUSB0");//定义传输的串口
	sp.set_option(serial_port::baud_rate(460800));
	sp.set_option(serial_port::flow_control());
	sp.set_option(serial_port::parity());
	sp.set_option(serial_port::stop_bits());
	sp.set_option(serial_port::character_size());
unsigned char buff[20];    
int cnt=0;
while(ros::ok()){
	cout<<cnt++<<endl;
	read(sp,buffer(buff));
	// program start
	
	ros::spinOnce();
	bool met = loop_rate.sleep();
}
//*********************************************************************
	unsigned char input1[20] = {
		0x01,0x01,0x3c,0x00,0x41,
		0x58,0x41,0x44,0x42,0x00,0x00,0x00,0x00,0x93,0x5f,  
		0x39,0x43,0x3c,0x00,0x02
	};

	unsigned char input2[20] ={
		0x00,0x01,0x01,0xcd,0x02, 
		0x00,0x21,0x84,0x40,0xa0,0x12,0x6d,0x3c,0x0f,0x05,
		0x2b,0xc0,0xe0,0x16,0x7d
	};

	unsigned char input3[20] ={
		0x42,0xc7,0x24,0x41,0x41,
	0x3b,0x29,0xe5,0x43,0xbe,0x0d,0xf8,0x3c,0x34,0x57,
	0xc2,0xc1,0x25,0x36,0x47
	};

	unsigned char input4[20] ={
		0x42,0x5f,0x04,0x6e,0x40,
		0x58,0x41,0x44,0x42,0x00,0x00,0x00,0x00,0x93,0x5f,  
		0x39,0x43,0x3c,0x00,0x02
	};

	unsigned char input5[20] = {
		0x00,0x01,0x01,0xcd,0x02,
		0x00,0x21,0x84,0x40,0xa0,0x12,0x6d,0x3c,0x0f,0x05,
		0x2b,0xc0,0xe0,0x16,0x7d
	};

	unsigned char input6[20] ={
		0x42,0xc7,0x24,0x41,0x41,
		0x3b,0x29,0xe5,0x43,0xbe,0x0d,0xf8,0x3c,0x34,0x57,
		0xc2,0xc1,0x25,0x36,0x47
	};

	unsigned char input7[20] ={
		0x42,0x5f,0x04,0x6e,0x40,
		0x58,0x41,0x44,0x42,0x00,0x00,0x00,0x00,0x93,0x5f,  
		0x39,0x43,0x3c,0x00,0x02
	};

	unsigned char input8[20] ={
		0x42,0x5f,0x04,0x6e,0x40,
	0x58,0x41,0x44,0x42,0x00,0x00,0x00,0x00,0x93,0x5f,  
	0x39,0x43,0x3c,0x00,0x02
	};
	list<unsigned char> OneFrame;
	unsigned char frame_header[20];
	unsigned char frame_data[20];

	MovingData(JudgeFrameHead(input1),input1,OneFrame);
	MovingData(JudgeFrameHead(input2),input2,OneFrame);
	MovingData(JudgeFrameHead(input3),input3,OneFrame);
	MovingData(JudgeFrameHead(input4),input4,OneFrame);
	MovingData(JudgeFrameHead(input5),input5,OneFrame);
	MovingData(JudgeFrameHead(input6),input6,OneFrame);
	MovingData(JudgeFrameHead(input7),input7,OneFrame);
	MovingData(JudgeFrameHead(input8),input8,OneFrame);

	int target_number0 = DataToArrayHead(OneFrame , frame_header);
	cout<<"这一帧有几个点 "<<target_number0<<endl;
	DataToArrayPointData(OneFrame , frame_data);
	DataToArrayPointData(OneFrame , frame_data);

	int target_number1 = DataToArrayHead(OneFrame , frame_header);
	cout<<"这一帧几个点"<<target_number1<<endl;
	DataToArrayPointData(OneFrame , frame_data);
	DataToArrayPointData(OneFrame , frame_data);

	cout<<"list中还剩余"<<OneFrame.size()<<endl;

        
/*
    while (ros::ok())
    {

        unsigned char buffer[20];
        vector<float> data;
        vector<float> a;
        vector<float> b;

        list<unsigned char> OneFrame;
        unsigned char frame_header[20];
        unsigned char frame_data[20];

        MovingData(JudgeFrameHead(input1),input1,OneFrame);
        MovingData(JudgeFrameHead(input2),input2,OneFrame);
        MovingData(JudgeFrameHead(input3),input3,OneFrame);
        MovingData(JudgeFrameHead(input4),input4,OneFrame);
        MovingData(JudgeFrameHead(input5),input5,OneFrame);
        MovingData(JudgeFrameHead(input6),input6,OneFrame);
        MovingData(JudgeFrameHead(input7),input7,OneFrame);
        MovingData(JudgeFrameHead(input8),input8,OneFrame);

        int target_number0 = DataToArrayHead(OneFrame , frame_header);
        cout<<"这一帧有几个点 "<<target_number0<<endl;
        data.push_back(target_number0);
        //a = DataToArrayPointData(OneFrame , frame_data);

        vector<int >::iterator it;
        for(it = a.begin();it!=a.end();++it){
             data.push_back(it);
        }

        //DataToArrayPointData(OneFrame , frame_data);

        int target_number1 = DataToArrayHead(OneFrame , frame_header);
        cout<<"这一帧几个点"<<target_number1<<endl;
        data.push_back(target_number0);
        DataToArrayPointData(OneFrame , frame_data);
        //DataToArrayPointData(OneFrame , frame_data);
        //b = DataToArrayPointData(OneFrame , frame_data);
        vector<int >::iterator it;
        for(it = b.begin();it!=b.end();++it){
             data.push_back(it);
        }
        cout<<"list中还剩余"<<OneFrame.size()<<endl;
        data.push_back(OneFrame.size());
        std_msgs::Float64MultiArray msg;
        //msg.data = data;
        chatter_pub.publish(msg);
        ros::spinOnce();
    
    }
*/
    

cout<<"ll ok!"<<endl;
	return 0;
}
