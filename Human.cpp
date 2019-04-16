#include "Human.h"
#include "World.h"
#include <iostream>
#include <conio.h>

enum class Direction : uint8_t	{ Left, Right, Up, Down, Count };
static int DirCode[] =			{ 75, 77, 72, 80 };
static Vec2i DirVec[] =			{ {-1, 0}, {1, 0}, {0, -1}, {0, 1} };


Human::Human(World & world) : Animal(world, this, 'H')
{
	initiative = 4;
	str = DefaultStr;
	powerUp = -(int)AbilityExh;
}

void Human::tick()
{
	if (powerUp > -(int)AbilityExh)
		--powerUp;
	if (powerUp > 0)
		str = DefaultStr + powerUp;

	int dir = _getch();
	if (dir == 224)
	{
		dir = _getch();
		for (int i = 0; i < (uint8_t)Direction::Count; ++i)
			if (dir == DirCode[(uint8_t)Direction(i)])
			{
				Vec2i pos2 = Vec2i(pos) + DirVec[i];
				if (pos2.x >= 0 && pos2.y >= 0 && pos2.x < (int)world.size.x && pos2.y < (int)world.size.y)
				{
					attack(Vec2u(pos2));
					break;
				}
			}
	}
	else if (dir == 's' && powerUp <= -(int)AbilityExh)
	{
		powerUp += AbilityPowerUp;
		world.addComment("Czlowiek uzyl specjalnej umiejetnosci!");
	}
	else if (dir == 'z')
	{
		world.save();
		tick();
	}
	else if (dir == 'l')
		world.load();
}

void Human::save(std::ofstream & file)
{
	Animal::save(file);
	file << '\t' << powerUp << '\n';
}

void Human::load(std::ifstream & file)
{
	Animal::load(file);
	file >> powerUp;
}
