// dice_01.cpp : Defines the entry point for the console application.
//
////////////////////////////////////
// ___   ___   ___
//|   | |   | |   |
//| P | | I | | G |      A Program By:
//|___| |___| |___|      Monte Nichols
////////////////////////////////////

/*---------------------------------------
//Display The Rules:
Goal:
Be the first player to reach 30 points!

Gameplay:
On a turn, a player rolls the die repeatedly until either:

* A 1 is rolled
* The player chooses to hold (stop rolling)

If a 1 is rolled, that player's turn ends and no points are earned.
If the player chooses to hold, all of the points rolled during that turn are
added to his or her score.

At the end of a game you gain not only all of the money you put up ($30) but
also all the money the opponent was betting.

Try to have a close game with the opponent so you have the chance to earn more
be careful though, the closer the scores, the more likely your opponent will win.
Let's roll to see who goes first.
(type r to roll) //[[INPUT TO ROLL]]

//We decide who goes first by roll, for example if you go first:

You go first!

Press r to roll some dice.
(type r to roll) //[[INPUT TO ROLL]]

You roll calling your turn function [[see myTurn();]]
After, the computer does the same   [[see cpTurn();]]

If either of you go past the winning score value you gain or lose money and might play another round

-----------------------------------------*/

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int rollDice (string name);
int myTurn (string ME, int myScore, int cpScore);
int cpTurn (string CP, int myScore, int cpScore, int winningScore);
void displayRules ();
void displayMoney ( int yoMoney, int compMoney);
void getScore (int mine, int cps);
void win (string winner);

int main()
{
	//Variables
	char again = ' ';
	int wrongInput = 0;
	char roll = ' ';
	int result = 0;
	int myScore;
	int cpScore;
	int myMoney = 100;
	int cpMoney = 100;
	int winningScore = 30;
	int myFirst;
	int cpFirst;
	bool isMyTurn;

	//Constants
	string ME = "You";
	string CP = "The Computer";

	//Title
	cout << " ___   ___   ___  \n";
	cout << "|   | |   | |   | \n";
	cout << "| P | | I | | G |      A Program By:\n";
	cout << "|___| |___| |___|      Monte Nichols\n";

	// Display the rules
	displayRules();

	//Game loop
	do
	{
		cpScore = 0;
		myScore = 0;
		// This chunk of code decides who goes first
		do
		{
			if (wrongInput != 0)
			{
				cout << "\n\nThat character doesn't work.\n";
			}
			wrongInput++;
			cout << "Let's roll to see who goes first.\n(type 'r' to roll or 'q' to quit)";
			cin >> again;
		} while (again != 'r' && again != 'q');

		if (again == 'q')
		{
			return 0;
		}

		again = ' ';
		wrongInput = 0;

		do
		{
			system("cls");
			myFirst = rollDice(ME);
			cpFirst = rollDice(CP);
		}while (cpFirst == myFirst);

		if (myFirst > cpFirst)
		{
			cout << "You go first.\n\n";
			isMyTurn = true;
		}

		if (myFirst < cpFirst)
		{
			cout << "The computer goes first.\n\n";
			isMyTurn = false;
		}

		displayMoney(myMoney, cpMoney);

		// Turn Loop
		do
		{
			if (isMyTurn)
			{
				do
				{

					if (wrongInput != 0)
					{
						cout << "\n\nThat character doesn't work.\n";
					}

					wrongInput++;
					cout << "Press r to roll some dice.\n(type 'r' to roll or 'q' to quit)";
					cin >> again;
				} while (again != 'r' && again != 'q');

				if (again == 'q')
				{
					return 0;
				}

				system("cls");
				again = ' ';
				wrongInput = 0;
				myScore += myTurn(ME, myScore, cpScore);
				isMyTurn = false;
			}
			else
			{
				cpScore += cpTurn(CP, myScore, cpScore, winningScore);
				isMyTurn = true;
				cout << "\n";
				getScore(myScore, cpScore);
				cout << "\n";
			}

		} while (myScore < winningScore && cpScore < winningScore);
		// END Turn Loop

		//Display Winner
		if (myScore >= winningScore)
		{
			win(ME);
			myMoney += cpScore;
			cpMoney -= cpScore;
			displayMoney(myMoney, cpMoney);
		}

		else
		{
			win(CP);
			myMoney -= myScore;
			cpMoney += myScore;
			displayMoney(myMoney, cpMoney);
		}

		// Ask them to play again
		if ( cpMoney > winningScore && myMoney > winningScore )
		{
		do
			{
				cout << "\nWould you like to play another round? (y/n)";
				cin >> again;

			} while (again != 'y' && again != 'n');
		}
		else
		{
			if (cpMoney < winningScore)
			{
				cout << "The computer doesn't have enough money to play a game, it needs at least " << winningScore << ". Bye!";
				cout << "\n\nEnter any character followed by enter.";
				cin >> again;
				again = 'n';
			}

			if (myMoney < winningScore)
			{
				cout << "You don't have enough money to play a game. You need at least " << winningScore << ". Bye!";
				cout << "\n\nEnter any character followed by enter.";
				cin >> again;
				again = 'n';
			}
		}

	} while (again == 'y'); // End Game loop

	return 0;
}


