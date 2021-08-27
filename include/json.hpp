
#ifndef CPARSE_JSON
# define CPARSE_JSON

#include <iostream>
#include <string>

class JSON {
    private:
        std::string filename;
        int         error;
    public:
        int cparse_json(std::string str);
};

#endif