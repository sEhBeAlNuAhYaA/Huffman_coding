#include <iostream>
#include <vector>
#include <string>
#include "Huffman_Tree.h"

int main() {
	Huffman_Encoding encode;

	std::string input_text;
	std::cout << "Input text: ";
	std::getline(std::cin, input_text);

	encode.Encoding(textsorting::count_frequency(input_text));
	std::cout << encode.Entropy_Counter(textsorting::count_frequency(input_text)) << std::endl;
	encode.getHuffmanCode();
	encode.PrintHuffmanCodeTable();
	encode.PrintEncodeText(input_text);
	encode.WriteInFile("decoder\\out.txt");
	return 0;
}