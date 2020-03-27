#include <iostream>
#include <string>

using namespace std;

int main()
{
	
	string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ " }; //include whitespace swap @ end
	string key{ "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM " };
	   	
	cout << "Enter a secret message: " << endl;
	string secret_message;
	getline(cin, secret_message);

	string encrypt_message;

	//encrypting the message
	for (auto letter : secret_message) {

		//for each char in message string, find index of letter in alphabet string
		size_t i = alphabet.find(letter);

		//then using same index, concatenate letter at index from key string
		encrypt_message += key.at(i);	

	}

	cout << "The encrypted message is : " << encrypt_message << endl;
	cout << "The original message is : " << secret_message << endl;

	string decrypt_message;
	//decrypting the message 
	for (auto letter : encrypt_message)
	{
		size_t i = key.find(letter);

		decrypt_message += alphabet.at(i);

	}

	cout << "-------------------------------" << endl;
	cout << "The encrypted message is : " << encrypt_message << endl;
	cout << "The decrypt_message message is : " << decrypt_message << endl;






}