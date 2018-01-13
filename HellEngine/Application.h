#ifndef __H_APPLICATION__
#define __H_APPLICATION__

#include<list>
#include "Module.h"
#include "UpdateStatus.h"

class ModuleRender;
class ModuleWindow;
class ModuleTextures;
class ModuleInput;
class ModuleAudio;
class ModuleFadeToBlack;
class ModuleCollision;
class ModuleParticles;

/* Game modules */
class ModulePlayer;

class Application
{
public:

	Application();
	~Application();

	bool Init();
	UpdateStatus Update();
	bool CleanUp();

public:

	ModuleRender* renderer;
	ModuleWindow* window;
	ModuleTextures* textures;
	ModuleInput* input;
	ModuleAudio* audio;
	ModuleFadeToBlack* fade;
	ModuleCollision* collision;
	ModuleParticles* particles;

	/* Game modules */
	ModulePlayer* player;

private:

	std::list<Module*> modules;
};

extern Application* App;

#endif /* __H_APPLICATION__ */