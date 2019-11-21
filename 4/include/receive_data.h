#ifndef RECEIVE_DATA_H
#define RECEIVE_DATA_H

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int JudgeFrameHead(unsigned char input[]);
void MovingData(int i,unsigned char input[],list<unsigned char> &OneFrame);
int DataToArrayHead(list<unsigned char> &OneFrame,unsigned char frame_header[20]);
float * DataToArrayPointData(list<unsigned char> &OneFrame,unsigned char frame_data[20]);
#endif
