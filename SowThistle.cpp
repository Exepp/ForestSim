#include "SowThistle.h"


SowThistle::SowThistle(World & world) : Plant(world, this, '9', 10)
{
}

void SowThistle::tick()
{
	for (int i = 0; i < ReproduceAttempts; ++i)
		Plant::tick();
}
