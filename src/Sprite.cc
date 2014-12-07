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

#include "Player.hh"

#include <cmath>
#include <SDL2_gfxPrimitives.h>

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
	rotation = 0.0;
}

Sprite::~Sprite() {

}

float Sprite::getCenterX() const {
	return getX() + (getWidth() / 2.0f);
}
float Sprite::getCenterY() const {
	return getY() + (getHeight() / 2.0f);
}

int Sprite::getX() const {
	return position.x;
}

int Sprite::getY() const {
	return position.y;
}

void Sprite::setPosition(int x, int y) {
	position.x = x;
	position.y = y;
}

void Sprite::render(Uint32 tickDiff) {

	SDL_RenderCopyEx(getRenderer(), getTexture(), &drawRegion, &position, rotation, nullptr, flip);
	//rectangleRGBA(getRenderer(), getX(), getY(), getX() + getWidth(), getY() + getHeight(), 0xFF, 0, 0,	SDL_ALPHA_OPAQUE);
}

bool Sprite::isColliding(const Sprite& sprite) const {
	if (&sprite == this)
		return true;

	const int x1 = sprite.getX();
	const int x2 = sprite.getX() + sprite.getWidth();
	const int y1 = sprite.getY();
	const int y2 = sprite.getY() + sprite.getHeight();

	const int myX1 = getX();
	const int myX2 = getX() + getWidth();
	const int myY1 = getY();
	const int myY2 = getY() + getHeight();

	return (myX1 < x2 && myX2 > x1 && myY1 < y2 && myY2 > y1);
}

float Sprite::getDistance(int x, int y) const {
	int xDist = abs(getCenterX() - x);
	int yDist = abs(getCenterY() - y);

	return sqrtf((xDist * xDist) + (yDist * yDist));
}

float Sprite::getDistance(const Sprite& sprite) const {
	return getDistance(sprite.getCenterX(), sprite.getCenterY());
}

void Sprite::onCollideWithPlayer(Player& player) {
	// Don't care
}
