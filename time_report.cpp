#include "time_report.h"

string* time_report::getorSetReas(){
	return &Reason;
}
string* time_report::getorSetStatus(){
	return &Status;
}
string* time_report::getorSetTotalWh(){
	return &TotalWorkH;
}
string* time_report::getorSetEmpName(){
	return &employeeName;
}
