#include "Demo.h"

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

void Game::Demo::onGraphics(RenderDevice* rd) {
    LightingParameters lighting(G3D::toSeconds(12, 00, 00, PM), false);
    rd->setProjectionAndCameraMatrix(app->debugCamera);

    // Cyan background
    rd->setColorClearValue(Color3(0.1f, 0.5f, 1.0f));

    rd->clear(app->sky.isNull(), true, true);
    if (app->sky.notNull()) {
        app->sky->render(lighting);
    }
}