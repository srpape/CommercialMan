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
#include "Player.hh"

Player::Player(Window& window) :
        AnimatedSprite(window, "man.png", 1) {

    speed = 5;
    hspeed = vspeed = 0;
}

Player::~Player() {

}

void Player::handleKeyDown(SDL_Event& event) {
    if (event.key.repeat)
        return;

    switch (event.key.keysym.scancode) {
    case SDL_SCANCODE_UP:
    case SDL_SCANCODE_W:
        vspeed -= speed;
        break;
    case SDL_SCANCODE_DOWN:
    case SDL_SCANCODE_S:
        vspeed += speed;
        break;
    case SDL_SCANCODE_LEFT:
    case SDL_SCANCODE_A:
        hspeed -= speed;
        break;
    case SDL_SCANCODE_RIGHT:
    case SDL_SCANCODE_D:
        hspeed += speed;
        break;
    }
}

void Player::handleKeyUp(SDL_Event& event) {
    if (event.key.repeat)
        return;

    switch (event.key.keysym.scancode) {
    case SDL_SCANCODE_UP:
    case SDL_SCANCODE_W:
        vspeed += speed;
        break;
    case SDL_SCANCODE_DOWN:
    case SDL_SCANCODE_S:
        vspeed -= speed;
        break;
    case SDL_SCANCODE_LEFT:
    case SDL_SCANCODE_A:
        hspeed += speed;
        break;
    case SDL_SCANCODE_RIGHT:
    case SDL_SCANCODE_D:
        hspeed -= speed;
        break;
    }
}

void Player::render() {
    position.x += hspeed;
    position.y += vspeed;

    if (position.x < 0)
        position.x = 0;
    if (position.y < 0)
        position.y = 0;

    AnimatedSprite::render();
}
