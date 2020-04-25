// Section20-4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cctype>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <iomanip>

bool is_palindrome(const std::string& s)
{
    // You must implement this function.
    // Since we are learning the STL - use a stack and a queue to solve the problem.
    
    std::stack<char> reverse; //LIFO
    std::queue<char> temp; //FIFO
    //remove whitespace and special character
    for (auto const& letter : s)
        if (std::isalpha(letter)) {

            reverse.push(toupper(letter)); //HELLO -> OLLEH
            temp.push(toupper(letter)); //HELLO -> HELLO
        }
    
    char c1{};
    char c2{};
    while (!temp.empty()) {
        c1 = temp.front(); 
        c2 = reverse.top();
        if (c1 != c2)
            return false;

        reverse.pop();
        temp.pop();
    }

    
    return true;
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for (const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
