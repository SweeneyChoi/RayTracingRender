#include "IntersectResult.h"



IntersectResult::IntersectResult()
{
	this->geometry = nullptr;
	this->distance = 0.0;
	this->position = Vector3::zero();
	this->normal = Vector3::zero();
}

IntersectResult IntersectResult::noHit() {
	return IntersectResult();
}


IntersectResult::~IntersectResult()
{
}
