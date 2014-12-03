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
#include "Character.hh"

Character::Character(Window& window, const std::string& fileName, unsigned int frameCount) :
		AnimatedSprite(window, fileName, frameCount) {

	dir = NONE;
	speed = 5;
	renderCount = 0;
}

Character::~Character() {

}

void Character::setDirection(Direction dir) {
	this->dir = dir;
}
void Character::setSpeed(unsigned int speed) {
	this->speed = speed;
}

void Character::render() {
	switch (dir) {
	case UP:
		position.y -= speed;
		break;
	case DOWN:
		position.y += speed;
		break;
	case LEFT:
		position.x -= speed;
		break;
	case RIGHT:
		position.x += speed;
		break;
	case NONE:
		AnimatedSprite::render();
		return;
	}

	// TODO: Real collision checks
	bool moving = true;
	if (position.x < 20) {
		position.x = 20;
		moving = false;
		setFrameIndex(0);
	}
	if (position.x > (800 - (position.w / 2)) - 50) {
		position.x = (800 - (position.w / 2) - 50);
		moving = false;
		setFrameIndex(0);
	}
	if (position.y < 20) {
		position.y = 20;
		moving = false;
		setFrameIndex(0);
	}
	if (position.y > (600 - (position.h / 2)) - 50) {
		position.y = (600 - (position.h / 2) - 50);
		moving = false;
		setFrameIndex(0);
	}

	if (moving) {
		++renderCount;
		if (!(renderCount % 7)) {
			nextFrame();
		}
	}

	AnimatedSprite::render();
}
