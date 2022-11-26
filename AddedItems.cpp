// .ccp implementation of added items .h
#include "AddedItems.h"


//If player combines vase and net it will construct golden armor
void addGoldenArmor(Player& currPlayer, LoadedObjects& allObjs)
{
	currPlayer.pickUp(allObjs.getByName("ArmorG"));
	allObjs.setWhereitIS("ArmorG", "inventory");
}

//if Player opens crate it gives him golden shield
void addGoldenShield(Player& currPlayer, LoadedObjects& allObjs)
{
	currPlayer.pickUp(allObjs.getByName("ShieldG"));
	allObjs.setWhereitIS("ShieldG", "inventory");
}

void addPotion(Player& currPlayer, LoadedObjects& allObjs)
{
	allObjs.addPotionAfterBattleWithClone(currPlayer);
}