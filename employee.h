#ifndef __EMPLOYEE_H_INCLUDED__
#define __EMPLOYEE_H_INCLUDED__

#include <string>
#include <stdlib.h>
#include <conio.h>
#include <sstream>
#include <fstream>
#include <math.h>
#include <ctime>
#include <iostream>


using namespace std;

class employee{
	 private:
	 	string ID_number;
	 	string Name;
	 	string Address;
	 	string ContactNumber;
	 	string Age;
	 	string emailAdd;
	 	string Birthday;
	 	string Sex;
	 	string FatherName;
	 	string OccuF;
	 	string MotherName;
	 	string OccuM;
	 	string MaritalStat;
	 	string StartDate;
	 	string Employee_Status;
	 	
	 	string Department;
	 	string Jobposition;
	 	string location;
		string BasicPay;
		string TotalWorkH;
		string RatePhour;
		string GrossPay;
		string Tax;
		string Pagibig;
		string SSS;
		string PhilHealth;
		string totalDed;
		string TotalBen;
		string TotalAdj;
		string NetPay;
	public:
		
		string* getorSetIDnum();
		string* getorSetName();
		string* getorSetAdd();
		string* getorSetContNum();
		string* getorSetAge();
		string* getorSetEadd();
		string* getorSetbDate();
		string* getorSetSex();
		string* getorSetFname();
		string* getorSetOccuF();
		string* getorSetMname();
		string* getorSetOccuM();
		string* getorSetMStat();
		string* getorSetStDate();
		string* getorSetEmpStat();
		
		
		string* getorSetDept();
		string* getorSetBasPay();
		string* getorSetTotWorkH();
		string* getorSetRPhour();
		string* getorSetGrossP();
		string* getorSetTax();
		string* getorSetPagibig();
		string* getorSetsss();
		string* getorSetPhilH();
		string* getorSettotalDed();
		string* getorSettotalBen();
		string* getorSettotalAdj();
		string* getorSetnPay();
		string* getorSetJobP();
		string* getorsetLoc();
		
		employee* next;
		employee* prev;
};
#endif
