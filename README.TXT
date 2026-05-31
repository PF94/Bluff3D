Bluff3D is a fork of Graphics3D version 6 from 2006.

Bluff3D is primarily developed on Windows, with additional testing done on Linux. Mac is untested and unsupported.

Required dependencies:
* SDL2
* OpenGL
* GLEW
* X11 (Linux)

Build instructions (Linux):
mkdir build && cd build
cmake ..
make

Build instructions (Windows):
WIP

Bonus game:
added cowblocks because funny (also for testing stuff)
if too many cows then edit main.cpp in cowblocks and change const int N = 1000; to const int N = 100;
