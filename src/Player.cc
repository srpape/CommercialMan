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

Player::Player(Window& window, Board& board) :
        Character(window, board, "man.png", 2) {

}

Player::~Player() {

}

void Player::render(std::set<Sprite*>& artifacts, Uint32 tickDiff) {

    for (auto iter = artifacts.begin(); iter != artifacts.end();) {
        Sprite* artifact = *iter;

        if (isInsideMe(artifact)) {
            iter = artifacts.erase(iter);
            delete artifact;
        } else {
            ++iter;
        }
    }

    Character::render(tickDiff);
}

bool Player::isInsideMe(int x, int y) const {
    if (x < getX())
        return false;

    if (y < getY())
        return false;

    if (x > getX() + getWidth())
        return false;

    if (y > getY() + getHeight())
        return false;

    return true;
}

bool Player::isInsideMe(const Sprite* sprite) const {

    if (isInsideMe(sprite->getX(), sprite->getY()))
        return true;
    if (isInsideMe(sprite->getX() + sprite->getWidth(), sprite->getY()))
        return true;
    if (isInsideMe(sprite->getX(), sprite->getY() + sprite->getHeight()))
        return true;
    if (isInsideMe(sprite->getX() + sprite->getWidth(), sprite->getY() + sprite->getHeight()))
        return true;

    return false;

}

void Player::handleKeyDown(SDL_Event& event) {
    if (event.key.repeat)
        return;

    switch (event.key.keysym.scancode) {
    case SDL_SCANCODE_UP:
    case SDL_SCANCODE_W:
        if (flip == SDL_FLIP_HORIZONTAL) {
            rotation = 90.0;
        } else {
            rotation = -90.0;
        }
        setDirection(UP);
        break;
    case SDL_SCANCODE_DOWN:
    case SDL_SCANCODE_S:
        if (flip == SDL_FLIP_HORIZONTAL) {
            rotation = -90.0;
        } else {
            rotation = 90.0;
        }
        setDirection(DOWN);
        break;
    case SDL_SCANCODE_LEFT:
    case SDL_SCANCODE_A:
        rotation = 0.0;
        setDirection(LEFT);
        flip = SDL_FLIP_HORIZONTAL;
        break;
    case SDL_SCANCODE_RIGHT:
    case SDL_SCANCODE_D:
        rotation = 0.0;
        setDirection(RIGHT);
        flip = SDL_FLIP_NONE;
        break;
    default:
        break;
    }
}

