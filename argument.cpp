#include <iostream>
#include "argument.h"
using namespace std;

Argument::Argument(int argc, char* argv[], string input_filename) {
	this->argc = argc;
	this->argv = argv;
	this->input_filename = input_filename;
}

void Argument::run() {
	if (argc == 1) {
		string _input;
		set_input_filename(_input);
	}
	else if (argc > 1) {
		select_function();
	}
}

void Argument::select_function() {
	string _output,
	int _shift_num;
	if (is_valid_selector()) {
		if (argv[1] == "-s") {
			cin >> _shift_num;
			set_shift_num(_shift_num);
		}
		else if (argv[1] == "-o") {
			cin >> _output;
			set_output_filename(_output);
		}
		else {
			cerr << "Unsupported argument.\n";
		}
		if (argv[2] == "-o") {
			cin >> _output;
			set_output_filename(_output);
		}
		else if (argv[2] == "-s") {
			cin >> _shift_num;
			set_shift_num(_shift_num);
		}
		else {
			cerr << "Unsupported argument.\n";
		}
	}
}

bool Argument::is_valid_selector() {
	string selector = argv[1];
	if (selector != "a.out" && selector != "-s" && selector != "-o") {
		cerr << "Unsupported argument.\n";
		return false;
	}
	else {
		return true;
	} 
}

string Argument::get_input_filename() {
	return input_filename;
}

string Argument::set_input_filename(string _input) {
	input_filename = _input;
}

string Argument::get_output_filename() {
	return output_filename;
}

string Argument::set_output_filename(string _output) {
	output_filename = _output;
}

int Argument::get_shift_num() {
	return shift_num;
}

int Argument::set_shift_num(int _num) {
	shift_num = _num;
}

Argument::~Argument() {}