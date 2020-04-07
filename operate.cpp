#include "operate.h"
#include "operatoracc.h"

void operate::setopaccHEAD(operatoracc* temp){
	opaccHEAD=temp;
}

void operate::setemploHEAD(employee* temp){
	emploHEAD=temp;
}


void operate::display(){
	department* temp1=depHEAD;
	while(temp1!=NULL){
		cout<<(*temp1->getorSetDeptName())<<"-"<<(*temp1->getorSetCode())<<endl;
		temp1=temp1->next;
	}
}

void operate::AdminUpdate(){
	employee* temp1=emploHEAD;
	employee* temp2;
	char subchoice1;
	char subchoice2;
	int count=0;
	int eq;
	string line;
	string final=" ";
	cout<<"Available Employees:"<<endl<<endl;
	while(temp1!=NULL){
		cout<<"["<<count+1<<"]"<<endl;
		cout<<"Employee Name: "<<(*temp1->getorSetName())<<endl;
		cout<<"ID Number: "<<(*temp1->getorSetIDnum())<<endl;
		cout<<"SSS: "<<(*temp1->getorSetsss())<<endl;
		cout<<"Pag-ibig #:"<<(*temp1->getorSetPagibig())<<endl;
		cout<<"Phil-Health #:"<<(*temp1->getorSetPhilH())<<endl<<endl;
		temp1=temp1->next;
		count++;
	}
	fflush(stdin);
	cout<<"Select an employee: (press x and enter to exit)";
	cin>>subchoice1;
	subchoice1=tolower(subchoice1);
	if(cin.fail()){
		cout<<"FAILED! "<<endl;
		return;
	}
	else if(subchoice1=='x')return;
	else{
		eq=subchoice1-'0';
		temp2=returnforDelorUp(eq);
		system("cls");
		fflush(stdin);
		cout<<"Select a data to update: "<<endl;
		cout<<"[1]SSS"<<endl;
		cout<<"[2]Pag-ibig #"<<endl;
		cout<<"[3]Phil-Health #"<<endl;
		cout<<"[x]Logout"<<endl;
		cin>>subchoice2;
		if(cin.fail()){
			cout<<"FAILED! "<<endl;
			return;
		}
		else{
			fflush(stdin);
			if(subchoice2=='1'){
				cout<<"Enter new SSS #: ";
				getline(cin,line);
				final+=line;
				if(checkSameAttribute(line,4)==true){
					cout<<endl<<"The SSS number already exists!"<<endl;
					return;
				}
				fflush(stdin);
				cout<<"Confirm? (y/n) ";
				cin>>subchoice2;
				if(subchoice2=='y')(*temp2->getorSetsss())=final;
				else return;
			}
			else if(subchoice2=='2'){
				cout<<"Enter new Pag-ibig #: ";
				getline(cin,line);
				final+=line;
				if(checkSameAttribute(line,3)==true){
					cout<<endl<<"The Contact Number already exists!"<<endl;
					return;
				}
				fflush(stdin);
				cout<<"Confirm? (y/n) ";
				cin>>subchoice2;
				if(subchoice2=='y')(*temp2->getorSetPagibig())=final;
				else return;
			}
			else if(subchoice2=='3'){
				cout<<"Enter new Phil-Health #: ";
				getline(cin,line);
				final+=line; 
				if(checkSameAttribute(line,5)==true){
					cout<<endl<<"The Contact Number already exists!"<<endl;
					return;
				}
				fflush(stdin);
				cout<<"Confirm? (y/n) ";
				cin>>subchoice2;
				if(subchoice2=='y')(*temp2->getorSetPhilH())=final; 
				else return;
			}
			else return;
		}
	}
}
void operate::refreshopacc(){
	int i=0,count=0;
	operatoracc* temp1=opaccHEAD;
	ofstream file("operator/users.txt");
	if(file.is_open()){
		while(temp1!=NULL){
			i=0;
			while(i<=6){
				if(i==0 && count==0){
					file<<"First Name:"<<(*temp1->getorSetFname())<<endl;
				}
				else if(i==0 && count>0){
					file<<endl<<"First Name:"<<(*temp1->getorSetFname())<<endl;
				}
				else if(i==1){
					file<<"Middle Name:"<<(*temp1->getorSetMname())<<endl;
				}	
				else if(i==2){
					file<<"Last Name:"<<(*temp1->getorSetLname())<<endl;
				}
				else if(i==3){
					file<<"User Level:"<<(*temp1->getorSetuserLvl())<<endl;
				}
				else if(i==4){
					file<<"Username:"<<(*temp1->getorSetuserN())<<endl;
				}
				else if(i==5){
					file<<"Password:"<<(*temp1->getorSetpassw())<<endl;
				}
				else if(i==6){
					file<<"================================================~";
				}
				i++;
			}	
			temp1=temp1->next;
			count++;
		}
		file.close();
	}
	else{
		cout<<endl<<"error \a"<<endl;
	}
}


void operate::removeallopAcc(){
	operatoracc* temp1=opaccHEAD;
	operatoracc* temp2;
	while(temp2!=NULL){
		temp2=temp1->next;
		free(temp1);
		temp1=temp2;
	}
	opaccHEAD=NULL;
	
}


void operate::removeOneopAcc(operatoracc* temp1,int lvl){
	operatoracc* temp2=opaccHEAD;
	operatoracc* temp3;
	while(temp2!=NULL){
		if(temp2==temp1){
			if(temp2==opaccHEAD && opaccHEAD->next!=NULL){
				temp3=temp2->next;
				temp3->prev=NULL;
				opaccHEAD=temp3;
				free(temp2);
			}
			else if(temp2==opaccHEAD && opaccHEAD->next==NULL){
				free(temp2);
				opaccHEAD=NULL;
			}
			else if(temp2!=opaccHEAD && temp2->next==NULL){
				temp3=temp2->prev;
				temp3->next=NULL;
				free(temp2);
			}
			else if(temp2!=opaccHEAD && temp2->next!=NULL){
				temp3=temp2->prev;
				temp3->next=temp2->next;
				free(temp2);
			}
			if(lvl==1)AdminCount-=1;
			else if(lvl==2)HRManCount-=1;
			else if(lvl==3)RecCount-=1;
			else if(lvl==4)HRPersoCount-=1;
			break;
		}
		temp2=temp2->next;
	}
}

void operate::generateLLoperator(){
	int i=0;
	string line;
	string* temporary1;
	string tempo1;
	AdminCount=0;
	HRManCount=0;
	RecCount=0;
	HRPersoCount=0;
	ifstream file("operator/users.txt");
	if(file.is_open()){
		while(file.good()){
			i=0;
			operatoracc* temp1= new operatoracc();
			while(file.good()){
				if(file.good()==false)return;
				fflush(stdin);
				if(getline(file,line));
				else return;
				if(line=="\t" || line==" " || line=="\n");
				if(i==0){
					temporary1 = temp1->getorSetFname();
					tempo1 = filt(line);
					(*temporary1)= tempo1;
				}
				else if(i==1){
					temporary1 = temp1->getorSetMname();
					tempo1 = filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==2){
					temporary1 = temp1->getorSetLname();
					tempo1 = filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==3){
					temporary1 = temp1->getorSetuserLvl();
					tempo1 = filt(line);
					(*temporary1)=tempo1;
					if((To_lower(tempo1))==" admin")AdminCount+=1;
					else if((To_lower(tempo1))==" hr manager")HRManCount+=1;
					else if((To_lower(tempo1))==" recruiter")RecCount+=1;
					else if((To_lower(tempo1))==" hr personnel")HRPersoCount+=1;
				}
				else if(i==4){
					temporary1 = temp1->getorSetuserN();
					tempo1 = filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==5){
					temporary1 = temp1->getorSetpassw();
					tempo1 = filt(line);
					(*temporary1)=tempo1;
				}
				else if(i>=6)break;
			    	i++;
			}
			temp1->prev=NULL;
			if(opaccHEAD!=NULL){
				opaccHEAD->prev=temp1;
			}
			temp1->next=opaccHEAD;
			opaccHEAD=temp1;
		}
		file.close();
	}
	else{
		cout<<"error \a"<<endl;
	}
}

operatoracc* operate::getopaccHEAD(){
	return opaccHEAD;
}
operatoracc* operate::getopaccCurrent(){
	return opacccurrent;
}
string operate::filt(string temp1){
	char* temp2;
	char temp3[20]={0};
	temp2=temp3;
	int loop=0,iloop=0;
	while(temp1[loop]!=':'){
		loop++;
	}
	loop++;
	while(loop<temp1.length()){
		temp2[iloop]=temp1[loop];
		iloop++;
		loop++;
	}
	return temp2;
}

string operate::To_lower(string temp1){
	int length=0;
	while(length!=temp1.length()){
		temp1[length]=tolower(temp1[length]);
		length++;
	}	
	return temp1;
}


bool operate::AdminLogin(){
	string user;
	string passw;
	fflush(stdin);
	cout<<"*************LOG-IN REQUIREMENT***************"<<endl<<endl;
	cout<<"USERNAME: ";
	getline(cin,user);
	cout<<"PASSWORD: ";
	getline(cin,passw);
	
	if(searchOperUser(user,passw,1)==NULL){
		cout<<endl<<endl<<"THE ACCOUNT DOES NOT EXIST!"<<endl<<endl;
		return false;
	}
	else{
		cout<<endl<<endl<<"SUCCESSFULLY LOGIN!!"<<endl<<endl;	
		opacccurrent=searchOperUser(user,passw,1);
		return true;
	}
}


bool operate::HRPersonnelLogin(){
	string user;
	string passw;
	fflush(stdin);
	cout<<"*************LOG-IN REQUIREMENT***************"<<endl<<endl;
	cout<<"USERNAME: ";
	getline(cin,user);
	cout<<"PASSWORD: ";
	getline(cin,passw);
	
	if(searchOperUser(user,passw,4)==NULL){
		cout<<endl<<endl<<"THE ACCOUNT DOES NOT EXIST!"<<endl<<endl;
		return false;
	}
	else{
		cout<<endl<<endl<<"SUCCESSFULLY LOGIN!!"<<endl<<endl;	
		opacccurrent=searchOperUser(user,passw,4);
		return true;
	}	
}

