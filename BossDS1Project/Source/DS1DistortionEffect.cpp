/*
  ==============================================================================

    DS1DistortionEffect.cpp
    Created: 16 Apr 2023 8:11:05am
    Author:  Jacob Stallings

  ==============================================================================
*/

#include "DS1DistortionEffect.h"

float DS1DistortionEffect::processSample(float x, const int c) {
    
    if(IS_SIMPLE_DIST)
        x = (2.f/M_PI) * atan(x * (9*dist+1)); // drive needs to be from 1 to 10
    // else TODO - implement DS1 chain
    
    return x;
    
}

float DS1DistortionEffect::getTone() { return tone; }

void DS1DistortionEffect::setTone(float tone) { this->tone = tone; }

float DS1DistortionEffect::getDist() { return dist; }

void DS1DistortionEffect::setDist(float dist) { this->dist = dist; }

float DS1DistortionEffect::getLevel() { return level; }

void DS1DistortionEffect::setLevel(float level) { this->level = level; }


