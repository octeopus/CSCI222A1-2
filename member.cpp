#include "member.h"

void membersystem()	//member login system
{
	string MEMUser;
	string MEMPass;
	char MAoption;

	cout << "=========================================================\n"
       	 << "                   Club Member Login\n"
       	 << "=========================================================\n" << endl;
    
    cout << "Please Enter [Username] & [Password] to Login\n" << endl;
   	
	cout << "[Username]: ";
   	getline(cin, MEMUser);

	cout << "[Password]: ";
   	getline(cin, MEMPass);
   	
   	cout << endl;
    	
	if(MEMUser == "member" && MEMPass == "pass")
	{
		do
		{
			cout << "=========================================================\n"
        		 << "                  Welcome Club Member\n"
       	 		 << "=========================================================\n" << endl;
        
       		cout << "--------------- Please Choose Your Option ---------------\n" << endl;    	
			cout << "1)\tMember Profile System\n"
    			 << "2)\tSearch Facilities\n" 
    			 << "9)\tQuit\n" << endl;
    		cout << "---------------------------------------------------------\n" << endl;
    		cout << "WTF!!" << endl;
			cout << "Please enter your option: ";
    		cin >> MAoption;
    		cin.clear();
    		cin.ignore(100, '\n');
    	
    		cout << '\n' << endl;
    	
    		switch(MAoption)
    		{
    			case '1': cout << "Member Profile System" << endl;	//Facilities Management System
    				   	  break;
    				 
    			case '2': cout << "Search Facilities" << endl;	//Club Membership Ranking System
    					  break;
    		
    			case '9': cout << "\n[Exiting Club Member's Subsystem]\n\n" << endl;;	//Quit
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

//==================================================================================================
