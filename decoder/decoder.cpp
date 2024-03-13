#include <iostream>
#include <vector>
#include <fstream>
#include <string>


class Huffman_Decoder {
	std::vector <std::pair<std::string, std::string>> Table;
public:
	Huffman_Decoder() {}
	void Parsing(std::string table) {
		while (table.size() > 1) {
			std::pair<std::string, std::string> current_pair;
		
			current_pair.first = table.substr(0, 1);
			table.erase(0, 2);
			int del_pos = table.find(':');
			current_pair.second = table.substr(0, del_pos - 1);
			table.erase(0,current_pair.second.size());
			

			this->Table.push_back(current_pair);
		}
	}

	void Decoding(std::string input_code) {
		std::string answer;
		int poz = 0;
		while (poz != input_code.size()) {
			for (auto el : this->Table) {
				if (input_code.substr(poz, el.second.size()) == el.second) {
					answer.append(el.first);
					poz += el.second.size();
				}
			}
		}
		std::cout << answer << std::endl;
	}

};

int main() {
	
	std::ifstream file_in("out.txt");
	std::string file_in_table;
	std::getline(file_in, file_in_table);

	Huffman_Decoder decoder;
	decoder.Parsing(file_in_table);
	decoder.Decoding("111100011010101100");
	return 0;
}
