#include "display.h"

void display::MainDisplay(){
	cout<<"********OPERATOR SELECTION**********"<<endl;
	cout<<"*           [1]ADMIN               *"<<endl;
	cout<<"*           [2]HR MANAGER          *"<<endl;
	cout<<"*           [3]RECRUITER           *"<<endl;
	cout<<"*           [4]HR PERSONNEL        *"<<endl;
	cout<<"*           [5]EXIT                *"<<endl;
	cout<<"************************************"<<endl;
}
void display::AdminDisplayone(){
	cout<<"**********MODE SELECTION************"<<endl;
	cout<<"*           [1]LOGIN               *"<<endl;
	cout<<"*           [2]REGISTER            *"<<endl;
	cout<<"*           [3]DELETE USER         *"<<endl;
	cout<<"*           [4]RETURN              *"<<endl;
	cout<<"************************************"<<endl;
}
void display::AdminDisplaytwo(){
	cout<<"**********MODE SELECTION*************"<<endl;
	cout<<"*           [1]EDIT EMPLOYEE        *"<<endl;
	cout<<"*           [2]CHANGE PASSWORD      *"<<endl;
	cout<<"*           [3]LOGOUT               *"<<endl;
	cout<<"*************************************"<<endl;
}
void display::HrManagerDisplayOne(){
	cout<<"**********MODE SELECTION************"<<endl;
	cout<<"*           [1]LOGIN               *"<<endl;
	cout<<"*           [2]RETURN              *"<<endl;
	cout<<"************************************"<<endl;
}
void display::HrManagerDisplayTwo(){
	cout<<"*****************MODE SELECTION******************"<<endl;
	cout<<"*           [1]RECORD DIRECTORIES               *"<<endl;
	cout<<"*           [2]TRANSACTIONS                     *"<<endl;
	cout<<"*           [3]REPORTS                          *"<<endl;
	cout<<"*           [4]CHANGE PASSWORD                  *"<<endl;
	cout<<"*           [5]LOGOUT                           *"<<endl;
	cout<<"*************************************************"<<endl;
}
void display::HrManagerDisplayRecDir(){
	cout<<"*****************MODE SELECTION******************"<<endl;
	cout<<"*           [1]SEARCH RECORD                    *"<<endl;
	cout<<"*           [2]VIEW RECORD                      *"<<endl;
	cout<<"*           [3]CREATE RECORD                    *"<<endl;
	cout<<"*           [4]LOGOUT                           *"<<endl;
	cout<<"*************************************************"<<endl;
}
void display::HrManagerDisplayRecDirone(){
	cout<<"****************CREATE A RECORD******************"<<endl;
	cout<<"*           [1]EMPLOYEE                         *"<<endl;
	cout<<"*           [2]DEPARTMENT                       *"<<endl;
	cout<<"*           [3]JOB                              *"<<endl;
	cout<<"*           [4]BENEFITS                         *"<<endl;
	cout<<"*           [5]LOGOUT                           *"<<endl;
	cout<<"*************************************************"<<endl;
}
void display::HrManagerDisplayRecDirtwo(){
	cout<<"*****************VIEW A RECORD*******************"<<endl;
	cout<<"*           [1]EMPLOYEE                         *"<<endl;
	cout<<"*           [2]DEPARTMENT                       *"<<endl;
	cout<<"*           [3]JOB                              *"<<endl;
	cout<<"*           [4]BENEFITS                         *"<<endl;
	cout<<"*           [5]LOGOUT                           *"<<endl;
	cout<<"*************************************************"<<endl;
}
void display::HrManagerDisplayRecDirthree(){
	cout<<"****************SEARCH A RECORD******************"<<endl;
	cout<<"*           [1]EMPLOYEE                         *"<<endl;
	cout<<"*           [2]DEPARTMENT                       *"<<endl;
	cout<<"*           [3]JOB                              *"<<endl;
	cout<<"*           [4]BENEFITS                         *"<<endl;
	cout<<"*           [5]LOGOUT                           *"<<endl;
	cout<<"*************************************************"<<endl;
}
void display::HrManagerDisplayTran(){
	cout<<"*************AVAILABLE TRANSACTIONS**************"<<endl;
	cout<<"*           [1]ASSIGN APPLICANTS                *"<<endl;
	cout<<"*           [2]HIRE APPLICANTS                  *"<<endl;
	cout<<"*           [3]JOB OPENING                      *"<<endl;
	cout<<"*           [4]SALARY CALCULATION               *"<<endl;
	cout<<"*           [5]TIME REPORT                      *"<<endl;
	cout<<"*           [6]LOGOUT                           *"<<endl;
	cout<<"*************************************************"<<endl;
}
void display::HrManagerDisplayTranone(){
	cout<<"****************JOB TRANSACTION******************"<<endl;
	cout<<"*           [1]VIEW JOB POSITION                *"<<endl;
	cout<<"*           [2]OPEN JOB POSITION                *"<<endl;
	cout<<"*           [3]LOGOUT                           *"<<endl;
	cout<<"*************************************************"<<endl;
}
void display::HRPersonnelDisplay(){
	cout<<"*****************MODE SELECTION******************"<<endl;
	cout<<"*           [1]TIME REPORT LISTS                *"<<endl;
	cout<<"*           [2]CREATE TIME REPORT               *"<<endl;
	cout<<"*           [3]CHANGE PASSWORD                  *"<<endl;
	cout<<"*           [4]LOGOUT                           *"<<endl;
	cout<<"*************************************************"<<endl;
}
