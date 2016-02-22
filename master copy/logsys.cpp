#include "logsys.h"

logSys::logSys(){
	//-------------------------CHECK IF MEMBER FILE EXISTS-------------------------//
	fstream fs;
	
	fs.open(MEMBER_FILE);
	bool ifExists = false;
	
	//check if fs can reach the file
	if(fs.good()){
		
		ifExists = true;
	}
	fs.close();
	//then if the file does not exist, create a new file and write a blank FacBin into it.
	if(ifExists == false){
		cout << MEMBER_FILE << " does not exist! Creating new " << MEMBER_FILE << "...\n\n";
		
	
		memVec.index = 0; 
		memVec.f.clear();
		
		writeMemFile(fs, memVec);
	}
	//-------------------------WRITE DATA INTO VECTOR OF FACILITIES-------------------------//
	else{
		readMemFile(fs, memVec);

	}
	//read member.txt into memVec
	//readMemFile(fs, memVec);
	//read manager.txt into manVec
}

void logSys::mainMenu(){
	char option;
	do
	{
		cout << "=========================================================\n"
        	 << "         Country Club Facilities Booking System\n"
        	 << "=========================================================\n" << endl;
        
        cout << "------------ Please Choose Your Login Option ------------\n" << endl;
    	
		cout << "1)\tClub Manager Login\n"
    		 << "2)\tClub Member Login\n" 
    		 << "9)\tQuit\n" << endl;
    	cout << "---------------------------------------------------------\n" << endl;
    	
		cout << "Please enter your option: ";
    	cin >> option;
    	cin.clear();
    	cin.ignore(100, '\n');

    	cout << '\n' << endl;
    	
    	switch(option)
    	{
    		case '1': //managersystem();	//Manager Login
					  break;
    				 
    		case '2': membersystem();	//Member Login
    				  break;
    		
    		case '9': cout << "Thank you for using the Booking System\n\n" << endl;	//Quit
    				  break;
    				 
    		default: cout << "\n[Invalid Option, Please Try Again]\n\n" << endl;
		}
    	
	}while(option != '9');
}

