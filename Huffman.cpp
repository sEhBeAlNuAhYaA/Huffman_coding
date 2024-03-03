#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Huffman_Tree.h"

int main() {
	Huffman_Encoding encode;

	std::string input_text;
	std::cout << "Input text: ";
	std::getline(std::cin, input_text);
	
	encode.Encoding(textsorting::count_frequency(input_text));
	encode.getHuffmanCode();
	encode.PrintHuffmanCodeTable();
	encode.PrintEncodeText(input_text);


	return 0;
}