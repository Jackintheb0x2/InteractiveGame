#include <iostream>//is for inputting and outputting information
#include <string>//is for saving a collection of characters as a variable
#include <cstdlib>//is for using random and getting a key
#include <Windows.h>//is for being able to close the program

using namespace std;

int dieValue;
int health = 20;
int goblin1Health = 5;
int goblin2Health = 6;
int goblin3Health = 5;
string userChoice;


/*
 * These three decision functions are for the player for each situation.
 * The first one is used when the player is in the tavern
 * the second one is used when the player gets captured by goblins
 * the last one is used when the player is trying to flee
 */
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
string decision2()
{
	cout << "--------------------------------------------------------------------------------------------------------\n";
	cout << "1. Scream\n";
	cout << "2. Release yourself quietly\n";
	cout << "3. Stay\n";
	cout << "4. Exit\n";

	cin >> userChoice;
	if (userChoice == "Exit" || userChoice == "exit" || userChoice == "4")
	{
		exit(EXIT_FAILURE);
	}
	else if (!(userChoice == "Scream" || userChoice == "scream" || userChoice == "1" || userChoice == "Release" || userChoice == "release" || userChoice == "2" || userChoice == "Stay" || userChoice == "stay" || userChoice == "3"))
	{
		cout << "Error, could not process request. Please enter a new answer\n";
		userChoice = decision();
	}
	return userChoice;
}

string decision3()
{
	cout << "--------------------------------------------------------------------------------------------------------\n";
	cout << "1. Run\n";
	cout << "2. Fight\n";
	cout << "3. Exit\n";

	cin >> userChoice;
	if (userChoice == "Exit" || userChoice == "exit" || userChoice == "3")
	{
		exit(EXIT_FAILURE);
	}
	else if (!(userChoice == "Run" || userChoice == "run" || userChoice == "1" || userChoice == "Fight" || userChoice == "fight" || userChoice == "2"))
	{
		cout << "Error, could not process request. Please enter a new answer\n";
		userChoice = decision();
	}
	return userChoice;
}

/*
 * I wanted to incorporate some dnd elements so I added a die rolling system that
 * can randomize the game a little bit more while still being in control of the narrative
 */
int roll()
{
	
	cout << "press space to roll a D20\n";
	while (!(GetAsyncKeyState(' ') & 0x80000000));
	dieValue = (rand() % 20) + 1;
	cout << "*You rolled a " << dieValue << "*\n";
	
	return dieValue;
}

/*
 * this is for if i need to pause the game and wait for the player to move on
 */
void continues(){
	cout << "\n*Press Space to Continue!*\n";
	while (!(GetAsyncKeyState(' ') & 0x80000000));//this gets and waits for the space bar to be pressed before returning to the rest of the program
}


/*
 * This function is for if goblin attacks a player.
 */
void goblinAttack()
{
	cout << "roll to dodge";
	dieValue = roll();
	if (dieValue > 12)
	{
		cout << "You manage to dodge the attack successfully!\n";
		cout << "Your current health is " << health << "\n";
	}
	else
	{
		cout << "You take damage from the Goblin\n";
		health = health - (roll() / 3);
		cout << "Your current health is " << health << "\n";
		if (health <= 0)
		{
			cout << "\n\n\t\tYOU DIED!\n\n";
			exit(EXIT_FAILURE);
		}
	}
}


/*
 * This function is for if the player attacks a goblin.
 */
int playerAttack(int goblinHealth)
{
	dieValue = roll();
	goblinHealth = goblinHealth - dieValue;
	if (goblinHealth <= 0)
	{
		cout << "The goblin is dead!\n";
	}
	else
	{
		cout << "The goblin's health is " << goblinHealth << "\n";
	}
	return goblinHealth;
}


/*
 * This function is for if the player gets into a fight with a goblin.
 * I created this function to reduce redundancy and to have my program run more efficiently.
 * this goes through the entire goblin fight
 */
void goblinFight()
{

	cout << "You raise your fist preparing to fight\n";
	cout << "Goblin 1 strikes first!";
	goblinAttack();
	cout << "You attack the goblin!\n";
	goblin1Health = playerAttack(goblin1Health);
	while(goblin1Health > 0)
	{
		cout << "an opportunity arises to attack again!\n";
		goblin1Health = playerAttack(goblin1Health);
	}
	cout << "The first goblin has died!\n";
	cout << "Goblin 2 strikes next!";
	goblinAttack();
	cout << "You attack the goblin!\n";
	goblin2Health = playerAttack(goblin2Health);
	while (goblin2Health > 0)
	{
		cout << "an opportunity arises to attack again!\n";
		goblin2Health = playerAttack(goblin2Health);
	}
	cout << "The second goblin has fallen!\n";
	cout << "Goblin 3 strikes last!";
	goblinAttack();
	cout << "You attack the goblin!\n";
	goblin3Health = playerAttack(goblin3Health);
	while (goblin3Health > 0)
	{
		cout << "an opportunity arises to attack again!\n";
		goblin3Health = playerAttack(goblin3Health);
	}
	cout << "The final goblin has fallen!\n";
	cout << "You beat the goblins!";
}


