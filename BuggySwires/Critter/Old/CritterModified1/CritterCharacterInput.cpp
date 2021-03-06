/** 
    
    This file is part of Critter.
    
    Copyright (c) 2009 Robin Southern, http://www.nxogre.org
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    
    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.
    
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
    
*/

#include "CritterStable.h"

#if NxOgreHasCharacterController == 1

#include "CritterCharacterInput.h"
#include <algorithm>


                                                                                       

namespace Critter
{

                                                                                       

CharacterInputHelper::CharacterInputHelper()
{
 reset();
}

void CharacterInputHelper::reset()
{
 input.forward_backward = 0;
 input.left_right = 0;
 input.turning_mode = Enums::CharacterTurningMode_SideStep;
 input.up = 0;
 input.down = 0;
 input.user = 0;
}
 
void CharacterInputHelper::forward(unsigned short val)
{
 input.forward_backward = Ogre::Math::Clamp<unsigned short>(val, 0, 2^15);
}
 
void CharacterInputHelper::forwardFractional(Ogre::Real val)
{
 input.forward_backward = unsigned short(Ogre::Math::Clamp<float>(val, 0.0f, 1.0f) * float(2^15));
}
 
void CharacterInputHelper::backward(unsigned short val)
{
 input.forward_backward = -Ogre::Math::Clamp<unsigned short>(val, 0, 2^15);
}
 
void CharacterInputHelper::backwardFractional(Ogre::Real val)
{
 input.forward_backward = -unsigned short(Ogre::Math::Clamp<float>(val, 0.0f, 1.0f) * float(2^15));
}
 
void CharacterInputHelper::left(unsigned short val)
{
 input.left_right = -Ogre::Math::Clamp<unsigned short>(val, 0, 2^15);
}
 
void CharacterInputHelper::leftFractional(Ogre::Real val)
{
 input.left_right = -unsigned char(Ogre::Math::Clamp<float>(val, 0.0f, 1.0f) * float(2^15));
}
 
void CharacterInputHelper::right(unsigned short val)
{
 input.left_right =  Ogre::Math::Clamp<unsigned char>(val, 0, 2^15);
}
 
void CharacterInputHelper::rightFractional(Ogre::Real val)
{
 input.left_right =  unsigned short(Ogre::Math::Clamp<float>(val, 0.0f, 1.0f) * float(2^15));
}

void CharacterInputHelper::up(bool val)
{
 input.up = (val ? 1 : 0);
}
  
void CharacterInputHelper::down(bool val)
{
 input.down = (val ? 1 : 0);
}

void CharacterInputHelper::turn(Ogre::Degree difference, Ogre::Degree maxTurningAngle)
{
 input.turning_mode = Enums::CharacterTurningMode_Add_DeltaTime;
 input.left_right = short(Ogre::Math::Clamp<Ogre::Real>(difference.valueDegrees() / maxTurningAngle.valueDegrees(), -1.0f, 1.0f) * float(2^15));
}

void CharacterInputHelper::turn(short direction)
{
 input.turning_mode = Enums::CharacterTurningMode_Add_DeltaTime;
 input.left_right = short(Ogre::Math::Clamp<short>(direction, -2^15, 2^15));
}

                                                                                       

}

                                                                                       

#endif