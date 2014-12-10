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
#include "Cigg.hh"

#include "Player.hh"

#include <SDL2_gfxPrimitives.h>
#include <iostream> //TODO

Cigg::Cigg(Window& window) :
		Sprite(window, "cigg.png") {

	pickupSound.reset(Mix_LoadWAV("sounds/select.ogg"), Mix_FreeChunk);
	if (!pickupSound) {
		std::cout << "Failed to load select.ogg\n";
		std::cout << Mix_GetError() << '\n';
	}

	destroyTimeout = 0;
}

Cigg::~Cigg() {

}

void Cigg::onCollideWithPlayer(Player& player) {
	if (!destroyTimeout) {
		destroyTimeout = SDL_GetTicks() + 600;
		player.addToScore(1000);
		Mix_PlayChannel(-1, pickupSound.get(), 0);
	}
}

void Cigg::render(Uint32 tickDiff) {
	if (!destroyTimeout) {
		Sprite::render(tickDiff);
	} else if (SDL_GetTicks() < destroyTimeout) {
		stringRGBA(getRenderer(), getX(), getY(), "1000", 0, 0xFF, 0, SDL_ALPHA_OPAQUE);
	} else {
		// Don't render anything, we're gone.
	}
}