/*
 * This function is for if the player gets detected.
 * I created this function to reduce redundancy and to have my program run more efficiently
 */
void detected()
{
	
	cout << "Goblin 1 grabs his sword and yells ARRAGAHARA\n *The other two stand up and look startled*\n";
	cout << "Release me or I'll kill you!";
	cout << "The goblin responds: RAAAAAAAGAR";
	cout << "Goblin 1 cuts the rope from the tree and you fall to teh ground still tied up\nAll three grab the end of the rope and start pulling you in some direction\n";
	cout << "*You try to release yourself*\n";
	dieValue = roll();
	if (dieValue > 8)
	{
		cout << "*You free yourself from the rope*\n";
		cout << "What will you do?\n";
		userChoice = decision3();
		if (userChoice == "Run" || userChoice == "run" || userChoice == "1")
		{
			cout << "*You take off running in the other direction with the three goblins following close behind*\n";
			cout << "Do you escape?\n";
			dieValue = roll();
			if (dieValue > 10)
			{
				cout << "*You escape the goblins*\n";
			}
			else
			{
				cout << "*The goblins catch up to you and you are forced to fight*\n";
				goblinFight();
			}
		}
		else if (userChoice == "Fight" || userChoice == "fight" || userChoice == "2")
		{
			goblinFight();
		}
	}
	else
	{
		cout << "*The goblins take you to a lake and throw you in*\n*You are unable to swim up*\n";
		dieValue = roll();
		if (dieValue > 12)
		{
			cout << "*You are able to untie yourself and swim to the surface*\n*Once you reach the surface you take a giant breath of air and start swimming to the shore*\n";;
			cout << "*When you reach the shore, the goblins were nowhere to be found*\n";
		}
		else
		{
			cout << "*You were unable to untie yourself and start to sink*\n*5 seconds later you pass out, never to be seen again*";
			cout << "\n\n\t\tYOU DIED!\n\n";
			exit(EXIT_FAILURE);

		}
	}
}




/*
 * There are two scenes. It first starts in the tavern where you can choose different options on how you want to deal with the situation.
 * The second scene shows teh player waking up and being tied to a tree and the player has to make calculated decisions on how to escape alive.
 * Everything in the main function uses the cout command, if statements, and calling different functions
 */
int main()
{
	cout << "\n\n\t\t *** Welcome to my Adventure ***\n\n";

	//SCENE ONE - THE TAVERN
	
	cout << "*You awake in a tavern from a drunken stupor*\n";
	cout << "*The bartender shouts* HEY YOU! You've been here all night. You need to leave or I'll kick ya out!\n";
	cout << "What should I do?\n";
	userChoice = decision();//there are three different kinds of decisions for three different situations

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
		if(dieValue > 15)//if the dice roll is above a certain number then something will happen, 
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
	cout << "*Hours seem to pass by in the blink of an eye*\n";
	cout << "*You awake to the sound of goblins chattering*\n";
	//the player is being hung upside down and is trapped
	cout << "*You regain your consciousness and realize you are hanging upside down from a piece of rope attached to a tree branch*\n";
	cout << "*You also see 3 GOBLINS sitting around a fire*\n";
	cout << "What will you do?\n";
	userChoice = decision2();
	if(userChoice == "Scream" || userChoice == "scream" || userChoice == "1")
	{
		cout << "Release me you FIENDS!\n";
		cout << "*You alert the goblins*\n";
		
	}
	else if(userChoice == "Release" || userChoice == "release" || userChoice == "2")
	{
		cout << "*you try to untie yourself but the goblins notice!*\n";
		detected();
	}
	else if(userChoice == "Stay" || userChoice == "stay" || userChoice == "3")
	{
		cout << "*You try not move until it's safe*\n";
		cout << "How long do you wait?\n";
		dieValue = roll()/2;
		cout << "You wait " << dieValue << " hours and check again\n";
		cout << "*It seems like the goblins are asleep*\n*you try to untie yourself and succeed*\n";
		if(dieValue < 15)
		{
			cout << "*You awake the Goblins*";
			detected();
		}else
		{
			cout << "*You manage to sneak away*";
		}
	}
	cout << "You finally are able to walk home into the sunset knowing that you will live for another day.\n";
	cout << "\n\n\t\tYOU WIN!\n\n";
}

