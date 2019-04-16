#pragma once
#include "Animal.h"

class Antelope : public Animal
{
public:
	Antelope(World& world);

	virtual void tick() override;

	virtual bool defendFrom(Entity & entity) override;

private:

	static size_t const ChanceToRun = 50; // in %

	static size_t const MaxMoveDist = 2;
};

