#include <iostream>
#include <string>
#include <stdlib.h>

#include "player.h"
#include "enemy.h"
#include "item.h"

using namespace std;

// Declares the map as a global array

int map[4][4] = {{0,1,0,3},{3,0,5,4},{0,3,4,1},{0,4,2,5}};

// Foreward declares all functions

int pastMove;

void readRoom( Player *player1 );
void encounterGoblin( Player *player1 );
void encounterGhost( Player *player1 );
void encounterDemon( Player *player1 );
void emptyRoom( Player *player1 );
void findPotion( Player *player1 );
void findWeapon( Player *player1 );
void victory( Player *player1 );

// This function prompts player for input regarding movement around the map. If player is already on the edge of the map it will
// not allow the player to proceed. If the player inputs an incorrect command it prompts the player again.

void movement( Player *player1 )	
{															
  cout << endl;
  string input;
  
  cout << "Please specify which direction to move... (Please use North, north, N, n etc)" << endl;
  cin >> input;
  cout << endl;
  cout << "----------------------" << endl;
	
  if( input == "North" | input == "north" | input == "N" | input == "n" )
    {
      if( player1->posY < 3 )
	{
	  player1->posY++;
	  pastMove = 1;
	}
      else
	{
	  cout << "You head down the corridor but come across a dead end." << endl;
	  cout << "It seems you cannot proceed any further this way." << endl;
	  cout << "You proceed back the way you came" << endl << endl;
	  movement( player1 );
	}
    }
  else if( input == "South" | input == "south" | input == "S" | input == "s" )
    {
      if( player1->posY > 0 )
	{
	  player1->posY--;
	  pastMove = 3;
	}
      else
	{
	  cout << "You head down the corridor but come across a dead end." << endl;
	  cout << "It seems you cannot proceed any further this way." << endl;
	  cout << "You proceed back the way you came" << endl << endl;
	  movement( player1 );
	}
    }
  else if( input == "East" | input == "east" | input == "E" | input == "e" )
    {
      if( player1->posX < 3 )
	{
	  player1->posX++;
	  pastMove = 2;
	}
      else
	{
	  cout << "You head down the corridor but come across a dead end." << endl;
	  cout << "It seems you cannot proceed any further this way." << endl;
	  cout << "You proceed back the way you came" << endl << endl;
	  movement( player1 );
	}
    }
  else if( input == "West" | input == "west" | input == "W" | input == "w" )
    {
      if( player1->posX > 0 )
	{
	  player1->posX--;
	  pastMove = 4;
	}
      else
	{
	  cout << "You head down the corridor but come across a dead end." << endl;
	  cout << "It seems you cannot proceed any further this way." << endl;
	  cout << "You proceed back the way you came" << endl << endl;
	  movement( player1 );
	}
    }
  else
    {
      cout << "This is not a valid command" << endl;
      movement( player1 );
    }
  
  readRoom( player1 );	
}

// This function checks the room that the player is in and checks whether that room has an enemy encounter inside.
// If so, it runs one of the three enemy encounter functions, or an empty room encounter.

void readRoom( Player *player1 )
{
  cout << endl;
  int room = map[player1->posY][player1->posX];
  
  if( room == 3 )
    {
      encounterGoblin( player1 );
    }

  else if( room == 4 )
    {
      encounterGhost( player1 );
    }
  
  else if( room == 5 )
    {
      encounterDemon( player1 );
    }
  
  else if( room == 1 )
    {
      findPotion( player1 );
    }
  
  else if( room == 2 )
    {
      findWeapon( player1 );
    }
  
  else
    {
      emptyRoom( player1 );
    }
}

// This function is initiated once an enemy has been encountered, allowing the player to either fight, run, check inventory, or check status.
// The player selects their chosen option using a cin statement.
// If the fight option is selected, the enemy and player will do damage to each other,
// If both are still alive, options will be prompted again.

void battle( Player *player1, Enemy *enemy )
{
  cout << endl;
  while( player1->health > 0 )
    {
      cout << "What do you do?" << endl << endl;
      cout << "Fight (f)   Run (r)	Check Inventory (i)	Check Status (s)" << endl;
      string input;
      cin >> input;
      cout << endl;
      cout << "----------------------" << endl;
      
      if( input == "f" )
	{
	  int damage = player1->finalDamage + rand() % 10 + 1;
	  enemy->health = enemy->health - damage;
	  cout << endl << "You attack the " << enemy->type << ", dealing " << damage << " damage." << endl << endl;
	  bool enemyAlive = enemy->checkHealth();
	  
	  if( enemyAlive == true )
	    {
	      enemy->attack( player1 );
	    }
	  
	  if( enemyAlive == false )
	    {
	      cout << "You have slain the " << enemy->type << endl;
	      delete enemy;
	      victory( player1 );
	    }
	}

      else if( input == "r" )
	{
	  int chance = rand() % 10 + 1;
	  cout << endl;
	  
	  if( chance > 3 )
	    {
	      cout << "You successfully flee into the darkness..." << endl;
	      delete enemy;
	      
	      if( pastMove == 1 )
		{
		  player1->posY++;
		  readRoom(player1);
		}
	      
	      if( pastMove == 2 )
		{
		  player1->posX--;
		  readRoom( player1 );
		}
	      
	      if( pastMove == 3 )
		{
		  player1->posY--;
		  readRoom( player1 );
		}
	      
	      if( pastMove == 4 )
		{
		  player1->posX++;
		  readRoom(player1);
		}
	    }
	  
	  if( chance <= 2 )
	    {
	      cout << "You fail to escape" << endl << endl;
	      enemy->attack( player1 );
	    }
	}

      else if( input == "i" )
	{
	  player1->getInventory();
	  int input2;
	  cout << endl << "Input the number slot of the item you wish to use..." << endl;
	  cin >> input2;
	  player1->inventory[input2]->apply( player1 );
	  battle( player1, enemy );
	}
      
      else if( input == "s" )
	{
	  cout << "Level: " << player1->level << endl;
	  cout << "Health: " << player1->health << endl;
	  cout << "Damage: " << player1->finalDamage << endl;
	  battle( player1, enemy );
	}
      else
	{
	  cout << "Invalid Entry..." << endl << endl;
	}
    }

  cout << endl << "You have been slain. GAME OVER" << endl;
  return;
}

