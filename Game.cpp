#include "Game.h"
Game::Game() {
	this->window = nullptr; 
	this->renderer = nullptr;
	this->isRunning = false;
	this->map = new Beatmap();
}

Game::~Game() {
}

bool Game::IsRunning() const {
	return this->isRunning; 
}

void Game::setIsRunning(const bool state) {
	this->isRunning = state;
}
void Game::LoadTexture(const std::string& path) {
	std::cout << "am loading texture" << path<< std::endl;
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (!surface) {
		std::cout << "IMG_Load failed: " << IMG_GetError() << std::endl;
		return;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	if (texture) {
		textures[path] = texture;
	}
	else {
		std::cout << "SDL_CreateTextureFromSurface failed: " << SDL_GetError() << std::endl;
	}
}
SDL_Texture* Game::GetTexture(const std::string& textureName) {
	if (this->textures.find(textureName) != this->textures.end()) {
		return textures[textureName];
	}
	return nullptr;
}
bool Game::Init(const char* title, int const width, int const height, bool const fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		return false; 
	}

	this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width,height, fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN);
	if (!this->window) {
		return false;
	}
	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
	if (!this->renderer) {
		return false;
	}
	this->isRunning = true;
	this->BeatmapStartTime = SDL_GetTicks();
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	this->LoadTexture("/home/eclipse/Desktop/My Code/SDL_osu/Skins/Yellow/hitcircle.png");
	this->LoadTexture("/home/eclipse/Desktop/My Code/SDL_osu/Skins/Yellow/approachcircle.png");
	this->map->loadBeatmap("/home/eclipse/Desktop/My Code/SDL_osu/Songs/NBO.txt");
	return true; 
}

void Game::Update() const {
	const Uint32 elapsedTime = SDL_GetTicks() - this->BeatmapStartTime;
	this->map->update(elapsedTime/1000.0f);
}

void Game::Render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(this->renderer);
	this->map->render(this->renderer,this->textures);
	SDL_RenderPresent(this->renderer);
}

void Game::handleEvent() {
	SDL_Event event;
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			this->setIsRunning(false);
			this->clean();
			break;
		case SDL_WINDOWEVENT:
			if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED ||
				event.window.event == SDL_WINDOWEVENT_MOVED) {
				//temporary fix : game is rendering in another dimension yey its a feature not a bug !!
				this->Render();
			}
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_x || event.key.keysym.sym == SDLK_w) {
				for (auto& hitobject : this->map->getHitObjects()) {
					if (hitobject.isHovered(mouseX, mouseY)) {
						hitobject.setIsHit(true);
						std::cout << "HitObject hit!" << std::endl;
					}
				}
			}
			break;
		default:
			break;
		}
	}
}
void Game::clean() {
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	for (auto& pair : textures) {
		SDL_DestroyTexture(pair.second);
	}
	textures.clear();
	SDL_Quit; 
}
