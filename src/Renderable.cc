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
#include "Renderable.hh"

#include <SDL_image.h>

#include <iostream>
#include <stdexcept>

Renderable::Renderable(Window& window, const std::string& fileName) :
        renderer(window.getRenderer()) {

    const std::string path = "images/" + fileName;

    SDL_Surface* image = IMG_Load(path.c_str());
    if (!image) {
        throw std::runtime_error("Unable to load " + path);
    }
    texture.reset(SDL_CreateTextureFromSurface(renderer, image), SDL_DestroyTexture);
    if (!texture) {
        SDL_FreeSurface(image);
        throw std::runtime_error("Unable to create texture for " + path);
    }
    SDL_FreeSurface(image);

    SDL_QueryTexture(texture.get(), nullptr, nullptr, &width, &height);
}

Renderable::~Renderable() {
}

SDL_Renderer* Renderable::getRenderer() const {
    return renderer;
}

void Renderable::render(Uint32 tickDiff) {
    SDL_RenderCopy(renderer, texture.get(), nullptr, nullptr);
}

int Renderable::getWidth() const {
    return width;
}

int Renderable::getHeight() const {
    return height;
}

SDL_Texture* Renderable::getTexture() const {
    return texture.get();
}

