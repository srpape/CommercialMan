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
#ifndef BOARD_HH_
#define BOARD_HH_

#include "Window.hh"
#include "Renderable.hh"

#include <SDL.h>

class Board {
public:
	Board(Window& window);
	virtual ~Board();
public:
	void render();
private:
	SDL_Renderer* renderer;
	SDL_Texture* texTarget;
	SDL_Rect position;
};

#endif /* BOARD_HH_ */
