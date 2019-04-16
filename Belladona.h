#pragma once
#include "Plant.h"

class Belladona : public Plant
{
public:
	Belladona(World& world);

	virtual bool defendFrom(Entity & entity) override;
};

