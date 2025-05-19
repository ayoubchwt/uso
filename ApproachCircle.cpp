#include "ApproachCircle.h"
ApproachCircle::ApproachCircle() {
	this->radius = 0 ;
}
ApproachCircle::ApproachCircle(const float radius) {
	this->radius = radius;
}
ApproachCircle::~ApproachCircle() {
}
float ApproachCircle::getRadius() const {
	return this->radius;
}
void ApproachCircle::setRadius(float radius) {
	this->radius = radius;
}
void ApproachCircle::Update(const float radius, const float currentTime, const float startTime, const float delay) {
    if (currentTime >= startTime && currentTime <= (startTime + delay)) {
        const float approachStartRadius = 2.5 * radius;
        const float progress = (currentTime - startTime) / delay;
        this->radius = approachStartRadius + (radius - approachStartRadius) * progress;
    }
    else {
        this->radius = radius;
    }
}
void ApproachCircle::Render(SDL_Renderer* renderer, std::unordered_map<std::string, SDL_Texture*>& textures , const float x , const float y) const {
	const SDL_Rect dstRect = { static_cast<int>(x - this->radius), static_cast<int>(y - this->radius), static_cast<int>(this->radius * 2), static_cast<int>(this->radius * 2) };
	SDL_RenderCopy(renderer, textures["/home/eclipse/Desktop/My Code/SDL_osu/Skins/Yellow/approachcircle.png"], nullptr, &dstRect);
}
