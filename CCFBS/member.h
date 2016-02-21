#pragma once
#ifndef MEMBER_H
#define MEMBER_H

#ifndef FACILITIES_H
#include "facilities.h"
#endif
string MIDToString(int value);

class Member
{
	private: 
	   string memberID;
	   string memberName;
	   string memberPassword;
	   string memberAddress;
	   string memberPhone;
       string memberRank;
	   char memberGender;
       string MEMUser;
	   
        
    public:
		Member(); //memberName, memberAddress, memberPhone, memberGender
		Member(string MID, string MName, string MPass, string MAdd, string MPhone, string MRank, char MGen, string MemUs);
		Member(string MID, string MName, string MPass, string MAdd, string MPhone, char MGen, string MemUs); //for creating a new member
		
		//accessors
		string getMemID() const;
		string getMemName() const;
		string getMemPassword() const;
		string getMemAddress() const;
		string getMemPhone() const;
        string getMemRank() const;
		char getMemGender() const;
		string getMemUserName() const;
		//Booking getBookingInfo(bookingID);
		
		//mutators
		void setMemID(string);
		void setMemName(string);
		void setMemPassword(string);
		void setMemAddress(string);
		void setMemPhone(string);
        void setMemRank(string);
		void setMemGender(char);
		//void setBookingInfo(Booking oldBook, Booking newBook);
        vector<Booking> bookingHistory;
};

#endif