bool operate::AdminRegister(){
	string fname;
	string midname;
	string userLe;
	string lasname;
	char userLvl;
	cout<<"Welcome! Admin: "<<(*opacccurrent->getorSetFname())<<(*opacccurrent->getorSetLname())<<endl<<endl;
	cout<<"*****************REGISTRATION*****************"<<endl<<endl;
	cout<<"TYPE IN FIRST NAME: ";
	getline(cin,fname);
	cout<<"TYPE IN MIDDLE NAME: ";
	getline(cin,midname);
	cout<<"TYPE IN LAST NAME: ";
	getline(cin,lasname);
	cout<<endl<<endl;
	cout<<"SELECT A USER LEVEL FOR THIS ACCOUNT: "<<endl;
	cout<<"[1] ADMIN"<<endl;
	cout<<"[2] HR MANAGER"<<endl;
	cout<<"[3] RECRUITER"<<endl;
	cout<<"[4] HR PERSONNEL"<<endl;
	cout<<"[5] CANCEL"<<endl;
	cin>>userLvl;
	if(cin.fail()==true){
		cin.ignore();
		cin.clear();
		return false;
	}
	
	if(userLvl=='1'){
		userLe=" Admin";
	}
	else if(userLvl=='2'){
		userLe=" HR Manager";
	}
	else if(userLvl=='3'){
		userLe=" Rectruiter";
	}
	else if(userLvl=='4'){
		userLe=" HR Personnel";
	}
	else{
		return false;
	}
	ofstream file("operator/users.txt",ios::app);
	if(file.is_open()){
		file<<endl;
		file<<"First Name: "<<fname<<endl;
		file<<"Middle Name: "<<midname<<endl;
		file<<"Last Name: "<<lasname<<endl;
		file<<"User Level:"<<userLe<<endl;
		file<<"Username: "<<fname<<endl;
		file<<"Password: user@1234"<<endl;
		file<<"================================================~";
		file.close();
	}
	else{
		cout<<endl<<"AN ERROR HAS OCCURED! \a"<<endl;
		return false;
	}
	
	return true;
}

bool operate::AdminDelete(){
	string fname;
	string mname;
	string lname;
	char finalch;
	char subch1;
	
	operatoracc* temp1;
	cout<<"Welcome! Admin: "<<(*opacccurrent->getorSetFname())<<(*opacccurrent->getorSetLname())<<endl<<endl;
	cout<<"*****************ACCOUNT REMOVAL*****************"<<endl;
	cout<<"(WARNING!ONCE DELETED, THE ACCOUNT WON'T BE RECOVERED)"<<endl<<endl;
	cout<<"ACCOUNT FIRST NAME: ";
	getline(cin,fname);
	cout<<"ACCOUNT MIDDLE NAME: ";
	getline(cin,mname);
	cout<<"ACCOUNT LAST NAME: ";
	getline(cin,lname);
	cout<<endl<<endl;
	temp1=searchandDel(fname,mname,lname);
	if(temp1!=NULL){
		cout<<"Account Details: "<<endl;
		cout<<"First Name:"<<(*temp1->getorSetFname())<<endl;
		cout<<"Middle Name:"<<(*temp1->getorSetMname())<<endl;
		cout<<"Last Name:"<<(*temp1->getorSetLname())<<endl;
		cout<<"User Level:"<<(*temp1->getorSetuserLvl())<<endl;
		cout<<"Password:"<<(*temp1->getorSetpassw())<<endl;
	}
	else if(temp1==opacccurrent){
		cout<<"CURRENT ACTIVE ACCOUNT CANNOT BE DELETED!!"<<endl<<endl;
	}
	else return false;
	cout<<"Delete Account (y/n) ? "<<endl;
	cin>>finalch;
	if(cin.fail()){
		cin.clear();
		cin.ignore();
		return false;
	}
	finalch=tolower(finalch);
	if(finalch=='y'){
		if( To_lower(*temp1->getorSetuserLvl())==" admin"){
			if(AdminCount==2){
				cout<<endl<<"CANNOT DELETE ADMIN ACCOUNTS ANYMORE!"<<endl;
				return false;
			}
			else{
				removeOneopAcc(temp1,1);
				return true;	
			}
		}
		else if( To_lower(*temp1->getorSetuserLvl())==" hr manager"){
			if(HRManCount==1){
				cout<<"Warning! this is the last account remaining for this user type!"<<endl;
				cout<<"Continue? (y/n)";
				fflush(stdin);
				cin>>subch1;
				if(cin.fail()){
					cin.clear();
					cin.ignore();
					return false;
				}
				subch1=tolower(subch1);
				if(subch1=='y'){
					removeOneopAcc(temp1,2);
					return true;
				}
				else return false;
			}
			else{
				removeOneopAcc(temp1,2);
				return true;
			} 
		}
		else if( To_lower(*temp1->getorSetuserLvl())==" recruiter"){
			if(RecCount==1){
				cout<<"Warning! this is the last account remaining for this user type!"<<endl;
				cout<<"Continue? (y/n)";
				fflush(stdin);
				cin>>subch1;
				subch1=tolower(subch1);
				if(cin.fail()){
					cin.clear();
					cin.ignore();
					return false;
				}
				
				if(subch1=='y'){
					removeOneopAcc(temp1,3);
					return true;
				}
				else return false;
			}
			else{
				removeOneopAcc(temp1,3);
				return true;
			} 
		}
		else if( To_lower(*temp1->getorSetuserLvl())==" hr personnel"){
			if(RecCount==1){
				cout<<"Warning! this is the last account remaining for this user type!"<<endl;
				cout<<"Continue? (y/n)";
				fflush(stdin);
				cin>>subch1;
				subch1=tolower(subch1);
				if(cin.fail()){
					cin.clear();
					cin.ignore();
					return false;
				}
				
				if(subch1=='y'){
					removeOneopAcc(temp1,4);
					return true;
				}
				else return false;
			}
			else{
				removeOneopAcc(temp1,4);
				return true;
			} 
		}
	}
	else{
		return false;
	}
	
}


operatoracc* operate::searchandDel(string fname,string mname,string lname){
	operatoracc* temp1=opaccHEAD;
	while(temp1!=NULL){
		
		if( To_lower(" "+fname)==To_lower(*temp1->getorSetFname()) && To_lower(" "+mname)==To_lower(*temp1->getorSetMname()) && To_lower(*temp1->getorSetLname())==To_lower(" "+lname)){
			return temp1;
		}
		
		temp1=temp1->next;
	}
	
	return NULL;
}






operatoracc* operate::searchOperUser(string username,string password,int lvl){
 	operatoracc* temp1=opaccHEAD;
 	string userdd=" ";
 	string passwd=" ";
 	passwd+=password;
 	userdd+=username;
 	while(temp1!=NULL){
 		if(lvl==1){
 			if((*temp1->getorSetuserN())==userdd && (*temp1->getorSetpassw())==passwd && (To_lower(*temp1->getorSetuserLvl()))==" admin")return temp1;
		 }
		else if(lvl==2){
			if((*temp1->getorSetuserN())==userdd && (*temp1->getorSetpassw())==passwd && (To_lower(*temp1->getorSetuserLvl()))==" hr manager")return temp1;
		}
		
		else if(lvl==3){
			if((*temp1->getorSetuserN())==userdd && (*temp1->getorSetpassw())==passwd && (To_lower(*temp1->getorSetuserLvl()))==" recruiter")return temp1;
		}
		
		else if(lvl==4){
			if((*temp1->getorSetuserN())==userdd && (*temp1->getorSetpassw())==passwd && (To_lower(*temp1->getorSetuserLvl()))==" hr personnel")return temp1;
		}
		else;
 		temp1=temp1->next;
	 }
	 
	 return NULL;
}


bool operate::changePassword(){
	string newpass;
	string currentpass;
	char subchoice1;
	cout<<"**************CHANGE PASSWORD***************"<<endl<<endl;
	fflush(stdin);
	cout<<"ENTER OLD PASSWORD: ";
	getline(cin,currentpass);
	cout<<"ENTER NEW PASSWORD: ";
	getline(cin,newpass);
	cout<<endl<<endl;
	if(To_lower(*opacccurrent->getorSetpassw())==(" "+currentpass)){
		cout<<"Save Changes? (y/n)";
		cin>>subchoice1;
		subchoice1=tolower(subchoice1);
		if(subchoice1=='y'){
			(*opacccurrent->getorSetpassw())=" "+newpass;
			return true;
		}
		return false;	
	}
	else{
		cout<<endl<<"OLD PASSWORD DOES NOT MATCH!!"<<endl<<endl;
		return false;
	}
	
	
}

bool operate::HRManagerLogin(){
	string user;
	string passw;
	fflush(stdin);
	cout<<"****************LOG-IN REQUIREMENT***************"<<endl<<endl;
	cout<<"USERNAME: ";
	getline(cin,user);
	cout<<"PASSWORD: ";
	getline(cin,passw);
	
	if(searchOperUser(user,passw,2)==NULL){
		cout<<endl<<endl<<"THE ACCOUNT DOES NOT EXIST!"<<endl<<endl;
		return false;
	}
	else{
		cout<<endl<<endl<<"SUCCESSFULLY LOGIN!!"<<endl<<endl;	
		opacccurrent=searchOperUser(user,passw,2);
		return true;
	}
}


