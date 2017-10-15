/*
* A program which parses user input to translate into "Scooby-text," ie. for every word, the leading consonant is an 'r' if it exists.
*
* For example,
*	Scooby-Doo => Rooby-Roo
*	Shaggy => Raggy
*	Scooby snacks => Rooby racks
*/

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

string scoobyPhrase(const string &word);
string scoobyWord(const string &word);
bool isVowel(char c);

int main() {
	string p;
	cout << "Input a phrase for Scooby-Doo: ";
	getline(cin, p);
	cout << scoobyPhrase(p) << endl;

	return 0;
}

/*
* Translates an entire phrase into "Scooby-text."
*
* @param phrase the phrase to be translated
* @return the translated phrase
*/
string scoobyPhrase(const string &phrase) {
	vector<string> words;
	int beginningOfWordIndex = 0;
	for (int i = 0; i < phrase.length(); i++) {
		if (isspace(phrase[i]) || phrase[i] == '-' || i + 1 == phrase.length()) { //parse word if condition is true
			string currentWord = phrase.substr(beginningOfWordIndex, i - beginningOfWordIndex + 1);
			words.push_back(scoobyWord(currentWord));
			beginningOfWordIndex = i + 1;
		}
	}

	string scooby;
	for (int i = 0; i < words.size(); i++) {
		scooby += words[i];
	}

	return scooby;
}

/*
* Translates a word to "Scooby-text," ie. the leading consonant becomes an 'r' if it exists.
*
* @param word the word to be translated
* @return the word in "Scooby-text"
*/
string scoobyWord(const string &word){
	int i;
	for (i = 0; isalpha(word[i]) && (i + 1) < word.length() && !isVowel(word[i + 1]); i++) { //iterate past leading consonants until we have a consonant followed by a vowel
		if (isVowel(word[i]))
			return word;
	}

	string scooby = "r";
	if (isupper(word[0]))
		scooby[0] = toupper(scooby[0]);

	scooby += word.substr(i + 1);

	return scooby;
}

bool isVowel(char c) {
	char upperC = toupper(c);
	return upperC == 'A' || upperC == 'E' || upperC == 'I' || upperC == 'O' || upperC == 'U';
}
