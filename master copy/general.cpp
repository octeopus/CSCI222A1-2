#include "general.h"


string FIDToString(int value){
	//use this to generate the FacilityID eg 'F0001'
	ostringstream os;
	os << "F" << setfill('0') << setw(4) << value;
	return os.str();
}

string MIDToString(int value){
	//use this to generate the FacilityID eg 'M0001'
	ostringstream os;
	os << "M" << setfill('0') << setw(4) << value;
	return os.str();
}
