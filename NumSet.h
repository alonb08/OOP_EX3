	
/*EX3
Alon Bernstein 209511583
Noam Bar-On 204749923
*/
#pragma once
#include <iostream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS 1
#define SIZE 5
using namespace::std;



class NumSet
{
private:
	int Cards[5];
public:
	NumSet();
	int getCard(int num)const { return this->Cards[num]; }
	int max() const;
	void insert(int num);
	int freeCells()const;
	void updateMax();
	int min()const { return this->Cards[0]; };
	float average()const;
	void replace(int num, int indx);
	int smallerThen(int num)const;
	void Del(int num);
	int biggerThen(int num) const;
	bool compare(int a, int b)const;
	NumSet& operator+=(int num) { this->insert(num); return(*this); }
	NumSet& operator+=(const NumSet&  Other);
	NumSet& operator ++();
	NumSet& operator --();
	bool operator==(const NumSet& other);
	NumSet& operator=(int arr[SIZE]);
	NumSet& operator=(const NumSet&  Other);
	NumSet& operator*=(const NumSet&  Other);
	friend ostream& operator <<(ostream& out, const  NumSet& other);
};

