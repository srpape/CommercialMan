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
#ifndef ANIMATEDSPRITE_HH_
#define ANIMATEDSPRITE_HH_

#include "Sprite.hh"

class AnimatedSprite: public Sprite {
public:
    AnimatedSprite(Window& window, const std::string& fileName, unsigned int frameCount);
    virtual ~AnimatedSprite();
public:
    virtual int getWidth() const;
    virtual int getHeight() const;
public:
    unsigned int getFrameCount() const;
    void setFrameIndex(unsigned int index);
    void nextFrame();
private:
    const unsigned int frameCount;
    unsigned int frameIndex;
};

#endif /* ANIMATEDSPRITE_HH_ */
