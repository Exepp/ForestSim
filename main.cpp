#include "World.h"
#include <ctime>

#include "Human.h"
#include "Wolf.h"


int main()
{
	srand(size_t(time(NULL)));
	World world({ 20, 20 });

	Human human(world);

	world.spawnEntity<Human>({ 0, 0 });
	world.spawnEntity<Wolf>({ 10,10 });
	world.spawnEntity<Wolf>({ 10,11 });
	world.spawnEntity<Sheep>({ 2,2 });
	world.spawnEntity<Sheep>({ 2,3 });
	world.spawnEntity<Fox>({ 19,7 });
	world.spawnEntity<Fox>({ 18,6 });
	world.spawnEntity<Turtle>({ 6, 19 });
	world.spawnEntity<Turtle>({ 7, 18 });
	world.spawnEntity<Antelope>({ 13, 19 });
	world.spawnEntity<Antelope>({ 14, 18 });
	world.spawnEntity<Belladona>({ 19,2 });
	world.spawnEntity<Grass>({ 18,3 });
	world.spawnEntity<Guarana>({ 2, 19 });
	world.spawnEntity<Hogweed>({ 3, 18 });
	world.spawnEntity<SowThistle>({ 18, 19 });

	world.draw();

	while (1)
	{
		world.tick();
		world.draw();
	}


	return 0;
}