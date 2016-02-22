#include "member.h"
#include "rank.h"


string MIDToString(int value){
	//use this to generate the FacilityID eg 'M0001'
	ostringstream os;
	os << "M" << setfill('0') << setw(4) << value;
	return os.str();
}

MemSys::MemSys(){
	fstream fs;
	
	readMemFile(fs, mVec);
} 

void MemSys::memProfMenu(const int ind){
	//access vector with ind and retrieve Member information
	
	int idx = ind;
	
	//----------------------MEMBER DUMP ZONE--------------------------//
		
		string MID, MName, MPass, MAdd, MPhone, MRank, MemUs;
		char gend;
	
	MID = mVec.f[idx].getMemID();
	MName = mVec.f[idx].getMemName();
	MPass = mVec.f[idx].getMemPassword();
	MAdd = mVec.f[idx].getMemAddress();
	MPhone = mVec.f[idx].getMemPhone();
	MRank = mVec.f[idx].getMemRank();
	gend = mVec.f[idx].getMemGender();
	MemUs = mVec.f[idx].getMemUserName();
	bool exitloop = false;
	char choice;
	
	while(!exitloop){
		cout << "=========================================================\n"
		 << "               Member Profile Subsystem\n"
		 << "=========================================================\n" << endl;
		 cout << "--------------- Please Choose Your Option ---------------\n" << endl;    	
				cout << "1)\tEdit Member Profile\n"
			    	 << "2)\tEdit Booking Preference\n"
					 << "3)\tEdit Member Rank\n" 
					 << "4)\tToggle Notification\n"
			    	 << "9)\tQuit\n" << endl;
			    cout << "---------------------------------------------------------\n" << endl;
			    		
				cout << "Please enter your option: ";
				cin >> choice; 
				cin.clear();
				cin.ignore(200,'\n');
				
				switch(choice){
					case '1':
						editInformation(idx);
						break;
					case '2':
						cout << "Not an implemented function yet!" << endl;
						//editBookPref(ind);
						break;
					case '3':
						editRank(idx);
						break;
					case '4':
						cout << "Not an implmented function yet!" << endl;
						break;
					case '9':
						exitloop = true;
						break;
					default:
						cout << "Not a valid input, please try again." << endl;
						break;	
				}
		 
	}
	
	
	//while loop
	//open menu for editing various aspects of member data
	//truncate member.txt
	//write new vector back into the file
} 

void MemSys::editInformation(const int ind){
	int idx = ind;
	bool exitloop = false;
	string input;
	char choice;

	fstream fs;
	while(!exitloop){
		cout << "=========================================================\n"
		 << "               Edit Member Profile Information\n"
		 << "=========================================================\n" << endl;
		 cout << "--------------- Please Choose Your Option ---------------\n" << endl;    	
				cout << "1)\tEdit Member Name\n"
			    	 << "2)\tChange Password\n"
					 << "3)\tEdit Member Address\n" 
					 << "4)\tEdit Member Phone Number\n"
			    	 << "9)\tQuit\n" << endl;
			    cout << "---------------------------------------------------------\n" << endl;
			    		
				cout << "Please enter your option: ";
				cin >> choice; 
				cin.clear();
				cin.ignore(200,'\n');
				
				switch(choice){
					case '1':
						cout << "Current Member Name: " << mVec.f[idx].getMemName() << endl;
						cout << "Edit Member Name to: ";
						getline(cin, input);
						mVec.f[idx].setMemName(input);
						fs.open(MEMBER_FILE, ios::trunc);
						fs.close();
						writeMemFile(fs, mVec);
						cout << endl;	
						break;
					case '2':
						cout << "Current Member Password: " << mVec.f[idx].getMemPassword() << endl;
						cout << "Edit Member Password to: ";
						getline(cin, input);
						mVec.f[idx].setMemPassword(input);
						fs.open(MEMBER_FILE, ios::trunc);
						fs.close();
						writeMemFile(fs, mVec);
						cout << endl;
						break;
					case '3':
						cout << "Current Member Address: " << mVec.f[idx].getMemAddress() << endl;
						cout << "Edit Member Name to: ";
						getline(cin, input);
						mVec.f[idx].setMemAddress(input);
						fs.open(MEMBER_FILE, ios::trunc);
						fs.close();
						writeMemFile(fs, mVec);
						cout << endl;
						break;
					case '4':
						cout << "Current Member Phone No.: " << mVec.f[idx].getMemPhone() << endl;
						cout << "Edit Member Phone No. to: ";
						getline(cin, input);
						mVec.f[idx].setMemPhone(input);
						fs.open(MEMBER_FILE, ios::trunc);
						fs.close();
						writeMemFile(fs, mVec);
						cout << endl;
						break;
					case '9':
						exitloop = true;
						break;
					default:
						cout << "Not a valid input, please try again." << endl;
						break;	
				}
	}
		
				
				
}

