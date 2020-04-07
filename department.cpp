#include "department.h"

string* department::getorSetDeptName(){
	return &DeptName;
}
string* department::getorSetlocation(){
	return &location;
}
string* department::getorSetCode(){
	return &Code;
}
