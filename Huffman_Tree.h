#pragma once
#include <iostream>
#include <vector>

struct Node {
	std::pair <std::string, int> value;
	Node* left; Node* right;

	Node(std::string ch, int value);
};


class Huffman_Encoding {
	std::vector <Node*> Encode_Vector;
	

	Huffman_Encoding();
	void Fill_Vector(std::vector <char> text);
		
};
