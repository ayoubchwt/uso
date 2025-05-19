#include "HitObject.h"

HitObject::HitObject() {
	this->x = 0; 
	this->y = 0;
	this->radius = 0;
	this->time = 0;
	this->delay = 0;
	this->isVisible = false;
	this->approachCircle = ApproachCircle();
}
HitObject::HitObject(const float x, const float y, const float radius, const float time, const float delay) {
	this->x = x;
	this->y = y;
	this->radius = radius;
	this->time = time;
	this->delay = delay;
	this->isVisible = false;
	this->isHit = false;
}
HitObject::~HitObject() {

}
float HitObject::getX() const {
	return this->x;
}
float HitObject::getY() const {
	return this->y;
}
float HitObject::getRadius() const {
	return this->radius;
}
float HitObject::getTime() const {
	return this->time;
}
float HitObject::getDelay() const {
	return this->delay;
}
bool HitObject::getIsVisible() const {
	return this->isVisible;
}
void HitObject::setIsHit(const bool state) {
	this->isHit = state;
}
bool HitObject::isHovered(const int mouseX, const int mouseY) const {
    const float dx = mouseX - this->x;
    const float dy = mouseY - this->y;
    return (dx * dx + dy * dy) <= (this->radius * this->radius);
}  
void HitObject::update(float const currentTime) {
	if (isHit) {
		this->isVisible = false;
		return;
	}
	if (currentTime >= this->time && currentTime <= (this->time + this->delay)) {
		this->isVisible = true;
		this->approachCircle.Update(this->radius, currentTime, this->time, this->delay);
	}
	else {
		this->isVisible = false;
	}
}
void HitObject::render(SDL_Renderer* renderer, std::unordered_map<std::string, SDL_Texture*>& textures) const {
	if (this->isVisible && !isHit ) {
		const SDL_Rect dstRect = { static_cast<int>(this->x - this->radius), static_cast<int>(this->y - this->radius), static_cast<int>(this->radius * 2), static_cast<int>(this->radius * 2) };
		SDL_RenderCopy(renderer,textures["/home/eclipse/Desktop/My Code/SDL_osu/Skins/Yellow/hitcircle.png"], nullptr, &dstRect);
		this->approachCircle.Render(renderer, textures, this->x, this->y);
	}
} 