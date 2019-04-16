#pragma once
#include "Animal.h"

class Turtle : public Animal
{
public:
	Turtle(World& world);

	virtual void tick() override;

	virtual bool defendFrom(Entity & entity) override;

private:

	static size_t const defence = 4; // blocks attacks from animals with str <= 4

	static size_t const MoveChance = 75; // in %
};

