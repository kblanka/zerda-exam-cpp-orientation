#include <iostream>
#include <string>
#include <fstream>
#include "cypher.h"

Cypher::Cypher() {
}

bool Cypher::run_cypher_and_copy_to_file(string file_from, string file_to, int shift_num) {
	ifstream inputFile;
	inputFile.open(file_from);
	ofstream outputFile;
	outputFile.open(file_to);
	if (inputFile.is_open() && outputFile.is_open()) {
		string line;
		while (getline(inputFile, line)) {
			outputFile << cypher_converter(line, shift_num) << "\n";
		}
		inputFile.close();
		outputFile.close();
		return true;
	}
	else {
		return false;
	}
}

string Cypher::cypher_converter(string original_text, int shift_num) {
	string cypher_text;
	char word_to_shift;
	char buffer_word = 'a';
	for (int i = 0; i < original_text.size(); i++) {
		word_to_shift = original_text[i];
		if (isalpha(word_to_shift)) {
			if (islower(word_to_shift)) {
				buffer_word = 'a';
			}
			else {
				buffer_word = 'A';
			}
			word_to_shift = (word_to_shift - buffer_word + shift_num) % 26 + buffer_word;
		}
		cypher_text += word_to_shift;
	}
	return cypher_text;
}

Cypher::~Cypher() {
}