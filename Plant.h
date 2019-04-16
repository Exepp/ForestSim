#pragma once
#include "Entity.h"

class Plant : public Entity
{
protected:
	template<class T>
	Plant(World& world, T const* t, char displayChar, size_t reproduceChance) 
		: Entity(world, t, displayChar)
		, ReproduceChance(reproduceChance) 
	{ initiative = str = 0; }

public:

	virtual void tick() override;

	virtual void attack(Vec2u const& pos) override;


	const size_t ReproduceChance; // in %
};

