#include <iostream>
#include <vector>


using namespace std;

//Prototyping functions
void display_menu();
char get_choice();
void print_nums(const vector<int> list); // constant to not edit accidently 
void add_number(vector<int> &list); // pass reference to add to actual list
void display_mean(const vector<int> list); // constant to not edit accidently 
void display_largest(const vector<int> list); // constant to not edit accidently 
void display_smallest(const vector<int> list); // constant to not edit accidently 
void exit_prog(bool &run); // pass reference to exit while loop


int main()
{
	vector<int> list{};

	bool run = true;

	while (run) {
		display_menu();

		char response = get_choice();

		switch (response) 
		{
		
		case 'p':
		case 'P': 
			print_nums(list);
			break;
		case 'a':
		case 'A': 
			add_number(list); 
			break;
		case 'm':
		case 'M': 
			display_mean(list);
			break;
		case 'l':
		case 'L': 
			display_largest(list);
			break;
		case 's':
		case 'S': 
			display_smallest(list);
			break;
		case 'q':
		case 'Q': 
			exit_prog(run);
			break;
		default : 
			cout << "That was not a valid choice." << endl;

		}

	}
	  
	cout << "Program has exited. " << endl;
  
return 0;
}

// Display menu options
void display_menu()
{
	cout << endl;
	cout << "P - print numbers" << endl;
	cout << "A - add a number" << endl;
	cout << "M - Display mean of the numbers" << endl;
	cout << "S - Display the smallest number" << endl;
	cout << "L - Display the largest number" << endl;
	cout << "Q - Quit" << endl;
	cout << endl;

}

char get_choice()
{
	char choice{};
	cout << "Enter your choice: ";
	cin >> choice;

	return choice;
}

void print_nums(const vector<int> list)
{
	if (list.empty())
		cout << "The list is empty." << endl;
	else {
		cout << "[";
		for (auto num : list) {
			cout << num << " ";
		}
		cout << "]" << endl;
	}
}

void add_number(vector<int> &list)
{

	int add_num{};
	cout << "Enter number to add: ";
	cin >> add_num;

	list.push_back(add_num);

	cout << endl;

}

void display_mean(vector<int> list) 
{
	if(list.empty())
		cout << "List is empty, add numbers first" << endl;
	else {
		int sum{};
		for (auto num : list) {
			sum += num;
		}

		int mean = sum / list.size();
		cout << "The mean of the list is: " << mean << endl;
	}
}


void display_largest(const vector<int> list) 
{
	if (list.empty())
		cout << "List is empty, add numbers first" << endl;
	else {
		int largest{ list.at(0) }; // initialize to first num on list
		for (auto num : list)
		{
			if (largest < num)
				largest = num;
		}
		cout << "The largest in the list is :" << largest << endl;
	}

}


void display_smallest(const vector<int> list) 
{
	if(list.empty())
		cout << "List is empty, add numbers first" << endl;
	else {
		int smallest{ list.at(0) };
		for (auto num : list) {
			if (smallest > num)
				smallest = num;
		}
		cout << "The smallest in the list is: " << smallest << endl;
	}
}


void exit_prog(bool &run) 
{
	run = false;
	cout << endl;
	cout << "Exiting Program" << endl;
}