// Rolls a random number 1 through 6 and also shows an acii image of a Die for ease of use
int rollDice (string name)
{
	//Create Random Number
	Sleep(1109);
	srand( time( NULL ));
	int number = ( rand() % 6 ) + 1;

	cout << name << " rolled: \n";

	//Show Dice
	if (number == 1)
	{
		cout << " ___ "   << endl;
		cout << "|   |"  << endl;
		cout << "| 0 |   one"  << endl;
		cout << "|___|"  << endl;
	}

	else if (number == 2)
	{
		cout << " __ "   << endl;
		cout << "|  0|"  << endl;
		cout << "|   |   two"  << endl;
		cout << "|0__|"  << endl;
	}

	else if (number == 3)
	{
		cout << " __ "   << endl;
		cout << "|  0|"  << endl;
		cout << "| 0 |   three"  << endl;
		cout << "|0__|"  << endl;
	}

	else if (number == 4)
	{
		cout << "  _ "   << endl;
		cout << "|0 0|"  << endl;
		cout << "|   |   four"  << endl;
		cout << "|0_0|"  << endl;
	}

	else if (number == 5)
	{
		cout << "  _ "   << endl;
		cout << "|0 0|"  << endl;
		cout << "| 0 |   five"  << endl;
		cout << "|0_0|"  << endl;
	}

	else if (number == 6)
	{
		cout << "  _ "   << endl;
		cout << "|0 0|"  << endl;
		cout << "|0 0|   six"  << endl;
		cout << "|0_0|"  << endl;
	}
	cout << "\n\n";
	return number;
}


/*------------------------------------

It displays your [[myScore]]
and the computer's [[cpScore]]

It displays your [[current Bet]]
Would you like to roll again to try and increase your bet?(y/n)? [[Input]]

If you ever roll a 1 or pass your turn, your turn passes to the opponent.

We return the bet and add it to the score

--------------------------------------*/
int myTurn (string ME, int myScore, int cpScore)
{
	int number;
	char rollAgain = ' ';
	int currentBet = 0;
	int wrongInput = 0;

	do
	{
		number = rollDice(ME);
		currentBet += number;

		getScore(myScore, cpScore);

		if (number != 1)
		{
			cout << "You are currently betting " << currentBet << ".\n";
			do
			{
				if (wrongInput != 0)
				{
					cout << "\n\nThat character doesn't work.\n";
				}

				wrongInput++;
				cout << "Would you like to roll again to try and increase your bet?\n";
				cout << "(enter 'y' for yes, 'n' for no)"; // or 'q' to quit)";
				cin >> rollAgain;

			} while (rollAgain != 'y' && rollAgain != 'n' );// && again != 'q');

				//if (again == 'q')
				//{
				//	return 0;
				//}

				//rollAgain = ' ';
				wrongInput = 0;
		}

		else
		{
			rollAgain = 'n';
			cout << "You lose your current betting pool becuase you rolled a 1. \n";
			currentBet = 0;
		}

	} while (rollAgain == 'y');

	if (myScore + currentBet >= 30)
	{
	}
	else
	{
		cout << "\n\nYou pass play to the computer.\n\n";
	}

	return currentBet;

}

/*------------------------------------

This computer has a small amount of intelligence and will keep bets based upon statistics

Basically the computer rolls again if
	Its current bet is lower than its minimum bet.
		It is almost always better to roll if your bet is under this number
    or Its current bet is way less than the opponent
		It is good to catch up as much as possible
    or the other guy is about to win
		It is good to go all out if you are about to lose

The computer will roll until these requirements are met or a 1 is rolled

We return the bet and add it to the score

--------------------------------------*/
int cpTurn (string CP, int myScore, int cpScore, int winningScore)
{
	int number;
	char rollAgain;
	int currentBet = 0;
	int stayValue = 6;
	int maxScoreDif = 10;
	int maxAllow = (winningScore - maxScoreDif);

	do
	{
		number = rollDice(CP);
		currentBet += number;
		rollAgain = ' ';

		if (number != 1)
		{
			if ( ( (currentBet < stayValue) && ( (cpScore + currentBet) < winningScore) ) || ( (cpScore + currentBet) < (myScore - maxScoreDif) ) || ( (myScore > maxAllow) && ( (cpScore + currentBet) < winningScore) ) )
			{
				cout << "The Computer is currently betting " << currentBet << " .\n";
				cout << "The Computer decides to roll again.\n\n";
				rollAgain = 'y';
			}
		}

		else
		{
		cout << "The Computer lost its current betting pool becuase it rolled a 1. \n";
		currentBet = 0;
		}

	} while (rollAgain == 'y');

	if (cpScore + currentBet >= winningScore)
	{
	}
	else
	{
		cout << "\nThe computer passes play to you and keeps its current bet of " << currentBet << ".\n";
	}

	return currentBet;
}


void displayRules ()
{
	cout << "Goal: \nBe the first player to reach 30 points!\n\n";
	cout << "Gameplay: \nOn a turn, a player rolls the die repeatedly until either:\n\n";
	cout << "* A 1 is rolled \n* The player chooses to hold (stop rolling)\n\n";
	cout << "If a 1 is rolled, that player's turn ends and no points are earned.\n";
	cout << "If the player chooses to hold, all of the points rolled during that turn are    added to his or her score.\n\n";
	cout << "At the end of a game you gain not only all of the money you put up ($30) but    also all the money the opponent was betting.\n\n";
	cout << "Try to have a close game with the opponent so you have the chance to earn more; be careful though, the closer the scores, the more likely your opponent will    win.\n";

	return;
}

void displayMoney ( int yoMoney, int compMoney)
{
	cout << "You have $" << yoMoney << ".\n";
	cout << "The computer has $" << compMoney << ".\n\n";

	return;
}
void getScore (int mine, int cps)
{
	cout << "\nYour current score is " << mine << ".\n";
	cout << "The computer's current score is " << cps << ".\n\n";

	return;
}

void win (string winner)
{
	cout << winner << " won!";
	return;
}
