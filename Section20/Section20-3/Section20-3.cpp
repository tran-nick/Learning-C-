// Section20-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#include <limits>
#include <map>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <string>
#include <sstream>


void print_header() {
    std::cout << std::setw(12) << std::left << "Word"
        << std::setw(7) << std::left << "Count"
        << std::endl;
    std::cout << std::setw(19) << std::setfill('=') << "="
        << std::endl;
    //reset back to whitespace
    std::cout << std::setfill(' ');
}

void display(const std::map<std::string , int>& m) {
    print_header();

    for (auto const& elem : m)
        std::cout << std::setw(12) << std::left << elem.first
        << std::setw(7) << std::left << elem.second
        << std::endl;

}

void display(const std::map<std::string, std::set<int>>& words) {

    std::cout << std::setw(12) << std::left << "\nWord"
        << "Occurrences" << std::endl;
    std::cout << "=====================================================================" << std::endl;
    for (auto pair : words) {
        std::cout << std::setw(12) << std::left << pair.first
            << std::left << "[ ";
        for (auto i : pair.second)
            std::cout << i << " ";
        std::cout << "]" << std::endl;
    }

}

std::string make_upper(std::string& word) {

    for (auto& letter : word) {
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

void log_out(const std::map<std::string, int>& m, std::ofstream &out) {
    out << std::setw(12) << std::left << "Word"
        << std::setw(7) << std::left << "Count"
        << std::endl;
    out << std::setw(19) << std::setfill('=') << "="
        << std::endl;
    //reset back to whitespace
    out << std::setfill(' ');

    for (auto const& elem : m)
        out << std::setw(12) << std::left << elem.first
        << std::setw(7) << std::left << elem.second
        << std::endl;
}

std::string clean_string(const std::string& s) {
    std::string result;
    for (char c : s) {
        if (c == '.' || c == ',' || c == ';' || c == ':')
            continue;
        else
            result += c;
    }
    return result;
}

//implement using my own way
//output result into text file so I can debug.
void part1() {
    std::map<std::string, int> m;
    std::ofstream out_file{ "results_part1.txt" };
    std::ifstream in_file{ "words.txt" };
    std::string word;

    if (!in_file) {
        std::cerr << "File not found!" << std::endl;
    }
    if (!out_file) {
        std::cerr << "Could not find out file" << std::endl;
    }
    else {
        
        while (in_file >> word) {
            std::string key{ clean_string(word) };
            //if key does not exist, it will be added with subscript access method
            m[key]++;
            //clear stream 
            in_file.clear();
        }

        display(m);
        log_out(m, out_file);

        in_file.close();
    }
}


//implement using starter code provided
void part2() {
    std::map<std::string, std::set<int>> words;
    std::string line;
    std::string word;
    std::ifstream in_file{ "words.txt" };
    if (in_file) {

        //my code
        int line_count{ 0 };

        while (std::getline(in_file, line)) {
            line_count++;
            std::istringstream iss{ line };

            while (iss >> word) {

                std::string key = clean_string(word);
                //if key does not exist, it will be added with subscript access method
                words[key].insert(line_count);
              
            }

        }
        in_file.close();
        display(words);
    }
    else {
        std::cerr << "error opening input file" << std::endl;
    }
}




int main()
{

    part1();
    part2();

    return 0;

}

