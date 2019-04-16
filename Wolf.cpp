#include "Wolf.h"

Wolf::Wolf(World & world) : Animal(world, this, 'W')
{
	initiative = 5;
	str = 9;
}
