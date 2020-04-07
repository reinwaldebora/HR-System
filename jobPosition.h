#ifndef __JOBPOSITION_H_INCLUDED__
#define __JOBPOSITION_H_INCLUDED__


#include <string>
#include <stdlib.h>
#include <conio.h>
#include <sstream>
#include <fstream>
#include <math.h>
#include <ctime>
#include <iostream>

using namespace std;



class jobPosition{
	private:
		string orderNum;
		string Position;
		string JobRequirements;
		string DepartMent;
		string Code;
		string location;
	public:
		
		string* getorSetorderNum();
		string* getorSetPosition();
		string* getorSetJobReq();
		string* getorSetDepartM();
		string* getorSetCode();
		string* getorSetlocation();
		
		jobPosition* next;
		jobPosition* prev;
};
#endif
