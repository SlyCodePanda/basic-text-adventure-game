#include "enemy.h"
#include "player.h"
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

Enemy::Enemy(string enType, int hp,int atk)
	:type(enType), health(hp), attackDmg(atk)
{
}

bool Enemy::checkHealth()
{
	if(health <=0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Enemy::attack(Player *player1)
{
	int damage = attackDmg + rand() % 10 + 1;
	player1->health = player1->health - damage;
	cout << "The " << type << " attacks you, dealing " << damage << " damage." << endl;
	cin;
}

Enemy::~Enemy()
{
}

