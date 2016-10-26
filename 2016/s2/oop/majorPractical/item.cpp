#include <string>
#include <iostream>
#include <stdlib.h>

#include "item.h"
#include "player.h"

using namespace std;

// Forward decalration of the Player class.

class Player;

// Basic constructor of a potion item, taking in the item's name and item effect.

Potion::Potion( string potName, int healEff )
{
  name = potName;
  effect = healEff;
}

void Potion::apply( Player *player1 )
{
  player1->health += effect;
  cout << "You drink " << name << "and restore " << effect << " points of health" << endl;
  cin;	
}

Potion::~Potion()
{
}

Weapon::Weapon( string weapName, int weapAtk )
{
  name = weapName;
  effect = weapAtk;
}

// Allows the user to equip an item to their player, with the effects from said item taking immediate effect over the players stats.
void Weapon::apply( Player *player1 )
{
  player1->weaponDamage = effect;
  cout << "You have equipped " << name << endl;
  cin;
}

Weapon::~Weapon()
{
}
