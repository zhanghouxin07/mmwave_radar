#ifndef CONVERT_H
#define CONVERT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
float Hex4Byte_To_DecimalFloat(unsigned char h_1,unsigned char h_2,unsigned char h_3,unsigned char h_4);
int Hex2Byte_to_Decimal(unsigned char a_left,unsigned char b_right);
int Hex4Byte_to_Decimal(unsigned char h_1,unsigned char h_2,unsigned char h_3,unsigned char h_4);
int FindTargetNumber(unsigned char frame_header[]);
void ConvertAndPrintHead(unsigned char frame_header[]);
float * ConvertAndPrintData(unsigned char frame_data[]);

#endif
