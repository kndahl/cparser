
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

// root
//     add
//         Source_Data
//             Product  : Alice Mutton
//             Customer : ANTON
//             Qtr_2    : $702.00
//         Info
//             Adress   : Some adress
//             Index    : 121087
//     c
//         v
//             fun      : FU

void    XML::make_copy(std::string str) {
    this->input.append(str);
}

void    XML::get_keys(std::string str) {
    std::string     key;
    std::string::size_type    start_position = 0;
    std::string::size_type    end_position = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '>')
            start_position = i + 1;
        if (str[i] == '<') {
            if (str[++i] == '/') {
                end_position = --i;
                break ;
            }
        }
    }
    key = str.substr(start_position, end_position - start_position);
    this->key.push_back(key);
}

void    XML::get_values(std::string str) {
    std::string                 close_event;
    std::string                 value;
    std::string                 exception = "<?xml";
    std::string::size_type    start_position = 0;
    std::string::size_type    end_position = 0;
    int         x; // Open of block
    int         y; // Close of block
    int         key_length;
    int         is_block;

    if (str.find(exception) != -1)
            return ; 
    for (int n = 0; n < this->blocks.size(); n++) {
        is_block = str.find(this->blocks[n]);
        if (is_block != -1) {
            return ;
        }
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '<')
            start_position = i + 1;
        if (str[i] == '>') {
            end_position = i;
            break ;
        }
    }
    value = str.substr(start_position, end_position - start_position);
    this->value.push_back(value);
    get_keys(str);
}

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
        make_copy(next);
        get_blocks(next);
        get_values(next);
    }
    fin.close();
    return (0);
}

int     XML::cparse_xml(std::string str) {
    this->filename = str;
    this->error = parse(this->filename);


    std::cout << "Made copy of XML: " << this->input << std::endl;
    std::cout << "Blocks number: " << this->blocks.size() << std::endl;
    std::cout << "Blocks names: " << std::endl;
    for(int i = 0; i < this->blocks.size(); i++)
		std::cout << '\t' << this->blocks[i] << std::endl;
    std::cout << "Values number: " << this->value.size() << std::endl;
    std::cout << "Values names: " << std::endl;
    for(int i = 0; i < this->value.size(); i++)
		std::cout << '\t' << this->value[i] << std::endl;
    std::cout << "Key number: " << this->key.size() << std::endl;
    std::cout << "Key names: " << std::endl;
    for(int i = 0; i < this->key.size(); i++)
		std::cout << '\t' << this->key[i] << std::endl;

    return (this->error);
}
