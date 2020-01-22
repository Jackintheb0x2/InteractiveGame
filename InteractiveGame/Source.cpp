#include <iostream>
#include <string>
#include <cstdlib>
#include <Windows.h>
//#include <stdlib.h>

using namespace std;

string decision()
{
	string userChoice;
	cout << "--------------------------------------------------------------------------------------------------------\n";
	cout << "1. Leave\n";
	cout << "2. Fight\n";
	cout << "3. Stay\n";
	cout << "4. Exit\n";

	cin >> userChoice;
	if(userChoice == "Exit" || userChoice == "exit" || userChoice == "4")
	{
		exit(EXIT_FAILURE);
	}else if(!(userChoice == "Leave" || userChoice == "leave" || userChoice == "1" || userChoice == "Fight" || userChoice == "fight" || userChoice == "2" || userChoice == "Stay" || userChoice == "stay" || userChoice == "3"))
	{
		cout << "Error, could not process request. Please enter a new answer\n";
		userChoice = decision();
	}
	return userChoice;
}

int roll()
{
	
	cout << "press space to roll a D20\n";
	while (!(GetAsyncKeyState(' ') & 0x80000000));
	int dieValue = (rand() % 20) + 1;
	cout << "*You rolled a " << dieValue << "*\n";
	
	return dieValue;
}

void continues(){
	cout << "\n*Press Space to Continue!*\n";
	while (!(GetAsyncKeyState(' ') & 0x80000000));
}

int main()
{
	
	string userChoice;
	int dieValue;
	
	
	cout << "\n\n\t\t *** Welcome to my Adventure ***\n\n";

	//SCENE ONE - THE TAVERN
	
	cout << "*You awake in a tavern from a drunken stupor*\n";
	cout << "*The bartender shouts* HEY YOU! You've been here all night. You need to leave or I'll kick ya out!\n";
	cout << "What should I do?\n";
	userChoice = decision();

	if (userChoice == "Leave" || userChoice == "leave" || userChoice == "1")
	{
		cout << "*You walk drunkenly out of the Tavern almost losing your balance*\n";
		cout << "*Once out of the tavern, you fall on your face onto the gravel road*\n";
	}
	else if (userChoice == "Fight" || userChoice == "fight" || userChoice == "2")
	{
		cout << "*You ignore the bartender and start harassing the other customers*\n";
		cout << "So you have chosen DEATH! said the bartender\n";
		cout << "*The bartender hops over the table and lunges toward you*\n";
		dieValue = roll();
		if(dieValue > 15)
		{
			cout << "\n*You successfully dodge the bartender and you throw your pitcher at him breaking his back and shattering the glass*\n";
			cout << "*Other customers start looking at you and giving you the stink-eye*\n";
			cout << "*what will you do?*\n";
			userChoice = decision();
			if(userChoice == "Leave" || userChoice == "leave" || userChoice == "1")
			{
				cout << "*You get up and walk out*\n";
				cout << "*On your way out you trip and fall onto the gravel road*\n";
			}
			else if (userChoice == "Fight" || userChoice == "fight" || userChoice == "2")
			{
				cout << "*You look around the room and spot one guy in the corner staring you down*\n";
				cout << "*You start to feel your blood boil, adrenaline surging and you walk towards him*\n";
				cout << "*The other guy gets up and walks toward you*\n";
				cout << "Will you attack first?\n";
				dieValue = roll();
				if (dieValue > 13)
				{
					cout << "*You swing first but it misses!*\n";
					cout << "*the guy comes back swinging and you are knocked out cold*\n";
				}else
				{
					cout << "*The guy throws a punch and it connects knocking you out cold*\n";
				}
				cout << "*You are then picked up and thrown out of the Tavern*\n";
			}
			else if (userChoice == "Stay" || userChoice == "stay" || userChoice == "3")
			{
				cout << "*One guy walks up to you from behind and knocks you out cold*\n";
				cout << "*You are then picked up and thrown out of the Tavern*\n";
			}
			
		}else
		{
			cout << "\n*You try to dodge but can't react in time and the bartender tackles you to the ground*\n";
			cout << "*The bartender throws you out into the street and you fall over again*\n";
		}
		
	}
	else if (userChoice == "Stay" || userChoice == "stay" || userChoice == "3")
	{
		cout << "*The bartender walks over to you, grabs you, and throws you out of the Tavern*\n";
		cout << "*Once outside, you fall face first onto the gravel road*\n";
	}

	cout << "*You are now unconscious outside of the bar*\n";
	continues();
	//SCENE TWO
	cout << "*Hours seem to pass by in the blink of an eye*";
	cout << "*You awake to the sound of goblins chattering, sitting around a fire*\n";
	//the player is being hung upside down and is trapped
}