bool operate::HrManagerCreateEmployee(){
	char subchoice1;
	jobPosition* tempo2;
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
	string Pagibig;
	string SSS;
	string PhilHealth;
	string departMent;
	string JobPos;
	string location;
	fflush(stdin);
	cout<<"Welcome! HR Manager: "<<(*opacccurrent->getorSetFname())<<(*opacccurrent->getorSetLname())<<endl;
	cout<<"******************EMPLOYEE CREATION****************"<<endl<<endl;
	cout<<"Enter ID Number: ";
	getline(cin,(ID_number));
	if(checkSameAttribute(ID_number,0)==true){
		cout<<endl<<"The ID Number already exists!"<<endl;
		return false;
	}
	cout<<"Enter Name: ";
	getline(cin,Name);
	if(checkSameAttribute(Name,1)==true){
		cout<<endl<<"The Employee Name already exists!"<<endl;
		return false;
	}
	cout<<"Enter Address: ";
	getline(cin,Address);
	cout<<"Enter Contact Number: ";
	getline(cin,ContactNumber);
	if(checkSameAttribute(ContactNumber,2)==true){
		cout<<endl<<"The Contact Number already exists!"<<endl;
		return false;
	}
	cout<<"Enter Age: ";
	getline(cin,Age);
	if(atoi(Age.c_str())<18){
		cout<<"Below 18 years old are prohibited in working in this company!"<<endl<<endl;
		return false;
	}
	cout<<"Enter Email-Address: ";
	getline(cin,emailAdd);
	if(checkSameAttribute(emailAdd,6)==true){
		cout<<endl<<"The Contact Number already exists!"<<endl;
		return false;
	}
	cout<<"Enter Birthday: ";
	getline(cin,Birthday);
	cout<<"Enter Sex: ";
	getline(cin,Sex);
	cout<<"Enter Father's Name: ";
	getline(cin,FatherName);
	cout<<"Enter Father's Occupation: ";
	getline(cin,OccuF);
	cout<<"Enter Mother's Name: ";
	getline(cin,MotherName);
	cout<<"Enter Mother's Occupation: ";
	getline(cin,OccuM);
	cout<<"Enter Marital Status: ";
	getline(cin,MaritalStat);
	cout<<"Enter Start Date: ";
	getline(cin,StartDate);
	cout<<"Enter (PAG-IBIG) MID number: ";
	getline(cin,Pagibig);
	if(checkSameAttribute(Pagibig,3)==true){
		cout<<endl<<"The Contact Number already exists!"<<endl;
		return false;
	}
	cout<<"Enter SSS number: ";
	getline(cin,SSS);
	if(checkSameAttribute(SSS,4)==true){
		cout<<endl<<"The SSS number already exists!"<<endl;
		return false;
	}
	cout<<"Enter Phil-Health number: ";
	getline(cin,PhilHealth);
	if(checkSameAttribute(PhilHealth,5)==true){
		cout<<endl<<"The Contact Number already exists!"<<endl;
		return false;
	}
	viewDept();
	cout<<"Enter Department: ";
	getline(cin,departMent);
	cout<<"Enter location: ";
	getline(cin,location);
	cout<<endl<<endl;
	viewJob();
	cout<<"Enter Job Position: ";
	getline(cin,JobPos);
	tempo2=checkforJobexist(departMent,location,JobPos);
	if(tempo2==NULL){
		cout<<"Please fill up an existing job in an existing department!"<<endl<<endl;
		return false;
	}
	cout<<endl;
	fflush(stdin);
	cout<<"Confirm? (y/n)";
	cin>>subchoice1;
	if(cin.fail()){
		cin.ignore();
		cin.clear();
		return false;
	}
	subchoice1=tolower(subchoice1);
	if(subchoice1=='y'){
		ofstream file("employee/employee.txt",ios::app);
		if(file.is_open()){
			if(employeeCount>0)file<<endl;
			file<<"ID Number: "<<ID_number<<endl;
			file<<"Name: "<<Name<<endl;
			file<<"Address: "<<Address<<endl;
			file<<"Contact Number: "<<ContactNumber<<endl;
			file<<"Age: "<<Age<<endl;
			file<<"E-mail Address: "<<emailAdd<<endl;
			file<<"Birthday: "<<Birthday<<endl;
			file<<"Sex: "<<Sex<<endl;
			file<<"Father's Name: "<<FatherName<<endl;
			file<<"Father's Occupation: "<<OccuF<<endl;
			file<<"Mother's Name: "<<MotherName<<endl;
			file<<"Mother's Occupation: "<<OccuM<<endl;
			file<<"Marital Status: "<<MaritalStat<<endl;
			file<<"Start Date: "<<StartDate<<endl;
			file<<"Employee Status: Applicant"<<endl;
			file<<"Department: "<<departMent<<endl;
			file<<"Basic Pay: n/a"<<endl;
			file<<"Total Work Hours: n/a"<<endl;
			file<<"Rate Per Hour: n/a"<<endl;
			file<<"Gross Pay: n/a"<<endl;
			file<<"Tax: "<<endl;
			file<<"Pag-ibig: "<<Pagibig<<endl;
			file<<"SSS: "<<SSS<<endl;
			file<<"Phil Health: "<<PhilHealth<<endl;
			file<<"Total Deductions: "<<endl;
			file<<"Total Benefits: "<<endl;
			file<<"Total Adjustments: "<<endl;
			file<<"NetPay: "<<endl;
			file<<"Job Position: "<<JobPos<<endl;
			file<<"Location: "<<location<<endl;
			file<<"================================================~";
			file.close();
		}
		else{
			
			cout<<"AN ERROR HAS OCCURED \a"<<endl<<endl;
			return false;
		}
		
		
		
		return true;
	}
	return false;
	
	
}


void operate::generateLLemployee(){
	int i;
	string line;
	string tempo1;
	string* temporary1;
	employeeCount=0;
	ifstream file("employee/employee.txt");
	if(file.is_open()){
		while(file.good()){
			i=0;
			employee* temp1= new employee();
			while(file.good()){
				if(file.good()==false)return;
				fflush(stdin);
				if(getline(file,line));
				else return;
				if(line==" " || line=="\t" || line=="\n");
				if(i==0){
					temporary1=(temp1->getorSetIDnum());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==1){
					temporary1=(temp1->getorSetName());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==2){
					temporary1=(temp1->getorSetAdd());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==3){
					temporary1=(temp1->getorSetContNum());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==4){
					temporary1=(temp1->getorSetAge());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==5){
					temporary1=(temp1->getorSetEadd());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==6){
					temporary1=(temp1->getorSetbDate());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==7){
					temporary1=(temp1->getorSetSex());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==8){
					temporary1=(temp1->getorSetFname());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==9){
					temporary1=(temp1->getorSetOccuF());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==10){
					temporary1=(temp1->getorSetMname());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==11){
					temporary1=(temp1->getorSetOccuM());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==12){
					temporary1=(temp1->getorSetMStat());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==13){
					temporary1=(temp1->getorSetStDate());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==14){
					temporary1=(temp1->getorSetEmpStat());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==15){
					temporary1=(temp1->getorSetDept());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==16){
					temporary1=(temp1->getorSetBasPay());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==17){
					temporary1=(temp1->getorSetTotWorkH());
					tempo1=filt(line);
					(*temporary1)=tempo1;	
				}
				else if(i==18){
					temporary1=(temp1->getorSetRPhour());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==19){
					temporary1=(temp1->getorSetGrossP());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==20){
					temporary1=(temp1->getorSetTax());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==21){
					temporary1=(temp1->getorSetPagibig());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==22){
					temporary1=(temp1->getorSetsss());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==23){
					temporary1=(temp1->getorSetPhilH());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==24){
					temporary1=(temp1->getorSettotalDed());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==25){
					temporary1=(temp1->getorSettotalBen());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==26){
					temporary1=(temp1->getorSettotalAdj());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==27){
					temporary1=(temp1->getorSetnPay());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==28){
					temporary1=(temp1->getorSetJobP());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==29){
					temporary1=(temp1->getorsetLoc());
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i>29)break;
				i++;
			}
			temp1->prev=NULL;
			if(emploHEAD!=NULL){
				emploHEAD->prev=temp1;
			}
			temp1->next=emploHEAD;
			emploHEAD=temp1;
			employeeCount+=1;
		}
		file.close();
	}
	else{
		cout<<endl<<"AN ERROR HAS OCCURED!! \a"<<endl<<endl;
	}	
}


void operate::refreshEmploacc(){
	int i=0,count=0;
	employee* temp1=emploHEAD;
	
	ofstream file("employee/employee.txt");
	if(file.is_open()){
		while(temp1!=NULL){
			i=0;
			while(i<=30){
				if(i==0 && count==0){
					file<<"ID Number:"<<(*temp1->getorSetIDnum())<<endl;
				}
				else if(i==0 && count>0){
					file<<endl<<"ID Number:"<<(*temp1->getorSetIDnum())<<endl;
				}
				else if(i==1){
					file<<"Name:"<<(*temp1->getorSetName())<<endl;
				}
				else if(i==2){
					file<<"Address:"<<(*temp1->getorSetAdd())<<endl;
				}
				else if(i==3){
					file<<"Contact Number:"<<(*temp1->getorSetContNum())<<endl;
				}
				else if(i==4){
					file<<"Age:"<<(*temp1->getorSetAge())<<endl;
				}
				else if(i==5){
					file<<"E-mail Address:"<<(*temp1->getorSetEadd())<<endl;
				}
				else if(i==6){
					file<<"Birthday:"<<(*temp1->getorSetbDate())<<endl;
				}
				else if(i==7){
					file<<"Sex:"<<(*temp1->getorSetSex())<<endl;
				}
				else if(i==8){
					file<<"Father's Name:"<<(*temp1->getorSetFname())<<endl;
				}
				else if(i==9){
					file<<"Father's Occupation:"<<(*temp1->getorSetOccuF())<<endl;
				}
				else if(i==10){
					file<<"Mother's Name:"<<(*temp1->getorSetMname())<<endl;
				}
				else if(i==11){
					file<<"Mother's Occupation:"<<(*temp1->getorSetOccuM())<<endl;
				}
				else if(i==12){
					file<<"Marital Status:"<<(*temp1->getorSetMStat())<<endl;
				}
				else if(i==13){
					file<<"Start Date:"<<(*temp1->getorSetStDate())<<endl;
				}
				else if(i==14){
					file<<"Employee Status:"<<(*temp1->getorSetEmpStat())<<endl;
				}
				else if(i==15){
					file<<"Department:"<<(*temp1->getorSetDept())<<endl;
				}
				else if(i==16){
					file<<"Basic Pay:"<<(*temp1->getorSetBasPay())<<endl;
				}
				else if(i==17){
					file<<"Total Work Hours:"<<(*temp1->getorSetTotWorkH())<<endl;
				}
				else if(i==18){
					file<<"Rate Per Hour:"<<(*temp1->getorSetRPhour())<<endl;
				}
				else if(i==19){
					file<<"Gross Pay:"<<(*temp1->getorSetGrossP())<<endl;
				}
				else if(i==20){
					file<<"Tax:"<<(*temp1->getorSetTax())<<endl;
				}
				else if(i==21){
					file<<"Pag-ibig:"<<(*temp1->getorSetPagibig())<<endl;
				}
				else if(i==22){
					file<<"SSS:"<<(*temp1->getorSetsss())<<endl;
				}
				else if(i==23){
					file<<"Phil Health:"<<(*temp1->getorSetPhilH())<<endl;
				}
				else if(i==24){
					file<<"Total Deductions:"<<(*temp1->getorSettotalDed())<<endl;
				}
				else if(i==25){
					file<<"Total Benefits:"<<(*temp1->getorSettotalBen())<<endl;
				}
				else if(i==26){
					file<<"Total Adjustments:"<<(*temp1->getorSettotalAdj())<<endl;
				}
				else if(i==27){
					file<<"NetPay:"<<(*temp1->getorSetnPay())<<endl;
				}
				else if(i==28){
					file<<"Job Position:"<<(*temp1->getorSetJobP())<<endl;
				}
				else if(i==29){
					file<<"Location:"<<(*temp1->getorsetLoc())<<endl;
				}
				else if(i==30){
					file<<"================================================~";
				}
				i++;
			}
			
			temp1=temp1->next;
			count++;
		}
		file.close();
	}
	else{
		cout<<endl<<"error \a"<<endl<<endl;
	}
	
}

