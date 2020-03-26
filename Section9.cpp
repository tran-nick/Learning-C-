#include <iostream>
#include <vector>


using namespace std;

void print_menu() {

	cout << "P - Print numbers" << endl;
	cout << "A - Add numbers" << endl;
	cout << "M - Display mean of the numbers" << endl;
	cout << "S - Display the smallest number" << endl;
	cout << "L - Display the largest number" << endl;
	cout << "Q - Quit" << endl;
	cout << endl;
	cout << "Enter your choice: ";

}


int main()
{
	vector<int> list;
	char response;
	bool run{ true };

	while (run)
	{
		print_menu();
		cin >> response;

		switch (response) { 

		case 'P':
		case 'p':
		{
			if (list.empty()) {
				cout << "[] - the list is empty." << endl;
			} else 
			{
				cout << "[ ";
				for (auto num : list) 
				{
					cout << num << " ";
				}
				cout << "]" << endl;

			}
			cout << endl;
		}
		break;

		case 'A':
		case 'a':
		{
			int new_int{ 0 };
			cout << "Enter number to add: ";
			cin >> new_int;
			cout << endl;

			list.push_back(new_int);

			cout << "Number " << new_int << " has been added to list." << endl;
			cout << endl;
		}
		break;

		case 'm':
		case 'M':
		{
			int sum{ 0 }; // initialize to first element of list
			int mean{ 0 };

			if (list.empty()) {
				cout << "Unable to calculate the mean - no data" << endl;
			}
			else {
				for (auto num : list) {
					sum += num;
				}

				mean = sum / list.size();

				cout << "The mean of the list is " << mean << endl;
				cout << endl;
			}
		}
		break;

		case 'S':
		case 's':
		{
			int smallest{ list[0] }; // initialize to first element of list

			for (auto num : list) {
				if (num < smallest) {
					smallest = num;
				}
			}

			cout << "The smallest in the list is " << smallest << endl;
			cout << endl;
		}
		break;

		case 'L':
		case 'l':
		{
			int largest{ 0 };

			for (auto num : list) {
				if (num > largest) {
					largest = num;
				}
			}

			cout << "The largest in the list is " << largest << endl;
			cout << endl;
		}
		break;

		case'Q':
		case 'q':
		{
			cout << "Goodbye" << endl;
			run = false;
		}
		break;

		default:
		{	cout << "Sorry, not a valid entry" << endl;
		cout << endl;
		}
		break;

		}


		
	}
	return 0;
}
