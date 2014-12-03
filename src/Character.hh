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
#ifndef CHARACTER_HH_
#define CHARACTER_HH_

#include "AnimatedSprite.hh"
#include "Board.hh"

class Character: public AnimatedSprite {
public:
	Character(Window& window, Board& board, const std::string& fileName, unsigned int frameCount);
	virtual ~Character();
public:
	enum Direction {
		NONE, UP, DOWN, LEFT, RIGHT
	};
public:
	void setDirection(Direction dir);
	void setSpeed(unsigned int speed);
public:
	virtual void render(Uint32 tickDiff) override;
private:
	Board& board;
	Direction dir;
	unsigned int speed;
	unsigned int animationDistance;
};

#endif /* CHARACTER_HH_ */
