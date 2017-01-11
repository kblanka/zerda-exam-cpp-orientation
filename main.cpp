#include <iostream>
#include <string>
#include <fstream>
#include "cypher.h"

using namespace std; 

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "cypher.h"

TEST_CASE("Cypher::cypher_converter _ can shift alphabets") {
	string test_word = "a";
	Cypher test_case;
	REQUIRE(test_case.cypher_converter(test_word, 1) == "b");
}

TEST_CASE("Cypher::cypher_converter _ can shift alphabets, after abc ended, begin from a") {
	string test_word = "z";
	Cypher test_case;
	REQUIRE(test_case.cypher_converter(test_word, 3) == "c");
}

TEST_CASE("Cypher::cypher_converter _ is case sensitive") {
	string test_word = "Bring";
	Cypher test_case;
	REQUIRE(test_case.cypher_converter(test_word, 1) == "Csjoh");
}

TEST_CASE("Cypher::cypher_converter _ not change the numbers, whitespace charactes(tabs, spaces, new lines) and any punctuation") {
	string test_word = "Bring a small pan 2 me!";
	Cypher test_case;
	REQUIRE(test_case.cypher_converter(test_word, 1) == "Csjoh b tnbmm qbo 2 nf!");
}

TEST_CASE("Cypher::run_cypher_and_copy_to_file _ can finish") {
	string test_word = "Case";
	Cypher test_case;
	REQUIRE(test_case.run_cypher_and_copy_to_file("original_text_file.txt", "cypher_text_file.txt", 4));
}



int main(int argc, char * const argv[]) {
	Cypher test;
	test.run_cypher_and_copy_to_file("original_text_file.txt", "cypher_text_file.txt", 1);
}