bool operate::checkSameAttribute(string temp,int datalvl){
	employee* tempo1=emploHEAD;
	while(tempo1!=NULL){
		if(datalvl==0){
			if( To_lower(" "+temp)==To_lower(*tempo1->getorSetIDnum())) return true;
		}
		else if(datalvl==1){
			if( To_lower(" "+temp)==To_lower(*tempo1->getorSetName())) return true;
		}
		else if(datalvl==2){
			if( To_lower(" "+temp)==To_lower(*tempo1->getorSetContNum())) return true;
		}
		else if(datalvl==3){
			if( To_lower(" "+temp)==To_lower(*tempo1->getorSetPagibig())) return true;
		}
		else if(datalvl==4){
			if( To_lower(" "+temp)==To_lower(*tempo1->getorSetsss())) return true;
		}
		else if(datalvl==5){
			if( To_lower(" "+temp)==To_lower(*tempo1->getorSetPhilH())) return true;
		}
		else if(datalvl==6){
			if( To_lower(" "+temp)==To_lower(*tempo1->getorSetEadd())) return true;
		}
		else;
		tempo1=tempo1->next;
	}
	
	return false;
}

void operate::viewEmployee(){
	employee* temp1=emploHEAD;
	int count=0;
	cout<<"*****************EMPLOYEE LIST AVAILABLE******************"<<endl<<endl;
	while(temp1!=NULL){
		cout<<"["<<count+1<<"]"<<endl;
		cout<<"Employee Information: "<<endl;
		cout<<"ID Number:"<<(*temp1->getorSetIDnum())<<endl;
		cout<<"Name:"<<(*temp1->getorSetName())<<endl;
		cout<<"E-mail Address:"<<(*temp1->getorSetEadd())<<endl;
		cout<<"Start Date:"<<(*temp1->getorSetStDate())<<endl;
		cout<<"Employee Status:"<<(*temp1->getorSetEmpStat())<<endl;
		cout<<"Department:"<<(*temp1->getorSetDept())<<endl;
		cout<<"Job Position:"<<(*temp1->getorSetJobP())<<endl;
		cout<<"Payroll Information: "<<endl;
		cout<<"Basic Pay:"<<(*temp1->getorSetBasPay())<<endl;
		cout<<"Rate Per Hour:"<<(*temp1->getorSetRPhour())<<endl;
		cout<<"Deductions:"<<(*temp1->getorSettotalDed())<<endl;
		cout<<endl<<endl;
		temp1=temp1->next;
		count++;
	}
}

void operate::removeallEmploAcc(){
	employee* temp1=emploHEAD;
	employee* temp2=emploHEAD;
	while(temp2!=NULL){
		temp2=temp1->next;
		free(temp1);
		temp1=temp2;
	}
	emploHEAD=NULL;
	
}

employee* operate::getemploHEAD(){
	return emploHEAD;
}
employee* operate::getemploCurrent(){
	return emplocurrent;
}


void operate::generateLLDepartment(){
	int i=0;
	string line;
	string* temporary1;
	string tempo1;
	departmentCount=0;
	ifstream file("department/departments.txt");
	if(file.is_open()){
		while(file.good()){
			i=0;
			department* temp1= new department();
			while(file.good()){
				if(file.good()==false)return;
				fflush(stdin);
				if(getline(file,line));
				else return;
				if(i==0){
					temporary1=temp1->getorSetDeptName();
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==1){
					temporary1=temp1->getorSetlocation();
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==2){
					temporary1=temp1->getorSetCode();
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i>2)break;
				i++;
			}
			temp1->prev=NULL;
			if(depHEAD!=NULL){
				depHEAD->prev=temp1;
			}
			temp1->next=depHEAD;
			depHEAD=temp1;
			departmentCount+=1;
			
		}
		file.close();
	}
	else{
		cout<<endl<<"AN ERROR HAS OCCURED! \a"<<endl<<endl;
	}
}

void operate::refreshDepartment(){
	department* temp1=depHEAD;
	int i=0,count=0;
	ofstream file("department/departments.txt");
	if(file.is_open()){
		while(temp1!=NULL){
			i=0;
			while(i<=3){
				if(i==0 && count==0){
					file<<"Department Name:"<<(*temp1->getorSetDeptName())<<endl;
				}
				else if(i==0 && count>0){
					file<<endl<<"Department Name:"<<(*temp1->getorSetDeptName())<<endl;
				}
				else if(i==1){
					file<<"Location:"<<(*temp1->getorSetlocation())<<endl;
				}
				else if(i==2){
					file<<"Code:"<<(*temp1->getorSetCode())<<endl;
				}
				else if(i==3){
					file<<"================================================~";
				}
				i++;
			}
			count++;
			temp1=temp1->next;
		}
		file.close();
	}
	else{
		cout<<"AN ERROR HAS OCCURED!! \a"<<endl<<endl;
	}
}

bool operate::shortCutCreateJobP(string dept,string location){
	string jobOrdN;
	string jobReq;
	string jobPos;
	string uniCode;
	char subchoice1;
	cout<<endl<<endl;
	fflush(stdin);
	cout<<"(This job position will directly fall into the created department)"<<endl<<endl;
	cout<<"Enter corresponding Job Order Number: ";
	getline(cin,jobOrdN);
	cout<<"Enter corresponding Job Position: ";
	getline(cin,jobPos);
	cout<<"Enter Job requirement: ";
	getline(cin,jobReq);
	cout<<"Enter Record Code: ";
	getline(cin,uniCode);
	if(checkSameAttributeJob(jobOrdN,jobPos,dept,uniCode)==true){
		cout<<"Please fill in a unique description for each fields!"<<endl<<endl;
		return false;
	}
	fflush(stdin);
	cout<<"Confirm Job Position? (y/n)";
	cin>>subchoice1;
	if(cin.fail()==true){
		cin.ignore();
		cin.clear();
		return false;
	}
	subchoice1=tolower(subchoice1);
	cout<<endl;
	if(subchoice1=='y'){
		ofstream file("department/job.txt",ios::app);
		if(file.is_open()){
			if(jobCount>0)file<<endl;
			file<<"Job Order #: "<<jobOrdN<<endl;
			file<<"Job Position: "<<jobPos<<endl;
			file<<"Job Requirements: "<<jobReq<<endl;
			file<<"Corresponding Department: "<<dept<<endl;
			file<<"Correspoding Location: "<<location<<endl;
			file<<"Code: "<<uniCode<<endl;
			file<<"================================================~";
			file.close();
		}
		else{
			cout<<"AN ERROR HAS OCCURED! \a"<<endl<<endl;
			return false;
		}
		return true;
	}
	return false;
}

bool operate::HrManagerCreateDepartment(){
	string DeptName;
	string location;
	string uniCode;
	char subchoice1;
	fflush(stdin);
	cout<<"Welcome! HR Manager: "<<(*opacccurrent->getorSetFname())<<(*opacccurrent->getorSetLname())<<endl;
	cout<<"******************DEPARTMENT CREATION****************"<<endl<<endl;
	cout<<"Enter Corresponding Department Name: ";
	getline(cin,DeptName);
	if(checkSameAttributeDept(DeptName,0)==true){
		cout<<"The Department Name already exists!!"<<endl<<endl;
		return false;
	}
	cout<<"Enter Corresponding Location: ";
	getline(cin,location);
	if(checkSameAttributeDept(location,1)==true){
		cout<<"The location is already occupied!!"<<endl<<endl;
		return false;
	}
	cout<<"Enter Record Code: ";
	getline(cin,uniCode);
	if(checkSameAttributeDept(uniCode,2)==true){
		cout<<"Please choose a unique record code!!"<<endl<<endl;
		return false;
	}
	cout<<"Add Corresponding Job Positions? (y/n) ";
	cin>>subchoice1;
	if(cin.fail()){
		cin.clear();
		cin.ignore();
		return false;
	}
	subchoice1=tolower(subchoice1);
	if(subchoice1=='y'){
		if(shortCutCreateJobP(DeptName,location)==false){
			cout<<"The job position was not successfully created!"<<endl<<endl;
		}
		else cout<<"The job position was successfully created!"<<endl<<endl;
	}
	else;	
		
	cout<<"Confirm Department? (y/n) ";
	fflush(stdin);
	cin>>subchoice1;
	if(cin.fail()){
		cin.clear();
		cin.ignore();
		return false;
	}
	
	if(subchoice1=='y'){
		
		ofstream file("department/departments.txt",ios::app);
		if(file.is_open()){
			if(departmentCount>0)file<<endl;
			file<<"Department Name: "<<DeptName<<endl;
			file<<"Location: "<<location<<endl;
			file<<"Code: "<<uniCode<<endl;
			file<<"================================================~";
			file.close();
			return true;
		}
		else{
			cout<<"AN ERROR HAS OCCURED! "<<endl<<endl;
			return false;
		}
		
		return true;
	}
	return false;
}


bool operate::checkSameAttributeDept(string temp,int lvl){
	department* temp1=depHEAD;
	while(temp1!=NULL){
		if(lvl==0){
			if( To_lower(" "+temp)==To_lower(*temp1->getorSetDeptName())) return true;
		}
		else if(lvl==1){
			if( To_lower(" "+temp)==To_lower(*temp1->getorSetlocation())) return true;
		}
		else if(lvl==2){
			if( To_lower(" "+temp)==To_lower(*temp1->getorSetCode())) return true;
		}
		temp1=temp1->next;
	}
	return false;
	
}


void operate::viewDept(){
	department* temp1=depHEAD;
	int count=0;
	cout<<"******************DEPARTMENT LISTS AVAILABLE****************"<<endl<<endl<<endl;
	while(temp1!=NULL){
		cout<<"["<<count+1<<"]"<<endl;
		cout<<"Department Name:"<<(*temp1->getorSetDeptName())<<endl;
		cout<<"Location: "<<(*temp1->getorSetlocation())<<endl;
		cout<<"Code: "<<(*temp1->getorSetCode())<<endl;
		temp1=temp1->next;
		count++;
	}
	cout<<endl<<endl;
}


department* operate::searchDept(string n,string m){
	department* temp1=depHEAD;
	string finaln=" ";
	finaln+=n;
	string finalm=" ";
	finalm+=m;
	while(temp1!=NULL){
		if(To_lower(*temp1->getorSetDeptName())==finaln && To_lower(*temp1->getorSetlocation())==finalm){
			return temp1;
		}
		temp1=temp1->next;
	}
	return NULL;
}

void operate::removeallDepartment(){
	department* temp1=depHEAD;
	department* temp2=temp1;
	while(temp2!=NULL){
		temp2=temp1->next;
		free(temp1);
		temp1=temp2;
	}
	depHEAD=NULL;
}

void operate::setDepHEAD(department* temp){
	depHEAD=temp;
}

department* operate::getDepHEAD(){
	return depHEAD;
}

void operate::setJobPHEAD(jobPosition* temp){
	jobPosHEAD=temp;
}

jobPosition* operate::getJobPHEAD(){
	return jobPosHEAD;
}

