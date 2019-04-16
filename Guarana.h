#pragma once
#include "Plant.h"

class Guarana : public Plant
{
public:
	Guarana(World& world);

	virtual bool defendFrom(Entity & entity) override;

	static size_t const StrBoost = 3;

};

