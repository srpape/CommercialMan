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

    surface.reset(IMG_Load(path.c_str()), SDL_FreeSurface);
    if (!surface) {
        std::cout << "Unable to load " + path << ": " << SDL_GetError() << '\n';
        throw std::runtime_error("Unable to load " + path);
    }
    texture.reset(SDL_CreateTextureFromSurface(renderer, surface.get()), SDL_DestroyTexture);
    if (!texture) {
        std::cout << "Unable to create texture for " + path << '\n';
        throw std::runtime_error("Unable to create texture for " + path);
    }

    SDL_QueryTexture(texture.get(), nullptr, nullptr, &width, &height);
}

Renderable::~Renderable() {
}

SDL_Renderer* Renderable::getRenderer() const {
    return renderer;
}

int Renderable::getWidth() const {
    return width;
}

int Renderable::getHeight() const {
    return height;
}

SDL_Surface* Renderable::getSurface() const {
    return surface.get();
}

SDL_Texture* Renderable::getTexture() const {
    return texture.get();
}

bool Renderable::isTransparentXY(int x, int y) const {
    int bpp = surface->format->BytesPerPixel;
    Uint8* p = (Uint8*) surface->pixels + y * surface->pitch + x * bpp;
    Uint32 pixelColor;

    switch (bpp) {
    case (1):
        pixelColor = *p;
        break;
    case (2):
        pixelColor = *(Uint16*) p;
        break;
    case (3):
        if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
            pixelColor = p[0] << 16 | p[1] << 8 | p[2];
        else
            pixelColor = p[0] | p[1] << 8 | p[2] << 16;
        break;
    case (4):
        pixelColor = *(Uint32*) p;
        break;
    }

    Uint8 red, green, blue, alpha;
    SDL_GetRGBA(pixelColor, surface->format, &red, &green, &blue, &alpha);

    return alpha <= 20;
}
