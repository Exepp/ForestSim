#pragma once
#include "Vec2.h"
#include <type_traits>
#include <memory>
#include <fstream>

class World;

template<class T>
size_t idOfType();

class Entity : public std::enable_shared_from_this<Entity>
{
protected:

	template<class T>
	Entity(World& world, T const* t, char displayChar) : world(world), TypeId(idOfType<T>()), DisplayChar(displayChar) {}

public:

	virtual ~Entity() = default;


	virtual void tick() = 0;

	virtual void attack(Vec2u const& pos) = 0;

	virtual bool defendFrom(Entity & entity) { return false; }

	virtual void save(std::ofstream& file);

	virtual void load(std::ifstream& file);


	void draw() const;


	void setPosition(Vec2u const& pos) { this->pos = pos; }

	void setStrength(size_t str) { this->str = str; }

	void addAge() { ++age; }
	
	
	Vec2u const& getPosition() const { return pos; }

	size_t getInitiative() const { return initiative; }

	size_t getStrength() const { return str; }

	size_t getAge() const { return age; }


public:
	const size_t TypeId;


protected:
	Vec2u pos = Vec2u::ZeroVector;

	size_t initiative = 0;

	size_t age = 0;

	size_t str = 0;

	char DisplayChar = '?';

	World& world;
};


template<class T>
size_t idOfType()
{
	static_assert(std::is_base_of_v<Entity, T>);
	extern size_t TypeIdCounter;
	static size_t id = TypeIdCounter++;
	return id;
}