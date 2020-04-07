#include "display.h"
#include "employee.h"
#include "time_report.h"
#include "operate.h"
#include "operatoracc.h"

int main(int argc, char** argv) {
	display fDisplay;
	operate function;
	char mainchoice,subchoice1;
	function.setopaccHEAD(NULL);
	function.generateLLoperator();
	function.setemploHEAD(NULL);
	function.generateLLemployee();
	function.setDepHEAD(NULL);
	function.generateLLDepartment();
	function.setJobPHEAD(NULL);
	function.generateLLJobPos();
	function.setTimeRepHEAD(NULL);
	function.generateLLTimeRep();
/*	function.viewDept();
	system("pause");
	system("cls");
	function.viewEmployee();
	system("pause");
	system("cls");
	function.display();*/
	for(;;){
		
		fDisplay.MainDisplay();
		cin>>mainchoice;
		if(cin.fail()==true){
			cin.clear();
			cin.ignore();
		}
		mainchoice=tolower(mainchoice);
		system("cls");
		if(mainchoice=='1'){
			fDisplay.AdminDisplayone();
			cin>>subchoice1;
			if(cin.fail()==true){
				cin.ignore();
				cin.clear();
			}
			subchoice1=tolower(subchoice1);
			if(subchoice1=='1'){
				system("cls");
				if(function.AdminLogin()==false);
				else{
					system("cls");
					fDisplay.AdminDisplaytwo();
					fflush(stdin);
					cin>>subchoice1;
					subchoice1=tolower(subchoice1);
					system("cls");
					if(cin.fail());
					else if(subchoice1=='1'){
						function.AdminUpdate();
						function.refreshEmploacc();
						function.removeallEmploAcc();
						function.generateLLemployee();
					}
					else if(subchoice1=='2'){
						if(function.changePassword()==true){
							cout<<"SUCCESSFULLY CHANGED PASSWORD!"<<endl<<endl;
							function.refreshopacc();
							function.removeallopAcc();
							function.generateLLoperator();
						}
						else cout<<"FAILED! "<<endl<<endl;	
					}
					else;
				}
			}
			else if(subchoice1=='2'){
				system("cls");
				if(function.AdminLogin()==false){
					cout<<endl<<endl<<"Authorized Admin Only!"<<endl<<endl;
				}
				else{
					system("pause");
					system("cls");
					if(function.AdminRegister()==false){
						cout<<endl<<"Registration Failed!"<<endl<<endl;
					}
					else{
						cout<<endl<<"Registered Successfully!"<<endl<<endl;
						function.removeallopAcc();
						function.generateLLoperator();
					}
				}
			}
			else if(subchoice1=='3'){
				system("cls");
				if(function.AdminLogin()==false){
					cout<<endl<<endl<<"Authorized Admin Only!"<<endl<<endl;
				}
				else{
					system("pause");
					system("cls");
					if(function.AdminDelete()==false){
						cout<<endl<<"Failed!"<<endl<<endl;
					}
					else{
						cout<<endl<<"The account is successfully removed!"<<endl<<endl;
						function.refreshopacc();
						function.removeallopAcc();
						function.generateLLoperator();
					}
				}
				
			}
			else;
		}
		else if(mainchoice=='2'){
			fflush(stdin);
			fDisplay.HrManagerDisplayOne();
			cin>>subchoice1;
			if(cin.fail()==true){
				cin.ignore();
				cin.clear();
			}
			subchoice1=tolower(subchoice1);
			if(subchoice1=='1'){
				system("cls");
				if(function.HRManagerLogin()==true){
					system("pause");
					system("cls");
					fDisplay.HrManagerDisplayTwo();
					fflush(stdin);
					cin>>subchoice1;
					if(cin.fail()==true){
						cin.ignore();
						cin.clear();
					}
					subchoice1=tolower(subchoice1);
					system("cls");
					if(subchoice1=='1'){
						fDisplay.HrManagerDisplayRecDir();
						fflush(stdin);
						cin>>subchoice1;
						if(cin.fail()==true){
							cin.ignore();
							cin.clear();
						}
						subchoice1=tolower(subchoice1);
						system("cls");
						if(subchoice1=='3'){
							fDisplay.HrManagerDisplayRecDirone();
							fflush(stdin);
							cin>>subchoice1;
							if(cin.fail()==true){
								cin.ignore();
								cin.clear();
							}
							subchoice1=tolower(subchoice1);
							system("cls");
							if(subchoice1=='1'){
								if(function.HrManagerCreateEmployee()==true){
									cout<<"SUCCESSFULLY CREATED EMPLOYEE!"<<endl<<endl;
									function.removeallEmploAcc();
									function.generateLLemployee();
								}
								else{
									cout<<"FAILED! "<<endl<<endl;
								}
							}
							else if(subchoice1=='2'){
								if(function.HrManagerCreateDepartment()==true){
									cout<<"SUCCESSFULLY CREATED DEPARTMENT!"<<endl<<endl;
									function.removeallDepartment();
									function.generateLLDepartment();
									function.removeallJobPos();
									function.generateLLJobPos();
								}
								else{
									cout<<"FAILED! "<<endl<<endl;
								}
							}
							else if(subchoice1=='3'){
								if(function.HrManagerCreateJobP()==true){
									cout<<"SUCCESSFULLY CREATED JOB!"<<endl<<endl;
									function.removeallJobPos();
									function.generateLLJobPos();
								}       								
								else{
									cout<<"FAILED! "<<endl<<endl;
								}
							}
						}
						else if(subchoice1=='2'){
							fDisplay.HrManagerDisplayRecDirtwo();
							fflush(stdin);
							cin>>subchoice1;
							if(cin.fail()==true){
								cin.ignore();
								cin.clear();
							}
							subchoice1=tolower(subchoice1);
							system("cls");
							if(subchoice1=='1'){
								if(function.updateorDelEmployee()==true){
									cout<<"SUCCESSFULLY MADE CHANGES!"<<endl;
									function.refreshEmploacc();
									function.removeallEmploAcc();
									function.generateLLemployee();
								}
								else cout<<"FAILED! "<<endl;
							}
							else if(subchoice1=='2'){
								if(function.updateorDelDepartment()==true){
									cout<<"SUCCESSFULLY MADE CHANGES! "<<endl;
									function.refreshDepartment();
									function.removeallDepartment();
									function.generateLLDepartment();
								}
								else cout<<"FAILED! "<<endl;
							}
							else if(subchoice1=='3'){
								if(function.updateorDelJob()==true){
									cout<<"SUCCESSFULLY MADE CHANGES! "<<endl;
									function.refreshJobPos();
									function.removeallJobPos();
									function.generateLLJobPos();
								}
								else cout<<"FAILED! "<<endl;
							}
							else if(subchoice1=='4'){
								
							}
						}
						else if(subchoice1=='1'){
							fDisplay.HrManagerDisplayRecDirthree();
							fflush(stdin);
							cin>>subchoice1;
							if(cin.fail()==true){
								cin.ignore();
								cin.clear();
							}
							subchoice1=tolower(subchoice1);
							system("cls");
							if(subchoice1=='1'){
								function.searchEmployee();
							}
							else if(subchoice1=='2'){
								function.searchDepartment();
							}
							else if(subchoice1=='3'){
								function.searchJob();
							}
						}
					}
					else if(subchoice1=='2'){
						fDisplay.HrManagerDisplayTran();
						fflush(stdin);
						cin>>subchoice1;
						system("cls");
						if(cin.fail());
						else if(subchoice1=='1'){
							function.assignApplicantTrans();
							function.refreshEmploacc();
							function.removeallEmploAcc();
							function.generateLLemployee();
						}
						else if(subchoice1=='2'){
							function.approveInterview();
							function.refreshEmploacc();
							function.removeallEmploAcc();
							function.generateLLemployee();
						}
						else if(subchoice1=='3'){
							fDisplay.HrManagerDisplayTranone();
							fflush(stdin);
							cin>>subchoice1;
							system("cls");
							if(cin.fail());
							else if(subchoice1=='1'){
								if(function.updateorDelJob()==true){
									cout<<"SUCCESSFULLY MADE CHANGES! "<<endl;
									function.refreshJobPos();
									function.removeallJobPos();
									function.generateLLJobPos();
								}
								else cout<<"FAILED! "<<endl;
							}
							else if(subchoice1=='2'){
								if(function.HrManagerCreateJobP()==true){
									cout<<"SUCCESSFULLY CREATED JOB!"<<endl<<endl;
									function.removeallJobPos();
									function.generateLLJobPos();
								}       								
								else{
									cout<<"FAILED! "<<endl<<endl;
								}
							}	
							else;
						}
						else if(subchoice1=='4'){
							function.calculateSalary();
							function.refreshEmploacc();
							function.removeallEmploAcc();
							function.generateLLemployee();
						}
						
					}
					else if(subchoice1=='4'){
						if(function.changePassword()==true){
							cout<<"SUCCESSFULLY CHANGED PASSWORD!"<<endl<<endl;
							function.refreshopacc();
							function.removeallopAcc();
							function.generateLLoperator();
						}
						else{
							cout<<"FAILED!"<<endl<<endl;
						}
					}
				}
				else;
			}
			else;
	
		}
		else if(mainchoice=='3'){
			
		}
		else if(mainchoice=='4'){
			fflush(stdin);
			fDisplay.HrManagerDisplayOne();
			cin>>subchoice1;
			if(cin.fail());
			else{
				subchoice1=tolower(subchoice1);
				system("cls");
				if(subchoice1=='1'){
					if(function.HRPersonnelLogin()==true){
						system("pause");
						system("cls");
						fflush(stdin);
						fDisplay.HRPersonnelDisplay();
						cin>>subchoice1;
						if(cin.fail());
						else if(subchoice1=='3'){
							system("cls");
							if(function.changePassword()==true){
								cout<<"SUCCESSFULLY CHANGED PASSWORD!"<<endl<<endl;
								function.refreshopacc();
								function.removeallopAcc();
								function.generateLLoperator();
							}
							else{
							cout<<"FAILED!"<<endl<<endl;
							}
						}
						else if(subchoice1=='2'){
							system("cls");
							function.createTimeReport();
							function.removeAllTimeReport();
							function.generateLLTimeRep();
							function.refreshEmploacc();
							function.removeallEmploAcc();
							function.generateLLemployee();
						}
						else if(subchoice1=='1'){
							
						}
						
					}
					else;
				}
				else;
			}
		}
		else if(mainchoice=='5')break;
		system("pause");
		system("cls");
	}
	function.removeallEmploAcc();
	function.removeallDepartment();
	function.removeallJobPos();
	function.removeallopAcc();
	getch();
	return 0;
}
