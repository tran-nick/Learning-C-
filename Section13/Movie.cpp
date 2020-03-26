
#include "Movie.h"

using namespace std;

void Movie::set_name(string name_val) {
	name = name_val;
}

string Movie::get_name() {
	return name;
}

void Movie::set_rating(string rating_val){
	rating = rating_val;
	}

string Movie::get_rating() {
		return rating;
	}

void Movie::watched() {
	num_watched++;
}

int Movie::get_watched(){
	return num_watched;
}

//constructor
Movie::Movie(string name_val , string rating_val , int num_watched_val)
	: name{ name_val }, rating{ rating_val }, num_watched{ num_watched_val }{

}

//copy constructor
Movie::Movie(const Movie &source)
	:name{ source.name }, rating{ source.rating }, num_watched{ source.num_watched }{
}

//destructor - do you still have to implement if the destructor doesn't have to do anything extra
//beyond default behavior?


