//Wesley Cottrill
//This is my work
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <ctime>
#include "Guess.h"
using namespace std;

class Game {
private:
	Guess curGuess;
	Guess scrtGuess;
	int numGuess;
	int whPeg;
	int blPeg;
	bool isWinner() {
		if (blPeg == 4)
			return true;
			else return false;
		
	}
	bool outOfGuesses() {
		if (numGuess == 10)
			return true;
			else return false;

	}
	void getUserGuess() {
		int a; int b; int c; int d;
		cout << " Give me 4 colors(1-6) "<< endl;
		cin >> a >> b >> c >> d;
		curGuess.setGuess(a, b, c, d);
		

	}
	int getMin(int e, int s) {
		if (e < s)return e;
		else return s;
	}

public:
	Game() {
		numGuess = 0;
		whPeg = 0;
		blPeg = 0;
		scrtGuess.setMaster();

	}
	void generateFeedback() {
		int userColors[6];
		int codeColors[6];
		whPeg = 0;
		blPeg = 0;
		for (int i = 0; i <= 3; i++){
			if (curGuess[i] == scrtGuess[i])
				blPeg++;
			
		}
		for (int i = 0; i < 6; i++){
			userColors[i] = codeColors[i] = 0;
		}
		for (int i = 0; i < 4; i++){
			userColors[curGuess[i]]++;
			codeColors[scrtGuess[i]]++;
		}
		for (int i = 0; i < 6; i++){
			int x = getMin(userColors[i], codeColors[i]);
			whPeg = whPeg + x;
		}
		whPeg -= blPeg;
		numGuess++;
		cout << "Black Pegs: " << blPeg << " White Pegs: " << whPeg << endl;
	}
	void playGame() {

		while (!isWinner() && !outOfGuesses()) {
			getUserGuess();
			generateFeedback();
		}
		if (isWinner())
			cout << "You win my dude congrats" << endl;
		else
			cout << " Bro thats tough you are a loser.:( " << endl;

	}


	

};


#endif