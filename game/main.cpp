#include <G3DAll.h>
#include "Demo.h"
#include "App.h"

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl2.h"

void Game::App::main()
{
	setDebugMode(true);
	debugController.setActive(false);

	// Load objects here
	sky = Sky::create(renderDevice, dataDir + "sky/");
	log = new Log();

	log->print("DATA DIRECTORY: " + dataDir);

	debugShowRenderingStats = true;

	Demo(this).run();
}

int main(int argc, char** argv) 
{
	GAppSettings settings;
	settings.window.width = 800;
	settings.window.height = 600;

	Game::App app(settings);

	app.run();
	return 0;
}
