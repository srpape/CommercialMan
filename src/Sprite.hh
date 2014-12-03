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
#ifndef SPRITE_HH_
#define SPRITE_HH_

#include "Renderable.hh"
#include "Window.hh"

#include <SDL.h>

class Sprite: public Renderable {
public:
	Sprite(Window& window, const std::string& fileName);
	virtual ~Sprite();
public:
	void setPosition(int x, int y);
public:
	virtual void render(Uint32 tickDiff) override;
protected:
	SDL_Rect drawRegion;
	SDL_Rect position;
	SDL_RendererFlip flip;
	double rotation;
};

#endif /* SPRITE_HH_ */
