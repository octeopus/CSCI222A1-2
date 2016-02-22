#include "rank.h"

//constructor

Rank::Rank()
{
	rankName = "Basic";
	rankPriority = 1;
	rankPrivilege = 1;
	rankFee = 1;
	rankDiscount = 1;
}

Rank::Rank(string a, int b, int c, float d, int e)
{
	rankName = a;
	rankPriority = b;
	rankPrivilege = c;
	rankFee = d;
	rankDiscount = e;
}

//accessors
string Rank::getRankName()
{
	return rankName;
}

int Rank::getRankPriority() const
{
	return rankPriority;
}

int Rank::getRankPrivilege()
{
	return rankPrivilege;
}

float Rank::getRankFee()
{
	return rankFee;
}

string Rank::getRankDiscount()
{

	string discount;
	
	int value = rankDiscount;
	
	switch(value)
	{
		case 1:
			discount = "Rank 1: You get a year's supply of nothing.";
			break;
		case 2: 
			discount = "Rank 2: You get 2% off sponges. Lucky you!";
			break;
		case 3:
			discount = "Rank 3: You get 0.01% off parking! We're so generous.";
			break;
		case 4:
			discount = "Rank 4: You get $1 off our soap.";
			break;
		case 9:
			discount = "Rank 9: You're that legendary B10 group? Everything is free for you.";
			break;
	}
	
	return discount;
		
}

//mutators
void Rank::setRankName(string rankName)
{
	this->rankName = rankName;
}

void Rank::setRankPriority(int rankPriority)
{
	this->rankPriority = rankPriority;
}

void Rank::setRankPrivilege(int rankPrivilege)
{
	this->rankPrivilege = rankPrivilege;
}

void Rank::setRankFee(float rankFee)
{
	this->rankFee = rankFee;
}

void Rank::setRankDiscount(int rankDiscount)
{
	this->rankDiscount = rankDiscount;
}

istream &operator>>(istream &is, Rank &rank)
{
	is >> rank.rankName;
	is >> rank.rankPriority;
	is >> rank.rankPrivilege;
	is >> rank.rankFee;
	is >> rank.rankDiscount;

	return is;
}

ostream &operator<<(ostream &os, const Rank &rank)
{

	os << rank.rankName << " " << rank.rankPriority << " " << rank.rankPrivilege << " " << rank.rankFee << " " << rank.rankDiscount << "\n";

	return os;

}