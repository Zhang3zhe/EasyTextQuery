/**
* TextQuery.h
* Copyright (c) 2019-10 https://github.com/Zhang3zhe All rights reserved.
*/
#pragma once
#include<fstream>
#include"QueryResult.h"

class TextQuery {
 public:
	 TextQuery(std::ifstream&);
	 QueryResult query(const std::string&) const;
};

TextQuery::TextQuery(std::ifstream& is) {

}

QueryResult TextQuery::query(const std::string& sought) const {

}
