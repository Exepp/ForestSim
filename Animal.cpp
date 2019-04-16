#include "Animal.h"
#include "World.h"


void Animal::tick()
{
	std::vector<Vec2u> freeIdx;

	if ((int)pos.x - 1 >= 0)
		freeIdx.push_back({ pos.x - 1, pos.y });
	if (pos.x + 1 < world.size.x)
		freeIdx.push_back({ pos.x + 1, pos.y });
	if ((int)pos.y - 1 >= 0)
		freeIdx.push_back({ pos.x, pos.y - 1 });
	if (pos.y + 1 < world.size.y)
		freeIdx.push_back({ pos.x, pos.y + 1 });

	attack(freeIdx[rand() % freeIdx.size()]);
}

void Animal::attack(Vec2u const& pos2)
{
	if (auto ePtr = world.getEntityPtr(pos2))
		if (reproduced(*ePtr) || ePtr->defendFrom(*this))
			return;
		else if (str < ePtr->getStrength())
			return (void)world.killEntity(pos, &*ePtr);
		else
			world.killEntity(pos2, this);
	world.swap(pos, pos2);
}

bool Animal::reproduced(Entity& other)
{
	Vec2u pos2 = other.getPosition();
	if (other.TypeId == this->TypeId)
	{
		Vec2u posMin = { std::min(pos.x, pos2.x), std::min(pos.y, pos2.y) };
		Vec2u posMax = { std::max(pos.x, pos2.x), std::max(pos.y, pos2.y) };
		Vec2u min = { (uint32_t)std::max(0, (int)posMin.x - 1), (uint32_t)std::max(0, (int)posMin.y - 1) };
		Vec2u max = { std::min(world.size.x - 1, posMax.x + 1), std::min(world.size.y - 1, posMax.y + 1) };

		for (uint32_t i = min.y; i < max.y; ++i)
			for (uint32_t j = min.x; j < max.x; ++j)
				if (world.spawnEntity(TypeId, { j, i }))
					return true;
		return true;
	}
	return false;
}
