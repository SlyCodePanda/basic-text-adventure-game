#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <iostream>

#include "player.h"

using namespace std;

// Forward declaration of Player class.

class Player;

// Constructs enemy and sets the type of enemy, health and attack values.
// Checks the health of the enemy to see if health has reached 0.
// Enemy attacks player, depleting players health by the attack value.

class Enemy
{
	public:
	Enemy( string enType, int hp,int atk );
	
	string type;
	int health;
	int attackDmg;

	bool checkHealth();	
	void attack( Player *player1 );

	~Enemy();
};

#endif
