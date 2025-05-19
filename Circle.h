#pragma once
#include "HitObject.h"
class Circle : public HitObject
{
public : 
	Circle();
	Circle(float x, float y, float radius, float time, float delay);
	~Circle();
private:
};

