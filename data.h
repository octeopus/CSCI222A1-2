//<name> indicates who left the comment.
//Leon - This comemnt was left by me. Temporary measure until we get VCS done.
//17th Feb - File created.
//18th Feb - added Rank class, attention need on line 66, 74, 123, 124.

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime> //Marcus - use ctime to get time and date

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
        void setMemRank(string);
		char setMemGender(char);
		void setBookingInfo(Booking oldBook, Booking newBook);
		
};

class Facility{
	
	//Marcus - NOTE: consider adding accessor and mutator functions to access the variables
	private:
		string facilityID;
		string facilityName;
		string facilityLocation; 
		int facilityStatus; 
		string facilityPhone;
		string facilityType; 
		vector<Booking> bookingHistory
	public: 
		Facility(string, string, string, int, string, string); //id, name, location, status, phone, type
		
		string getFacilityID();
		string getFacilityName();
		string getFacilityLocation();
		int getFacilityStatus();
		string getFacilityPhone();
		string getFacilityType();
		Booking getBookingInfo(bookingID); //Leon - repeat?
		
		void setFacID(string);
		void setFacName(string);
		void setFacLocation(string);
		void setFacStatus(int);
		void setFacPhone(string);
		void setFacType(string);
		//Leon - do we need setBookingInfo()?
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
	
	public:
		//accessors
		string getMgrID();
		string getMgrName();
		string getMgrPassword();
		string getMgrAddress();
		string getMgrPhone();
		
		void setMgrPhone();
		void setMgrName();
		void setMgrPassword();
		void setMgrAddress();
		void setMgrPhone();
		
};

class Rank{
	private:
		string rankName;
		string rankID;
		float rankFee;
		int rankPriority;
		int rankPrivilege; //Leon - rankPrivilege == rankID? is this redundant? should we rename this to rankID?
		int rankDiscount; //Leon - returns discount based on rankID. etc if (rankID == 0) {discount = "25% off sponges";}
		
	public:
		string getRankName();
		string getRankID();
		float getRankFee();
		int getRankPriority();
		int getRankPrivilege();
		string getRankDiscount(); //Leon - Returns string as suggested by Marcus.
		
		/*Leon - example of how it might look.
		
			getRankDiscount() {
				
			string discount;
			
			value = this->rankDiscount
			
			switch(value)
			{
				case 1: 
					discount = "You get 25% off sponges. Lucky you!";
					break;
				case 2:
					discount = "You get 0.01% off parking! We're so generous.";
					break;
			}
			
			return discount;
		
			}
			
		*/
		
		void setRankName();
		void setRankID();
		void setRankFee();
		void setRankPriority();
		void setRankPrivilege();
		void setRankDiscount();
		
};


