#include "receive_data.h"
#include "convert.h"
#include <vector>

int JudgeFrameHead(unsigned char input[])
{
	for(int i=0 ; i<200 ;i++) //suiyi 50
	{
		if(input[i] == 0x58 &&input[i+1] == 0x41 &&input[i+2] == 0x44 &&input[i+3] == 0x42)
			{cout<<"I find the framehead!"<<endl;return i;}
			
	}
	cout<<"No framehead here"<<endl;
	return 0;
}

void MovingData(int i,unsigned char input[],list<unsigned char> &OneFrame)
{
	if(i != 0&&OneFrame.size()==0)
		{
			for(int i1=i;i1<200;i1++)
			{
				OneFrame.push_back(input[i1]);
			}
		}
	else if(i == 0)
	{
		for(int i1=i;i1<200;i1++)
		{
			OneFrame.push_back(input[i1]);
		}
	}
	else if(i != 0&&OneFrame.size()!=0)
	{
		for (int i1 = 0; i1 < 200;i1++)
		{
			OneFrame.push_back(input[i1]);
		}
	} 
	cout<<OneFrame.size()<<endl;
}

int DataToArrayHead(list<unsigned char> &OneFrame,unsigned char frame_header[20])
{
	for(int i=0 ; i<20 ;i++)
	{
		frame_header[i] = OneFrame.front();
		if(OneFrame.size()!=0)
		OneFrame.pop_front();
	}
	int target_number = FindTargetNumber(frame_header);
	ConvertAndPrintHead(frame_header);
	return target_number;
}

float * DataToArrayPointData(list<unsigned char> &OneFrame,unsigned char frame_data[20])
{       float * a;
	for(int i=0 ; i<20 ;i++)
	{
		frame_data[i] = OneFrame.front();
		if(OneFrame.size()!=0)
		{	OneFrame.pop_front();}
	}
        a = ConvertAndPrintData(frame_data);
	return a;
}

