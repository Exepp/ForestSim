#include "Plant.h"
#include "World.h"


void Plant::tick()
{
	if (rand() % 100 < (int)ReproduceChance)
	{
		std::vector<Vec2u> freeIdx;
		Vec2u min = { (uint32_t)std::max(0, (int)pos.x - 1), (uint32_t)std::max(0, (int)pos.y - 1) };
		Vec2u max = { std::min(world.size.x - 1, pos.x + 1), std::min(world.size.y - 1, pos.y + 1) };

		for (uint32_t i = min.x; i <= max.x; ++i)
			if (Vec2u mPos(i, pos.y); mPos != pos && !world.isOccupied(mPos))
				freeIdx.push_back(mPos);
		for (uint32_t i = min.y; i <= max.y; ++i)
			if (Vec2u mPos(pos.x, i); mPos != pos && !world.isOccupied(mPos))
				freeIdx.push_back(mPos);

		if(freeIdx.size())
			attack(freeIdx[rand() % freeIdx.size()]);
	}
}

void Plant::attack(Vec2u const & pos2)
{
	world.spawnEntity(TypeId, pos2);
}