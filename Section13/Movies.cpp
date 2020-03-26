
#include "Movies.h"
#include <iostream>

using namespace std;


bool Movies::increment_watched(string movie_name) {
	//check vector for movie by name
	for (auto movie : movie_list) {
		if (movie_name == movie.get_name()) {
			movie.watched();
			//increment and break here if found
			return true;
		} 
	}
	//else for loop will go out of scope and return false
	return false;
}

void Movies::display() {

	size_t list_size{ movie_list.size() };

	if (list_size == 0) {
		cout << "Sorry, no movies to display" << endl;
	}
	else {

		//returns names on list before last one
		for (size_t i{ 0 }; i < list_size - 1; i++) {
			cout << movie_list[i].get_name() << ", ";
		}
		//return name of last movie in list
		cout << movie_list[list_size - 1].get_name() << endl;
	}
}

bool  Movies::add_movie(std::string name_val, std::string rating_val, int num_watched_val){

	bool already_exist{false};

	//run through list to see if movie exist by name first - assume all movie names are unique
	for (auto movie : movie_list) {
		if (movie.get_name() == name_val) {
			already_exist = true;
			//break here, no need to continue;
			return false;
		}
	} 
	//only add if does not exist is true
	if (!already_exist) {
		movie_list.push_back(Movie(name_val, rating_val, num_watched_val));
	}

	return true;
}

//constructor - initialize attribute to empty vector 
Movies::Movies() {
	vector <Movie> movie_list{};
}
