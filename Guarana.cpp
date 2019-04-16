#include "Guarana.h"



Guarana::Guarana(World & world) : Plant(world, this, 'G', 10)
{
}

bool Guarana::defendFrom(Entity & entity)
{
	entity.setStrength(entity.getStrength() + StrBoost);
	return false;
}
