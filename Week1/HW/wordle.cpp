// TODO: When finished, write a file comment that describes the program.
// Write your name and date, and cite anyone who helped you.


/*
This file is located in my SCU Course Folder under the OOP Class directory
This program is a rudimentary version of wordle that gets a random 5 letter
word froma text file, takes user input,evaluates it to make sure it is 
usable, and indicates whether the guess is valid via wordle rules

I  relied heavily on the python file. I "translated"
everything from python into C++ for the logic function.

I wrote my own functionality as well commented out below. It uses similar 
variable names as python file, but the algorithm is 100% original
*/



//Abhinav Pala 9/28/24

/*
https://www.programiz.com/cpp-programming/library-function/cctype/toupper

I used the above link to figure out how to capitalize letters using STL
library. 

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

// program constants
const string FILENAME = "wordbank.txt";
const int NUM_LETTERS = 5;
const int NUM_GUESSES = 6;

// helper function declarations
string getWord();
string getGuess();
string processGuess(string guess, string secret);

/* TODO: declare additional helper functions here */

/* TODO: when done, give an overview of how your program works */
int main() {
	/* TODO: modify this to give instructions and play the game */

	string secret = getWord();
	cout << "Secret: " << secret << endl; // for testing; remove later!

	//My Additions to CODE!
	int game = 0;
	for (game = 0; game<NUM_GUESSES;game++)
	{
	string user_guess = getGuess();

	cout << processGuess(user_guess,secret) << endl;

	if (user_guess == secret)
	{
		cout << "Congrats! You guessed correctly";
		break;
	}

	};

	if (game == NUM_GUESSES)
	{
		cout << "Sorry, you failed";
	}



	return 0;
}

// helper function definitions 

// picks a random word from the specified file
string getWord() {
	// open the file
	ifstream f(FILENAME);
	// read words line-by-line into a vector (array-like data structure)
	vector<string> allWords;
	string word;
	while (getline(f,word)) {
		allWords.push_back(word);
	}
	// close the file
	f.close();
	// pick a random word from the vector and capitalize its letters
	srand(time(nullptr));
	word = allWords[rand()%allWords.size()];
	for (int i=0; i<word.length(); i++) {
		word[i] = toupper(word[i]);
	}
	return word;
}


/*
+++++++++++++++++++++++++++++MY CODE STARTS HERE++++++++++++++++++++
*/

//Obtains User Input
/*
Function asks user to input a word. Checks to see if it has 5 letters.
If not, while prompt user until 5 letter word is provided.
Then will capitalize the user input and return
*/
string getGuess()
{
	string guess;

	//Getting user input
	cout << "Enter a guess!:" << endl;
	cin >> guess;


	while(NUM_LETTERS!=guess.length())
	{
		cout << "Your guess has to be 5 letters, try again: "<<endl;
		cin >>guess;
	};

	for (int i = 0; i<5;i++)
	{
		guess[i] = toupper(guess[i]);
	};

	return guess;
}

string processGuess(string guess, string secret)
{
	string response = " ";

	for (int i=0;i<NUM_LETTERS;i++)
	{
		char letter = guess[i];

		if (secret[i] == letter)
		{
			response += '*';
		}
		else
		{
			bool inWord = false;
			for (int j = 0; j<NUM_LETTERS;j++)
			{
				if (secret[j] == letter)
				{
					inWord = true;
					break;
				};

			}

			if (inWord)
			{
				response += '!';
			}
			else
			{
				response += '-';
			};
		}
	}
	return response;
	//Initialized with 5 spaces
	// string checker = "     "; //The output that shows what letters are right, wrong, and partially correct

	// for (int i = 0; i<5;i++)
	// {
	// 	//Check for Direct Match
	// 	if (guess[i]==secret[i])
	// 	{
	// 		checker[i] = '*';
	// 	}

	// 	//Check if is in word, but not right place
	// 	else
	// 	{
	// 		int j = 0;
	// 		int temp = 0;

	// 		while (j<5)
	// 		{
	// 			if (guess[i]!=secret[j])
	// 			{
	// 				temp++;
	// 			};
	// 			j++;
	// 		};

	// 		if (temp==5)
	// 		{
	// 			checker[i] = '-';
	// 		}
	// 		else
	// 		{
	// 			checker[i] = '!';
	// 		};


	// 	};

	// }


	// return checker;
}
/* TODO: define your additional helper functions here */
