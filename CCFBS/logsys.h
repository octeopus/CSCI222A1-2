#pragma once
#ifndef LOGSYS_H
#define LOGSYS_H

#ifndef FACILITIES_H
#include "facilities.h"
#endif
#ifndef MEMBER_H
#include "member.h"
#endif
#define MEMBER_FILE "member.txt"
//#define MANAGER_FILE "manager.txt"

struct memBox{
	int index; 
	vector<Member> f;
};

/* ONLY OPEN THIS WHEN MANAGER IS DONE
struct manBox{
	int index; 
	vector<Manager> f;
};
*/
class logSys{
	public:
	memBox memVec;
	//manBox manVec;
	
	logSys();
	
	void mainMenu();
	
	void membersystem();
	void readMemFile(fstream&, memBox&);
	void writeMemFile(fstream&, const memBox);
    //void saveReg();
    void MemReg();
    void MemLogin();
    
    
	//void managersystem(); //main menu for manager system.
	//void readManFile(fstream&, manBox);
	
};



#endif