void logSys::readMemFile(fstream& fs, memBox& v){
	v.index = 0;
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

	while (!fs.eof()){
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
		v.index++;


		if (BNum > 0){
			while (BNum > 0){
				getline(fs, BMID, ';');
				getline(fs, BFID, ';');
				getline(fs, BBID, ';');

				getline(fs, contain, ';');
				sDateD = stoi(contain);

				getline(fs, contain, ';');
				sDateM = stoi(contain);

				getline(fs, contain, ';');
				sDateY = stoi(contain);

				getline(fs, contain, ';');
				eDateD = stoi(contain);

				getline(fs, contain, ';');
				eDateM = stoi(contain);

				getline(fs, contain, ';');
				eDateY = stoi(contain);

				getline(fs, contain, ';');
				sTimeH = stoi(contain);

				getline(fs, contain, ';');
				sTimeM = stoi(contain);

				getline(fs, contain, ';');
				eTimeH = stoi(contain);

				getline(fs, contain, ';');
				eTimeM = stoi(contain);

				getline(fs, contain, ';');
				bStatus = stoi(contain);

				getline(fs, chaff, '\n');

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
		if (ins.getMemID().length() > 4){
			v.f.push_back(ins);
		}
	}
	//Marcus - changed delimiter to ; to standardize

	fs.close();
}

void logSys::writeMemFile(fstream& fs, const memBox v){
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

//==================================================================================================
//member login system
void logSys::membersystem()	//member login system
{
	char choice;
	if (memVec.index == 0){
		MemReg();
	}
	else{
		do{
			cout << "=========================================================\n"
				<< "         	    Member Login\n"
				<< "=========================================================\n" << endl;
			cout << "1) Log In " << endl;
			cout << "2) Register\n " << endl;
			cout << "Please enter your choice: ";
			cin >> choice;
			cin.clear();
			cin.ignore(200, '\n');
			switch (choice){
			case '1':
				MemLogin();
				break;
			case '2':
				MemReg();
				break;
			default:
				cout << "Invalid input, please try again." << endl;
			}
		} while (choice != '9');
	}
}

//==================================================================================================

/*
void logSys::saveReg()
{
	ofstream ofile("member.txt");
				
	if(!ofile.is_open())
	{
		ofile.open("member.txt");
	}
				
	ofile << MEMUser << ", " << memberPassword << ", " << memberName << ", " << memberAddress << ", " << memberGender << endl;
				
	ofile.close();
}

*/
//==================================================================================================

void logSys::MemReg()
{
	
	string MID, user, pass, name, addr, phone;
	char gender;
	
	cout << "=========================================================\n"
		 << "               Club Member Registeration\n"
		 << "=========================================================\n" << endl;
			   	
	cout << "[Please Enter A Username]: ";
	//cin >> MEMUser;
	getline(cin, user, '\n');
			
	cout << "[Please Enter A Password]: ";
	//cin >> memberPassword;
	getline(cin, pass, '\n');
	
	cout << "[Please Enter Your Name]: ";
	getline(cin, name, '\n');
	
	cout << "[Please Enter Your Address]: ";
	getline(cin, addr, '\n');
	
	cout << "[Please Enter Your Phone Number]: ";
	getline(cin,phone, '\n');
	
	cout << "[Please Enter Your Gender (M / F)]: ";
	cin >> gender;
	cin.clear();
	cin.ignore(200,'\n');
			   	
	MID = MIDToString(memVec.index+1);
	Member ins(MID, name, pass, addr, phone, gender, user);
	memVec.index++;
	memVec.f.push_back(ins);
	
	fstream fs;
	
	fs.open(MEMBER_FILE, ios::trunc); //clear file first before writing in the information again
	fs.close();
	
	writeMemFile(fs,memVec);
	cout << "Member " << user << " has been registered! Please log in again with your account credentials!" << endl;
	cout << '\n' << endl;
			   	
	cout << endl;
}

//==================================================================================================

void logSys::MemLogin()
{
	MemSys ms; //access to Member System

	string inputUser;
	string inputPass;
	
	cout << "=========================================================\n"
		 << "                   Club Member Login\n"
		 << "=========================================================\n" << endl;
			    
	cout << "Please Enter [Username] & [Password] to Login\n" << endl;
			   	
	cout << "[Username]: ";
	getline(cin, inputUser, '\n');
					
	cout << "[Password]: ";
	getline(cin, inputPass, '\n');
			   	
	cin.clear();
	cin.ignore(100, '\n');
			
	cout << endl;
				
	fstream fs;
	
	readMemFile(fs, memVec);
	//read file to update memVec
	//check if username and password hits
	bool ifFound = false;
	string MID; 
	int retainIndex; //use this to retain the index of the user
	for(size_t i = 0; i != memVec.f.size(); i++){
		if (inputUser.compare(memVec.f[i].getMemUserName()) == 0 && inputPass.compare(memVec.f[i].getMemPassword()) == 0){
			ifFound = true;
			retainIndex = i;
			MID = memVec.f[i].getMemID();
		}
	}			
		if(ifFound)		
		{
			char MEoption;
			do
			{
				
				cout << "=========================================================\n"
			         << "                 Welcome [ " << inputUser << " ]\n"
			       	 << "=========================================================\n" << endl;
			        
			    cout << "--------------- Please Choose Your Option ---------------\n" << endl;    	
				cout << "1)\tMember Profile System\n"
			    	 << "2)\tSearch Facilities\n" 
			    	 << "9)\tQuit\n" << endl;
			    cout << "---------------------------------------------------------\n" << endl;
			    		
				cout << "Please enter your option: ";
			    cin >> MEoption;
			    cin.clear();
			    cin.ignore(100, '\n');
			    	
			    cout << '\n' << endl;
			    	
			    switch(MEoption){
					case '1': 
							  ms.memProfMenu(retainIndex);
			    			  break;
			    				 
			    	case '2': cout << "Search Facilities" << endl;	//Club Membership Ranking System
			    				//call Search Subsystem while passing MemberID into the function
			    			  break;
			    		
			    	case '9': cout << "\n[Exiting Club Member's Subsystem]\n\n" << endl;;	//Quit
			    			  break;
			    				 
			    	default: cout << "\n[Invalid Option, Please Try Again] \n\n" << endl;
				}
			    	
			}while(MEoption != '9');
		}
		else
		{
			cout << "\n[Invalid Username or Password, Please Try Again!]\n\n" << endl;
		}

}
/*
void logSys::managersystem()	//manager login system
{
	string MAUser;
	string MAPass;
	char MAoption;

	cout << "=========================================================\n"
       	 << "                  Club Manager Login\n"
       	 << "=========================================================\n" << endl;
    
    cout << "Please Enter [Username] & [Password] to Login\n" << endl;
   	
	cout << "[Username]: ";
   	getline(cin, MAUser);

	cout << "[Password]: ";
   	getline(cin, MAPass);
   	
   	cout << endl;
    	
	if(MAUser == "manager" && MAPass == "pass")
	{
		do
		{
			cout << "=========================================================\n"
        		 << "                    Welcome Manager\n"
       	 		 << "=========================================================\n" << endl;
        
       		cout << "--------------- Please Choose Your Option ---------------\n" << endl;
    	
			cout << "1)\tFacilities Management System\n"
    			 << "2)\tClub Membership Ranking System\n" 
    			 << "3)\tGenerate Summary Report\n" 
    			 << "9)\tQuit\n" << endl;
    		cout << "---------------------------------------------------------\n" << endl;
    		
    		cout << "Please enter your option: ";
    		cin >> MAoption;
    		cin.clear();
    		cin.ignore(100, '\n');
    	
    		cout << '\n' << endl;
    	
    		switch(MAoption)
    		{
    			case '1': cout << "Facilities Management System" << endl;	//Facilities Management System
    				   	  break;
    				 
    			case '2': cout << "Club Membership Ranking System" << endl;	//Club Membership Ranking System
    					  break;
    				 
    			case '3': cout << "Generate Summary Report" << endl;	//Generate Summary Report
    					  break;
    		
    			case '9': cout << "\n[Exiting Manager's Subsystem]\n\n" << endl;;	//Quit
    					  break;
    				 
    			default: cout << "\n[Invalid Option, Please Try Again] \n\n" << endl;
			}
    	
		}while(MAoption != '9');
	}
	else
	{
		cout << "\n[Invalid Username or Password, Please Try Again!]\n\n" << endl;
	}
}
*/


