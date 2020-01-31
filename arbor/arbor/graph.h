#pragma once
#include <map>
#include <string>
using namespace std;
class graph: map<string, map<string, int>>
{
public:
	graph();
	void quitar(string);
	~graph();
};