void operate::removeallJobPos(){
	jobPosition* temp1=jobPosHEAD;
	jobPosition* temp2=temp1;
	while(temp1!=NULL){
		temp2=temp1->next;
		free(temp1);
		temp1=temp2;
	}
	jobPosHEAD=NULL;
}
void operate::refreshJobPos(){
	int i=0,count=0;
	jobPosition* temp1=jobPosHEAD;
	ofstream file("department/job.txt");
	if(file.is_open()){
		while(temp1!=NULL){
			i=0;
			while(i<=6){
				if(i==0 && count==0){
					file<<"Job Order #:"<<(*temp1->getorSetorderNum())<<endl;
				}
				else if(i==0 && count>0){
					file<<endl<<"Job Order #:"<<(*temp1->getorSetorderNum())<<endl;
				}
				else if(i==1){
					file<<"Job Position:"<<(*temp1->getorSetPosition())<<endl;
				}
				else if(i==2){
					file<<"Job Requirements:"<<(*temp1->getorSetJobReq())<<endl;
				}
				else if(i==3){
					file<<"Corresponding Department:"<<(*temp1->getorSetDepartM())<<endl;
				}
				else if(i==4){
					file<<"Corresponding Location:"<<(*temp1->getorSetlocation())<<endl;
				}
				else if(i==5){
					file<<"Code:"<<(*temp1->getorSetCode())<<endl;
				}
				else if(i==6){
					file<<"================================================~";
				}	
				i++;
			}
			count++;
			temp1=temp1->next;
		}
	}
	else{
		cout<<"AN ERROR HAS OCCURED! "<<endl<<endl;
	}
	
}


void operate::generateLLJobPos(){
	string line;
	int i=0;
	string* temporary1;
	string tempo1;
	jobCount=0;
	ifstream file("department/job.txt");
	if(file.is_open()){
		while(file.good()){
			i=0;
			jobPosition* temp1= new jobPosition();
			while(file.good()){
				fflush(stdin);
				if(file.good()==false)return;
				if(getline(file,line));
				else return;
				
				if(i==0){
					temporary1 = temp1->getorSetorderNum();
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==1){
					temporary1 = temp1->getorSetPosition();
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==2){
					temporary1 = temp1->getorSetJobReq();
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==3){
					temporary1 = temp1->getorSetDepartM();
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==4){
					temporary1 = temp1->getorSetlocation();
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==5){
					temporary1 = temp1->getorSetCode();
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i>5)break;
				i++;	
			}
			temp1->prev=NULL;
			if(jobPosHEAD!=NULL){
				jobPosHEAD->prev=temp1;
			}
			
			temp1->next=jobPosHEAD;
			jobPosHEAD=temp1;
			jobCount+=1;
			
		}
		file.close();
	}
	else{
		cout<<"AN ERROR HAS OCCURED! "<<endl<<endl;
	}
}



bool operate::HrManagerCreateJobP(){
	string orderNum;
	string Position;
	string JobRequirements;
	string DepartMent;
	string uniCode;
	string location;
	char subchoice1;
	
	department* tempo1;
	
	fflush(stdin);
	cout<<"Welcome! HR Manager: "<<(*opacccurrent->getorSetFname())<<(*opacccurrent->getorSetLname())<<endl;
	cout<<"******************JOB POSITION CREATION****************"<<endl<<endl;
	cout<<"Enter Job Order #: ";
	getline(cin,orderNum);
	cout<<"Enter Job Position: ";
	getline(cin,Position);
	if(To_lower(Position)==" " || To_lower(Position)=="\n" || To_lower(Position)=="\t"){
		cout<<"Please fill in a valid name! "<<endl<<endl;
		return false;
	}
	cout<<"Enter Job Requirement: ";
	getline(cin,JobRequirements);
	cout<<endl<<endl;
	cout<<"Available Department: "<<endl;
	viewDept();
	cout<<"Enter Corresponding Department: ";
	getline(cin,DepartMent);
	cout<<"Enter Corresponding Location: ";
	getline(cin,location);
	tempo1=searchDept(To_lower(DepartMent),To_lower(location));
	if(tempo1==NULL){
		cout<<endl<<"Please fill in an existing department and location! "<<endl<<endl;
		return false;
	}
	cout<<"Enter Record Code: ";
	getline(cin,uniCode);
	cout<<endl;
	if(checkSameAttributeJob(orderNum,Position,DepartMent,uniCode)==true){
		cout<<"Please fill in a unique description for each fields!"<<endl<<endl;
		return false;
	}
	cout<<"Confirm (y/n) ";
	cin>>subchoice1;
	if(cin.fail()==true){
		cin.ignore();
		cin.clear();
		return false;
	}
	subchoice1=tolower(subchoice1);
	if(subchoice1=='y'){
		ofstream file("department/job.txt",ios::app);
		if(file.is_open()){
			if(jobCount>0)file<<endl;
			file<<"Job Order #: "<<orderNum<<endl;
			file<<"Job Position: "<<Position<<endl;
			file<<"Job Requirements: "<<JobRequirements<<endl;
			file<<"Corresponding Department: "<<DepartMent<<endl;
			file<<"Corresponding Location: "<<location<<endl;
			file<<"Code: "<<uniCode<<endl;
			file<<"================================================~";
			file.close();
		}
		else{
			cout<<"AN ERROR HAS OCCURED! \a"<<endl<<endl;
			return false;
		}
		
		return true;
	}	
	else return false;
	
}

bool operate::checkSameAttributeJob(string orderN,string jPos,string Dept,string uniCode){
	jobPosition* temp1=jobPosHEAD;
	while(temp1!=NULL){
		if( To_lower(*temp1->getorSetCode())==To_lower(" "+uniCode) || (To_lower(*temp1->getorSetDepartM())==To_lower(" "+Dept) && To_lower(*temp1->getorSetorderNum())==To_lower(" "+orderN) && To_lower(*temp1->getorSetPosition())==To_lower(" "+jPos))){
			return true;
		}
		temp1=temp1->next;
	}
	return false;
		
}

void operate::searchEmployee(){
	char subchoice1;
	string name;
	cout<<"******************SEARCH EMPLOYEE**************"<<endl;
	cout<<"Please choice a criteria record: "<<endl;
	cout<<"[1]Name"<<endl;
	cout<<"[2]ID Number"<<endl;
	cout<<"[3]Logout"<<endl;
	cin>>subchoice1;
	if(cin.fail()==true){
		cin.ignore();
		cin.clear();
		return;
	}
	if(subchoice1=='1'){
		cout<<endl<<endl;
		fflush(stdin);
		cout<<"Enter Name: ";
		getline(cin,name);
		cout<<endl;
		searchempNameCri(name);
	}
	else if(subchoice1=='2'){
		cout<<endl<<endl;
		fflush(stdin);
		cout<<"Enter ID Number: ";
		getline(cin,name);
		cout<<endl;
		searchempIdNumCri(name);
	}
	else return;
	
}


void operate::searchempNameCri(string name){
	string fname=" ";
	string* addNameptr;
	string compnametwo="0";
	fname+=name;
	int length=fname.length();
	employee* temp1=emploHEAD;
	int i=0;
	int count=0;
	cout<<"Found Results: "<<endl<<endl<<endl;
	while(temp1!=NULL){
		i=0;
		char compname[20]={0};  
		addNameptr= (temp1->getorSetName());
		compnametwo=(*addNameptr);
		while(i<length){
			compname[i]=compnametwo[i];
			i++;
		}
		if( To_lower(fname)==To_lower(compname)){
			cout<<"Result #"<<count+1<<":"<<endl;
			cout<<"ID Number:"<<(*temp1->getorSetIDnum())<<endl;
			cout<<"Employee Name:"<<(*temp1->getorSetName())<<endl;
			cout<<"Department:"<<(*temp1->getorSetDept())<<endl;
			cout<<"Job Position:"<<(*temp1->getorSetJobP())<<endl;
			cout<<"Employee Status:"<<(*temp1->getorSetEmpStat())<<endl<<endl;
			count++;
		}
		temp1=temp1->next;
	}
	
}

void operate::searchempIdNumCri(string Idnumber){
	string fId=" ";
	fId+=Idnumber;
	string* IdPtr;
	string IdCompare="0";
	int length=fId.length();
	employee* temp1=emploHEAD;
	int i=0;
	int count=0;
	cout<<"Found Results: "<<endl<<endl<<endl;
	while(temp1!=NULL){
		i=0;
		char compID[20]={0};
		IdPtr= (temp1->getorSetIDnum());
		IdCompare=(*IdPtr);
		while(i<length){
			compID[i]=IdCompare[i];
			i++;
		}
		if( To_lower(fId)==To_lower(compID)){
			cout<<"Result #"<<count+1<<":"<<endl;
			cout<<"ID Number:"<<(*temp1->getorSetIDnum())<<endl;
			cout<<"Employee Name:"<<(*temp1->getorSetName())<<endl;
			cout<<"Department:"<<(*temp1->getorSetDept())<<endl;
			cout<<"Job Position:"<<(*temp1->getorSetJobP())<<endl<<endl;
			count++;
		}
		temp1=temp1->next;
	}
}


void operate::searchDepartment(){
	string toBeSearch;
	char subchoice1;
	cout<<"******************SEARCH DEPARTMENT***************"<<endl<<endl;
	cout<<"Please choose a criteria to search: "<<endl;
	cout<<"[1]Department Name"<<endl;
	cout<<"[2]Record Code"<<endl;
	cout<<"[3]Location"<<endl;
	cin>>subchoice1;
	if(cin.fail()){
		cin.clear();
		cin.ignore();
		return;
	}
	fflush(stdin);
	if(subchoice1=='1'){
		cout<<"Enter Department Name: ";
		getline(cin,toBeSearch);
		searchDepCrit(toBeSearch,0);
	}
	else if(subchoice1=='2'){
		cout<<"Enter Record Code: ";
		getline(cin,toBeSearch);
		searchDepCrit(toBeSearch,1);
	}
	else if(subchoice1=='3'){
		cout<<"Enter Location: ";
		getline(cin,toBeSearch);
		searchDepCrit(toBeSearch,2);
	}
	else;
	return;
}


