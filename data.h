#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime> //use ctime to get time and date

using namespace std;

class Member {
	private: 
	string memberID;
	string memberName;
	string memberPassword;
	string memberAddress;
	string memberPhone;
	char memberGender;
	vector<Booking> bookingHistory;
	public:
		Member(string, string, string, char); //memberName, memberAddress, memberPhone, memberGender
		//accessors
		string getMemID();
		string getMemName();
		string getMemPassword();
		string getMemAddress();
		string getMemPhone(); 
		char getMemGender();
		Booking getBookingInfo(bookingID);
		
		//mutators
		void setMemID(string);
		void setMemName(string);
		void setMemPassword(string);
		void setMemAddress(string);
		void setMemPhone(string); 
		char setMemGender(char);
		void setBookingInfo(Booking oldBook, Booking newBook);
		
};

class Facilities{
	
	//NOTE: consider adding accessor and mutator functions to access the variables
	private:
		string facilityID;
		string facilityName;
		string facilityLocation; 
		int facilityStatus; 
		string facilityPhone;
		string facilityType; 
		vector<Booking> bookingHistory
	public: 
		
	
};

class Booking{
	private:
		string memberID; 
		string facilityID; 
		string bookingID; 
		//date startDate
		//date endDate
		//time startTime
		//time endTime 
		int bookingStatus;
		
	public: 
		Booking(string memberID, string facilityID, date startDate, date endDate, time startTime, time endTime, int bookingStatus);
		
};

class Manager{
	private:
		string managerID;
		string managerName;
		string managerPassword;
		string managerAddress; 
		string managerPhone; 
		
		//accessors
		string getMgrID();
		string getMgrName();
		string getMgrPassword();
		string getMgrAddress();
		string getMgrPhone();
		
};


