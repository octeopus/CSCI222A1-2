#include "facilities.h"


string FIDToString(int value){
	//use this to generate the FacilityID eg 'F0001'
	ostringstream os;
	os << "F" << setfill('0') << setw(4) << value;
	return os.str();
}

Booking::Booking(){

}

Booking::Booking(string BMID, string BFID, string BBID, Date sDate, Date eDate, Time sTime, Time eTime, int bStat){
	setBMID(BMID);
	setBFID(BFID);
	setBBID(BBID);
	setsDate(sDate);
	seteDate(eDate);
	setsTime(sTime);
	seteTime(eTime);
	setBookStat(bStat);

}
FacSys::FacSys(){
	
	//-------------------------CHECK IF FILE EXISTS-------------------------//
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
		
		data.index = 0;
		fs.open(FAC_FILE_NAME, ios::out);
		fs << data.index;
		fs.close();
	}
	//-------------------------WRITE DATA INTO VECTOR OF FACILITIES-------------------------//
	else{
		readFile(fs, data);

	}
	
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
	    		 << "3)\tList all Facilities\n"
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
	    		case '2': editFacility(); //edit facility
	    				  break;
	    		case '3': checkStruct(); //List every facility and their booking histories.
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
		Facilities insert(name, loc, phone, type);
		
		insert.toString();
		
		fstream fs;
		
		
		readFile(fs, data);
				
		data.index++;
		
		data.f.push_back(insert);
		
		fs.open(FAC_FILE_NAME, ios::trunc); //clear out the text file first
		fs.close();
		//then write out the information of the data to the text file
		writeFile(fs,data);
}

void FacSys::editFacility(){
	string code;
	fstream fs;
		cout << "=========================================================\n"
	         << "                      Edit Facility\n"
	         << "=========================================================\n" << endl;
		cout << "Please type in the serial code of the facility you wish to find: ";
		getline(cin, code);
		
		readFile(fs, data);
		bool ifFound = false;
		int index;
		for(size_t i = 0; i != data.f.size(); i++){
			if(!data.f[i].getFacilityID().compare(code)){
				ifFound = true;
				index = i; //retain index for editing later 
			}
		}
		
		cout << '\n' << endl;
		
		char choice;
		char confirmDel;
		string input;
		bool exitLoop = false;
		if(ifFound){
			do{
			cout << "--------------------Editing " << code << "-------------------\n" << endl;	
				cout << "1)\tEdit Facility Name\n"
	    		 << "2)\tEdit Facility Location\n" 
	    		 << "3)\tEdit Facility Status\n"
	    		 << "4)\tEdit Facility Phone Number\n"
	    		 << "5)\tEdit Facility Type\n\n"
	    		 << "7)\tDelete Facility\n\n"
	    		 << "9)\tBack to previous Menu\n" << endl;
	    	cout << "--------------------------------------------------------\n" << endl;
	    	
			cout << "Please enter your option: ";
	    	cin >> choice;
	    	cin.clear();
	    	cin.ignore(100, '\n');
				switch (choice){
					case '1':
						cout << "Current Facility Name: " << data.f[index].getFacilityName() << endl;
						cout << "Edit Facility Name to:";
						getline(cin, input);
						data.f[index].setFacName(input);
						fs.open(FAC_FILE_NAME, ios::trunc);
						fs.close();
						writeFile(fs, data);
						cout << endl;	
						break;	
					case '2':
						cout << "Current Facility Location: " << data.f[index].getFacilityLocation() << endl;
						cout << "Edit Facility Location to:";
						getline(cin, input);
						data.f[index].setFacLocation(input);
						fs.open(FAC_FILE_NAME, ios::trunc);
						fs.close();
						writeFile(fs, data);
						cout << endl;
						break;
					case '3':
						cout << "Current Facility Status: " << data.f[index].getFacilityStatus() << endl;
						cout << "Change Facility Status to:";
						getline(cin, input);
						if(isdigit(input[0])){
							int num = atoi(&input[0]);
							
							data.f[index].setFacStatus(num);	
							fs.open(FAC_FILE_NAME, ios::trunc);
							fs.close();
							writeFile(fs, data);
						}
						else{
							cout << "Not a valid input. Please enter a positive integer.";
						}
						cout << endl;	
					break;
					case '4':
						cout << "Current Facility Phone Number: " << data.f[index].getFacilityPhone() << endl;
						cout << "Edit Facility Phone Number to:";
						getline(cin, input);
						data.f[index].setFacPhone(input);
						fs.open(FAC_FILE_NAME, ios::trunc);
						fs.close();
						writeFile(fs, data);
						cout << endl;
					break;
					case '5':
						cout << "Current Facility Type: " << data.f[index].getFacilityType() << endl;
						cout << "Edit Facility Type to:";
						getline(cin, input);
						data.f[index].setFacType(input);
						fs.open(FAC_FILE_NAME, ios::trunc);
						fs.close();
						writeFile(fs, data);
						cout << endl;
					break;
					case '7':
						exitLoop = false;
						while(!exitLoop){
							
							cout << "Confirm Deletion? (y/n):";
						cin >> confirmDel;
						cin.clear();
						cin.ignore(200, '\n');
							if(confirmDel == 'y' || confirmDel == 'Y'){
								data.f.erase(data.f.begin() + index);
								data.index--;
								fs.open(FAC_FILE_NAME, ios::trunc);
								fs.close();
								writeFile(fs, data);
								cout << "Entry " << code << " has been deleted." << endl;
								exitLoop = true;
							}
							else if(confirmDel == 'n' || confirmDel == 'N'){
								exitLoop = true;
							}
							else{
								cout << "Invalid input, please try again.\n" << endl;
							}
						}
						break;
					case '9':
					break;
					
					default:
						cout << "Please input a valid menu option." << endl;
					break;
					
				}
			}while((choice != '7') && (choice != '9'));
		}
		else{
			cout << "Facility not found. For a full listing of available Facilities,\n"
				 << "please use function 3 on the main menu.\n\n" << endl;
		}
}

