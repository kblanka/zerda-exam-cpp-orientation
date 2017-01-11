#pragma once
#include <string>

using namespace std;

class Argument {
public:
	Argument(int argc, char* argv[], string input_filename);
	void run();
	void select_function();
	bool is_valid_selector();
	string get_input_filename();
	string set_input_filename(string _input);
	string get_output_filename();
	string set_output_filename(string _output);
	int get_shift_num();
	int set_shift_num(int _num);
	~Argument();
private:
	int argc;
	char** argv;
	string input_filename, output_filename;
	int shift_num;
};