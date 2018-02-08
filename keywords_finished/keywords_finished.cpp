// keywords_finished.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
bool playagain = true;
int main()

{
	while (playagain == true) {
		int tries = 0;//keeps track of the tries it took to complete the program
		string answer;
		srand(time(NULL)); //the random number generators seed generator 
		string keywords[10] = { "mech", "hello", "gears","pizza", "food", "car", "friend", "person", "robot", "computer" };
		string hints[10] = { "giant robot", "what you say when meeting someone", "the inner workings of a machine", "yummy food", "Needed to survive", "Transportation", "someone close to you", "a human", "a machine", "what this program was made on" };
		string guess;
		for (int word = 1; word <= 3; word++) {

			int ran = rand() % 9; //randomly selects words from the lists


			string jumble = keywords[ran];
			int length = jumble.size(); //Randomizes the words 
			for (int i = 0; i < length; ++i) {
				int index1 = (rand() % length);
				int index2 = (rand() % length);
				char temp = jumble[index1];
				jumble[index1] = jumble[index2];
				jumble[index2] = temp;
			}

			while (guess != keywords[ran]) { //the main game loop keeping the player here until they guess the word

				cout << "Here is the jumbled word for you to guess" << endl;
				cout << jumble << endl;
				cout << "would you like a hint?" << endl;
				cin >> guess;
				if (guess == "yes") {
					cout << hints[ran] << endl;
				}
				else if (guess == keywords[ran]) {
					cout << "You guessed correctly!!" << endl;
				}
				else {
					cout << "incorrect" << endl;
					tries++;
				}
			}
			cout << "Congrats you guessed correct" << endl;



		}
		playagain = false; // set the game mode to end if the user doesnt specify to replay
		tries = tries + 3; // adds the 3 minimum attempts it takes to complete the program
		cout << "You passed the test in " << tries << " tries." << endl;

		cout << "Play again?" << endl << "Type yes or no" << endl;
		cin >> answer;
		if (answer == "yes") { // resets the game if the player desires to play again
			playagain = true;
		}



	}


	return 0;
}


