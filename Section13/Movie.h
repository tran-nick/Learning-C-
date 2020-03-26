#pragma once
#include <string>

class Movie
{
private:
	std::string name;
	std::string rating;
	int num_watched;

public:

	void set_name(std::string name_val);
	std::string get_name();

	void set_rating(std::string rating_val);
	std::string get_rating();

	void watched();
	int get_watched();

	//constructor with defaults parameters
	Movie(std::string name_val = "", std::string rating_val = "", int num_watched_val = 0);

	//copy constructor
	Movie(const Movie& source);

};
