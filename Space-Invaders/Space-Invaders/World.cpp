#include "World.h"

World::World()
{
	objects = 0;
}
World::~World()
{
	int len = sizeof(ObjectList) / sizeof(ObjectList[0]);
	for (int i = 0; i < len; ++i)
	{
		if (ObjectList[i] == nullptr)
			break;

		delete &ObjectList[i];
	}
}

void World::addObject(Entity* Obj)
{
	objects += 1;
	ObjectList[objects] = Obj;
}
int World::removeObject(Entity* Obj)
{
	int len = sizeof(ObjectList) / sizeof(ObjectList[0]);
	for (int i = 0; i < len; ++i)
	{
		if (ObjectList[i] == nullptr)
			break;

		if (ObjectList[i] == Obj)
		{ 
			for (int j = i; j < len-2; ++j)
			{
				if (ObjectList[j] == nullptr)
					break;

				ObjectList[j] = ObjectList[j + 1];
			}
			return 1;
		}

	}
	objects -= 1;
	return -1;
}