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
#include "Board.hh"

#include "AnimatedSprite.hh"

#include <SDL_image.h>
#include <stdexcept>

Board::Board(Window& window) :
		renderer(window.getRenderer()) {

	position.x = position.y = 0;
	position.w = window.getWidth();
	position.h = window.getHeight() - 64;

	texTarget = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, position.w, position.h);

	if (!texTarget)
		throw std::runtime_error("Unable to create texture");

	// Render the board to the texture
	SDL_SetRenderTarget(renderer, texTarget);

	SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);

	AnimatedSprite tileSet(window, "board.png", 2);

	// Draw the normal tiles
	tileSet.setFrameIndex(0);
	for (unsigned int x = 0; x < position.w; x += tileSet.getWidth()) {
		for (unsigned int y = 0; y < position.h; y += tileSet.getHeight()) {
			tileSet.setPosition(x, y);
			tileSet.render(0);
		}
	}

	// Draw some walls around the perimeter
	tileSet.setFrameIndex(1);
	for (unsigned int x = 0; x < position.w; x += tileSet.getWidth()) {
		// Draw the top and bottom bars
		tileSet.setPosition(x, 0);
		tileSet.render(0);
		tileSet.setPosition(x, position.h - tileSet.getHeight());
		tileSet.render(0);
	}
	for (unsigned int y = 0; y < position.h; y += tileSet.getHeight()) {
		// Draw the left and right bars
		tileSet.setPosition(0, y);
		tileSet.render(0);
		tileSet.setPosition(position.w - tileSet.getWidth(), y);
		tileSet.render(0);
	}

	// Release the render target
	SDL_SetRenderTarget(renderer, nullptr);
}

Board::~Board() {
	SDL_DestroyTexture(texTarget);
}

void Board::render() {
	SDL_RenderCopy(renderer, texTarget, nullptr, &position);
}
