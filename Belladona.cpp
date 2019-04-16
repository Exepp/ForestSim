#include "Belladona.h"
#include "World.h"


Belladona::Belladona(World & world) : Plant(world, this, 'B', 10)
{
	str = 99;
}

bool Belladona::defendFrom(Entity & entity)
{
	world.killEntity(entity.getPosition(), this);
	return false;
}
