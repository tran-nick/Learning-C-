// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song {
    friend std::ostream& operator<<(std::ostream& os, const Song& s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
        : name{ name }, artist{ artist }, rating{ rating } {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }

    bool operator<(const Song& rhs) const {
        return this->name < rhs.name;
    }

    bool operator==(const Song& rhs) const {
        return this->name == rhs.name;
    }
};

std::ostream& operator<<(std::ostream& os, const Song& s) {
    os << std::setw(20) << std::left << s.name
        << std::setw(30) << std::left << s.artist
        << std::setw(2) << std::left << s.rating;
    return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song& song) {
    std::cout << "Playing:\n" << song << std::endl;
}

void display_playlist(const std::list<Song>& playlist, const Song& current_song) {
    for (const auto& song : playlist)
        std::cout << song << std::endl;
    
    std::cout << "Current song:\n" << current_song << std::endl;
}

void add_song(std::list<Song>::iterator &current_song , std::list<Song> &playlist) {
    
    std::cout << "Adding and playing new song" << std::endl;
    
    //clearing out input stream
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string title {};
    std::cout << "Enter song name:";
    std::getline(std::cin, title);

    std::string artist{};
    std::cout << "Enter song artist:";
    std::getline(std::cin, artist);

    int rating;
    std::cout << "Enter your rating (1-5):";
    std::cin >> rating;

    current_song = playlist.emplace(current_song, title, artist, rating);
    std::cout << std::endl;
    play_current_song(*current_song);

}


void next_song(std::list<Song>::iterator& current_song, std::list<Song>& playlist) {
    //end() reutrn iterator past last element, so need to pre-decrement before you can use
    if (current_song != --playlist.end()) {
         current_song++;
         play_current_song(*current_song);
    }else {
        current_song = playlist.begin();
        play_current_song(*current_song);
    }

}

void prev_song(std::list<Song>::iterator& current_song, std::list<Song>& playlist) {
    if (current_song != playlist.begin()) {
        current_song--;
        play_current_song(*current_song);
    }else {
        current_song = --playlist.end();
        play_current_song(*current_song);
    }
}

void first_song(std::list<Song>::iterator& current_song, std::list<Song>& playlist) {
    current_song = playlist.begin();
    play_current_song(*current_song);
}

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}
    };

    std::list<Song>::iterator current_song = playlist.begin();

    char response{};
    bool listening{ true };

    while (listening) {
        display_playlist(playlist, *current_song);
        std::cout << std::endl;
        display_menu();

        std::cin >> response;
        switch (response){
        case 'F':
        case 'f': {
            first_song(current_song, playlist);
            std::cout << std::endl;
            break;
        }
        case 'N':
        case 'n': {
            next_song(current_song, playlist);
            std::cout << std::endl;
            break;
        }
        case 'P':
        case 'p': {
            prev_song(current_song, playlist);
            std::cout << std::endl;
            break;
        }
        case 'A':
        case 'a': {
            add_song(current_song, playlist);
            std::cout << std::endl;
            break;
        }
        case 'L':
        case 'l': {
            std::cout << std::endl;
            display_playlist(playlist, *current_song);
            std::cout << std::endl;
            break;
        }
        case 'Q':
        case 'q': {
            listening = false;
            std::cout << std::endl;
            break;
        }
        default: {
            std::cout << "That was not a valid response. Please select an option from the menu." << std::endl;
            std::cout << std::endl;
            break;
        }

        }
    }

    std::cout << "Thanks for listening!" << std::endl;
    return 0;

}
