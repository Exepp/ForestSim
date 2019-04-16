#include "Turtle.h"


Turtle::Turtle(World & world) : Animal(world, this, 'T')
{
	initiative = 1;
	str = 2;
}

void Turtle::tick()
{
	if (rand() % 100 < MoveChance)
		Animal::tick();
}

bool Turtle::defendFrom(Entity & entity)
{
	return (entity.getStrength() <= defence);
}

