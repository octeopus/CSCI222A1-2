#pragma once
#ifndef RANK_H
#define RANK_H

#include <iterator>
#include <algorithm>
#include <string>

#define RANK_FILE "rank.txt"

using namespace std;

class Rank{
	private:
		string rankName;
		int rankPriority; //priority = advantages over other ranks.
		int rankPrivilege; //privilege dictates what facilites and services they can access etc.
		float rankFee;
		int rankDiscount;
		
	public:
		Rank();
		Rank(string, int, int, float, int);
		
		string getRankName();
		int getRankPriority() const;
		int getRankPrivilege();
		float getRankFee();
		string getRankDiscount(); //returns a string.
		
		void setRankName(string rankName);
		void setRankPriority(int rankPriority);
		void setRankPrivilege(int rankPrivilege);
		void setRankFee(float rankFee);
		void setRankDiscount(int rankDiscount);
		
		friend istream &operator>>(istream &is, Rank &rank);
		friend ostream &operator<<(ostream &os, const Rank &rank);
		
};



#endif
