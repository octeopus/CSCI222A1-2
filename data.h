#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

struct Date{
	int day; 
	int month; 
	int year;
};

struct Time{
	//we're going 2359 on this shit 
	int 
};

class Member {
	private: 
	string memberID;
	string memberName;
	string memberPassword;
	string memberAddress;
	string memberPhone;
	char memberGender;
	//vector<booking> bookingHistory;
	public:
		Member(string, string, string, char); //memberName, memberAddress, memberPhone, memberGender
		//accessors
		string getMemID();
		string getMemName();
		string getMemPassword();
		string getMemAddress();
		string getMemPhone(); 
		char getMemGender();
		//booking getBookingInfo(bookingID);
		
		//mutators
		void setMemID(string);
		void setMemName(string);
		void setMemPassword(string);
		void setMemAddress(string);
		void setMemPhone(string); 
		char setMemGender(char);
		//void setBookingInfo(booking oldBook, booking newBook);
		
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
		//vector<booking> bookingHistory
	public: 
		
	
};

class Booking{
	private:
		string memberID; 
		string facilityID; 
		string bookingID; 
		
};


