// Section19-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct City {
    std::string name;
    long population;
    double cost;
};

struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

void print_headers() {
    cout << setw(15) << left << "Country"
         << setw(15) << left << "City"
         << setw(15) << right << "Population"
         << setw(15) << right << "Price "
         << endl;
};

void print_line() {
    cout << setw(59) << setfill('-') << "-" << endl; //width of 60 -1 for final output
};


//setting print width to 60
int main()
{

    Tours tours
    { "Tour Ticket Prices from Miami",
        {
            {
                "Colombia", {
                    { "Bogota", 8778000, 400.98 },
                    { "Cali", 2401000, 424.12 },
                    { "Medellin", 2464000, 350.98 },
                    { "Cartagena", 972000, 345.34 }
                },
            },
            {
                "Brazil", {
                    { "Rio De Janiero", 13500000, 567.45 },
                    { "Sao Paulo", 11310000, 975.45 },
                    { "Salvador", 18234000, 855.99 }
                },
            },
            {
                "Chile", {
                    { "Valdivia", 260000, 569.12 },
                    { "Santiago", 7040000, 520.00 }
            },
        },
            { "Argentina", {
                { "Buenos Aires", 3010000, 723.77 }
            }
        },
    }
    };

    size_t middle_print_spacing{ tours.title.length() / 2 };
    //divide print width by half and add half of str length to get middle print
    //setting print width to 60 because divisble by 4 columns evenly
    cout << setw(30 + middle_print_spacing) << right << tours.title << endl << endl;
    print_headers();
    print_line();

    cout << setfill(' '); //change fill back from '-' to ' '


    for (auto country : tours.countries) {
        cout << setw(15) << left << country.name;
        size_t index{ 0 }; //reset when we print new country name
        for (auto city : country.cities) {
            if (index == 0) {
                cout << setw(15) << left << city.name
                    << setw(15) << right << city.population
                    << setw(15) << right << setprecision(2) << fixed << city.cost
                    << endl;
                index++;
            }
            else {
                cout << setw(15) << left << " "
                    << setw(15) << left << city.name
                    << setw(15) << right << city.population
                    << setw(15) << right << setprecision(2) << fixed << city.cost
                    << endl;
            }

        }
    }



    //// Unformatted display so you can see how to access the vector elements
    //std::cout << tours.title << std::endl;
    //for (auto country : tours.countries) {   // loop through the countries
    //    std::cout << country.name << std::endl;
    //    for (auto city : country.cities) {       // loop through the cities for each country
    //        std::cout << "\t" << city.name
    //            << "\t" << city.population
    //            << "\t" << city.cost
    //            << std::endl;
    //    }
    //}

    std::cout << std::endl << std::endl;
    return 0;
    
}
