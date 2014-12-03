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
#ifndef WINDOW_HH_
#define WINDOW_HH_

#include <string>
#include <SDL2/SDL.h>

class Window {
public:
    Window(const std::string& title, unsigned int width, unsigned int height);
    ~Window();
public:
    SDL_Renderer* getRenderer() const;

    unsigned int getHeight() const;
    unsigned int getWidth() const;
private:
    const unsigned int width;
    const unsigned int height;
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif /* WINDOW_HH_ */
