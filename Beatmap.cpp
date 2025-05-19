#include "Beatmap.h"

Beatmap::Beatmap() {

}
Beatmap::~Beatmap() {
    hitobjects.clear();
}
void Beatmap::loadBeatmap(const std::string& path) {
        std::ifstream BeatmapFile(path);
        if (!BeatmapFile.is_open()) {
			std::cout << "Failed to open file" << std::endl;
            return;
        }
        std::string line;
        std::vector<std::string> tokens;
        while (std::getline(BeatmapFile, line)) {
            std::istringstream iss(line);
            std::string token;
			while (std::getline(iss, token, ',')) {
                tokens.push_back(token);
            }
            if (std::stof(tokens[0]) == 1) {
                HitObject hitobject(std::stof(tokens[1]), std::stof(tokens[2]), std::stof(tokens[3]),std::stof(tokens[4]), std::stof(tokens[5]));
                this->hitobjects.push_back(hitobject);
            }
			tokens.clear();
        }
        BeatmapFile.close();
		std::cout << this->hitobjects.size() << std::endl;
}
void Beatmap::displayHitobjects() const {
    for (int i = 0; i < hitobjects.size(); ++i) {
        std::cout << " object : " <<i << std::endl;
        std::cout << hitobjects[i].getX() << hitobjects[i].getY() << hitobjects[i].getRadius() << hitobjects[i].getTime() << hitobjects[i].getDelay() << std::endl;
    }
}
std::vector<HitObject>& Beatmap::getHitObjects() {
	return this->hitobjects;
}
void Beatmap::update(float currentTime){
    for (auto& hitobject : hitobjects) {
        hitobject.update(currentTime);
    }
}
void Beatmap::render(SDL_Renderer* renderer, std::unordered_map<std::string, SDL_Texture*>& textures) {
    for (auto& hitobject : hitobjects) {
		//std::cout << " v: " << hitobject.getIsVisible()  << std::endl;
        if (hitobject.getIsVisible()) {
            hitobject.render(renderer,textures);
        }
    }
}
