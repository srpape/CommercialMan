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
#include "Sprite.hh"

Sprite::Sprite(Window& window, const std::string& fileName) :
		Renderable(window, fileName) {

	position.x = 0;
	position.y = 0;
	position.w = getWidth();
	position.h = getHeight();

	drawRegion.x = 0;
	drawRegion.y = 0;
	drawRegion.w = getWidth();
	drawRegion.h = getHeight();

	flip = SDL_FLIP_NONE;
}

Sprite::~Sprite() {

}

void Sprite::setPosition(int x, int y) {
	position.x = x;
	position.y = y;
}

void Sprite::render(Uint32 tickDiff) {
	SDL_RenderCopyEx(getRenderer(), getTexture(), &drawRegion, &position, 0, nullptr, flip);
}

