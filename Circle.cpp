#include "Circle.h"
Circle::Circle() : HitObject() {
}
Circle::Circle(const float x, const float y, const float radius, const float time, const float delay) : HitObject(x, y, radius, time, delay) {
}
Circle::~Circle() {
}
