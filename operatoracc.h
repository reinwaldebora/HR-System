#ifndef __OPERATOR_H_INCLUDED__
#define __OPERATOR_H_INCLUDED__



#include <string>
#include <stdlib.h>
#include <conio.h>
#include <sstream>
#include <fstream>
#include <math.h>
#include <ctime>
#include <iostream>
#include <stdio.h>

using namespace std;

class operatoracc{
	private:
		string Fname;
		string Mname;
		string Lname;
		string usern;
		string passw;
		string userLevl;
	public:
		string* getorSetFname();
		string* getorSetMname();
		string* getorSetLname();
		string* getorSetuserN();
		string* getorSetpassw();
		string* getorSetuserLvl();
		
		operatoracc* next;
		operatoracc* prev;
};
#endif
