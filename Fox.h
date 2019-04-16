#pragma once
#include "Animal.h"

class Fox : public Animal
{
public:
	Fox(World& world);

	virtual void tick() override;
};

