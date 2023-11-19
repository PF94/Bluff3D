#ifndef App_H
#define App_H
#include <G3DAll.h>

namespace Game
{
	class App: public GApp {
		public:
			App(const GAppSettings& settings): GApp(settings) {}; 
			void main();
			SkyRef              sky;
			Log*				log;
	};
}
#endif
