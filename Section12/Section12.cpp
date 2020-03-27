#include <iostream>

using namespace std;

void print(int *array_name , size_t array_size);
int *apply_all(int *array1 , size_t array1_size , int *array2 , size_t array2_size);


int main() {

	//main function provided by instructor
	const size_t array1_size{ 5 };
	const size_t array2_size{ 3 };

	int array1[]{ 1,2,3,4,5 };
	int array2[]{ 10,20,30 };

	cout << "Array 1: ";
	print(array1, array1_size);

	cout << "Array 2: ";
	print(array2, array2_size);

	int* results = apply_all(array1, array1_size, array2, array2_size);
	constexpr size_t results_size{ array1_size * array2_size };

	cout << "Results: ";
	print(results, results_size);

	cout << endl;

	return 0;


}

void print(int*const array_name, size_t array_size)
{
	cout << "[ ";
	
	for (size_t i{ 0 }; i < array_size; i++)
	{
		cout << *(array_name + i) << " ";
	}
	
	cout << "]";
	cout << endl;
}



int *apply_all(int* const array1, size_t array1_size, int* const array2, size_t array2_size)
{
	int* new_result{ nullptr };
	size_t new_size{ array1_size * array2_size };

	new_result = new int[new_size] {0};


	size_t index{ 0 };
	while (index < new_size)
	{

		for (size_t i{ 0 }; i < array2_size ; i++)
		{
			for (size_t x{ 0 }; x < array1_size; x++)
			{
				new_result[index] = array2[i] * array1[x]; //subscript notation
				//*(new_result + index) = *(array2 + i) * *(array1 + x); //offset notation alternative
				
				//new_result[index]  = *(array2 + i) * *(array1 + x); // mixing offest and subscript notation works too. 
				//*(new_result + index) = array2[i] * array1[x]; // mixing offest and subscript notation works too. 

				index++;
			}
		}

	}

	return new_result;
}
