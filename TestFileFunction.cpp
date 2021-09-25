#include <iostream>
#include <fstream>
#include <string>

int main() {

    std::string test_variable, test_array[4];
    std::fstream file;

    /* file.open("file.test", std::ios::out);

    file << "Hello world!";
    
    file.close(); */

    file.open("file.test", std::ios::in);

    for (int i=0; i<=4; i++) {
        getline(file, test_array[i]);
    }

    for (int i =0; i<=4; i++) {
        std::cout << test_array[i] << std::endl;
    }

    file.close();

    //std::cout << test_variable;

    return 0;
}