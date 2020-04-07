#ifndef __TIME_REPORT_H_INCLUDED__
#define __TIME_REPORT_H_INCLUDED__

#include <string>
#include <stdlib.h>
#include <conio.h>
#include <sstream>
#include <fstream>
#include <math.h>
#include <ctime>
#include <iostream>
#include "employee.h"

using namespace std;

class time_report{
	private:
		string Status;
		string TotalWorkH;
		string Reason;
		string employeeName;
	public:
		string* getorSetStatus();
		string* getorSetTotalWh();
		string* getorSetReas();	
		string* getorSetEmpName();
		time_report* next;
		time_report* prev;
};
#endif
