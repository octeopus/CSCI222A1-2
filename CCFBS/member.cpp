#include "member.h"



string MIDToString(int value){
	//use this to generate the FacilityID eg 'M0001'
	ostringstream os; 
	os << "M" << setfill('0') << setw(4) << value;
	return os.str();
}

Member::Member()
{
	memberName = " ";
	memberAddress = " ";
	memberPhone = " ";
	memberGender = 'A';
}

Member::Member(string MID, string MName, string MPass, string MAdd, string MPhone, string MRank, char MGen, string MemUs){
	memberID = MID;
	memberName = MName;
	memberPassword = MPass;
	memberAddress = MAdd;
	memberPhone = MPhone;
	memberRank = MRank;
	memberGender = MGen;
	MEMUser = MemUs;
	
}

Member::Member(string MID, string MName, string MPass, string MAdd, string MPhone, char MGen, string MemUs){
	memberID = MID; 
	memberName = MName;
	memberPassword = MPass;
	memberAddress = MAdd;
	memberPhone = MPhone;
	memberRank = "Basic";
	memberGender = MGen;
	MEMUser = MemUs;
}

string Member::getMemID() const
{
	return memberID;
}

string Member::getMemName() const
{
	return memberName;
}

string Member::getMemPassword() const
{
	return memberPassword;
}

string Member::getMemAddress() const
{
	return memberAddress;
}

string Member::getMemPhone() const
{
	return memberPhone;
}

string Member::getMemRank() const
{
	return memberRank;
}

char Member::getMemGender() const
{
	return memberGender;
}

string Member::getMemUserName() const{
	return MEMUser;
}

/*Booking Member::getBookingInfo()
{
	return bookingID;
}*/

//==================================================================================================

void Member::setMemID(string newMeID)
{
	memberID = newMeID;
}

void Member::setMemName(string newMeName)
{
	memberName = newMeName;
}

void Member::setMemPassword(string newMePassword)
{
	memberPassword = newMePassword;
}

void Member::setMemAddress(string newMeAddress)
{
	memberAddress = newMeAddress;
}

void Member::setMemPhone(string newMePhone)
{
	memberPhone = newMePhone;
}

void Member::setMemRank(string newMeRank)
{
	memberRank = newMeRank;
}

void Member::setMemGender(char newMeGender)
{
	memberGender = newMeGender;
}


