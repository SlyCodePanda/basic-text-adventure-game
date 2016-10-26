#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

#include "item.h"
#include "enemy.h"

using namespace std;

// Forward decleration of Enemy and Item classes.

class Enemy;
class Item;

// Encapsulates all information regarding the player.
// Allows you to enter a x-coordinate, y-coordinate, level, health, and exp. in initial constructor.

// Applies the array of pointers to the variable inventory.
// Retrieves values from inventory, mostly for testing purposes.

class Player
{
 public:
  Player( int xPos, int yPos, int lvl, int hp, int ex );

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

  void setInventory( Item **invt, int invtNum );	
  void getInventory();
	
  void setPlayerDamage( int pDam );

  void setWeaponDamage( int wDam );
  int getWeaponDamage();

  void setFinalDamage();
  int getFinalDamage();

  ~Player();

};
  
#endif
  
