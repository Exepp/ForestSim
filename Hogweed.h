#pragma once
#include "Plant.h"

class Hogweed : public Plant
{
public:
	Hogweed(World& world);


	virtual void tick() override;

	virtual bool defendFrom(Entity & entity) override;
};

