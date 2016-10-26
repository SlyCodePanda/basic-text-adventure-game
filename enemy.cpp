#include <string>
#include <iostream>
#include <stdlib.h>

#include "enemy.h"
#include "player.h"

using namespace std;

// Basic Enemy constructor that allows input for the enemies' type, health, and attack.

Enemy::Enemy( string enType, int hp,int atk )
	:type( enType ), health( hp ), attackDmg( atk )
{
}

// Behaviour allowing the program to refer to the enemies' health.
// Primarily used during battle function for checking if the enemy is still alive.

bool Enemy::checkHealth()
{
  if( health <=0 )
    {
      return false;
    }
  else
    {
      return true;
    }
}

// Behaviour that allows the enemy to attack the player in the battle functioin.
// Its attack has a randomiser attached where it does its base attack with a random addition of 1-10% using stdlib.h.

void Enemy::attack( Player *player1 )
{
  int damage = attackDmg + rand() % 10 + 1;
  player1->health = player1->health - damage;
  cout << "The " << type << " attacks you, dealing " << damage << " damage." << endl;
  cin;
}

Enemy::~Enemy()
{
}

