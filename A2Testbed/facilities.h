#ifndef FACILITIES_H
#define FACILITIES_H

#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>

#define FAC_FILE_NAME "facilities.txt"

using namespace std;

struct Date{
	int day;
	int month;
	int year;
};

struct Time{
	int hour;
	int minute;
};



class Booking{
private:
	string memberID;
	string facilityID;
	string bookingID;
	Date startDate;
	Date endDate;
	Time startTime;
	Time endTime;
	int bookingStatus;

public:
	Booking();
	Booking(string BMID, string BFID, string BBID, Date sDate, Date eDate, Time sTime, Time eTime, int bStat);
	//accessor
	string getBMID()const{ return memberID; };
	string getBFID()const{ return facilityID; };
	string getBBID()const{ return bookingID; };
	Date getsDate()const{ return startDate; };
	Date geteDate()const{ return endDate; };
	Time getsTime()const{ return startTime; };
	Time geteTime()const{ return endTime; };
	int getBookStat()const{ return bookingStatus; };

	//mutator

	void setBMID(string a){ memberID = a; };
	void setBFID(string a){ facilityID = a; };
	void setBBID(string a){ bookingID = a; };
	void setsDate(Date a){
		startDate.day = a.day;
		startDate.month = a.month;
		startDate.year = a.year;
	}
	void seteDate(Date a){
		endDate.day = a.day;
		endDate.month = a.month;
		endDate.year = a.year;
	}
	void setsTime(Time a){
		startTime.hour = a.hour;
		startTime.minute = a.minute;
	}
	void seteTime(Time a){
		endTime.hour = a.hour;
		endTime.minute = a.minute;
	}
	void setBookStat(int a){ bookingStatus = a; };

	//Booking(string memberID, string facilityID, date startDate, date endDate, time startTime, time endTime, int bookingStatus);

};


class Facilities{
	
	
	//Marcus - NOTE: consider adding accessor and mutator functions to access the variables
	private:
		string facilityID;
		string facilityName;
		string facilityLocation; 
		int facilityStatus; 
		string facilityPhone;
		string facilityType; 
		
	public: 
		Facilities();
		Facilities(string, string, string, string); //name, location, phone, type
		Facilities(string, string, string, int, string, string); 
		
		
		string getFacilityID() const{return this->facilityID;};
		string getFacilityName()const{return this->facilityName;};
		string getFacilityLocation()const{return this->facilityLocation;};
		int getFacilityStatus()const{return this->facilityStatus;};
		string getFacilityPhone()const{return this->facilityPhone;};
		string getFacilityType()const{return this->facilityType;};
		Booking getBookingInfo(string bookingID);
		
		void setFacID(string a){this->facilityID = a;};
		void setFacName(string a){this->facilityName = a;};
		void setFacLocation(string a){this->facilityLocation = a;};
		void setFacStatus(int a){this->facilityStatus = a;};
		void setFacPhone(string a){this->facilityPhone = a;};
		void setFacType(string a){this->facilityType = a;};
		
		//debug
		void toString();
		
		vector<Booking> bookingHistory;
		
};

struct FacBin{
	int index;
	vector<Facilities> f;
};

class FacSys{ //class of Facility Subsystem. This class manages the main program.
	public:
	FacSys(); 
	void FacSubMenu(); //done
	void addFacility(); //done
	void readFile(fstream&, FacBin& fb);
	void writeFile(fstream&, const FacBin fb);
	
	void editFacility(); //TODO
	
	//debug
	void checkStruct();
	
	
	FacBin data;
};

string IDToString(int);

#endif
