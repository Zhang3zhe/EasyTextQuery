/**
* EasyTextQuery main.cpp
* Copyright (c) 2019-10 https://github.com/Zhang3zhe All rights reserved.
*/
#include<fstream>
#include<iostream>
#include<string>
#include"QueryResult.h"
#include"TextQuery.h"

std::ostream& print(std::ostream& os, const QueryResult& qr) {

	return os;
}

void runQueries(std::ifstream& infile) {
	// Arguement infile points to a file to be processed.
	TextQuery tq(infile);
	// Interact with user: remind user to Input and print the result after searching.
	while (true) {
		std::cout << "Enter word to look for, or q to quit: " << std::endl;
		std::string s;
		if (!(std::cin >> s) || s == "q")	 break;
		print(std::cout, tq.query(s)) << std::endl;
	}
}

int main(int argc, char** argv) {
	
	return 0;
}
