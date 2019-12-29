	
/*EX3
Alon Bernstein 209511583
Noam Bar-On 204749923
*/
#include "NumSet.h"

#pragma once
#include <iostream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS 1
using namespace::std;
#define SIZE 5

//return the highest element in the NumSet
int NumSet::max() const {
	for (int i = SIZE - 1; i > 0; i--) {
		if (this->Cards[i] > 0) {
			return this->Cards[i];
		}
	}
	cout << "NumSet is empty" << endl;
	return 0;
}
//a method
bool NumSet::compare(int a, int b) const{
	if (a == 0) {
		return true;
	}
	if (b == 0) {
		return false;
	}
	return (a > b);
}
void NumSet::updateMax() { //check if Cards[i]> Cards[i+1], if so switch them
	int tmp = 0;
	for (int i = 0; i <SIZE -1; i++) {
		for (int j = 0; j < SIZE -1 - i; j++) {
			if ( this->compare(this->Cards[j], this->Cards[j+1])) {
				tmp = this->Cards[j];
				this->Cards[j] = this->Cards[j + 1];
				this->Cards[j + 1] = tmp;
			}
		}
	}
}

int NumSet::freeCells()const {
	int result = 0;
	for (int i = 0; i < SIZE; i++) {
		if (this->getCard(i) == 0) {
			result++;
		}
	}
	return result;
}

NumSet::NumSet(){
	for (int i = 0; i < SIZE; i++) {
		this->Cards[i] = 0;
	}
}

void NumSet::insert(int num) {
	if (this->freeCells() == 0) {
		cout << "The deck is already full of cards" << endl;
		return;
	}
	for (int i = 0; i < SIZE; i++) {
		if (this->Cards[i] == 0) {
			this->Cards[i] = num;
			break;
		}
	}
	this->updateMax();
}


float NumSet::average()const {
	int numOfNonZeros = 5 - this->freeCells();
	if (numOfNonZeros == 0) {
		cout <<"No Cards in hand, cant divide by zero" << endl;
		return 0.0;
	}
	float sum = 0.0;
	for (int i = 0; i < 5; i++) {
		sum += this->Cards[i];
	}
	return (sum / float(numOfNonZeros));

}

int NumSet::biggerThen(int num)const {
	int counter = 0;
	for (int i = SIZE-this->freeCells()-1; i > 0; i--) {
		if (this->Cards[i] >= num) {
			counter++;
		}
		else {
			break;
		}
	}
	return counter;
}

int NumSet::smallerThen(int num)const  {
	int counter = 0;
	for (int i = 0; i < SIZE - this->freeCells() ; i++) {
		if (this->Cards[i] <= num) {
			counter++;
		}
		
	}
	return counter;
}



void NumSet::replace(int num, int indx) {
	if (indx > 4) {
		cout << "not a valid place" << endl;
		return;
	}
	if (num <= 0) {
		cout << "cards need to be possitive" << endl;
		return;
	}
	this->Cards[indx] = num;
	updateMax();
}
void NumSet::Del(int num) {
	if (num < 4 && num>0) {
		this->Cards[num] = 0;
	}
	else {
		cout << "there is no  " << num << "spot. Out of Bounds error" << endl;
	}

}
NumSet& NumSet::operator+=(const NumSet& other) {
	for (int i = 0; i < SIZE; i++) {
		
			this->Cards[i] += other.getCard(i);
			if (this->getCard(i) > 10) {
				this->Cards[i] = 10;
			}
	}
	return (*this);
}

NumSet& NumSet:: operator ++() {
	for (int i = 0; i < SIZE; i++) {
		if (this->Cards[i] < 10)
			if (this->Cards[i] == 0) {
				continue;
			}
			(this->Cards[i])++;
		
	}
	return (*this);
}

NumSet& NumSet:: operator --() {
	for (int i = 0; i < SIZE; i++) {
		if (this->Cards[i] > 1)
			(this->Cards[i])--;
	}
	return (*this);
}

bool NumSet::operator==(const NumSet& other) {
	for (int i = 0; i < SIZE; i++) {
		if(this->Cards[i] != other.getCard(i))
		return false;
	}
	return true;
}

NumSet& NumSet:: operator=(int arr[SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		if (arr[i] > 10 || arr[i] < 1) {
			cout << "invalid card, putting 0 instead" << endl;
			arr[i] = 0;
			continue;
		}
		this->Cards[i] = arr[i];
	}
	this->updateMax();
	return (*this);

}
NumSet& NumSet::operator=(const NumSet&  Other){
	for(int i=0;i<SIZE;i++){
		this->Cards[i] = Other.Cards[i];
	}
		

	return (*this);
}/*
NumSet& NumSet::operator*=(const NumSet& Other) {
	int NumSetSize = (SIZE - (this->freeCells()));
	int OtherSize = (SIZE - (Other.freeCells()));

	for(int i=0;i< ((NumSetSize + OtherSize) -5 ) ;i++){
		this->Cards[i] = 0;
	}
		updateMax();

	//if get here than there is enoth space
	for (int i = 0; i < SIZE; i++) {
		this->insert(Other.Cards[i]);
	}
	*/
/*
NumSet& NumSet::operator*=(const NumSet& Other) {
	int NumSetSize = (SIZE - (this->freeCells()));
	int OtherSize = (SIZE - (Other.freeCells()));
	for (int i = NumSetSize; i < SIZE; i++) {
		this->Cards[i] = Other.Cards[i - NumSetSize];
	}
	*/
	//noam//

NumSet& NumSet::operator*=(const NumSet& Other) {
	int NumSetSize = SIZE - (this->freeCells() );//how meny unavailable
	int OtherSize = SIZE - (Other.freeCells() );

	for (int i = 0; i < (NumSetSize + OtherSize - 5); i++){
		this->Cards[i] = 0; // reset the leftmost card  (NumSetSize + OtherSize - 5) times
	}
	int j = 0;
	for (int i = 0; i < SIZE; i++) {
		if (this->Cards[i] == 0) {
			this->Cards[i] = Other.Cards[j];
			j++;
		}
	}
	this->updateMax();
	return (*this);
}


/*
A= 1 2 3 4 0     NumSetSize=4
B= 6 7 0 0 0	 OtherSize=2    
           1
A= 0 2 3 4 0  
A= 6 2 3 4 0  
A= 0 2 3 4 7  

}

*/

ostream&  operator <<(ostream& out, const  NumSet& other) {
	if (other.freeCells() == SIZE) {
		out << "Empty NumSet" << endl;
		return out;
;	}
	for (int i = 0; i < SIZE; i++) {
		out << other.getCard(i) << " ";
	}
	out << endl;
	return out;
}
