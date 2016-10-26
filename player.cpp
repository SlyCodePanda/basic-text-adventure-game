#include <iostream>
#include <string>
#include <stdlib.h>

#include "player.h"

using namespace std;

// Basic Player constructor that allows for input giving the player their position in x & y space, their level, health, and exp.

Player::Player( int xPos, int yPos, int lvl, int hp, int ex )
	:posX( xPos ), posY( yPos ), level( lvl ), health( hp ), exp( ex )
{
	
}

// Sets the players base damage before and inventory additions.

void Player::setPlayerDamage( int pDam )
{
  playerDamage = pDam;
}

// This is used when a weapon item is equipped to the player, altering the players attack damage when in battle.

void Player::setWeaponDamage( int wDam )
{
  weaponDamage = wDam;
}

// Retrieving the players equipped weapon damage for use when deducting enemy health.

int Player::getWeaponDamage()
{
  return weaponDamage;
}

// Sets the final player damage from players base damage plus the equipped item damage. Resulting in total damage deducted from enemy health.

void Player::setFinalDamage()
{
  finalDamage = playerDamage + weaponDamage;
}

int Player::getFinalDamage()
{
  return finalDamage;
}

// Takes a pointer to another pointer from the Item class, to place them in the players inventory. So items that are added can be used
// during the battle function.

void Player::setInventory(Item **invent, int inventNum)
{
  inventory = invent;
  inventoryNum = inventNum;
}
 
void Player::getInventory()
{
  for(int i = 0; i < inventoryNum; i++){
    cout << inventory[i]->name << endl;
  }
}

Player::~Player()
{
}
