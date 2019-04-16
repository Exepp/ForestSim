#pragma once
#include "Entity.h"


class Animal : public Entity
{
	Animal() = delete;
protected:
	template<class T>
	Animal(World& world, T const* t, char displayChar) : Entity(world, t, displayChar) {}

public:

	virtual void tick() override;

	virtual void attack(Vec2u const& pos) override;

private:

	bool reproduced(Entity& other);
};