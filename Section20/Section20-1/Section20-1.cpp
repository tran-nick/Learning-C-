// Section20-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <iomanip>



bool is_palindrome(const std::string& s)
{
    //reverse the string and compare
    //std::deque<char> temp{};
    //std::deque<char> reverse{};

    //for (const auto& letter : s) {
    //    //removes whitespace and special characters
    //    if (std::isalpha(letter)) {
    //        temp.push_back(std::toupper(letter));
    //        reverse.push_front(std::toupper(letter));
    //    }
    //}

    ////lexically compare values in deque
    //return temp == reverse;


    //method 2, if palindrome, deq size will eliminate to 0 (string length even)
    //or to 1 (string length odd). 
    std::deque<char> deq{};
    for (auto const& letter : s)
        if(std::isalpha(letter))
            deq.push_back(toupper(letter));

    char c1{};
    char c2{};

    while (deq.size() > 1) {
        c1 = deq.front();
        c2 = deq.back();
        if (c1 != c2)
            return false;
        //if true, process letters and run loop again. 
        deq.pop_back();
        deq.pop_front();
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

