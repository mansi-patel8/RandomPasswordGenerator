/*
* Name: Mansi Patel
* Problem:
		- Write a program to generate k passwords of length n with m possible characters (based on the length of the alphabet). The user should have several alphabet options:
			1. Lowercase English characters + digits.
			2. Lowercase/Uppercase English characters + digits
			3. Lowercase/Uppercase English characters, digits + extra characters: !@#$%^&*()[]{}\.:;/~
		- The password alphabet of possible characters is going to be read from a text file called alphabet.config and generated passwords are going to be shown to user in console and stored in passwords.txt file. If such does not exist, it must be created by the program. You also have to show the number of possible password combinations of such configuration calculated as: m to the power of n.
		- Your alphabet.config file should be containing 3 strings representing different character sets; this file is given to you together with assignment description.
		- Hint: include <fstream> to do reading/writing with files

* Peudo Code:
		- ask for the user input for number of password and store it as varible k
		- ask for the user input for length of the password ad store it as varible n
		- ask for the user input for password alphabet option and store it as avriable option
		- check for user input for the option (shouldbe between 1 to 3)
		- for loop (starts at 1 and stops at 4)  //this for loop will go through inputfile alphabet.config
			- check if inputfileline == option selected by user
			- if yes then
				- console output of the possible password combinations
				- for loop (starts with 1 and stops at k) //this for loop is for number password k
					- for loop (starts with 0 staops at n) //this for lopp is for the length of the password n
					- get the random numner between (0, fileline.size()-1), because each line in the file has different number of characters
					- generate the password string // as get the random character from the selected line in the file with the postion from above random number - suing substr() to get the random character for n length
					- console output of the password string
					- stoe the password in output.txt
*/

#include "RandomPasswordGenerator.h"
#include <fstream>
#include <iostream> 
#include <string>
#include <math.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

int main() {

	int k = 0;				 //number of passwords 
	int n = 0;				//length of the password
	int option = 1;			//option for the password choice
	string fileLine;		//string from the file

	//user input for number of password
	cout << "This program generates random passwordsand stores them in file. " << endl;
	cout << "Please enter number of passwords to generate(k) :" << endl;
	cin >> k;

	//user input for length of the password
	cout << "Please enter password length(n) :" << endl;
	cin >> n;

	//user input for password alphabet option
	cout << "Please choose the character alphabet option :" << endl;
	cout << "1. Lowercase English characters + digits. " << endl;
	cout << "2. Lowercase / Uppercase English characters + digits" << endl;
	cout << "3. Lowercase / Uppercase English characters, digits + extra characters" << endl;
	cin >> option;

	//check if the user input is correct for password character alphabet option
	if (option > 3 || option <= 0)
	{
		cout << "Error: Choose the correct Option " << endl;
		return false;
	}

	ifstream inputFile("alphabet.config");						//connect to "alphabet.config"
	if (inputFile.is_open())									//opening the input file 
	{
		cout << "Reading alphabet.config ..." << endl;

		for (int lineNo = 1; getline(inputFile, fileLine) && lineNo < 4; lineNo++)
		{
			//check if user selected option matches with the lineno from the file 
			if (lineNo == option)
			{
				//console output for possible password combinations 
				cout << setprecision(25) << "This configuration has a total of " << fileLine.size() << "^" << n
					<< " or " << pow(fileLine.size(), n) << " possible password combinations." << endl;

				cout << "The generated passwords are:" << endl;

				inputFile.close();								//close and release input file

				//create/open the output.txt file
				ofstream outputFile("password.txt");			//connect to "password.txt"
				if (!outputFile.fail())
				{
					//this for loop is for number of password
					for (int m = 1; m <= k; m++)
					{
						string password = "";				 // empty string for password
						int position;						//position in the string

						//this for loop will run n time - n length of the password
						for (int i = 0; i < n; i++)
						{
							//this will get the random character from password character option 
							position = rnd_num(0, fileLine.size() - 1);
							// this will apppend the password string with randomized character with substring 1 each time
							password += fileLine.substr(position, 1);
						}

						//console output of the password
						cout << password << endl;

						//storing password(s) in passwords.txt file
						outputFile << password << endl;
					}
					cout << "The passwords were stored in passwords.txt file on disk." << endl;
					outputFile.close();							 // close and release passwords.txt file					
				}
				else outputFile << "ERROR: Could not open output file." << endl;
			}
		}
	}
	else cout << "Unable to open the input file" << endl;

	return 0;

}