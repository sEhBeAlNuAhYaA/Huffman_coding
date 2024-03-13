#include "Huffman_Tree.h"

std::vector <std::pair<std::string, int>> textsorting::count_frequency(std::string input_text) {
	
	std::vector <std::pair<std::string, int>> freq_map;
	
	std::string prev_symb;

	for (auto ch : input_text) {
		std::pair<std::string, int> current_pair;
		if (std::find(prev_symb.begin(), prev_symb.end(), ch) == prev_symb.end()) {
			current_pair.first += ch;
			prev_symb += ch;
			current_pair.second = std::count(input_text.begin(), input_text.end(), ch);
			freq_map.push_back(current_pair);
		}
	}
	return freq_map;

}


Node::Node() {
	this->left = nullptr;
	this->right = nullptr;
}
Node::Node(std::string ch, int value) {
	this->value.first = ch;
	this->value.second = value;
	this->left = nullptr;
	this->right = nullptr;
}


Huffman_Encoding::Huffman_Encoding(){}
void Huffman_Encoding::Fill_Vector(std::vector <std::pair <std::string, int>> vector) {
	for (auto el : vector) {
		Node* node = new Node;
		node->value.first = el.first;
		node->value.second = el.second;
		this->Encode_Vector.push_back(node);
	}
}
void Huffman_Encoding::Encoding(std::vector <std::pair <std::string, int>> vector) {

	this->Fill_Vector(vector);
	this->sort_Vector();
	while (this->Encode_Vector.size() != 1) {
		this->Encode_Vector[this->Encode_Vector.size() - 2] =
			this->Nodes_addition(this->Encode_Vector[this->Encode_Vector.size() - 1],
				this->Encode_Vector[this->Encode_Vector.size() - 2]);
		this->Encode_Vector.erase(this->Encode_Vector.end() - 1);
		this->sort_Vector();
	}

}
Node* Huffman_Encoding::Nodes_addition(Node* node1, Node* node2) {
	Node* final_Node = new Node;
	if (node1->value.second > node2->value.second) {
		final_Node->left = node1;
		final_Node->right = node2;
		final_Node->value.first = node1->value.first + node2->value.first;
		node1->binary += '1';
		node2->binary += '0';
	}
	else {
		final_Node->right = node1;
		final_Node->left = node2;
		final_Node->value.first = node2->value.first + node1->value.first;
		node1->binary += '0';
		node2->binary += '1';
	}
	final_Node->value.second = node1->value.second + node2->value.second;
	return final_Node;
}
std::vector <std::pair<std::string, std::string>> Huffman_Encoding::getHuffmanCode(){
	//coding table

	for (char ch : this->Encode_Vector[0]->value.first) {

		std::string el;
		el += ch;

		Node* node = this->Encode_Vector[0];

		std::pair <std::string, std::string> symbol;

		while (el != node->value.first) {
			if (node->left != nullptr && std::find(node->left->value.first.begin(),
				node->left->value.first.end(), ch) != node->left->value.first.end()) {
				node = node->left;
				symbol.second += node->binary;

				continue;
			}
			else {
				if (node->right != nullptr) {
					node = node->right;
					symbol.second += node->binary;
				}
				continue;
			}
		} 
		symbol.first = el;
		this->Table.push_back(symbol);
	}
	return this->Table;
}
void Huffman_Encoding::sort_Vector() {
	std::sort(this->Encode_Vector.begin(), this->Encode_Vector.end(), 
		[](Node* a, Node* b) {return a->value.second > b->value.second; });
}
void Huffman_Encoding::PrintHuffmanCodeTable() {
	for (auto el : this->Table) {
		std::cout << el.first << ": " << el.second << std::endl;
	}
}
void Huffman_Encoding::PrintEncodeText(std::string input_text) {
	for (auto ch : input_text) {
		std::cout << this->Table[std::distance(this->Table.begin(), 
			std::find_if(this->Table.begin(), this->Table.end(), 
			[&ch](std::pair<std::string, std::string> vec) {
			std::string str;
			str += ch;
			return vec.first == str; }))].second << " ";
	}
}
void Huffman_Encoding::WriteInFile(std::string file_name) {
	std::ofstream file_out(file_name);
	for (auto el : this->Table) {
		file_out << el.first << ":" << el.second;
	}
	file_out.close();
}
float Huffman_Encoding::Entropy_Counter(std::vector <std::pair <std::string, int>> vector) {
	int sum = 0;
	int Pi = 0;
	float answer = 0;
	std::vector <float> propability;
	for (auto el : vector) {
		sum += el.second;
	}
	for (auto el : vector){
		propability.push_back((float)el.second / (float)sum);
		answer -= propability[propability.size()-1] * log2(propability[propability.size()-1]);

	}
	
	return answer;
}
