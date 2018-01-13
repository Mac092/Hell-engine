#ifndef __H_DUMMY__
#define __H_DUMMY__

#include "Globals.h"
#include "Module.h"

class ModuleDummy : public Module
{
public:

	bool Init()
	{
		LOG("Dummy Init!");
		return true;
	}

	bool CleanUp()
	{
		LOG("Dummy CleanUp!");
		return true;
	}
};

#endif /* __H_DUMMY__ */