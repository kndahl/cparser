
#include "include/json.hpp"
#include "include/xml.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

int     main(void) {
    XML             xml_input;
    xml_input.cparse_xml("samples/1.xml");
    return (0);
}