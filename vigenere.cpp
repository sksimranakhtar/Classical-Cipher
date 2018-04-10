#include "stdafx.h"
#include <iostream>
#include <string>
#include <Windows.h>


using namespace std;




int encrypt(string plainText, string sneakyText, string key) {


	int k = 0;


	string computerPrank;
	getline(cin, computerPrank);
	
	cout << "Enter plaintext: ";
	getline(cin, plainText);


	cout << "Enter key: ";
	cin >> key;


	for (int i = 0; i < plainText.length(); i++) {
		if (plainText[i] == 32) {
			sneakyText[i] = '\x84';
		}
		else {
			sneakyText[i] = (((plainText[i] - 97) + (key[k] - 97)) % 26)+97;
			k++;
			if (k == key.length()) {
				k = 0;
			}
		}
	}


	cout << endl << "ciphertext: ";


	for (int i = 0; i < plainText.length(); i++) {
		cout << sneakyText[i];
	}


	cout << endl << endl;


	return 0;
}




int decrypt(string plainText, string sneakyText, string key) {


// the sneakyText and plainText in this function have swapped placed since i initialized sneakyText to wwwwwwwww to make the program work but other than that the both variables are exactly the same.


	int k = 0;


	string computerPrank;
	getline(cin, computerPrank);


	cout << "Enter ciphertext: ";
	getline(cin, plainText);


	cout << "Enter key: ";
	cin >> key;


	for (int i = 0; i < plainText.length(); i++) {
		if (plainText[i] == '\x84') {
			sneakyText[i] = 32;
		}
		else {
			sneakyText[i] = (((plainText[i] - 122) - (key[k] - 97)) % 26) + 122;
			k++;
			if (k == key.length()) {
				k = 0;
			}
		}
	}


	cout << endl << "Plaintext: ";


	for (int i = 0; i < plainText.length(); i++) {
		cout << sneakyText[i];
	}


	cout << endl << endl;


	return 0;
}




int main() {
	
	string plainText;
	string sneakyText = "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww";
	string key;


	cout << "1 - encrypt text" << endl << "2 - decrypt text" << endl << endl;


	int input;
	cin >> input;


	switch (input) {
	case 1: 
		encrypt(plainText, sneakyText, key);
		break;
	case 2:
		decrypt(plainText, sneakyText, key);
		break;
	default:
		cout << "invalid option" << endl << endl;
		break;
	}


	system("pause");
	return 0;
}