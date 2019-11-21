#include "convert.h"

float Hex4Byte_To_DecimalFloat(unsigned char h_1,unsigned char h_2,unsigned char h_3,unsigned char h_4)//十六进制到浮点数
{
     
     char cByte[4];
     cByte[0] = h_1;
     cByte[1] = h_2;
     cByte[2] = h_3;
     cByte[3] = h_4;
      
     float pfValue=*(float*)&cByte;
	
	return  pfValue;
}

int Hex2Byte_to_Decimal(unsigned char a_left,unsigned char b_right)
{
	return  (int)(a_left | b_right<<8);
}

int Hex4Byte_to_Decimal(unsigned char h_1,unsigned char h_2,unsigned char h_3,unsigned char h_4)
{
	int h_int[4];
	//强制类型转换
	h_int[0]=(int)h_1;
	h_int[1]=(int)h_2;
	h_int[2]=(int)h_3;
	h_int[3]=(int)h_4;

	int sum = 0;
	sum=(((h_int[3]*256+h_int[2])*256+h_int[1])*256+h_int[0]);

	return sum;
}

int FindTargetNumber(unsigned char frame_header[])
{
	int target_number = Hex2Byte_to_Decimal(frame_header[14],frame_header[15]);
	return target_number;
}


void ConvertAndPrintHead(unsigned char frame_header[20])
{
	int Sync = Hex4Byte_to_Decimal(frame_header[0],frame_header[1],frame_header[2],frame_header[3]);
	cout<<"Sync "<<Sync<<endl;
	int FramNumber = Hex4Byte_to_Decimal(frame_header[4],frame_header[5],frame_header[6],frame_header[7]);
	cout<<"FramNumber "<<FramNumber<<endl;
	float FramTime = Hex4Byte_To_DecimalFloat(frame_header[8],frame_header[9],frame_header[10],frame_header[11]);
	cout<<"FramTime "<<FramTime<<endl;
	int PacketLength = Hex2Byte_to_Decimal(frame_header[12],frame_header[13]);
	cout<<"PacketLength "<<PacketLength<<endl;
	int target_number = Hex2Byte_to_Decimal(frame_header[14],frame_header[15]);
	cout<<"target_number "<<target_number<<endl;

	int Version = Hex2Byte_to_Decimal(frame_header[16],frame_header[17]);
	cout<<"Version "<<Version<<endl;
	int CheckSum = Hex2Byte_to_Decimal(frame_header[18],frame_header[19]);
	cout<<"CheckSum "<<CheckSum<<endl;
}

float * ConvertAndPrintData(unsigned char frame_data[])
{       float * a;
	a = (float *)malloc(sizeof(float)*5);
	cout<<"----------"<<endl;
	float Range = Hex4Byte_To_DecimalFloat(frame_data[0],frame_data[1],frame_data[2],frame_data[3]);
	
	cout<<"Range "<<Range<<endl;
	a[0] = Range;
	float Azimuth = Hex4Byte_To_DecimalFloat(frame_data[4],frame_data[5],frame_data[6],frame_data[7]);
	cout<<"Azimuth "<<Azimuth<<endl;
	a[1] = Azimuth;
	float Doppler = Hex4Byte_To_DecimalFloat(frame_data[8],frame_data[9],frame_data[10],frame_data[11]);
	cout<<"Doppler "<<Doppler<<endl;
	a[2] = Doppler;
	float Energy = Hex4Byte_To_DecimalFloat(frame_data[12],frame_data[13],frame_data[14],frame_data[15]);
	cout<<"Energy "<<Energy<<endl;
	a[3] = Energy;
	float SNR = Hex4Byte_To_DecimalFloat(frame_data[16],frame_data[17],frame_data[18],frame_data[19]);
	cout<<"SNR "<<SNR<<endl;
	a[4] = Energy;
	return a;

}
