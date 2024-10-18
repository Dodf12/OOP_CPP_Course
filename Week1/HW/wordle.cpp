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
variable names as python file, but the algorithm is 100% original.

I thought my logic was incorrect, since for double letters in teh guess,
it did not mark the second letter with a -. It instead marked it with !.
I consulted my friend Tate and asked him if his program did the same.
It turns out that it was in the instructions that the python.cpp logic
does the same thing. He said his logic was the same, and referred
me to the hw1.pdf document.

https://www.programiz.com/cpp-programming/library-function/cctype/toupper

I used the above link to figure out how to capitalize letters using STL
library. 
*/



//Abhinav Pala 9/28/24


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
bool guessInList(vector<string> words, string guess);
string processGuess(string guess, string secret);


/* 
I use a for loop to give the user exactly 6 tries. It also
breaks out of the loop and the program if the user gets it right,
so that it does not keep running even after they guessed
correctly. Game variable keeps track of number of guesses.
If game =6, it prompts user to try again
*/
int main() {
	/* TODO: modify this to give instructions and play the game */

	string secret = getWord();
	cout << "Secret: " << secret << endl; 
	
	//####################
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

	//EXTRA CREDIT

	//Getting words from teh file
	ifstream f(FILENAME);
	// read words line-by-line into a vector (array-like data structure)
	vector<string> allWords;
	string word;
	while (getline(f,word)) {
		allWords.push_back(word);
	}
	// close the file
	f.close();
	

	 bool isInList = guessInList(allWords, guess);

	 if (isInList == false)
	 {
	 	while (isInList == false)
	 	{
	 		cout << "Your guess is not a word, please enter a real word" << endl;
	 		cin >> guess;

	 		if (guessInList(allWords, guess) == true)
	 		{
	 			isInList = true;
	 		};
	 	};
	};

	return guess;
};

bool guessInList(vector<string> allWords, string guess)
{
	int count = 0;

	for ( int i = 0; i< allWords.size(); i++)
	{
		if (guess == allWords.at(i))
			{
				count++;
			};
	};

	if (count == 0)
	{
		return false;
	}
	else
	{
		return true;
	};
};



//Takes user guess, and compares it to the word they are supposed to guess
/*
Takes the user guess, and user guess as the input. Runs through the user
guess string, and compares each letter to the letters of the answer word
Outputs star if the letter matches, ! if the letter is in the word,
but not in the right place and - if the letter is not even in the secret
word at all
*/
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
	//Initialized with 5 spaces. (I wrote this before I saw the python reference code)
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
