#include <iostream>
#include <string>
#include <stdlib.h>
#include "player.h"

using namespace std;

Player::Player(int xPos, int yPos, int lvl, int hp, int ex)
	:posX(xPos), posY(yPos), level(lvl), health(hp), exp(ex)
	{
	
	}


 void Player::setPlayerDamage( int pDam )
 {
   playerDamage = pDam;
 }

 void Player::setWeaponDamage( int wDam )
 {
   weaponDamage = wDam;
 }

 int Player::getWeaponDamage()
 {
   return weaponDamage;
 }

 void Player::setFinalDamage()
 {
   finalDamage = playerDamage + weaponDamage;
 }

 int Player::getFinalDamage()
 {
   return finalDamage;
 }

 void Player::setInventory(Item **invent, int inventNum)
 {
   inventory = invent;
   inventoryNum = inventNum;
 }
 
 void Player::getInventory()
 {
   for(int i = 0; i < inventoryNum; i++)
   {
     cout << inventory[i]->name << endl;
   }
 }

 Player::~Player()
 {
 }