void MemSys::editRank(const int ind){
	int idx = ind;
	vector<Rank> rVec; 
	Rank ins;
	fstream fs; 
	//retrieve available ranks
	fs.open(RANK_FILE, ios::in);
	if(!fs.good()){
		cout << "Failed to open " << RANK_FILE << ". It is possible that the file does not exist.\n\n";
	}
	else{
		while(!fs.eof()){
			fs >> ins;
			rVec.push_back(ins);
		}
	}
	fs.close();
	//display user's current rank
	
	cout << "Current Rank: " << mVec.f[idx].getMemRank() << endl;
	cout << "\n\n" << endl;
	cout << "Available Ranks: \n";
	for(size_t i = 0; i != rVec.size(); i++){
		
		cout << i << ") " << rVec[i].getRankName() << "\t| $" << rVec[i].getRankFee() << " per Month" << endl;
		if(rVec[i].getRankName() == mVec.f[idx].getMemRank()){
			cout << "(This is your current Rank)" << endl;
		}
		cout << "Privileges: " << endl;
		cout << rVec[i].getRankDiscount() << endl;
		cout << '\n' << endl;
	}
		//make them choose a rank that they want to upgrade/downgrade to
	int choice;
	bool exitloop = false;
	while(!exitloop){
		cout << "Which Rank would you like to purchase?: "; 
		cin >> choice; 
		cin.clear();
		cin.ignore(200,'\n');
		
		if((unsigned)choice > rVec.size() - 1){
			cout << "Not a valid input. Please try again.";
		} 	
		else{
			exitloop = true;
			mVec.f[idx].setMemRank(rVec[choice].getRankName());
			cout << "Your Member Rank has been set to " << mVec.f[idx].getMemRank() << ". The Billing Information will\n"
				<< "be reflected in the bill for the coming month.";
		}
	}
		//truncate member.txt
	fs.open(RANK_FILE, ios::trunc);
	fs.close();

	//change rank and update
	writeMemFile(fs, mVec);
}

void MemSys::readMemFile(fstream& fs, memBox& v){
	
	v.f.clear();
	
	fs.open(MEMBER_FILE, ios::in);
	
		Member ins;
		//----------------------MEMBER DUMP ZONE--------------------------//
		
		string MID, MName, MPass, MAdd, MPhone, MRank, MGen, MemUs;
		char gend;
		//----------------------BOOKING DUMP ZONE--------------------------//
		string BCont; //carries the number of bookings made by a member
		int BNum;
		string BMID, BFID, BBID; 
		int sDateD, sDateM, sDateY, eDateD, eDateM, eDateY, sTimeH, sTimeM, eTimeH, eTimeM, bStatus;
		Date sDate, eDate;
		Time sTime, eTime;
		string contain; //used to carry integers and needs to be used to convert to the appropriate format using int
		//----------------------CHAFF DUMP ZONE-----------------------//
		string chaff;
	string firstLine;	
	getline(fs, firstLine, '\n');
	v.index = stoi(firstLine);
	cout << firstLine << endl;
	
	while(!fs.eof()){
		getline(fs, MID, ';');
		getline(fs, MName, ';');
		getline(fs, MPass, ';');
		getline(fs, MAdd, ';');
		getline(fs, MPhone, ';');
		getline(fs, MRank, ';');
		getline(fs, MGen, ';');
		gend = *MGen.begin();
		getline(fs, MemUs, ';');
		getline(fs, BCont, ';');
		BNum = stoi(BCont);
		Member ins(MID, MName, MPass, MAdd, MPhone, MRank, gend, MemUs);
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
		}
		if(ins.getMemID().length() > 4){
			v.f.push_back(ins);
		}
	}
	
	//Marcus - changed delimiter to ; to standardize
	
	fs.close();
}

void MemSys::writeMemFile(fstream& fs, const memBox v){
	fs.open(MEMBER_FILE, ios::out);
	fs << v.index << '\n';
	
	for(size_t i = 0; i != v.f.size(); i++){ 
		fs << v.f[i].getMemID() << ';'
			<< v.f[i].getMemName() << ';'
			<< v.f[i].getMemPassword() << ';'
			<< v.f[i].getMemAddress() << ';'
			<< v.f[i].getMemPhone() << ';'
			<< v.f[i].getMemRank() << ';'
			<< v.f[i].getMemGender() << ';'
			<< v.f[i].getMemUserName() << ';'
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


