#pragma once

#include <G3DAll.h>
#include "App.h"

namespace Game
{
	class Demo : public GApplet {
	public:
		class App* app;

		Demo(App* app);
		virtual ~Demo(){}

		virtual void onInit();

		virtual void onUserInput(UserInput*);

		virtual void onGraphics(RenderDevice*);

        virtual void onImGui();
    };
}