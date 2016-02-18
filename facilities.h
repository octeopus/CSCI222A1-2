#include 'data.h'
#include <iomanip>
#include <sstream>

#DEFINE FAC_FILE_NAME = 'facilities.bin'

struct FacBin{
	int index;
	vector<Facilities> f;
};

Facilities::Facilities(string name, string loc, string phone, string type){
	FacBin f;
	//read facilities.bin to retrieve latest index
	checkFacFile();
	fstream fs(FAC_FILE_NAME, ios::out | ios::bin);
	fs.read(<reinterpret_cast<char*>(&f), sizeof(f));
	//increment index by 1 
	f.index++;
	//form Facilities index with F + index "e.g. F0001"
	this->facilityID = IDToString(f.index);
	//paste all that relevant information
	this->facilityName = name;
	this->facilityLocation = loc;
	this->facilityStatus = 1; //set facilityStatus to 1 by default
	this->facilityPhone = phone;
	this->facilityType = type;
	
	
}

string IDToString(int value){
	ostringstream os; 
	os << "F" << setfill('0') << setw(4) << value;
	return os.str();
}

void checkFacFile(){
	fstream fs(FAC_FILE_NAME, ios::bin);
	
	if(!fs){
		cout << FAC_FILE_NAME << " does not exist! Creating new " << FAC_FILE_NAME << "...";
		
		FacBin f; 
		f.index = 0; 
		fs.write(reinterpret_cast<char*>(&f), sizeof(f));
		fs.close();
	}
	fs.close();
}

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
    		case '1': addFacility();	//add Facility
					  break;
    				 
    		case '2': editFacility();	//edit facility
    				  break;
    		
    		case '9': break; //Quit
    				 
    		default: cout << "\n[Invalid Option, Please Try Again]\n\n" << endl;
		}
    	
	}while(option != '9');
}
