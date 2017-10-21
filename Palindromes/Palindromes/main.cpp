/*
* A program which prompts the user for a string and it will state whether or not it is a palindrome.
*
* A palindrome is a string whose non-space, non-punctuation characters are read the same left to right as they are right to left.
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const string BREAKSTRING = "-1";

bool palindrome(string str);

int main() {
	string palString;
	cout << "Enter strings to determine if they are a palindrome (" << BREAKSTRING << " to quit)>";
	getline(cin, palString);
	
	while (palString != BREAKSTRING) {
		if (palindrome(palString))
			cout << "\"" << palString << "\" is a palindrome." << endl;
		else
			cout << "\"" << palString << "\" is not a palindrome." << endl;
		cout << ">";
		getline(cin, palString);
	}

	return 0;
}

/*
* @param str the string to be tested
* @return true if str is a palindrome, false if not
*/
bool palindrome(string str) {
	string strNoSpaces;
	for (int i = 0; i < str.length(); i++) {
		if (!isspace(str[i]) && !ispunct(str[i]))
			strNoSpaces += str[i];
	}

	for (int i = 0; i < strNoSpaces.length() / 2; i++) {
		int latterIndex = (strNoSpaces.length() - 1) - i;
		strNoSpaces[i] = tolower(strNoSpaces[i]);
		strNoSpaces[latterIndex] = tolower(strNoSpaces[latterIndex]);
		if (strNoSpaces[i] != strNoSpaces[latterIndex])
			return false;
	}
	
	return true;
}