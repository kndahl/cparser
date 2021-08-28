
#ifndef CPARSE_XML
# define CPARSE_XML

#include <iostream>
#include <string>
#include <vector>
#include <array>

class XML {
    private:
        std::string filename;
        std::vector<std::string> blocks;  // TODO: Make it dynamic
        std::string output;
        int         error;
    public:
        int  cparse_xml(std::string str);
        int  parse(std::string fl);
        void get_blocks(std::string str);
};

#endif