void operate::searchDepCrit(string tobeS,int lvl){
	string finaltobeS=" ";
	finaltobeS+=tobeS;
	
	string* addPtr;
	string tobeComp;
	department* temp1=depHEAD;
	int length=finaltobeS.length();
	int i=0;
	int count;
	cout<<"Found Results: "<<endl<<endl<<endl;
	
	if(lvl==0){
		count=0;
		while(temp1!=NULL){
			i=0;
			char compName[20]={0};
			addPtr=(temp1->getorSetDeptName());
			tobeComp=(*addPtr);
			while(i<length){
				compName[i]=tobeComp[i];
				i++;
			}
			
			if( To_lower(finaltobeS)==To_lower(compName)){
				cout<<"Result #"<<count+1<<endl;
				cout<<"Department Name:"<<(*temp1->getorSetDeptName())<<endl;
				cout<<"Location:"<<(*temp1->getorSetlocation())<<endl;
				cout<<"Record Code:"<<(*temp1->getorSetCode())<<endl<<endl;
				count++;
			}
			temp1=temp1->next;
		}
	}
	else if(lvl==1){
		count=0;
		while(temp1!=NULL){
			i=0;
			char compName[20]={0};
			addPtr=(temp1->getorSetCode());
			tobeComp=(*addPtr);
			while(i<length){
				compName[i]=tobeComp[i];
				i++;
			}
			
			if( To_lower(finaltobeS)==To_lower(compName)){
				cout<<"Result #"<<count+1<<endl;
				cout<<"Department Name:"<<(*temp1->getorSetDeptName())<<endl;
				cout<<"Location:"<<(*temp1->getorSetlocation())<<endl;
				cout<<"Record Code:"<<(*temp1->getorSetCode())<<endl<<endl;
				count++;
			}
			temp1=temp1->next;
		}
	}
	else if(lvl==2){
		count=0;
		while(temp1!=NULL){
			i=0;
			char compName[20]={0};
			addPtr=(temp1->getorSetlocation());
			tobeComp=(*addPtr);
			while(i<length){
				compName[i]=tobeComp[i];
				i++;
			}
			
			if( To_lower(finaltobeS)==To_lower(compName)){
				cout<<"Result #"<<count+1<<endl;
				cout<<"Department Name:"<<(*temp1->getorSetDeptName())<<endl;
				cout<<"Location:"<<(*temp1->getorSetlocation())<<endl;
				cout<<"Record Code:"<<(*temp1->getorSetCode())<<endl<<endl;
				count++;
			}
			temp1=temp1->next;
		}
	}
	
}


void operate::searchJob(){
	string toBesearch;
	char subchoice1;
	fflush(stdin);
	cout<<"******************SEARCH JOB POSITION***************"<<endl<<endl;
	cout<<"Please choose a criteria to search"<<endl;
	cout<<"[1]Name"<<endl;
	cout<<"[2]Order"<<endl;
	cout<<"[3]Code"<<endl;
	cin>>subchoice1;
	if(cin.fail()){
		return;
	}
	fflush(stdin);
	if(subchoice1=='1'){
		cout<<"Enter Job Position: ";
		getline(cin,toBesearch);
		searchDepCrit(toBesearch,0);
	}
	else if(subchoice1=='2'){
		cout<<"Enter Job Order #: ";
		getline(cin,toBesearch);
		searchDepCrit(toBesearch,1);
	}
	else if(subchoice1=='3'){
		cout<<"Enter Job Code: ";
		getline(cin,toBesearch);
		searchDepCrit(toBesearch,2);
	}
	else;
	return;
	
}

void operate::searchJobCrit(string tobesearch,int lvl){
	string final=" ";
	final+=tobesearch;
	string* addPtr;
	string tobeComp;
	jobPosition* temp1=jobPosHEAD;
	int length=final.length();
	int i=0;
	int count=0;
	cout<<"Found Results: "<<endl<<endl;
	if(lvl==0){
		count=0;
		while(temp1!=NULL){
			char compName[20]={0};
			addPtr=temp1->getorSetPosition();
			tobeComp=(*addPtr);
			while(i<length){
				compName[i]=tobeComp[i];
				i++;
			}
			if(To_lower(compName)==To_lower(final)){
				cout<<"Result #"<<count+1<<":"<<endl;
				cout<<"Job Position:"<<(*temp1->getorSetPosition())<<endl;
				cout<<"Job Order Number:"<<(*temp1->getorSetorderNum())<<endl;
				cout<<"Job Department:"<<(*temp1->getorSetDepartM())<<endl;
				cout<<"Job Location:"<<(*temp1->getorSetlocation())<<endl;
				count++;
			}
			temp1=temp1->next;
		}
	}
	else if(lvl==1){
		count=0;
		while(temp1!=NULL){
			char compName[20]={0};
			addPtr=temp1->getorSetorderNum();
			tobeComp=(*addPtr);
			while(i<length){
				compName[i]=tobeComp[i];
				i++;
			}
			if(To_lower(compName)==To_lower(final)){
				cout<<"Result #"<<count+1<<":"<<endl;
				cout<<"Job Position:"<<(*temp1->getorSetPosition())<<endl;
				cout<<"Job Order Number:"<<(*temp1->getorSetorderNum())<<endl;
				cout<<"Job Department:"<<(*temp1->getorSetDepartM())<<endl;
				cout<<"Job Location:"<<(*temp1->getorSetlocation())<<endl;
				count++;
			}
			temp1=temp1->next;
		}
	}
	else if(lvl==2){
		count=0;
		while(temp1!=NULL){
			char compName[20]={0};
			addPtr=temp1->getorSetCode();
			tobeComp=(*addPtr);
			while(i<length){
				compName[i]=tobeComp[i];
				i++;
			}
			if(To_lower(compName)==To_lower(final)){
				cout<<"Result #"<<count+1<<":"<<endl;
				cout<<"Job Position:"<<(*temp1->getorSetPosition())<<endl;
				cout<<"Job Order Number:"<<(*temp1->getorSetorderNum())<<endl;
				cout<<"Job Department:"<<(*temp1->getorSetDepartM())<<endl;
				cout<<"Job Location:"<<(*temp1->getorSetlocation())<<endl;
				count++;
			}
			temp1=temp1->next;
		}
	}
	return;
	
}

bool operate::updateorDelEmployee(){
	char subchoice1;
	char subchoice2;
	int eq;
	viewEmployee();
	fflush(stdin);
	cout<<"Please choose an action: "<<endl;
	cout<<"[1]Update "<<endl;
	cout<<"[2]Delete "<<endl;
	cout<<"[3]Logout "<<endl; 
	cin>>subchoice1;
	if(cin.fail())return false;
	cout<<endl<<endl;
	if(subchoice1=='3')return false;
	fflush(stdin);
	cout<<"Select a corresponding number: ";
	cin>>subchoice2;
	if(cin.fail())return false;
	eq=(int)subchoice2-'0';
	if(subchoice1=='1'){
		fflush(stdin);
		updateonlyEmployee(returnforDelorUp(eq));
		return true;
	}
	else if(subchoice1=='2'){
		system("cls");
		cout<<"*************DELETE************"<<endl<<endl;
		fflush(stdin);
		cout<<"Confirm Delete? (y/n)";
		cin>>subchoice2;
		subchoice2=tolower(subchoice2);
		if(subchoice2=='y'){
			removeOneEmployee(returnforDelorUp(eq));
			return true;
		}
		else return false;
	}
	return false;
}

void operate::updateonlyEmployee(employee* temp1){
	char subchoice1;
	fflush(stdin);
	string line;
	string final=" ";
	system("cls");
	cout<<"*************UPDATE************"<<endl<<endl;
	cout<<"Please select the data you wish to update/edit: "<<endl;
	cout<<"[1]ID Number"<<endl;
	cout<<"[2]Name"<<endl;
	cout<<"[3]Address"<<endl;
	cout<<"[4]Contact Number"<<endl;
	cout<<"[5]Age"<<endl;
	cout<<"[6]E-mail Address"<<endl;
	cout<<"[7]Birthday"<<endl;
	cout<<"[8]Sex"<<endl;
	cout<<"[9]Father's Name"<<endl;
	cout<<"[A]Father's Occupation"<<endl;
	cout<<"[B]Mother's Name"<<endl;
	cout<<"[C]Mother's Occupation"<<endl;
	cout<<"[D]Marital Status"<<endl;
	cout<<"[E]Employee Status"<<endl;
	cout<<"[X]Logout"<<endl<<endl;
	cin>>subchoice1;
	if(cin.fail())return;
	subchoice1=tolower(subchoice1);
	fflush(stdin);
	if(subchoice1=='1'){
		cout<<"Enter new ID Number: ";
		getline(cin,line);
		final+=line;
		(*temp1->getorSetIDnum())=final;
	}
	else if(subchoice1=='2'){
		cout<<"Enter new Name: ";
		getline(cin,line);
		final+=line;
		(*temp1->getorSetName())=final;
	}
	else if(subchoice1=='3'){
		cout<<"Enter new Address: ";
		getline(cin,line);
		final+=line;
		(*temp1->getorSetAdd())=final;
	}
	else if(subchoice1=='4'){
		cout<<"Enter new Contact Number: ";
		getline(cin,line);
		final+=line;
		(*temp1->getorSetContNum())=final;
	}
	else if(subchoice1=='5'){
		cout<<"Enter new Age: ";
		getline(cin,line);
		final+=line;
		(*temp1->getorSetAge())=final;
	}
	else if(subchoice1=='6'){
		cout<<"Enter new E-mail: ";
		getline(cin,line);
		final+=line;
		(*temp1->getorSetEadd())=final;
	}
	else if(subchoice1=='7'){
		cout<<"Enter new Birthday: ";
		getline(cin,line);
		final+=line;
		(*temp1->getorSetbDate())=final;
	}
	else if(subchoice1=='8'){
		cout<<"Enter new Sex: ";
		getline(cin,line);
		final+=line;
		(*temp1->getorSetSex())=final;
	}
	else if(subchoice1=='9'){
		cout<<"Enter new Father's Name: ";
		getline(cin,line);
		final+=line;
		(*temp1->getorSetFname())=final;
	}
	else if(subchoice1=='a'){
		cout<<"Enter new Father's Occupation: ";
		getline(cin,line);
		final+=line;
		(*temp1->getorSetOccuF())=final;
	}
	else if(subchoice1=='b'){
		cout<<"Enter new Mother's Name: ";
		getline(cin,line);
		final+=line;
		(*temp1->getorSetMname())=final;
	}
	else if(subchoice1=='c'){
		cout<<"Enter new Mother's Occupation: ";
		getline(cin,line);
		final+=line;
		(*temp1->getorSetOccuM())=final;
	}
	else if(subchoice1=='d'){
		cout<<"Enter new Marital Status: ";
		getline(cin,line);
		final+=line;
		(*temp1->getorSetMStat())=final;
	}
	else if(subchoice1=='e'){
		cout<<"Update Employee Status: "<<endl;
		getline(cin,line);
		final+=line;
		(*temp1->getorSetEmpStat())=final;
	}
	else if(subchoice1='x')return;
	fflush(stdin);
	cout<<endl<<endl<<"Update another info? (y/n)";
	cin>>subchoice1;
	subchoice1=tolower(subchoice1);
	if(subchoice1=='y'){
		updateonlyEmployee(temp1);
	}
	else return;
}


