// Section19-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "FileNotFoundException.h"


using namespace std;

//prototyping
void ruler();
void print_header();
void print_avg(double total, int students);
void print_student(std::string name, int score);
int  get_score(std::string answer, std::string response);

const int left_col{ 10 };
const int mid_col{ 5 };
const int right_col{ 6 };

int main()
{
    ifstream in_file;
    string line;
    string answers;
    string name;
    string response;
    double total{0};
    int students{ 0 };
     
    

    //attempting challenge excercise using exception and handling
    try {
        in_file.open("response.txt");
        if (!in_file) {
            throw FileNotFoundException();
        }
        
        print_header();

        //set first line to answers string
        in_file >> answers;
        
        while (in_file >> name >> response) {
           int score = get_score(answers, response);
           total += score;
           students++;
           print_student(name, score);
                      
        }

        in_file.close();

        print_avg(total , students);

    }
    catch (FileNotFoundException& ex) {
        cerr << ex.what() << endl;
    }


    return 0;
}

void print_student(std::string name, int score) {
    cout << setw(left_col) << left << name
        << setw(mid_col) << left << " "
        << setw(right_col) << right << score
        << endl;
}

int get_score(std::string answer , std::string response) {
    int score{ 0 };
    for (size_t i{ 0 }; i < answer.length(); i++) {
        if (answer[i] == response[i])
            score++;
    }
    return score;
}

void print_header() {
    
    cout << setw(left_col) << left << "Student"
        << setw(mid_col) << " "
        << setw(right_col) << right << "Score"
        << endl;
    ruler();
}


void ruler() {
    cout << "---------------------" << endl;
}

void print_avg(double total , int students) {

    ruler();
    cout << setw(left_col) << left << "Average"
        << setw(mid_col) << left << "score"
        << setw(right_col) << right << total / students
        << endl;
}
