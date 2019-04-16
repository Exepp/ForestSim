#pragma once
#include "Animal.h"

class Human : public Animal
{
public:
	Human(World& world);

	virtual void tick() override;

	virtual void save(std::ofstream& file) override;

	virtual void load(std::ifstream& file) override;

private:

	int powerUp = 0;

	static size_t const DefaultStr = 5;

	static size_t const AbilityExh = 5;

	static size_t const AbilityPowerUp = 5;
};

