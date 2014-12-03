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

#include <iostream>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

using namespace std;

const static unsigned int SCREEN_WIDTH = 1024;
const static unsigned int SCREEN_HEIGHT = 768;
const static unsigned int MAX_FPS = 100;

#ifdef __EMSCRIPTEN__
static GameLoop* emLoop = nullptr;

void runOne() {
    emLoop->runOne();
}

#endif

// Main game loop
int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) != 0) {
        cout << "Error initializing SDL\n";
        return 1;
    }

    GameLoop loop(SCREEN_WIDTH, SCREEN_HEIGHT, MAX_FPS);

#ifdef __EMSCRIPTEN__
    emLoop = &loop;
    // void emscripten_set_main_loop(em_callback_func func, int fps, int simulate_infinite_loop);
    emscripten_set_main_loop(runOne, 0, 1);
#else
    loop.run();
#endif

    return 0;
}
