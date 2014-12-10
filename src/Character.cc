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

Character::Character(Window& window, Board& board, const std::string& fileName, unsigned int frameCount) :
		AnimatedSprite(window, fileName, frameCount), board(board) {

	dir = NONE;
	speed = 25;
	animationDistance = 0;
}

Character::~Character() {

}

void Character::setDirection(Direction dir) {
	this->dir = dir;
}
void Character::setSpeed(unsigned int speed) {
	this->speed = speed;
}

void Character::render(Uint32 tickDiff) {
	const Uint32 distanceMoved = speed * (tickDiff / 100.0f);

	bool updatePosition = true;

	switch (dir) {
	case DOWN:
	case UP: {
		const int xScanRange = (position.w / 4);
		const int x1 = position.x + xScanRange;
		const int x2 = (position.x + position.w) - xScanRange;
		const int y = (dir == UP) ? position.y : position.y + position.h;
		for (int x = x1; x <= x2; ++x) {
			//if (!board.isTransparentXY(x, y)) {
			if (y <= 25 || y >= (768 - 64 - 25)) {
				updatePosition = false;
				break;
			}
			//}
		}
		if (updatePosition) {
			if (dir == UP) {
				position.y -= distanceMoved;
			} else {
				position.y += distanceMoved;
			}
		}
		break;
	}
	case LEFT:
	case RIGHT: {
		const int yScanRange = (position.h / 4);
		const int x = (dir == LEFT) ? position.x : position.x + position.w;
		const int y1 = position.y + yScanRange;
		const int y2 = (position.y + position.h) - yScanRange;
		for (int y = y1; y <= y2; ++y) {
			//if (!board.isTransparentXY(x, y)) {
			if (x <= 25 || x >= (958 + 40)) {
				updatePosition = false;
				break;
			}
			//}
		}
		if (updatePosition) {
			if (dir == LEFT)
				position.x -= distanceMoved;
			else
				position.x += distanceMoved;
		}
		break;
	}
	case NONE:
		updatePosition = false;
		break;
	}

	if (updatePosition) {
		animationDistance += distanceMoved;
		if (animationDistance >= 10) {
			nextFrame();
			animationDistance = 0;
		}
	} else {
		animationDistance = 0;
		setFrameIndex(0);
	}

	AnimatedSprite::render(tickDiff);
}
