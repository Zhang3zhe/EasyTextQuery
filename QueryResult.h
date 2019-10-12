/**
* QueryResult.h
* Copyright (c) 2019-10 https://github.com/Zhang3zhe All rights reserved.
*/
#pragma once
#include"common.h"

class QueryResult {
 friend std::ostream& print(std::ostream&, const QueryResult&);
 public:
	 QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p,
		         std::shared_ptr<std::vector<std::string>> f) :
				 sought(s), lines(p), file(f){};
 private:	 
	 std::string sought; // word
	 std::shared_ptr<std::set<line_no>> lines;
	 std::shared_ptr<std::vector<std::string>> file;
};

inline std::string make_plural(size_t ctr, const std::string& word, const std::string& ending){
	return (ctr == 1) ? word : word + ending;
}

std::ostream& print(std::ostream& os, const QueryResult& qr) {
	os << qr.sought << " occurs " << qr.lines->size() << " "
	   << make_plural(qr.lines->size(), "time", "s") << std::endl;
	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;
	return os;
}
