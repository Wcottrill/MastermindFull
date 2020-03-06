#include "Header1.h"

bool Guess::isValid(int ch)
{
	return ch >=  1 && ch <= 6;
}

Guess::Guess()
{
	aGuess[0] = -1;
	aGuess[1] = -1;
	aGuess[2] = -1;
	aGuess[3] = -1;
	srand(time(0));
}

void Guess::setGuess(int a, int b, int c, int d)
{
	aGuess[0] = a;
	aGuess[1] = b;
	aGuess[2] = c;
	aGuess[3] = d;
}

void Guess::setMaster()
{
	aGuess[0] = rand()%6+1;
	aGuess[1] = rand()%6+1;
	aGuess[2] = rand()%6+1;
	aGuess[3] = rand()%6+1;
}
