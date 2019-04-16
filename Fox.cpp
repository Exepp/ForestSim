#include "Fox.h"
#include "World.h"


Fox::Fox(World & world) : Animal(world, this, 'F')
{
	initiative = 7;
	str = 3;
}

void Fox::tick()
{
	std::vector<Vec2u> freeIdx;

	Vec2u min = { (uint32_t)std::max(0, (int)pos.x - 1), (uint32_t)std::max(0, (int)pos.y - 1) };
	Vec2u max = { std::min(world.size.x - 1, pos.x + 1), std::min(world.size.y - 1, pos.y + 1) };

	for (uint32_t i = min.x; i <= max.x; ++i)
		if (Vec2u mPos(i, pos.y); mPos != pos && (!world.isOccupied(Vec2u(mPos)) || (world.getEntityPtr(Vec2u(mPos))->getStrength() <= str || world.getEntityPtr(Vec2u(mPos))->TypeId == TypeId)))
			freeIdx.push_back(mPos);
	for (uint32_t i = min.y; i <= max.y; ++i)
		if (Vec2u mPos(pos.x, i); mPos != pos && (!world.isOccupied(Vec2u(mPos)) || (world.getEntityPtr(Vec2u(mPos))->getStrength() <= str || world.getEntityPtr(Vec2u(mPos))->TypeId == TypeId)))
			freeIdx.push_back(mPos);

	if(freeIdx.size())
		attack(freeIdx[rand() % freeIdx.size()]);
}
