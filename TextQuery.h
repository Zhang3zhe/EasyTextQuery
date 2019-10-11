#pragma once
#include<iostream>
#include<string>

class TextQuery {
 public:
	 TextQuery(std::string s) : data(s) {
		 std::cout << "This is a TextQuery object." << std::endl;
	 }

 private:
	 std::string data;
};
