#pragma once

#include "Movie.h"
#include <string>
#include <vector>


class Movies
{
private:
	std::vector <Movie> movie_list;

public:

	bool increment_watched(std::string movie_name);
	
	bool add_movie(std::string name_val, std::string rating_val, int num_watched_val);

	void display();
	
	//constructor
	Movies();

};
