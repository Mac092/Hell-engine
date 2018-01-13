#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )
#include "SDL/include/SDL.h"
#include <stdlib.h>
#include "Application.h"
#include "Globals.h"
#include "MainStates.h"
#include "UpdateStatus.h"

Application* App = nullptr;

int main(int argc, char ** argv)
{
	ReportMemoryLeaks();

	int mainReturn = EXIT_FAILURE;
	MainStates state = MainStates::MAIN_CREATION;

	while (state != MainStates::MAIN_EXIT)
	{
		switch (state)
		{
		case MainStates::MAIN_CREATION:

			LOG("Application Creation --------------");
			App = new Application();
			state = MainStates::MAIN_START;
			break;

		case MainStates::MAIN_START:

			LOG("Application Init --------------");
			if (App->Init() == false)
			{
				LOG("Application Init exits with error -----");
				state = MainStates::MAIN_EXIT;
			}
			else
			{
				state = MainStates::MAIN_UPDATE;
				LOG("Application Update --------------");
			}

			break;

		case MainStates::MAIN_UPDATE:
		{
			UpdateStatus updateReturn = App->Update();

			if (updateReturn == UpdateStatus::UPDATE_ERROR)
			{
				LOG("Application Update exits with error -----");
				state = MainStates::MAIN_EXIT;
			}

			if (updateReturn == UpdateStatus::UPDATE_STOP)
				state = MainStates::MAIN_FINISH;
		}
		break;

		case MainStates::MAIN_FINISH:

			LOG("Application CleanUp --------------");
			if (App->CleanUp() == false)
			{
				LOG("Application CleanUp exits with error -----");
			}
			else
				mainReturn = EXIT_SUCCESS;

			state = MainStates::MAIN_EXIT;

			break;

		}
	}

	RELEASE(App);
	LOG("Bye :)\n");
	return mainReturn;
}