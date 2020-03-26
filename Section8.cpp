#include <iostream>

using namespace std;

int main()
{
	/*
	Prompt use for cents
	Calculate change in coins by largest to smallets, prioritizing biggest coins first
	Print response
	*/

	int cents{}, dollars{}, quarters{}, dimes{}, nickels{}, pennies{};
	int dollar_val{ 100 }, quarter_val{ 25 }, dimes_val{ 10 }, nickel_val{ 5 }, pennies_val{ 1 };

	cout << "Enter an amount in cents: ";
	cin >> cents;
		
	dollars = cents / dollar_val;
	quarters = (cents % dollar_val) / quarter_val;
	dimes = (cents % quarter_val) / dimes_val;
	nickels = (cents % dimes_val) / nickel_val;
	pennies = (cents % nickel_val) / pennies_val;


	cout << "You can provide this change as follows: " << endl;
	cout << "Dollars: " << dollars << endl;
	cout << "Quarters: " << quarters << endl;
	cout << "Dimes: " << dimes << endl;
	cout << "Nickels: " << nickels << endl;
	cout << "Pennies: " << pennies << endl;


}