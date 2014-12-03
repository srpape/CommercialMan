/*
 *  Copyright 2014 Stephen Pape
 *  Created on: Dec 2, 2014
 *
 *  This file is part of CommercialMan.
 *
 *  CommercialMan is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *  CommercialMan is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with CommercialMan.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "GameLoop.hh"
#include "Cigg.hh"

#include <iostream>

GameLoop::GameLoop(Uint32 width, Uint32 height, Uint32 maxFPS) :
        delayTime(1000 / maxFPS), window("CommercialMan v0.0.1", width, height), board(window), player(window, board), running(true) {

    renderer = window.getRenderer();
    SDL_SetRenderDrawColor(renderer, 0x0, 0, 0x30, SDL_ALPHA_OPAQUE);

    // Initial player position
    player.setPosition(width / 2, height / 2);

    // Create a master cigg for cloning
    Cigg srcCigg(window);
    for (int i = 0; i < 5; ++i) {
        Cigg* cigg = new Cigg(srcCigg);
        cigg->setPosition(rand() % width, rand() % height);
        artifacts.insert(cigg);
    }

    firstRenderTime = lastRenderTime = SDL_GetTicks();
    framesRendered = 0;
}

GameLoop::~GameLoop() {
    for (Sprite* artifact : artifacts) {
        delete artifact;
    }
}

void GameLoop::run() {
    while (running) {
        runOne();
    }
}
void GameLoop::runOne() {
    pollEvents();

    const Uint32 time = SDL_GetTicks();
    const Uint32 millisecondsSinceRender = time - lastRenderTime;
    if (millisecondsSinceRender > delayTime) {
        render(millisecondsSinceRender);
        lastRenderTime = time;
    }
}

void GameLoop::pollEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_KEYDOWN:
            player.handleKeyDown(event);
            break;
        default:
            break;
        }
    }
}

void GameLoop::render(Uint32 tickDiff) {
    SDL_RenderClear(renderer);

    board.render(tickDiff);
    player.render(artifacts, tickDiff);

    for (Sprite* artifact : artifacts) {
        artifact->render(tickDiff);
    }

    // Update the screen
    SDL_RenderPresent(renderer);

    /*
     if (framesRendered % 100 == 0) {
     float fps = framesRendered;
     fps /= ((lastRenderTime - firstRenderTime) / 1000.0);
     std::cout << "FPS: " << fps << " (delayTime:" << delayTime << " Frames: " << framesRendered << ")\n";
     }
     ++framesRendered;
     */

}

