#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

namespace textsorting {
	
	std::vector <std::pair<std::string, int>> count_frequency(std::string input_text);
}

static struct Node {
	std::pair <std::string, int> value;
	std::string binary;
	Node* left; Node* right;
	Node();
	Node(std::string ch, int value);
};

class Huffman_Encoding {
	std::vector <Node*> Encode_Vector;
	std::vector <std::pair<std::string, std::string>> Table;
public:
	Huffman_Encoding();
	void Encoding(std::vector <std::pair <std::string, int>> vector);
	std::vector <std::pair<std::string, std::string>> getHuffmanCode();	
	void PrintHuffmanCodeTable();
	void PrintEncodeText(std::string input_text);
	void WriteInFile(std::string);
	float Entropy_Counter(std::vector <std::pair <std::string, int>> vector);
private:
	void Fill_Vector(std::vector <std::pair <std::string, int>> vector);
	Node* Nodes_addition(Node* node1, Node* node2);
	void sort_Vector();
};
