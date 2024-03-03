#include "Huffman_Tree.h"

Node::Node(std::string ch, int value) {
	this->value.first = ch;
	this->value.second = value;
	this->left = nullptr;
	this->right = nullptr;
}

Huffman_Encoding::Huffman_Encoding(){}
void Huffman_Encoding::Fill_Vector(std::vector<char>text) {
	
}
