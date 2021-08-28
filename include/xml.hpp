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

#ifndef CPARSE_XML
# define CPARSE_XML

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <map>

class XML {
    private:
        std::string                         filename;
        std::vector<std::string>            key;
        std::vector<std::string>            value;
        std::map<std::string, std::string>  dictionary;
        std::string                         input;
        int                                 error;
    public:
        int     cparse_xml(std::string str);
        int     parse(std::string fl);
        void    make_copy(std::string);
        void    get_values(std::string str);
        void    get_keys(std::string str);
};

#endif