#include "Demo.h"
#include <imgui.h>

int timeArray[3] = { 06, 00, 00 };
bool timeAmPm = false;

Game::Demo::Demo(App* _app) : GApplet(_app), app(_app) {
}

void Game::Demo::onInit()  {
    // Called before Demo::run() beings
    app->debugCamera.setPosition(Vector3(0, 4, 3));
    app->debugCamera.lookAt(Vector3(0, 1, 0));
}

void Game::Demo::onUserInput(UserInput* ui) {
    if (ui->keyPressed(SDLK_ESCAPE)) {
        // Even when we aren't in debug mode, quit on escape.
        endApplet = true;
        app->endProgram = true;
    }

	// Add other key handling here
}

void Game::Demo::onImGui() {
    ImGui::Begin("Game");
    ImGui::SliderInt("Hour", &timeArray[0], 0, 11);
    ImGui::SliderInt("Minute", &timeArray[1], 0, 59);
    ImGui::SliderInt("Seconds", &timeArray[2], 0, 59);
    ImGui::Checkbox("AM/PM", &timeAmPm);
    ImGui::End();
}

void Game::Demo::onGraphics(RenderDevice* rd) {
    LightingParameters lighting(G3D::toSeconds(timeArray[0], timeArray[1], timeArray[2], static_cast<AMPM>(timeAmPm)), false);
    rd->setProjectionAndCameraMatrix(app->debugCamera);

    // Cyan background
    rd->setColorClearValue(Color3(0.1f, 0.5f, 1.0f));

    rd->clear(app->sky.isNull(), true, true);
    if (app->sky.notNull()) {
        app->sky->render(lighting);
    }
}