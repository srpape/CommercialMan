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
#ifndef GAMELOOP_HH_
#define GAMELOOP_HH_

#include "Board.hh"
#include "Player.hh"
#include "Renderable.hh"
#include "Window.hh"

#include <SDL.h>
#include <set>

class GameLoop {
public:
    GameLoop(Uint32 width, Uint32 height, Uint32 maxFPS);
    ~GameLoop();
public:
    void run();
    void runOne();
private:
    void pollEvents();
    void render(Uint32 tickDiff);
private:
    const Uint32 delayTime;
    Window window;
    Board board;
    Player player;
    SDL_Renderer* renderer;
    bool running;
    Uint32 firstRenderTime;
    Uint32 framesRendered;

    Uint32 lastRenderTime;

    std::set<Sprite*> artifacts;
};

#endif /* GAMELOOP_HH_ */
