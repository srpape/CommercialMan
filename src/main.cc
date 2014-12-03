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

#include "Board.hh"
#include "Cigg.hh"
#include "Player.hh"
#include "Window.hh"

#include <SDL2/SDL.h>

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

const static unsigned int SCREEN_WIDTH = 800;
const static unsigned int SCREEN_HEIGHT = 600;

// Main game loop
int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cout << "Error initializing SDL\n";
        return 1;
    }

    Window window("CommercialMan v0.0.1", SCREEN_WIDTH, SCREEN_HEIGHT);
    Board board(window);
    SDL_Renderer* const renderer = window.getRenderer();
    SDL_SetRenderDrawColor(renderer, 0x7f, 0x7f, 0x7f, SDL_ALPHA_OPAQUE);

    bool running = true;
    SDL_Event event;

    Player player(window);
    player.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

    static Cigg srcCigg(window);

    std::vector<Cigg> ciggs;
    for (int i = 0; i < 5; ++i) {
        Cigg cigg(srcCigg);
        cigg.setPosition(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT);
        ciggs.push_back(cigg);
    }

    while (running) {
        SDL_RenderClear(renderer);

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_KEYDOWN:
                player.handleKeyDown(event);
                break;
            case SDL_KEYUP:
                player.handleKeyUp(event);
                break;
            default:
                break;
            }
        }

        board.render();
        player.render();

        for (Cigg& cigg : ciggs) {
            cigg.render();
        }

        // Update the screen
        SDL_RenderPresent(renderer);
    }
}
