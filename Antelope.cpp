#include "Antelope.h"
#include "World.h"

Antelope::Antelope(World & world) : Animal(world, this, 'A')
{
	initiative = 4;
	str = 4;
}

void Antelope::tick()
{
	std::vector<Vec2u> freeIdx;

	Vec2u min = { (uint32_t)std::max(0, (int)pos.x - (int)MaxMoveDist), (uint32_t)std::max(0, (int)pos.y - (int)MaxMoveDist) };
	Vec2u max = { std::min(world.size.x - 1, pos.x + MaxMoveDist), std::min(world.size.y - 1, pos.y + MaxMoveDist) };

	for (uint32_t i = min.x; i <= max.x; ++i)
		if(Vec2u mPos(i, pos.y); mPos != pos)
			freeIdx.push_back(mPos);
	for (uint32_t i = min.y; i <= max.y; ++i)
		if (Vec2u mPos(pos.x, i); mPos != pos)
			freeIdx.push_back(mPos);

	attack(freeIdx[rand() % freeIdx.size()]);
}

bool Antelope::defendFrom(Entity & entity)
{
	return (rand() % 100 < ChanceToRun);
}
