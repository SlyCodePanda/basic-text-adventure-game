#ifndef ITEM_H
#define ITEM_H
#include "player.h"
#include <string>
#include <iostream>

using namespace std;
class Player;

class Item
{
	public:
	virtual void apply(Player *player1) = 0;	//Applies the effect of the selected object to the player
	
	string name;
	int effect;
};

class Potion: public Item
{
	public:
	Potion(string potName, int healEff);
	void apply(Player *player1);	//Will replenish the players by the value of effect
	~Potion();
};

class Weapon: public Item
{
	public:
	Weapon(string weapName, int weapAtk);
	void apply(Player *player1); //Will set the value of weapon damage in the player class to the value effect
	~Weapon();

};

#endif
