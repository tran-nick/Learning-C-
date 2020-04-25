// Section19-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "NoFileFoundException.h"


std::string make_upper(std::string &word) {
    
    for (auto &letter : word) {
        letter = std::toupper(letter);
    }
    return word;
}

std::string make_lower(std::string& word) {

    for (auto& letter : word) {
        letter = std::tolower(letter);
    }
    return word;
}



int main()
{


    std::ifstream in_file;
    std::string search;
    std::string key;
    int count{ 0 };
    int total{ 0 };

    try {
        in_file.open("romeoandjuliet.txt");
        if (!in_file) {
            throw NoFileFoundException();
        }

        std::cout << "Enter the substring to search for: ";
        std::cin >> key;

        while (in_file >> search) {


            if (make_upper(search) == make_upper(key)) {
                count++;
            }
            total++;
        }

        std::cout << total << " words were searched..." << std::endl;
        std::cout << "The substring " << key << " was found "
            << count << " times"
            << std::endl;

        in_file.close();
    }
    catch (NoFileFoundException& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
    
}

