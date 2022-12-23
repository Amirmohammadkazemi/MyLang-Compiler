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
	int state = 1;
	int exit = 0; //flag for exit for

	word = word + " "; //add space to end of word
	for(int ch=0; ch<word.size() && exit!=1; ch++) {
		switch(state) {
			case 1:
				if((word[ch]>='a' && word[ch]<='z')
				|| (word[ch]>='A' && word[ch]<='Z'))
					state = 2;
				break;
			case 2:
				if (word[ch] == ' ') {
					return 1;
					exit = 1;
				}
				else if((word[ch]>='a' && word[ch]<='z')
				|| (word[ch]>='A' && word[ch]<='Z')
				|| (word[ch]>='0' && word[ch]<='9'))
					state = 2;
				else {
					return 0;
					exit = 1;
				}
				break;
		}
	}
	return 0;
}

//isInt function for check word is integer Number or not
int isInt(string word) {
	int state = 1; 
	int exit = 0; //flag for exit for

	word = word + " "; //add space to end of word
	for(int ch=0; ch<word.size() && exit!=1; ch++) {
		switch(state) {
			case 1:
				if(word[ch]>='0' && word[ch]<='9'){
					state = 2;}
				break;
			case 2:
				if(word[ch] == ' ') {
					return 1;
					exit = 1;
				}
				else if(word[ch]>='0' && word[ch]<='9') {
					state = 2;
				}
				else {
					return 0;
					exit = 1;
				}
				break;
		}
	}
	return 0;
}

//isFloat function for check word is float number or not
int isFloat(string word) {
   int state = 1; 
	int dotCounter = 0; //count dot symbol for check float number have 1 dot or more
	int exit = 0; //flag for exit for

	word = word + " ||"; //add space to end of word
	for(int ch=0; ch<word.size() && exit!=1; ch++) {
		switch(state) {
			case 1:
				if(word[ch]>='0' && word[ch]<='9'){
					state = 2;}
				else {
						return 0;
						exit = 1;
					}
				break;
			case 2:
				if(word[ch] == ' ' && dotCounter == 1) {
               return 1;
               exit = 1;
				}
				else if(word[ch]>='0' && word[ch]<='9') {
					state = 2;
				}
            else if(word[ch] == '.') {
               dotCounter += 1;
               state = 2;
            }
				else {
					return 0;
					exit = 1;
				}
				break;
		}
	}
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
void genToken(string desc) {
	cout<<"T-"<<desc<<endl;
}

//Lexical analysis
void lexicalAnalysis(string word) {
	if(isKey(word) == 1){
		cout<<endl<<"Word "<<word<<" is key word || Token:> ";
		genToken("KEY");
	}
	else if(isID(word) == 1) {
		cout<<endl<<"Word "<<word<<" is ID || Token:> ";
		genToken("ID");
	}
	else if(isInt(word) == 1) {
		cout<<endl<<"Word "<<word<<" is integer number || Token:> ";
		genToken("INT");
	}
	else if(isFloat(word) == 1) {
		cout<<endl<<"Word "<<word<<" is float number || Token:> ";
		genToken("FLOAT");
	}
	else if(isOperator(word) == 1) {
		cout<<endl<<"Word "<<word<<" is key word || Token:> ";
		genToken("OPERATOR");
	}
	else if(isSymbol(word) == 1) {
		cout<<endl<<"Word "<<word<<" is key word || Token:> ";
		genToken("SYMBOL");
	}
	else
		cout<<endl<<"Error in word "<<word<<" (unknown word)"<<endl;
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

	//message for start compiling
	cout<<endl<<"\"------------Start------------\""<<endl;

	//opening file
	file.open(fileName.c_str());

	//extracting words from the file
	while (file >> word) {
		lexicalAnalysis(word);
	}

    return 0;
}
