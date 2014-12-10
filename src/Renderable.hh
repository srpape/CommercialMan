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
#ifndef RENDERABLE_HH_
#define RENDERABLE_HH_

#include "Window.hh"

#include <string>
#include <memory>

#include <SDL.h>

class Renderable {
public:
    Renderable(Window& window, const std::string& fileName);
    virtual ~Renderable();
public:
    virtual void render(Uint32 tickDiff) = 0;

    virtual int getWidth() const;
    virtual int getHeight() const;
    bool isTransparentXY(int x, int y) const;
protected:
    SDL_Renderer* getRenderer() const;
    SDL_Surface* getSurface() const;
    SDL_Texture* getTexture() const;
private:
    SDL_Renderer* const renderer;
    std::shared_ptr<SDL_Surface> surface;
    std::shared_ptr<SDL_Texture> texture;
    int width;
    int height;
};

#endif /* RENDERABLE_HH_ */
