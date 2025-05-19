#pragma once
#include "SDL.h"
#include <unordered_map>
#include <string>
class ApproachCircle
{
public:
	ApproachCircle();
	ApproachCircle(float radius);
	~ApproachCircle();
	float getRadius() const;
	void setRadius(float radius);
	void Update(float radius, float currentTime, float startTime, float delay);
	void Render(SDL_Renderer* renderer, std::unordered_map<std::string, SDL_Texture*>& textures, float x, float y) const;
private:
	float radius;
};

