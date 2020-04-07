#ifndef __OPERATE_H_INCLUDED__
#define __OPERATE_H_INCLUDED__


#include <string>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <math.h>
#include <ctime>
#include <iostream>
#include <string.h>
#include <sstream>
#include "operatoracc.h"
#include "employee.h"
#include "department.h"
#include "jobPosition.h"
#include "time_report.h"


using namespace std;

class operate{
	private:
		operatoracc* opaccHEAD;
		operatoracc* opacccurrent;
		employee* emploHEAD;
		employee* emplocurrent;
		
		department* depHEAD;
		department* depCurrent;
		
		jobPosition* jobPosHEAD;
		jobPosition* jobPosCurrent;
		
		
		
		time_report* timerepHEAD;
		time_report* timrerepCurr;
		
		int AdminCount;
		int HRManCount;
		int RecCount;
		int HRPersoCount;
		
		int employeeCount;
		int departmentCount;
		int jobCount;
		
		int timeRepCount;
	public:
		void AdminUpdate();
		///////////////////////
		void generateLLoperator();
		string To_lower(string);
		void refreshopacc();
		void removeallopAcc();
		void removeOneopAcc(operatoracc*,int);
	
		string filt(string);
		operatoracc* getopaccHEAD();
		void setopaccHEAD(operatoracc*);
		operatoracc* getopaccCurrent();
	
		bool AdminLogin();
		bool AdminDelete();
		bool AdminRegister();
	
		operatoracc* searchOperUser(string,string,int);
		operatoracc* searchandDel(string,string,string);
		
		
		bool HRManagerLogin();
		bool changePassword();
		bool HRPersonnelLogin();
		///////////////////////////////////
		
		void setemploHEAD(employee*);
		employee* getemploHEAD();
		employee* getemploCurrent();
		
		
		
		void generateLLemployee();
		void refreshEmploacc();
		void removeallEmploAcc();
		bool HrManagerCreateEmployee();
		bool checkSameAttribute(string,int);
		
		
		////////////////////////////////////////
		
		void setDepHEAD(department*);
		department* getDepHEAD();
		department* getDepCurrent();
		
		
		void generateLLDepartment();
		void refreshDepartment();
		void removeallDepartment();
		bool HrManagerCreateDepartment();
		bool checkSameAttributeDept(string,int);
		
		
		department* searchDept(string,string);
		
		////////////////////////////////////
		void setJobPHEAD(jobPosition*);
		jobPosition* getJobPHEAD();
		jobPosition* checkforJobexist(string,string,string);
		void generateLLJobPos();
		void refreshJobPos();
		void removeallJobPos();
		bool HrManagerCreateJobP();
		bool shortCutCreateJobP(string,string);	
		bool checkSameAttributeJob(string,string,string,string);
	
		void display();
		
		///Searching algorithm////
		void searchEmployee();
		void searchempNameCri(string);
		void searchempIdNumCri(string);
		
		void searchDepartment();
		void searchDepCrit(string,int);
		
		
		void searchJob();
		void searchJobCrit(string,int);
		////////////////////////////
		
		void viewEmployee();
		bool updateorDelEmployee();
		void updateonlyEmployee(employee*);
		employee* returnforDelorUp(int);
		void removeOneEmployee(employee*);
		
		
		
		
		void viewDept();
		bool updateorDelDepartment();
		void updateonlyDepartment(department*);
		department* returnforDelorupDep(int);
		void removeOneDept(department*);
		
		void viewJob();
		bool updateorDelJob(); 
		void updateonlyJobPos(jobPosition*);
		jobPosition* returnforDelorupJob(int);
		void removeOneJob(jobPosition*);
		
		
		////////////////////////////////
		void assignApplicantTrans();
		void approveInterview();
		void calculateSalary();
		
		///////////////////////////
		void createTimeReport();
		void generateLLTimeRep();
		void refreshTimeRep();
		void setTimeRepHEAD(time_report*);
		void removeAllTimeReport();
		
		string convertF(string);
		
		
};
#endif
