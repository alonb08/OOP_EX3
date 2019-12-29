#include "NumSet.h"
#include <iostream>
#pragma once

int main() {
	NumSet a1,a2;
	a1.insert(2);
	a1.insert(3);
	a1.insert(6);
	int arr[5] = { 4, 0 ,0, 0 ,0 };

	//a1 += 9;
	a2 = arr;
	


	// 2 3 5 6 0
	//a1 += 5;
	cout <<"a1 is "<< a1;
		
	cout << "a2 is " << a2;
	a1 *= a2;
	cout << "new a1 is : " << a1;

	return 1;
}