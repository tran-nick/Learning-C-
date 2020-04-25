// Section19-4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

int main()
{
    std::ifstream in_file{ "romeoandjuliet.txt" };
    std::ofstream out_file{"copy_numbered.txt"};

    if (!in_file) {
        std::cerr << "Could not open file!" << std::endl;
        return 1;
    }
    if (!out_file) {
        std::cerr << "Could not find out file!" << std::endl;
        return 1;
    }

    std::string line{};
    int line_count{ 1 };

    while (std::getline(in_file, line)) {
        if (line.empty()) {
            //if first char is whitespace, print line 
            out_file << line << std::endl;
        }
        //else add line number and line
        else {
            out_file << std::setw(4) << std::left << line_count
                << line
                << std::endl;
            line_count++;
        }
    }

    std::cout << "File copied!" << std::endl;

    in_file.close();
    out_file.close();

    return 0;

}

