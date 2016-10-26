#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

#include "player.h"

using namespace std;

// Forward declaration of the Player class.

class Player;

// Applies the effect of the selected object to the player.
// Will replenish the players by the value of effect

class Item
{
 public:
  virtual void apply( Player *player1 ) = 0;
  
  string name;
  int effect;
};

// Sub-class of item.
// Potion will effect player's health points.

class Potion: public Item
{
 public:
  Potion( string potName, int healEff );
  
  void apply( Player *player1 );
  
  ~Potion();
};

// Sub-class of item.
// Will set the value of weapon damage in the player class to the value effect.

class Weapon: public Item
{
 public:
  Weapon( string weapName, int weapAtk );
  
  void apply( Player *player1 );
  
  ~Weapon();

};

#endif
