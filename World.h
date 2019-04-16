#pragma once
#include <memory>
#include <vector>
#include <queue>
#include <string>

#include "Human.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Belladona.h"
#include "Grass.h"
#include "Guarana.h"
#include "Hogweed.h"
#include "SowThistle.h"

class World
{
	using EPtr_t = std::shared_ptr<Entity>;

	using Row_t = std::vector<EPtr_t>;

	using EArr_t = std::vector<Row_t>;

	struct ECmp { bool operator()(EPtr_t const& l, EPtr_t const& r) const 
	{ return l->getInitiative() < r->getInitiative() || (l->getInitiative() == r->getInitiative() && l->getAge() < r->getAge()); } };

	using OrderedEArr_t = std::priority_queue<EPtr_t, Row_t, ECmp>;

	using Comment_t = std::string;

	using CommentsArr_t = std::vector<Comment_t>;

public:
	World() : size({ 20, 20 }) {}

	World(Vec2u const& size);

	World(World&&) = default;

	World& operator=(World&& other) { entities = std::move(other.entities); isPlayer = other.isPlayer; return *this; }

	// returns false on collision (cannot spawn entity at given position), true otherwise
	template<class T>
	bool spawnEntity(Vec2u const& pos);

	bool spawnEntity(size_t typeId, Vec2u const& pos);

	bool killEntity(Vec2u const& pos, Entity* killer);


	bool swap(Vec2u pos1, Vec2u pos2);


	void tick();

	void draw();


	void save();

	void load();

	void addComment(std::string comment);


	EPtr_t const& getEntityPtr(Vec2u const& pos) const;

	bool isOccupied(Vec2u const& pos) const;

public:

	Vec2u const size;

private:

	bool isPlayer = true;

	EArr_t entities;

	OrderedEArr_t ordEntities;
	CommentsArr_t comments;
};


template<class T>
bool World::spawnEntity(Vec2u const& pos)
{
	EPtr_t ent = std::make_shared<T>(*this);
	ent->setPosition(pos);

	if (isOccupied(pos))
		return false;
	entities[pos.y][pos.x] = std::move(ent);
	comments.push_back("Organizm " + Comment_t(typeid(T).name()).substr(6) + " zostal stworzony");
	return true;
}