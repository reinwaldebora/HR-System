#ifndef __BENEFITS_H_INCLUDED__
#define __BENEFITS_H_INCLUDED__


#include <string>
#include <stdlib.h>
#include <conio.h>
#include <sstream>
#include <fstream>
#include <math.h>
#include <ctime>
#include <iostream>


using namespace std;

class benefits{
	private:
		string benName;
		string EmpName;
		string Calculate;
		string Department;
		string Location;
	public:
		
		string* getorSetbenName();
		string* getorSetempName();
		string* getorSetCalculate();
		string* getorSetDep();
		string* getorSetLoc();
		
		
		benefits* next;
		benefits* prev;
		
};
#endif
