#ifndef __DEPARTMENT_H_INCLUDED__
#define __DEPARTMENT_H_INCLUDED__


#include <string>
#include <stdlib.h>
#include <conio.h>
#include <sstream>
#include <fstream>
#include <math.h>
#include <ctime>
#include <iostream>
#include "jobPosition.h"

using namespace std;

class department{
	private:
		string location;
		string DeptName;
		string Code;
	public:
		string* getorSetlocation();
		string* getorSetDeptName();
		string* getorSetCode();
		
		department* next;
		department* prev;
		
};
#endif
