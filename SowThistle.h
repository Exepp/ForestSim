#pragma once
#include "Plant.h"
class SowThistle : public Plant
{
public:

	SowThistle(World& world);

	virtual void tick() override;

	static size_t const ReproduceAttempts = 3;
};

