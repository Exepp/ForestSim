#include "World.h"

#include <iostream>
#include <conio.h>
#include <typeinfo>
#include <fstream>


World::World(Vec2u const& size) : size(size)
{
	entities.resize(size.y);
	for (auto& eArr : entities)
		eArr.resize(size.x);
}

bool World::spawnEntity(size_t typeId, Vec2u const & pos)
{
	if (typeId == idOfType<Human>())
		return spawnEntity<Human>(pos);
	if (typeId == idOfType<Wolf>())
		return spawnEntity<Wolf>(pos);
	if (typeId == idOfType<Sheep>())
		return spawnEntity<Sheep>(pos);
	if (typeId == idOfType<Fox>())
		return spawnEntity<Fox>(pos);
	if (typeId == idOfType<Turtle>())
		return spawnEntity<Turtle>(pos);
	if (typeId == idOfType<Antelope>())
		return spawnEntity<Antelope>(pos);
	if (typeId == idOfType<Belladona>())
		return spawnEntity<Belladona>(pos);
	if (typeId == idOfType<Grass>())
		return spawnEntity<Grass>(pos);
	if (typeId == idOfType<Guarana>())
		return spawnEntity<Guarana>(pos);
	if (typeId == idOfType<Hogweed>())
		return spawnEntity<Hogweed>(pos);
	if (typeId == idOfType<SowThistle>())
		return spawnEntity<SowThistle>(pos);
	return false;
}

bool World::killEntity(Vec2u const & pos, Entity* killer)
{
	if (isOccupied(pos))
	{
		if (std::dynamic_pointer_cast<Human>(entities[pos.y][pos.x]))
			isPlayer = false;
		if(killer)
			addComment("Organizm " +  std::string(typeid(*entities[pos.y][pos.x]).name()).substr(6) + std::string(" zostaje zabity przez ") + std::string(typeid(*killer).name()).substr(6));
		else
			addComment("Organizm " + Comment_t(std::string(typeid(*entities[pos.y][pos.x]).name()).substr(6)) + " zostal zniszczony");
		entities[pos.y][pos.x].reset();
		return true;
	}
	return false;
}

bool World::swap(Vec2u pos1, Vec2u pos2)
{
	if (pos1.y < size.y && pos2.y < size.y && 
		pos1.x < size.x && pos2.x < size.x)
	{
		if (entities[pos1.y][pos1.x])
			entities[pos1.y][pos1.x]->setPosition(pos2);
		if (entities[pos2.y][pos2.x])
			entities[pos2.y][pos2.x]->setPosition(pos1);

		entities[pos1.y][pos1.x].swap(entities[pos2.y][pos2.x]);
		return true;
	}
	return false;
}

void World::tick()
{
	if (!isPlayer)
	{
		int dir = _getch();
		if (dir == 'z')
			save();
		else if (dir == 'w')
			load();
	}

	for (auto& eArr : entities)
		for (auto& ePtr : eArr)
			if (ePtr)
				ordEntities.push(ePtr);

	while (!ordEntities.empty())
	{
		if (Vec2u pos = ordEntities.top()->getPosition(); entities[pos.y][pos.x] == ordEntities.top()) // dont tick on killed entities
		{
			auto guard = ordEntities.top();
			ordEntities.top()->tick();
			ordEntities.top()->addAge();
		}
		ordEntities.pop();
	}
}

void World::draw()
{
	system("cls");
	std::cout << "Pawel Glomski 172026 Inf 2" << std::endl;

	for (auto& eArr : entities)
	{
		for (auto& ePtr : eArr)
			if (!ePtr)
				std::cout << ".";
			else
				ePtr->draw();
		
		std::cout << '\n';
	}

	//for (auto const& com : comments)
	//	std::cout << com << std::endl;
	comments.clear();
}

void World::save()
{
	std::ofstream file("save");
	file << size.x << ' ' << size.y << ' ' << isPlayer << '\n';
	for (auto& eArr : entities)
		for (auto& ePtr : eArr)
			if (ePtr)
			{
				file << ePtr->TypeId << " " << ePtr->getPosition().x << ' ' << ePtr->getPosition().y << '\n';
				ePtr->save(file);
			}
			else file << -1 << '\n';
}

void World::load()
{
	std::ifstream file("save");
	Vec2u newSize;
	file >> newSize.x >> newSize.y >> isPlayer;
	World newWorld(newSize);
	newWorld.isPlayer = isPlayer;
	*this = std::move(newWorld);

	for (auto& eArr : entities)
		for (auto& ePtr : eArr)
		{
			int id = 0;
			Vec2u pos;
			file >> id;
			if (id != -1)
			{
				file >> pos.x >> pos.y;
				spawnEntity(id, pos);
				ePtr->load(file);
			}
		}
}

void World::addComment(std::string comment)
{
	comments.push_back(std::move(comment));
}

World::EPtr_t const & World::getEntityPtr(Vec2u const & pos) const
{
	return entities[pos.y][pos.x];
}

bool World::isOccupied(Vec2u const & pos) const
{
	return bool(entities[pos.y][pos.x]);
}
