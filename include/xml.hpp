
#ifndef CPARSE_XML
# define CPARSE_XML

#include <iostream>
#include <string>

class XML {
    private:
        std::string filename;
        int         error;
    public:
        int cparse_xml(std::string str);
};

#endif