#include <iostream>
#include <string>
#include <stdlib.h>
#include "player.h"
#include "enemy.h"
#include "item.h"

using namespace std;

int map[4][4] = {{0,3,4,5},{0,0,0,0},{0,0,0,0},{0,0,0,0}};	//declares the map as a global array
int pastMove;
void readRoom(Player *player1);
void encounterGoblin(Player *player1);
void encounterGhost(Player *player1);
void encounterDemon(Player *player1);
void emptyRoom(Player *player1);


void movement(Player *player1)
{
	cout << "~started movement function~" << endl;
	string input;
	cout << "Your Position is: " << player1->posX << ", " << player1->posY << endl;
	cout << "Please specify which direction to move... (Please use North, north, N, n etc)" << endl;
	cin >> input;
	cout << endl;
	cout << "----------------------" << endl;
	
	if(input == "North" | input == "north" | input == "N" | input == "n")
	{
		if(player1->posY < 3)
		{
			player1->posY++;
			pastMove = 1;
		}
		else
		{
			cout << "You head down the corridor but come across a dead end. It seems you cannot proceed any further this way." << endl << endl << "You proceed back " 			<< "the way you came" << endl;
			movement(player1);
		}
	}
	else if(input == "South" | input == "south" | input == "S" | input == "s")
	{
		if(player1->posY > 0)
		{
			player1->posY--;
			pastMove = 3;
		}
		else
		{
			cout << "You head down the corridor but come across a dead end. It seems you cannot proceed any further this way." << endl << endl << "You proceed back " 			<< "the way you came" << endl;
			movement(player1);
		}
	}
	else if(input == "East" | input == "east" | input == "E" | input == "e")
	{
		if(player1->posX < 3)
		{
			player1->posX++;
			pastMove = 2;
		}
		else
		{
			cout << "You head down the corridor but come across a dead end." << endl;
			cout << "It seems you cannot proceed any further this way." << endl;
			cout << "You proceed back the way you came" << endl << endl;
			movement(player1);
		}
	}
	else if(input == "West" | input == "west" | input == "W" | input == "w")
	{
		if(player1->posX > 0)
		{
			player1->posX--;
			pastMove = 4;
		}
		else
		{
			cout << "You head down the corridor but come across a dead end. It seems you cannot proceed any further this way." << endl << endl << "You proceed back " 			<< "the way you came" << endl;
			movement(player1);
		}
	}
	else
	{
		cout << "This is not a valid command" << endl;
		movement(player1);
	}

	readRoom(player1);	
}

void readRoom(Player *player1)
{
	cout << "~Started readRoom function~" << endl;
	int room = map[player1->posY][player1->posX];
	cout << "Room ID: " << room << endl << endl;

	if(room == 3)
	{
		encounterGoblin(player1);
	}

	else if(room == 4)
	{
		encounterGhost(player1);
	}

	else if(room == 5)
	{
		encounterDemon(player1);
	}

	else if(room == 1)
	{
		//findPotion(player1);
	}

	else if(room == 2)
	{
		//findWeapon(player1);
	}

	else
	{
		emptyRoom(player1);
	}
}

void battle(Player *player1, Enemy *enemy)
{
	cout << "~started battle function~" << endl;
	while(player1->health > 0)
	{
		cout << "What do you do?" << endl << endl;
		cout << "Fight (f)   Run (r)	Check Inventory (i)	Check Status (s)" << endl;
		string input;
		cin >> input;
		cout << endl;
		cout << "----------------------" << endl;

		if(input == "f")
		{
			int damage = player1->finalDamage + rand() % 10 + 1;
			enemy->health = enemy->health - damage;
			cout << "You attack the " << enemy->type << ", dealing " << damage << " damage." << endl;
			bool enemyAlive = enemy->checkHealth();

			if(enemyAlive == true)
			{
				cout << "checked enemy - still alive" << endl;
				enemy->attack(player1);
			}

			if(enemyAlive == false)
			{
				cout << "checked enemy - dead" << endl;
				cout << "You have slain the " << enemy->type << endl;
				return;
			}
		}

		else if(input == "r")
		{
			int chance = rand() % 10 + 1;
			cout << endl;

			if(chance > 3)
			{
				cout << "You successfully flee the way you came..." << endl;
				delete enemy;

				if(pastMove == 1)
				{
					player1->posY++;
					readRoom(player1);
				}

				if(pastMove == 2)
				{
					player1->posX--;
					readRoom(player1);
				}

				if(pastMove == 3)
				{
					player1->posY--;
					readRoom(player1);
				}

				if(pastMove == 4)
				{
					player1->posX++;
					readRoom(player1);
				}
			}

			if(chance <= 2)
			{
				cout << "You fail to escape" << endl << endl;
				enemy->attack(player1);
			}
		}

		else if(input == "i")
		{
			player1->getInventory();
		}

		else
		{
			cout << "Invalid Entry..." << endl << endl;
		}
	}

		cout << endl << "You have been slain. GAME OVER" << endl;
		return;
}

void encounterGoblin(Player *player1)
{
	cout << "~started encounterGoblin function~" << endl;
	Enemy *enemy;
	enemy = new Enemy( "Goblin", 50, 0 );

	cout << "You have run into a " << enemy->type << endl;

	battle(player1, enemy);
}

void encounterGhost(Player *player1)
{
	cout << "~started encounterGhost function~" << endl;
	Enemy *enemy;
	enemy = new Enemy( "Ghost", 80, 15 );

	cout << "You have run into a " << enemy->type << endl;

	battle(player1, enemy);
}

void encounterDemon(Player *player1)
{
	cout << "~started encounterDemon function~" << endl;
	Enemy *enemy;
	enemy = new Enemy( "Demon", 80, 25 );

	cout << "You have run into a " << enemy->type << endl;

	battle(player1, enemy);
}

void emptyRoom(Player *player1)
{
	cout << "This room is empty..." << endl << endl;
	movement(player1);
}

main()
{
  Item **inventory = new Item*[4];
  
  //Player1 is in position (1,1), is level 1, has 100 health, and 0 exp.
  Player *player1;
  player1 = new Player(0, 0, 1, 100, 0);
	player1->weaponName = "Basic Sword";
	player1->weaponDamage = 10;
	player1->setFinalDamage();
  //Giving Player1 inventory and printing what is in player1's inventory.
	player1->setInventory(inventory, 4);

	cout << endl << "Welcome...to the dungeon" << endl << endl;

	cout << "You will encounter many dangers on your quest." << endl;

  
	movement(player1);
    
}