void FacSys::readFile(fstream& fs, FacBin& v){
		v.index = 0;
		v.f.clear();
		fs.open(FAC_FILE_NAME, ios::in);
		
		
		//INDEX//
		string index;
		//----------------------FACILITY DUMP ZONE--------------------------//
		string FID, FName, FLoc, FPhone, FType;
		int FStat, BNum; //BNum is the number of bookings
		//----------------------BOOKING DUMP ZONE--------------------------//
		string BMID, BFID, BBID; 
		int sDateD, sDateM, sDateY, eDateD, eDateM, eDateY, sTimeH, sTimeM, eTimeH, eTimeM, bStatus;
		//----------------------CHAFF DUMP ZONE-----------------------//
		string chaff;

		//---ADDITIONAL STUFF I PUT IN BECAUSE I WAS THINKING ON THE FLY---//
		string toFstat;
		string toBnum;
		string contain;
		Date sDate, eDate;
		Time sTime, eTime;

		getline(fs, index, '\n');
		
		v.index = stoi(index);
		while(!fs.eof()){
			getline(fs, FID, ';');
			getline(fs, FName, ';');
			getline(fs, FLoc, ';');
			
			
			getline(fs, toFstat, ';');
			FStat = stoi(toFstat);
			
			getline(fs, FPhone, ';');
			getline(fs, FType, ';');
			
			getline(fs, toBnum, ';'); //then get the number of Bookings that a Facility has.
			BNum = stoi(toBnum);
			
			Facilities ins(FID,FName,FLoc,FStat,FPhone,FType);
			if(BNum > 0){
				while(BNum > 0){
					getline(fs,BMID,';');
					getline(fs,BFID,';');
					getline(fs,BBID,';');
					
					
					getline(fs,contain,';');
					sDateD = stoi(contain);
					
					getline(fs,contain, ';');
					sDateM = stoi(contain);
					
					getline(fs, contain,';');
					sDateY = stoi(contain);
					
					getline(fs,contain,';');
					eDateD = stoi(contain);
					
					getline(fs,contain, ';');
					eDateM = stoi(contain);
					
					getline(fs, contain,';');
					eDateY = stoi(contain);
					
					getline(fs,contain,';');
					sTimeH = stoi(contain);
					
					getline(fs,contain, ';');
					sTimeM = stoi(contain);
					
					getline(fs, contain,';');
					eTimeH = stoi(contain);
					
					getline(fs, contain,';');
					eTimeM = stoi(contain);
					
					getline(fs,contain,';');
					bStatus = stoi(contain);
					
					getline(fs, chaff,'\n');
					
					sDate.day = sDateD;
					sDate.month = sDateM;
					sDate.year = sDateY;
					
					eDate.day = eDateD;
					eDate.month = eDateM;
					eDate.year = eDateY;
					
					
					sTime.hour = sTimeH;
					sTime.minute = sTimeM;
					
					eTime.hour = eTimeH;
					eTime.minute = eTimeM;
					
					Booking bIns(BMID, BFID, BBID, sDate, eDate, sTime, eTime, bStatus);
					ins.bookingHistory.push_back(bIns);
					BNum--;
				}
				getline(fs, chaff,'\n');
				//getline the data that follows after BNum and insert them into the vector of Bookings
			}
			else{
				getline(fs, chaff,'\n'); //move to next line
			}
			if (!ins.getFacilityID().empty()){
				v.f.push_back(ins);
			}
			ins.bookingHistory.clear();
		}
	
}
void FacSys::writeFile(fstream& fs, const FacBin v){
	fs.open(FAC_FILE_NAME, ios::out);
	fs << v.index << '\n';
	
	for(size_t i = 0; i != v.f.size(); i++){ 
		fs << v.f[i].getFacilityID() << ';'
			<< v.f[i].getFacilityName() << ';'
			<< v.f[i].getFacilityLocation() << ';'
			<< v.f[i].getFacilityStatus() << ';'
			<< v.f[i].getFacilityPhone() << ';'
			<< v.f[i].getFacilityType() << ';'
			<< v.f[i].bookingHistory.size() << ';';
		if(v.f[i].bookingHistory.size() > 0){ //check if booking History has more than 1 entry
			for(size_t m = 0; m != v.f[i].bookingHistory.size(); m++){
				fs << v.f[i].bookingHistory[m].getBMID() << ';'
				   << v.f[i].bookingHistory[m].getBFID() << ';'
				   << v.f[i].bookingHistory[m].getBBID() << ';'
				   << v.f[i].bookingHistory[m].getsDate().day << ';'
				   << v.f[i].bookingHistory[m].getsDate().month << ';'
				   << v.f[i].bookingHistory[m].getsDate().year << ';'
				   << v.f[i].bookingHistory[m].geteDate().day << ';'
				   << v.f[i].bookingHistory[m].geteDate().month << ';'
				   << v.f[i].bookingHistory[m].geteDate().year << ';'
				   << v.f[i].bookingHistory[m].getsTime().hour << ';'
				   << v.f[i].bookingHistory[m].getsTime().minute << ';'
				   << v.f[i].bookingHistory[m].geteTime().hour << ';'
				   << v.f[i].bookingHistory[m].geteTime().minute << ';'
				   << v.f[i].bookingHistory[m].getsTime().hour << ';'
				   << v.f[i].bookingHistory[m].getBookStat() << ';';
			}
			
		}
		fs << '\n';
	}
	fs.close();
}

