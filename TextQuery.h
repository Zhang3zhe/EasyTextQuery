/**
* TextQuery.h
* Copyright (c) 2019-10 https://github.com/Zhang3zhe All rights reserved.
*/
#pragma once
#include"common.h"

class QueryResult;

class TextQuery {
 public:
	 TextQuery(std::ifstream&);
	 QueryResult query(const std::string&) const;
 private:
	 std::shared_ptr<std::vector<std::string>> file;
	 // Word-->line number
	 std::map<std::string, std::shared_ptr<std::set<line_no>>> word_map;
};

TextQuery::TextQuery(std::ifstream& is) : file(new std::vector<std::string>) {
	std::string text;
	while (getline(is, text)) {
		file->push_back(text); // Current line number.
		int no = file->size() - 1;
		std::istringstream line(text); // Split line to words.
		std::string word;
		while (line >> word) {
			auto& lines = word_map[word]; // lines is a shared_ptr.
			if (!lines)	   lines.reset(new std::set<line_no>);
			lines->insert(no);
		}
	}
}

QueryResult TextQuery::query(const std::string& sought) const {
	// If not found, return a pointor to this static empty set.
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	// find() is used to avoid add a element to word_map;
	auto loc = word_map.find(sought);
	if (loc == word_map.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}
