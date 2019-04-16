#include "Entity.h"
#include <iostream>

size_t TypeIdCounter = 0;

void Entity::tick()
{
	++age;
}

void Entity::save(std::ofstream & file)
{
	file << pos.x << ' ' << pos.y << ' ' << age << ' ' << str << '\n';
}

void Entity::load(std::ifstream & file)
{
	file >> pos.x >> pos.y  >> age  >> str;
}

void Entity::draw() const
{
	std::cout << DisplayChar;
}
