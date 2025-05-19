#pragma once
#include <vector>
#include "SDL.h"
#include "HitObject.h"
#include <unordered_map>
#include <string>
#include <fstream> 
#include<sstream>
#include <iostream>
class Beatmap
{
public : 
	Beatmap();
	~Beatmap();
	void loadBeatmap(const std::string& path);
	void displayHitobjects() const;
	std::vector<HitObject>& getHitObjects();
	void update(float currentTime);
	void render(SDL_Renderer* renderer, std::unordered_map<std::string, SDL_Texture*>& textures);
private : 
	std::vector<HitObject> hitobjects;
};
