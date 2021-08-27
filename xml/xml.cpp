
#include "../include/xml.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

//XML parser class. An error returns 1. Succes means 0.

int     parse(std::string fl) {
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
        std::cout << next << std::endl;
    }
    fin.close();
    return (0);
}

int     XML::cparse_xml(std::string str) {
    this->filename = str;
    this->error = parse(this->filename);
    return (this->error);
}