// The following functions are the individual encounters of the three different enemies: Goblin, Ghost, and Demon.
// Each enemy interaction begins with introducing which enemy you have ran into.

void encounterGoblin( Player *player1 )
{
  cout << endl;
  Enemy *enemy;
  enemy = new Enemy( "Goblin", 50, 0 );

  cout << "You have run into a " << enemy->type << endl;

  battle( player1, enemy );
}

void encounterGhost( Player *player1 )
{
  cout << endl;
  Enemy *enemy;
  enemy = new Enemy( "Ghost", 80, 15 );

  cout << "You have run into a " << enemy->type << endl;
  
  battle( player1, enemy );
}

void encounterDemon( Player *player1 )
{
  cout << endl;
  Enemy *enemy;
  enemy = new Enemy( "Demon", 80, 25 );
  
  cout << "You have run into a " << enemy->type << endl;
  
  battle( player1, enemy );
}

// If there is no enemy in the given room, this function will run.

void emptyRoom( Player *player1 )
{
  cout << "This room is empty..." << endl << endl;
  movement( player1 );
}

// If the room has an item inside, the following function will run. Giving the player the option to put said found item into the inventory.
// The item will either be a potion or weapon, which are sub-classes of the item class.

void findPotion( Player *player1 )
{
  cout << endl;;
  
  Potion *potion;
  potion = new Potion( "Health Potion", 20 );
  
  cout << "This room is empty, however upon closer inspection" << endl;
  cout << "you find a health potion, do you wish to take the potion?" << endl << endl;
  cout << "(y/n)?" << endl;
  string input;
  cin >> input;

  if( input == "y" )
    {
      player1->getInventory();
      int input2;
      cout << endl << "Input the number slot you wish to place the item..." << endl;
      cin >> input2;
      
      player1->inventory[input2] = potion;
      
      movement( player1 );
    }
  
  if( input == "n" )
    {
      cout << endl << "You leave the potion where it is" << endl;
      movement( player1 );
    }
  delete potion;
}

void findWeapon( Player *player1 )
{
  cout << endl;;
  
  Weapon *weapon;
  weapon = new Weapon( "Greater Sword", 30 );
  
  cout << "This room is empty, however upon closer inspection" << endl;
  cout << "you find a" << weapon->name << ", do you wish to take the weapon?" << endl;
  cout << "(y/n)" << endl;
  string input;
  cin >> input;
  
  if( input == "y" )
    {
      player1->getInventory();
      int input2;
      cout << endl << "Input the number slot you wish to place the item..." << endl;
      cin >> input2;
      
      player1->inventory[input2] = weapon;
      delete weapon;
      movement( player1 );
    }
  
  if( input == "n" )
    {
      cout << endl << "You leave the weapon where it is" << endl;
      delete weapon;
      movement( player1 );
    }
	
}

// If a battle interaction is won by the player, this function will run. Issuing the player with a set amount of expierience points.
// These points are added to the players base stats.

void victory( Player *player1 )
{
  player1->exp+=20;
  cout << "You now have " << player1->exp << " exp" << endl;
  
  if( player1->exp >= 100 )
    {
      player1->level++;
      
      cout << "***You have leveled up***" << endl;
      
      player1->maxHealth += 50;
      player1->health = player1->maxHealth;
      player1->playerDamage += 20;
      player1->exp = 0;
    }
  
  movement(player1);
}

main()
{
  Item **inventory = new Item*[4];
  inventory[0] = new Weapon("Basic Sword" , 10);
  inventory[1] = new Weapon("Greatsword", 40);
  inventory[2] = new Potion("Health Potion", 20);
  inventory[3] = new Potion("Greater Health Potion", 50);
  
  // Player1 is in position (0,0), is level 1, has 100 health, and 0 exp.
  
  Player *player1;
  player1 = new Player(0, 0, 1, 100, 0, 10, 100);
  player1->weaponName = "Basic Sword";
  player1->weaponDamage = 10;
  player1->setFinalDamage();
	
  //Giving Player1 inventory and printing what is in player1's inventory.
  player1->setInventory( inventory, 4 );

  // Output that initialises at the start of the game.
  
  cout << endl << "Welcome...to the dungeon" << endl << endl;
  
  cout << "You will encounter many dangers on your quest." << endl;

  
  movement( player1 );
    
}
