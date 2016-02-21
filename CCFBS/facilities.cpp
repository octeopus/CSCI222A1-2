#include "facilities.h"

string IDToString(int value){
	//use this to generate the FacilityID eg 'F0001'
	ostringstream os; 
	os << "F" << setfill('0') << setw(4) << value;
	return os.str();
}


void checkFacFile(){
	fstream fs;
	
	fs.open(FAC_FILE_NAME);
	bool ifExists = false;
	
	//check if fs can reach the file
	if(fs.good()){
		
		ifExists = true;
	}
	fs.close();
	//then if the file does not exist, create a new file and write a blank FacBin into it.
	if(ifExists == false){
		cout << FAC_FILE_NAME << " does not exist! Creating new " << FAC_FILE_NAME << "...\n\n";
		
		FacBin f; 
		f.index = 0; 
		fs.open(FAC_FILE_NAME, ios::out | ios::binary);
		fs.write(reinterpret_cast<char*>(&f), sizeof(f));
		fs.close();
	}
}

Booking::Booking(string BMID, string BFID, string BBID, Date sDate, Date eDate, Time sTime, Time eTime, int bStat){
	memberID = BMID; 
	facilityID = BFID; 
	bookingID = BBID; 
	startDate.day = sDate.day;
	startDate.month = sDate.month;
	startDate.year = sDate.year;
	endDate.day = eDate.day;
	endDate.month = eDate.month;
	endDate.year = eDate.year;
	startTime.hour = sTime.hour;
	endTime.hour = eTime.hour;
	bookingStatus = bStat;

}

FacSys::FacSys(){
	
}
void FacSys::FacSubMenu(){
				char option;
		do
		{
			cout << "=========================================================\n"
	        	 << "         Facilities Management Subsystem\n"
	        	 << "=========================================================\n" << endl;
	        
	        cout << "------------ Manage Club Facilities here ------------\n" << endl;
	    	
			cout << "1)\tAdd new Facility\n"
	    		 << "2)\tEdit Facility\n" 
	    		 << "9)\tBack to previous Menu\n" << endl;
	    	cout << "---------------------------------------------------------\n" << endl;
	    	
			cout << "Please enter your option: ";
	    	cin >> option;
	    	cin.clear();
	    	cin.ignore(100, '\n');
	
	    	cout << '\n' << endl;
	    	
	    	switch(option)
	    	{
	    		case '1': {	
						  addFacility();	//add Facility
						  break;
	    			}
	    		case '2': cout << "Something!!"; //editFacility();	//edit facility
	    				  break;
	    		
	    		case '9': cout << "Something!!"; 
						break; //Quit
	    				 
	    		default: cout << "\n[Invalid Option, Please Try Again]\n\n" << endl;
			}
	    	
		}while(option != '9');
			}

void FacSys::addFacility(){
		string name, loc, phone, type;
		cout << "=========================================================\n"
	         << "                  Create New Facility\n"
	         << "=========================================================\n" << endl;
		cout << "Facility Name: ";
		getline(cin, name);
		cout << "Facility Location: ";
		getline(cin, loc);
		cout << "Facility Phone Number: ";
		getline(cin, phone);
		cout << "Facility Type: ";
		getline(cin, type);
		cout << "\nThe new Facility described below has been added.\n\n";
		Facilities insert(name, loc, phone, type); //error here: because of this i can't make a bin file that's larger than 2 entries large
		insert.toString();
		
		FacBin ins;
		
		fstream fs;
		fs.open(FAC_FILE_NAME, ios::in | ios::binary);
		fs.read(reinterpret_cast<char*>(&ins), sizeof(ins));
		fs.close();
		
		//read in old ins
		ins.index++;
		ins.f.push_back(insert);
		cout << ins.f.size() << endl;
		fs.open(FAC_FILE_NAME, ios::out | ios::binary | ios::trunc);
		fs.write(reinterpret_cast<char*>(&ins), sizeof(ins));
		//clear old file and write in new ins with updated values.
		fs.close();

}
Facilities::Facilities(string name, string loc, string phone, string type){
	FacBin insert;
	//read facilities.bin to retrieve latest index
	checkFacFile();
	fstream fs(FAC_FILE_NAME, ios::in | ios::binary);
	fs.read(reinterpret_cast<char*>(&insert), sizeof(insert));
	fs.close();
	//increment index by 1 
	int insertID = insert.index + 1;
	cout << insertID << "this ran!";
	//form Facilities index with F + index "e.g. F0001"
	this->facilityID = IDToString(insertID);
	
	cout << this->facilityID << "this ran!";
	//paste all that relevant information
	this->facilityName = name;
	this->facilityLocation = loc;
	this->facilityStatus = 1; //set facilityStatus to 1 by default
	this->facilityPhone = phone;
	this->facilityType = type;
}

void Facilities::toString(){
	cout << "Facility ID:\t" << this->facilityID << "\n";
	cout << "Facility Name:\t" << this->facilityName << "\n";
	cout << "Facility Location:\t" << this->facilityLocation << "\n";
	cout << "Facility Status:\t" << this->facilityStatus << "\n";
	cout << "Facility Phone:\t" << this->facilityPhone << "\n";
	cout << "Facility Type:\t" << this->facilityType << "\n";
	if(bookingHistory.size() == 0){
		//if there have been no bookings made, print out how there are none
		cout << "This member has made no bookings yet!" << endl;
	}
	else{
		//read go through the list of bookings that are in his Facility then Booking.toString() those
	}
}

/*
void Facilities::FacSubMenu(){
		char option;
	do
	{
		cout << "=========================================================\n"
        	 << "         Facilities Management Subsystem\n"
        	 << "=========================================================\n" << endl;
        
        cout << "------------ Manage Club Facilities here ------------\n" << endl;
    	
		cout << "1)\tAdd new Facility\n"
    		 << "2)\tEdit Facility\n" 
    		 << "9)\tBack to previous Menu\n" << endl;
    	cout << "---------------------------------------------------------\n" << endl;
    	
		cout << "Please enter your option: ";
    	cin >> option;
    	cin.clear();
    	cin.ignore(100, '\n');

    	cout << '\n' << endl;
    	
    	switch(option)
    	{
    		case '1': 	Facility a(f,u,c,k);
						cout << a.facilityID;
						//addFacility();	//add Facility
					  break;
    				 
    		case '2': editFacility();	//edit facility
    				  break;
    		
    		case '9': break; //Quit
    				 
    		default: cout << "\n[Invalid Option, Please Try Again]\n\n" << endl;
		}
    	
	}while(option != '9');
}
*/