Facilities::Facilities(){
	
}

Facilities::Facilities(string name, string loc, string phone, string type){
	
	//read facilities.bin to retrieve latest index
	string getIndex;
	int insert;
	fstream fs;
	fs.open(FAC_FILE_NAME, ios::in);
	getline(fs, getIndex);
	insert = stoi(getIndex);
	fs.close();
	
	//increment index by 1 
	insert++;
	//form Facilities index with F + index "e.g. F0001"
	this->facilityID = FIDToString(insert);
	//paste all that relevant information
	this->facilityName = name;
	this->facilityLocation = loc;
	this->facilityStatus = 1; //set facilityStatus to 1 by default
	this->facilityPhone = phone;
	this->facilityType = type;
}

Facilities::Facilities(string fid, string name, string loc, int stat, string phone, string type){

		setFacID(fid);
		setFacName(name);
		setFacLocation(loc);
		setFacStatus(stat);
		setFacPhone(phone);
		setFacType(type);
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
		cout << "No bookings have been made for this Facility yet!" << endl;
	}
	else{
		//read go through the list of bookings that are in his Facility then Booking.toString() those
	}
	cout << "\n------------------------------------------\n";
}

void FacSys::checkStruct(){
	
		FacBin ins;
		
		fstream fs;
		readFile(fs, ins);
		
		if(ins.f.size() == 0){
			cout << "There are no entries in " << FAC_FILE_NAME << " as of this moment." << endl;
		}
		else{
			for(size_t i = 0; i < ins.f.size(); i++){
			ins.f[i].toString();
		}
		}
		
}


