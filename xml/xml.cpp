
#include "../include/xml.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

//XML parser class. An error returns 1. Succes means 0.

// Сначала парсим и выявляем все блоки.
// Затем парсим каждый блок.
// Результат должен быть сохранен в объект, близкий к питоновскому дикту.

void    XML::get_blocks(std::string str) {
    std::string block;

    if (str.find("</") != std::string::npos)
        return ;
    if (str.find("<?") != std::string::npos)
        return ;
    else {
        if (str.find("<") != std::string::npos) {
            block.append(str);
        }
        int start = block.find("<");
        int end = block.find(">");

        block = block.substr(start + 1, end - (start + 1));
        this->blocks.push_back(block);
    }
}

int     XML::parse(std::string fl) {
    std::cout << "File: " << fl << std::endl;
    std::string     next;
    std::ifstream   fin;

    fin.open(fl);

    if (fin.fail()) {
		std::cout << "Input file opening failed." << std::endl;
		return (1);
	}
    while (!fin.eof()) {
        getline(fin, next);
        get_blocks(next);
    }
    fin.close();
    return (0);
}

int     XML::cparse_xml(std::string str) {
    this->filename = str;
    this->error = parse(this->filename);
    std::cout << "Blocks number: " << this->blocks.size() << std::endl;
    std::cout << "Blocks names: " << std::endl;
    for(int i = 0; i < this->blocks.size(); i++)
		std::cout << '\t' << this->blocks[i] << std::endl;
    return (this->error);
}
