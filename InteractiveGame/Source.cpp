#include <iostream>
#include <string>

using namespace std;

int decision()
{
	string userChoice;
	cout << "--------------------------------------------------------------------------------------------------------\n";
	cout << "1. Leave\n";
	cout << "2. Fight\n";
	cout << "3. Stay\n";
	cout << "4. Exit\n";

	cin >> userChoice;
	
	if(userChoice == "Leave" || userChoice == "leave")
	{
		
	}else if (userChoice == "Fight" || userChoice == "fight")
	{

	}
	else if (userChoice == "Stay" || userChoice == "stay")
	{

	}
	else if (userChoice == "Exit" || userChoice == "exit")
	{

	}else
	{
		cout << "Error, could not process request. Please enter a new answer\n";
		decision();
	}
}

void left()
{
	//go left
}

void right()
{
	//go right
}

void main()
{
	string userChoice;
	/*
	cout << "\n\n\t\t *** Welcome to my Adventure ***\n\n";
	cout << "*You awake in a tavern from a drunken stupor*\n";
	cout << "*The bartender shouts* HEY YOU! You've been here all night. You need to leave or I'll kick ya out!\n";
	cout << "What should I do?\n";
	*/

	cout << "Choose left or right\n";
	cin >> userChoice;

	if(userChoice == "left")
	{
		left();
	}
	else if (userChoice == "right")
	{
		right();
	}
	else
	{
		//error enter a new answer
	}
	
	//decision();
	
}

