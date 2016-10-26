#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include <iostream>
#include "player.h"

using namespace std;

class Enemy
{
	public:
	Enemy(string enType, int hp,int atk);	//constructs enemy and sets the type of enemy, health and attack values
	bool checkHealth();	//checks the health of the enemy to see if health has reached 0
	void attack(Player *player1);	//enemy attacks player, depleting players health by the attack value
	~Enemy();

	string type;
	int health;
	int attackDmg;
};

#endif
