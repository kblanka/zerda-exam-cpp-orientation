#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Cypher {
public:
	Cypher();
	bool run_cypher_and_copy_to_file(string file_from, string file_to, int shift_num);
	string cypher_converter(string original_text, int shift_num);
	virtual ~Cypher();
};