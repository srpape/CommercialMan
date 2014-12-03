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
#include "AnimatedSprite.hh"

#include <stdexcept>

AnimatedSprite::AnimatedSprite(Window& window, const std::string& fileName, unsigned int frameCount) :
        Sprite(window, fileName), frameCount(frameCount) {

    drawRegion.h = getHeight();
    drawRegion.w = getWidth() / frameCount;
    drawRegion.x = 0;
    drawRegion.y = 0;

    position.w = drawRegion.w;

    frameIndex = 0;
}

AnimatedSprite::~AnimatedSprite() {
    // TODO Auto-generated destructor stub
}

int AnimatedSprite::getWidth() const {
    return drawRegion.w;
}

int AnimatedSprite::getHeight() const {
    return drawRegion.h;
}

unsigned int AnimatedSprite::getFrameCount() const {
    return frameCount;
}

void AnimatedSprite::setFrameIndex(unsigned int index) {
    if (index >= frameCount) {
        throw std::runtime_error("Invalid frame index");
    }
    drawRegion.x = index * drawRegion.w;
    frameIndex = index;
}

void AnimatedSprite::nextFrame() {
    frameIndex++;
    if (frameIndex >= frameCount)
        frameIndex = 0;
    setFrameIndex(frameIndex);
}
