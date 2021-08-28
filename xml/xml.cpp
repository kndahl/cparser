
// Copyright (c) 2021 Kindly Not Dahl

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "../include/xml.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

//XML parser class. An error returns 1. Succes means 0.

// Сначала парсим и выявляем все блоки.
// Затем парсим каждый блок  в поисках ключей.
// Результат должен быть сохранен в объект, близкий к питоновскому дикту.

//{root: Source_Data: Product, Customer, Qtr_2, Info: Adress, Index} -> expected output

void    XML::make_copy(std::string str) {
    this->input.append(str);
}

void    XML::get_keys(std::string str) {
    // Парсит каждый блок и выписывает его ключи.
    std::string close_event;
    std::string value;
    int         x; // Open of block
    int         y; // Close of block
    int         key_length;

    for (int n = 1; n < this->key.size(); n++) {
        x = str.find(this->key[n]);
        close_event = "</" + std::string(this->key[n]) + '>';
        y = str.find(close_event);
        key_length = this->key[n].length() + 1;
        for (int j = x + key_length; j < y; j++) {
            std::cout << str[j];
        }
        std::cout << std::endl;
    }
}

void    XML::get_values(std::string str) {
    std::string key;

    if (str.find("</") != std::string::npos)
        return ;
    if (str.find("<?") != std::string::npos)
        return ;
    else {
        if (str.find("<") != std::string::npos) {
            key.append(str);
        }
        int start = key.find("<");
        int end = key.find(">");

        key = key.substr(start + 1, end - (start + 1));
        this->key.push_back(key);
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
        make_copy(next);
        get_values(next);
    }
    fin.close();
    get_keys(this->input);
    return (0);
}

int     XML::cparse_xml(std::string str) {
    this->filename = str;
    this->error = parse(this->filename);


    std::cout << "Made copy of XML: " << this->input << std::endl;
    std::cout << "Blocks number: " << this->key.size() << std::endl;
    std::cout << "Blocks names: " << std::endl;
    for(int i = 0; i < this->key.size(); i++)
		std::cout << '\t' << this->key[i] << std::endl;

    return (this->error);
}
