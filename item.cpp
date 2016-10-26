#include "item.h"
#include "player.h"
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;
class Player;

Potion::Potion(string potName, int healEff)
{
	name = potName;
	effect = healEff;
}

void Potion::apply(Player *player1)
{
	player1->health += effect;
	cout << "You drink " << name << "and restore " << effect << " points of health" << endl;
	cin;

	
}

Potion::~Potion()
{
}

Weapon::Weapon(string weapName, int weapAtk)
{
	name = weapName;
	effect = weapAtk;
}

void Weapon::apply(Player *player1)
{
	player1->weaponDamage = effect;
	cout << "You have equipped " << name << endl;
	cin;
}

Weapon::~Weapon()
{
}
