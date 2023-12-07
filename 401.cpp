#include <iostream>
#include <cstdlib> 
#include <map>

using namespace std;

const string not_palindrom = " -- is not a palindrome.";
const string reg_palindrom = " -- is a regular palindrome.";
const string mirror_string = " -- is a mirrored string.";
const string mirror_palindrom = " -- is a mirrored palindrome.";

bool check_for_palindrom(string s, int len){

	for(int i = 0; i <= len - 1; i++){
		if(s.at(i) != s.at(len -i - 1))
			return false;
	}
	return true;
}

bool check_for_mirror(string s, int len, map<char, char> reverse){

	// Store s backwards with each char replaced by reverse
	char s_rev_backwards[len];
	for(int i = 0; i <= len - 1; i++){
		char t = s.at(len - i - 1);
		s_rev_backwards[i] = reverse[t];
	}

	// Check if backwards the same
	for(int i = 0; i <= len - 1; i++){
		if(s.at(i) != s_rev_backwards[i])
			return false;
	}

	return true;
}

int main(){

	map<char, char> reverse;
	reverse['A'] = 'A';
	reverse['E'] = '3';
	reverse['H'] = 'H';
	reverse['I'] = 'I';
	reverse['J'] = 'L';
	reverse['L'] = 'J';
	reverse['M'] = 'M';
	reverse['O'] = 'O';
	reverse['S'] = '2';
	reverse['T'] = 'T';
	reverse['U'] = 'U';
	reverse['V'] = 'V';
	reverse['W'] = 'W';
	reverse['X'] = 'X';
	reverse['Y'] = 'Y';
	reverse['Z'] = '5';
	reverse['1'] = '1';
	reverse['2'] = 'S';
	reverse['3'] = 'E';
	reverse['5'] = 'Z';
	reverse['8'] = '8';

	string input;
	bool palindrom = false;
	bool mirror = false;
	int len = 0;

	while(cin >> input){
		
		len = input.length();
		
		palindrom = check_for_palindrom(input, len);

		mirror = check_for_mirror(input, len, reverse);

		// Print output
		if(!palindrom && !mirror){
			cout << input <<  not_palindrom << endl;
		}else if(palindrom && !mirror){
			cout << input << reg_palindrom << endl;
		}else if(!palindrom && mirror){
			cout << input << mirror_string << endl;
		}else{
			cout << input << mirror_palindrom << endl;
		}

		cout << endl;

	}
	
	return 0;
}
