#pragma once

#include <string>

class FNNode {
public:
	std::string fname;
	char gender;
	int popularity;
	FNNode* previous;
	FNNode* next;

	int method();
};
