#pragma once
#include<iostream>
#include<vector>
using namespace std;

void vector_test() {
	vector<int> vec{ 1,2,3,4,5 };
	for (auto elem : vec)
		cout << elem << endl;
}