employee* operate::returnforDelorUp(int n){
	employee* temp1;
	int i=0;
	while(temp1!=NULL){
		if(i==n)return temp1;
		if(i==0)temp1=emploHEAD;
		else temp1=temp1->next;
		i++;
	}
}

void operate::removeOneEmployee(employee* temp1){
	employee* temp2=emploHEAD;
	employee* temp3;
	while(temp2!=NULL){
		if(temp2==temp1){
			if(temp2==emploHEAD && emploHEAD->next!=NULL){
				temp3=temp2->next;
				temp3->prev=NULL;
				emploHEAD=temp3;
				free(temp2);
			}
			else if(temp2==emploHEAD && emploHEAD->next==NULL){
				free(temp2);
				emploHEAD=NULL;
			}
			else if(temp2!=emploHEAD && temp2->next==NULL){
				temp3=temp2->prev;
				temp3->next=NULL;
				free(temp2);
			}
			else if(temp2!=emploHEAD && temp2->next!=NULL){
				temp3=temp2->prev;
				temp3->next=temp2->next;
				free(temp2);
			}
			employeeCount-=1;
			return;
		}
		temp2=temp2->next;
	}
	system("pause");
}

department* operate::returnforDelorupDep(int n){
	department* temp1;
	for(int i=0;i<n;i++){
		if(i==0)temp1=depHEAD;
		else temp1=temp1->next;
	}
	return temp1;
}

bool operate::updateorDelDepartment(){
	char subchoice1;
	char subchoice2;
	int eq;
	viewDept();
	fflush(stdin);
	cout<<endl<<"Please choose an action: "<<endl;
	cout<<"[1]Update"<<endl;
	cout<<"[2]Delete"<<endl;
	cout<<"[3]Logout"<<endl;
	cin>>subchoice1;
	if(cin.fail())return false;
	cout<<endl<<endl;
	if(subchoice1=='3')return false;
	fflush(stdin);
	cout<<"Select a corresponding number: ";
	cin>>subchoice2;
	if(cin.fail())return false;
	eq=(int)subchoice2-'0';
	if(subchoice1=='1'){
		fflush(stdin);
		updateonlyDepartment(returnforDelorupDep(eq));
		return true;
	}
	else if(subchoice1=='2'){
		system("cls");
		cout<<"*************DELETE************"<<endl<<endl;
		fflush(stdin);
		cout<<"Confirm Delete? (y/n) ";
		cin>>subchoice2;
		subchoice2=tolower(subchoice2);
		if(subchoice2=='y'){
			removeOneDept(returnforDelorupDep(eq));
			return true;
		}
		else return false;
	}
	else return false;
}

void operate::updateonlyDepartment(department* temp1){
	char subchoice1;
	fflush(stdin);
	string line;
	string final=" ";
	system("cls");
	cout<<"*************UPDATE************"<<endl<<endl;
	cout<<"Please select the data you wish to update/edit: "<<endl;
	cout<<"[1]Department Name"<<endl;
	cout<<"[2]Location"<<endl;
	cout<<"[3]Record Code"<<endl;
	cout<<"[X]Logout"<<endl<<endl;
	cin>>subchoice1;
	if(cin.fail())return;
	subchoice1=tolower(subchoice1);
	fflush(stdin);
	if(subchoice1=='1'){
		cout<<"Enter new Department Name: "<<endl;
		getline(cin,line);
		final+=line;
		(*temp1->getorSetDeptName())=final;
		
	}
	else if(subchoice1=='2'){
		cout<<"Enter new Department Location: "<<endl;
		getline(cin,line);
		final+=line;
		(*temp1->getorSetlocation())=final;
	}
	else if(subchoice1=='3'){
		cout<<"Enter new Record Code: "<<endl;
		getline(cin,line);
		final+=line;
		(*temp1->getorSetCode())=final;
	}
	else if(subchoice1='x')return;
	fflush(stdin);
	cout<<endl<<endl<<"Update another info? (y/n)";
	cin>>subchoice1;
	subchoice1=tolower(subchoice1);
	if(subchoice1=='y'){
		updateonlyDepartment(temp1);
	}
	else return;
	
}

void operate::removeOneDept(department* temp1){
	department* temp2=depHEAD;
	department* temp3;
	while(temp2!=NULL){
		if(temp2==temp1){
			if(temp2==depHEAD && depHEAD->next!=NULL){
				temp3=temp2->next;
				temp3->prev=NULL;
				depHEAD=temp3;
				free(temp2);
			}
			else if(temp2==depHEAD && depHEAD->next==NULL){
				free(temp2);
				depHEAD=NULL;
			}
			else if(temp2!=depHEAD && temp2->next==NULL){
				temp3=temp2->prev;
				temp3->next=NULL;
				free(temp2);
			}
			else if(temp2!=depHEAD && temp2->next!=NULL){
				temp3=temp2->prev;
				temp3->next=temp2->next;
				free(temp2);
			}
			departmentCount-=1;
			return;
		}
		temp2=temp2->next;
	}
}


void operate::viewJob(){
	int count=0;
	cout<<"***************JOB LISTS AVAILABLE**************"<<endl<<endl;
	jobPosition* temp1=jobPosHEAD;
	while(temp1!=NULL){
		cout<<"["<<count+1<<"]"<<endl;
		cout<<"Job Position:"<<(*temp1->getorSetPosition())<<endl;
		cout<<"Job Order Number:"<<(*temp1->getorSetorderNum())<<endl;
		cout<<"Corresponding Department:"<<(*temp1->getorSetDepartM())<<endl;
		cout<<"Corresponding Location:"<<(*temp1->getorSetlocation())<<endl;
		cout<<"Code:"<<(*temp1->getorSetCode())<<endl<<endl;
		temp1=temp1->next;
		count++;
	}
	cout<<endl;
}

jobPosition* operate::returnforDelorupJob(int n){
	jobPosition* temp1;
	for(int i=0;i<n;i++){
		if(i==0)temp1=jobPosHEAD;
		else temp1=temp1->next;
	}
	return temp1;
}

bool operate::updateorDelJob(){
	char subchoice1;
	char subchoice2;
	int eq;
	viewJob();
	fflush(stdin);
	cout<<endl<<"Please choose an action: "<<endl;
	cout<<"[1]Update"<<endl;
	cout<<"[2]Delete"<<endl;
	cout<<"[3]Logout"<<endl;
	cin>>subchoice1;
	if(cin.fail())return false;
	cout<<endl<<endl;
	if(subchoice1=='3')return false;
	fflush(stdin);
	cout<<"Select a corresponding number: ";
	cin>>subchoice2;
	if(cin.fail())return false;
	eq=(int)subchoice2-'0';
	if(subchoice1=='1'){
		fflush(stdin);
		updateonlyJobPos(returnforDelorupJob(eq));
		return true;
	}
	else if(subchoice1=='2'){
		system("cls");
		cout<<"*************DELETE************"<<endl<<endl;
		fflush(stdin);
		cout<<"Confirm Delete? (y/n) ";
		cin>>subchoice2;
		subchoice2=tolower(subchoice2);
		if(subchoice2=='y'){
			removeOneJob(returnforDelorupJob(eq));
		}
		else return false;
	}
	else return false;
}

void operate::updateonlyJobPos(jobPosition* temp1){
	char subchoice1;
	fflush(stdin);
	string line;
	string line1;
	string final1=" ";
	string final=" ";
	system("cls");
	cout<<"*************UPDATE************"<<endl<<endl;
	cout<<"Please select the data you wish to update/edit: "<<endl;
	cout<<"[1]Job Position Name"<<endl;
	cout<<"[2]Department and Location"<<endl;
	cout<<"[3]Record Code"<<endl;
	cout<<"[X]Logout"<<endl<<endl;
	cin>>subchoice1;
	if(cin.fail())return;
	subchoice1=tolower(subchoice1);
	fflush(stdin);
	if(subchoice1=='1'){
		cout<<"Enter new Name: ";
		getline(cin,line);
		final+=line;
		(*temp1->getorSetPosition())=final;
	}
	else if(subchoice1=='2'){
		cout<<"Enter new Department: ";
		getline(cin,line);
		final+=line;
		cout<<"Enter corresponding Location: ";
		getline(cin,line1);
		final1+=line1;
		if(searchDept(To_lower(line),To_lower(line1))==NULL){
			cout<<endl<<"Please redirect to an existing department and location! "<<endl;
		}
		else{
			(*temp1->getorSetDepartM())=final;
			(*temp1->getorSetlocation())=final1;
		}
	}
	else if(subchoice1=='3'){
		cout<<"Enter new Record Code: ";
		getline(cin,line);
		final+=line;
		(*temp1->getorSetCode())=final;
	}
	else if(subchoice1=='x')return;
	fflush(stdin);
	cout<<endl<<endl<<"Update another info? (y/n)";
	cin>>subchoice1;
	subchoice1=tolower(subchoice1);
	if(subchoice1=='y'){
		updateonlyJobPos(temp1);
	}
	else return;
}

void operate::removeOneJob(jobPosition* temp1){
	jobPosition* temp2=jobPosHEAD;
	jobPosition* temp3;
	while(temp2!=NULL){
		if(temp2==temp1){
			if(temp2==jobPosHEAD && jobPosHEAD->next!=NULL){
				temp3=temp2->next;
				temp3->prev=NULL;
				jobPosHEAD=temp3;
				free(temp2);
			}
			else if(temp2==jobPosHEAD && jobPosHEAD->next==NULL){
				free(temp2);
				jobPosHEAD=NULL;
			}
			else if(temp2!=jobPosHEAD && temp2->next==NULL){
				temp3=temp2->prev;
				temp3->next=NULL;
				free(temp2);
			}
			else if(temp2!=jobPosHEAD && temp2->next!=NULL){
				temp3=temp2->prev;
				temp3->next=temp2->next;
				free(temp2);
			}
			jobCount-=1;
			return;
		}
		temp2=temp2->next;
	}
	
}



jobPosition* operate::checkforJobexist(string dept,string loc,string name){
	jobPosition* temp1=jobPosHEAD;
	while(temp1!=NULL){
		if( To_lower(*temp1->getorSetDepartM())==To_lower(" "+dept) && To_lower(*temp1->getorSetlocation())==To_lower(" "+loc) && To_lower(*temp1->getorSetPosition())==To_lower(" "+name)){
			return temp1;	
		}
		temp1=temp1->next;
	}
	return temp1;
}


