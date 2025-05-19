#pragma once
#include "SDL.h"
#include "Beatmap.h"
#include "SDL_image.h"
#include <unordered_map>
#include <string>
class Game
{
public : 
	Game();
	~Game();

	bool IsRunning() const;
	void setIsRunning(bool state);
	bool Init(const char* title,int width,int height,bool fullscreen);
	void Update() const;
	void Render();
	void handleEvent();
	void clean();
	void LoadTexture(const std::string& path);
	SDL_Texture* GetTexture(const std::string& textureName);
private: 
	SDL_Window* window; 
	SDL_Renderer* renderer;
	std::unordered_map<std::string, SDL_Texture*> textures;
	bool isRunning;
	Beatmap* map;
	Uint32 BeatmapStartTime;
};

