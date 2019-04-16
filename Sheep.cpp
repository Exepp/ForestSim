#include "Sheep.h"

Sheep::Sheep(World & world) : Animal(world, this, 'S')
{
	str = 4;
	initiative = 4;
}