void operate::assignApplicantTrans(){
	int count=0;
	int eq;
	char subchoice1;
	char subchoice2;
	employee* temp1=emploHEAD;
	employee* temp2;
	system("cls");
	cout<<"***************ASSIGN APPLICANTS INTERVIEW*************"<<endl<<endl;
	cout<<"List of Applicants available: "<<endl;
	while(temp1!=NULL){
		if( To_lower(*temp1->getorSetEmpStat())==" applicant"){
			cout<<"["<<count+1<<"]"<<endl;
			cout<<"Employee Name:"<<(*temp1->getorSetName())<<endl;
			cout<<"ID Number:"<<(*temp1->getorSetIDnum())<<endl;
			cout<<"Department:"<<(*temp1->getorSetDept())<<endl;
			cout<<"Job Position:"<<(*temp1->getorSetJobP())<<endl<<endl;
		}
		temp1=temp1->next;
		count++;
	}
	fflush(stdin);
	cout<<endl;
	cout<<"Please select an applicant to assign for interview: ";
	cin>>subchoice1;
	if(cin.fail())return;
	eq=subchoice1-'0';	
	temp2=returnforDelorUp(eq);
	cout<<endl;
	cout<<"Confirm? (y/n)"<<endl;
	cin>>subchoice2;
	if(subchoice2=='y'){
		(*temp2->getorSetEmpStat())=" Interview";
		cout<<"SUCCESSFULLY MADE CHANGES! "<<endl;
		return;	
	}
	else return;
	
}


void operate::approveInterview(){
	int count=0;
	int eq;
	char subchoice1;
	char subchoice2;
	employee* temp1=emploHEAD;
	employee* temp2;
	system("cls");
	cout<<"***************HIRE APPLICANTS*************"<<endl<<endl;
	cout<<"List of Applicants available: "<<endl;
	while(temp1!=NULL){
		if( To_lower(*temp1->getorSetEmpStat())==" interview"){
			cout<<"["<<count+1<<"]"<<endl;
			cout<<"Employee Name:"<<(*temp1->getorSetName())<<endl;
			cout<<"ID Number:"<<(*temp1->getorSetIDnum())<<endl;
			cout<<"Department:"<<(*temp1->getorSetDept())<<endl;
			cout<<"Job Position:"<<(*temp1->getorSetJobP())<<endl<<endl;
		}
		temp1=temp1->next;
		count++;
	}
	fflush(stdin);
	cout<<endl;
	cout<<"Please select an applicant to hire: ";
	cin>>subchoice1;
	if(cin.fail())return;
	eq=subchoice1-'0';	
	temp2=returnforDelorUp(eq);
	cout<<endl;
	cout<<"Confirm? (y/n)"<<endl;
	cin>>subchoice2;
	if(subchoice2=='y'){
		(*temp2->getorSetEmpStat())=" probation";
		cout<<"SUCCESSFULLY MADE CHANGES! "<<endl;
		return;	
	}
	else return;
}

void operate::calculateSalary(){
	int count=0;
	int eq;
	char subchoice1;
	char subchoice2;
	employee* temp2;
	employee* temp1=emploHEAD;
	string line;
	string final=" ";
	string final1=" ";
	string line1;
	float baspay;
	float hourrate;
	cout<<"***************CALCULATE SALARY*************"<<endl<<endl;
	cout<<"List of Employee available: "<<endl;
	while(temp1!=NULL){
		if( To_lower(*temp1->getorSetEmpStat())==" probation" || To_lower(*temp1->getorSetEmpStat())==" regular"){
			cout<<"["<<count+1<<"]"<<endl;
			cout<<"Employee Information: "<<endl;
			cout<<"Employee Name:"<<(*temp1->getorSetName())<<endl;
			cout<<"ID Number:"<<(*temp1->getorSetIDnum())<<endl;
			cout<<"Job Position:"<<(*temp1->getorSetJobP())<<endl;
			cout<<"Department:"<<(*temp1->getorSetDept())<<endl;
			cout<<"E-mail Address:"<<(*temp1->getorSetEadd())<<endl;
			cout<<"Payroll Information: "<<endl;
			cout<<"Basic Pay:"<<(*temp1->getorSetBasPay())<<endl;
			cout<<"Rate Per Hour:"<<(*temp1->getorSetRPhour())<<endl;
			cout<<"Deductions:"<<(*temp1->getorSettotalDed())<<endl;
			cout<<endl<<endl;
		}
		temp1=temp1->next;
	}
	fflush(stdin);
	cout<<"Please Select an employee you wish to edit his/her basic pay: ";
	cin>>subchoice1;
	if(cin.fail()){
		cout<<"FAILED! "<<endl;
		return;
	}
	else{
		eq=subchoice1-'0';
		temp2=returnforDelorUp(eq);
		fflush(stdin);
		cout<<endl<<"Basic Pay: ";
		getline(cin,line);
		baspay=atof(line.c_str());
		hourrate=(baspay*(0.00568181818181810));
		cout<<"Confirm? (y/n) ";
		fflush(stdin);
		cin>>subchoice2;
		if(subchoice2=='y'){
			final+=line;
			(*temp2->getorSetBasPay())=final;
			ostringstream ss;
			ss<<hourrate;
			line1=(ss.str());
			final1+=line1;
			(*temp2->getorSetRPhour())=final1;
			cout<<"SUCCESSFULLY MADE CHANGES!"<<endl;
			return;
		}
		else{
			cout<<"CANCELLED! "<<endl;
		}
	}
}

void operate::createTimeReport(){
	int count=0;
	int eq;
	char subchoice1;
	string workH;
	cout<<"*****************CREATE TIME REPORT****************"<<endl<<endl<<endl;
	employee* temp1=emploHEAD;
	employee* temp2;
	string initialWorkH;
	string totalWorkH;
	string final=" ";
	float total;
	cout<<"Available employees: "<<endl;
	while(temp1!=NULL){
		if( To_lower((*temp1->getorSetEmpStat()))==" probation" ||  To_lower((*temp1->getorSetEmpStat()))==" regular" ){
			cout<<"["<<count+1<<"]"<<endl;
			cout<<"Employee Name:"<<(*temp1->getorSetName())<<endl;
			cout<<"ID Number:"<<(*temp1->getorSetIDnum())<<endl;
			cout<<"E-mail Address:"<<(*temp1->getorSetEadd())<<endl;
			cout<<"Job Position:"<<(*temp1->getorSetJobP())<<endl;
			cout<<"Department:"<<(*temp1->getorSetDept())<<endl;
			cout<<"Location:"<<(*temp1->getorsetLoc())<<endl;
			cout<<"Employee Status:"<<(*temp1->getorSetEmpStat())<<endl<<endl;
		}
		temp1=temp1->next;	
	}
	fflush(stdin);
	cout<<"Please select an employee to submit time report: ";
	cin>>subchoice1;
	if(cin.fail()){
		cout<<"FAILED! "<<endl;
		return;
	}
	else{
		eq=subchoice1-'0';
		temp2=returnforDelorUp(eq);
		fflush(stdin);
		cout<<"Enter Total Work Hours: ";
		getline(cin,workH);
		fflush(stdin);
		cout<<endl<<"Confirm? (y/n) ";
		cin>>subchoice1;
		if(cin.fail())return;
		subchoice1=tolower(subchoice1);
		if(subchoice1!='y')return;
		initialWorkH=convertF((*temp2->getorSetTotWorkH()));
		total=atof(workH.c_str())+atof(initialWorkH.c_str());
		ostringstream ss;
		ss<<total;
		totalWorkH= (ss.str());
		final+=totalWorkH;
		(*temp2->getorSetTotWorkH())=final;
		
		ofstream file("time_report/reports.txt",ios::app);
		if(file.is_open()){
			if(timeRepCount>0)file<<endl;
			file<<"Employee Name:"<<(*temp2->getorSetName())<<endl;
			file<<"Report Status: for approval"<<endl;
			file<<"Total Hours Work: "<<workH<<endl;
			file<<"Reason (if disapproved): not edited"<<endl;
			file<<"================================================~";
			file.close();
			cout<<"SUCCESSFULLY CREATED TIME REPORT! "<<endl;
			return; 
		}
		else{
			cout<<"AN ERROR HAS OCCURED!"<<endl;
			return;
		}
	}
	
}

string operate::convertF(string temp1){
	char temp2[20]={0};
	for(int loop=0;loop<temp1.length();loop++){
		temp2[loop]=temp1[loop+1];
	}
	return temp2;
}
void operate::removeAllTimeReport(){
	time_report* temp1=timerepHEAD;
	time_report* temp2;
	while(temp2!=NULL){
		temp2=temp1->next;
		free(temp1);
		temp1=temp2;
	}
	timerepHEAD=NULL;
}
void operate::setTimeRepHEAD(time_report* temp){
	timerepHEAD=temp;
}

void operate::generateLLTimeRep(){
	int i=0;
	string line;
	timeRepCount=0;
	string* temporary1;
	string tempo1;
	ifstream file("time_report/reports.txt");
	if(file.is_open()){
		while(file.good()){
			i=0;
			time_report* temp1=new time_report();
			while(file.good()){
				fflush(stdin);
				if(file.good()==false)return;
				if(getline(file,line));
				else return;
				if(i==0){
					temporary1=temp1->getorSetEmpName();
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==1){
					temporary1=temp1->getorSetStatus();
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==2){
					temporary1=temp1->getorSetTotalWh();
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i==3){
					temporary1=temp1->getorSetReas();
					tempo1=filt(line);
					(*temporary1)=tempo1;
				}
				else if(i>3)break;
				i++;
			}
			temp1->prev=NULL;
			if(timerepHEAD!=NULL){
				timerepHEAD->prev=temp1;
			}
			temp1->next=timerepHEAD;
			timerepHEAD=temp1;
			timeRepCount+=1;
		}
		file.close();
	}
	else{
		cout<<"AN ERROR HAS OCCURED! "<<endl<<endl;
	}
	
}

void operate::refreshTimeRep(){
	int i=0;
	int count=0;
	time_report* temp1=timerepHEAD;
	ofstream file("time_report/reports.txt");
	if(file.is_open()){
		while(temp1!=NULL){
			i=0;
			while(i<=4){
				if(count==0 && i==0){
					file<<"Employee Name:"<<(*temp1->getorSetEmpName())<<endl;
				}
				if(i==0 && count>0){
					file<<endl<<"Employee Name:"<<(*temp1->getorSetEmpName())<<endl;
				}
				else if(i==1){
					file<<"Report Status:"<<(*temp1->getorSetStatus())<<endl;
				}
				else if(i==2){
					file<<"Total Work Hours:"<<(*temp1->getorSetTotalWh())<<endl;
				}
				else if(i==3){
					file<<"Reason (if disapproved):"<<(*temp1->getorSetReas())<<endl;
				}
				else if(i==4){
					file<<"================================================~";
				}
				else if(i>4)break;
				i++;
			}
			count++;
			temp1=temp1->next;
		}
		file.close();
	}
	else{
		cout<<"AN ERROR HAS OCCURED! "<<endl<<endl;
	}
}

