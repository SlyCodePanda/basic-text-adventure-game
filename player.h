#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "item.h"
/*#include "enemy.h"*/

using namespace std;
class Enemy;
class Item;
//Encapsulates all information regarding the player.
//Allows you to enter a x-coordinate, y-coordinate, level, health, and exp. in initial constructor.
class Player
{
 public:
  Player(int xPos, int yPos, int lvl, int hp, int ex);

  int level;
  int health;
  int exp;

  string weaponName;
  
  int playerDamage;
  int weaponDamage;
  int finalDamage;
  
  Item **inventory;
  int inventoryNum;
  
  int posX;
  int posY;

	void setInventory(Item **invt, int invtNum);	//applies the array of pointers to the variable inventory
	void getInventory();	//retrieves values from inventory, mostly for testing purposes
	
  void setPlayerDamage(int pDam);

  void setWeaponDamage(int wDam);
  int getWeaponDamage();

  void setFinalDamage();
  int getFinalDamage();


  
  ~Player();

};
  
#endif
  
