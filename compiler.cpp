//libraries
#include <iostream>
#include <string>
#include <bits/stdc++.h>

//namespaces
using namespace std;

//functions

//print welcome message to user
void startMessage() {
	cout<<"\t...Welcom to MyLang language compiler...\n";
}

//isKey function for check word is key word or not
int isKey(string word) {
	return 0;
}

//isID function for check word is ID or not
int isID(string word) {
	return 0;
}

//isInt function for check word is integer Number or not
int isInt(string word) {
	return 0;
}

//isFloat function for check word is float number or not
int isFloat(string word) {
	return 0;
}

//isOperator function for check word is operator or not
int isOperator(string word) {
	return 0;
}

//isSymbol function for check word is symbol or not
int isSymbol(string word) {
	return 0;
}

//getToken get word and description and generate token for syntax analysis
string genToken(string word, string desc) {
	return "Token";
}


//start function
int main() {

	string fileName; //input file name
	fstream file; //filestream variable file
	string word; //word

	//show start message
    startMessage();
	cout<<"Enter source file name:> ";

	//get file name from user
	cin>>fileName;

	//opening file
	file.open(fileName.c_str());

	//extracting words from the file
	while (file >> word) {
		//displaying content
		cout << word << endl;
	}

    return 0;
}
