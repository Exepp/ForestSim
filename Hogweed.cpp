#include "Hogweed.h"
#include "World.h"
#include "Animal.h"

Hogweed::Hogweed(World & world) : Plant(world, this, '#', 10)
{
	str = 10;
}

void Hogweed::tick()
{
	Plant::tick();

	Vec2u min = { (uint32_t)std::max(0, (int)pos.x - 1), (uint32_t)std::max(0, (int)pos.y - 1) };
	Vec2u max = { std::min(world.size.x - 1, pos.x + 1), std::min(world.size.y - 1, pos.y + 1) };

	for (uint32_t i = min.x; i <= max.x; ++i)
		if (Vec2u mPos(i, pos.y); mPos != pos && world.isOccupied(mPos) && std::dynamic_pointer_cast<Animal>(world.getEntityPtr(mPos)))
			world.killEntity(mPos, this);
	for (uint32_t i = min.y; i <= max.y; ++i)
		if (Vec2u mPos(pos.x, i); mPos != pos && world.isOccupied(mPos) && std::dynamic_pointer_cast<Animal>(world.getEntityPtr(mPos)))
			world.killEntity(mPos, this);
}

bool Hogweed::defendFrom(Entity & entity)
{
	world.killEntity(entity.getPosition(), this);
	return false;
}
