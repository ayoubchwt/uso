#pragma once
#include "SDL.h"
#include "ApproachCircle.h"
#include <unordered_map>
#include <string>
#include <iostream>
class HitObject
{
public: 	
	HitObject();
	HitObject(float x, float y, float radius, float time, float delay);
	~HitObject();
	float getX() const;
	float getY() const;
	float getRadius() const;
	float getTime() const;
	float getDelay() const;
	bool getIsVisible() const;
	void setIsHit(bool state);
	bool isHovered(int mouseX, int mouseY) const;
	void update(float currentTime);
	void render(SDL_Renderer* renderer, std::unordered_map<std::string, SDL_Texture*>& textures) const;

private : 
	float x, y, radius, time, delay ;
	bool isVisible;
	bool isHit;
	ApproachCircle approachCircle;
};
