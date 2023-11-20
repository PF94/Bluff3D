#include <G3DAll.h>

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl2.h"

int timeArray[3] = { 11, 00, 00 };
bool timeAmPm = false;

/**
 This simple demo applet uses the debug mode as the regular
 rendering mode so you can fly around the scene.
 */
class Game : public GApplet {
public:

    // Add state that should be visible to this applet.
    // If you have multiple applets that need to share
    // state, put it in the App.

    class App *app;

    Game(App *app);

    virtual ~Game() {}

    virtual void onInit();

    virtual void onLogic();

    virtual void onNetwork();

    virtual void onSimulation(RealTime rdt, SimTime sdt, SimTime idt);

    virtual void onGraphics(RenderDevice *rd);

    virtual void onUserInput(UserInput *ui);

    virtual void onCleanup();

    virtual void onImGui();
};


class App : public GApp {
protected:
    void main();

public:
    SkyRef sky;

    Game *applet;

    App(const GAppSettings &settings);

    ~App();
};


Game::Game(App *_app) : GApplet(_app), app(_app) {
}


void Game::onInit() {
    // Called before Game::run() beings
    app->debugCamera.setPosition(Vector3(0, 2, 10));
    app->debugCamera.lookAt(Vector3(0, 2, 0));

    GApplet::onInit();
}


void Game::onCleanup() {
    // Called when Game::run() exits
}


void Game::onLogic() {
    // Add non-simulation game logic and AI code here
}


void Game::onNetwork() {
    // Poll net messages here
}


void Game::onSimulation(RealTime rdt, SimTime sdt, SimTime idt) {
    // Add physical simulation here.  You can make your time advancement
    // based on any of the three arguments.
}


void Game::onUserInput(UserInput *ui) {
    if (ui->keyPressed(SDLK_ESCAPE)) {
        // Even when we aren't in debug mode, quit on escape.
        endApplet = true;
        app->endProgram = true;
    }

    // Add other key handling here
}

void Game::onImGui() {
    ImGui::Begin("Game");
    ImGui::SliderInt("Hour", &timeArray[0], 0, 11);
    ImGui::SliderInt("Minute", &timeArray[1], 0, 59);
    ImGui::SliderInt("Seconds", &timeArray[2], 0, 59);
    ImGui::Checkbox("AM/PM", &timeAmPm);
    ImGui::BeginDisabled(true);
    ImGui::Checkbox("Use Joystick", &this->app->userInput->useJoystick);
    ImGui::EndDisabled();
    ImGui::End();
}

void Game::onGraphics(RenderDevice *rd) {

    LightingParameters lighting(G3D::toSeconds(
            timeArray[0],
            timeArray[1],
            timeArray[2],
            static_cast<AMPM>(timeAmPm)));
    app->renderDevice->setProjectionAndCameraMatrix(app->debugCamera);

    // Cyan background
    app->renderDevice->setColorClearValue(Color3(0.1f, 0.5f, 1.0f));

    app->renderDevice->clear(app->sky.isNull(), true, true);
    if (app->sky.notNull()) {
        app->sky->render(app->renderDevice, lighting);
    }

    // Setup lighting
    app->renderDevice->enableLighting();
    app->renderDevice->setLight(0, GLight::directional(lighting.lightDirection, lighting.lightColor));
    app->renderDevice->setAmbientLightColor(lighting.ambient);

    Draw::axes(CoordinateFrame(Vector3(0, 4, 0)), app->renderDevice);

    app->renderDevice->disableLighting();

    if (app->sky.notNull()) {
        app->sky->renderLensFlare(app->renderDevice, lighting);
    }
}


void App::main() {
    setDebugMode(true);
    debugController.setActive(true);

    // Load objects here
    sky = Sky::create(renderDevice, dataDir + "sky/");

    debugShowRenderingStats = true;

    Game(this).run();

    applet->run();
}


App::App(const GAppSettings &settings) : GApp(settings) {
    applet = new Game(this);
}


App::~App() {
    delete applet;
}


int main(int argc, char** argv) 
{
    GAppSettings settings;
    settings.useNetwork = false;
    App(settings).run();
    return 0;
}
