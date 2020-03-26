//Section 6 
//Challenge


/*
Frank's Carpet Cleaning Service
Charges:
	$25 per small room
	$35 per large room

Sales Tax @ 6%
Estimales valid for 30 days

Prompt users for rooms cleaned and provide estimates


*/

#include <iostream>

using namespace std;


int main() {

	const double small_room{ 25 };
	const double lrg_room{ 35 };
	const double tax_rate{ 0.06 };
	const int expiry{ 30 };


	cout << "Frank's Carpet Cleaning Service" << endl;
	cout << "How many small rooms do you need?: " << endl;

	int small_need{ 0 };
	cin >> small_need;

	cout << "How many large rooms do you need?: " << endl;

	int lrg_need{ 0 };
	cin >> lrg_need;

	cout << "Estimate for carpet cleaning service: " << endl;
	cout << "Number of small rooms: " << small_need << endl;
	cout << "Number of large rooms: " << lrg_need << endl;
	cout << "Price per small room: $" << small_room << endl;
	cout << "Price per large room: $" << lrg_room << endl;
	cout << "Cost: $" << (small_need * small_room) + (lrg_need * lrg_room) << endl;
	cout << "Tax: $" << tax_rate * ((small_need * small_room) + (lrg_need * lrg_room)) << endl;
	cout << "==========================" << endl;
	cout << "Total estimate: $" << (small_need * small_room) + (lrg_need * lrg_room) + (tax_rate * ((small_need * small_room) + (lrg_need * lrg_room))) << endl;
	cout << "This estimate is valid for " << expiry << " days" << endl;

}
