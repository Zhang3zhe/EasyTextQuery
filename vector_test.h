#pragma once
#include<iostream>
#include<vector>

void vector_test() {
	std::vector<int> vec{ 1,2,3,4,5 };
	for (auto elem : vec)
		std::cout << elem << std::endl;
}
