#include "Union.h"
#define Infinity 10000


Union::Union()
{
}

Union::Union(std::vector<Geometry*> geometries) {
	this->geometries = geometries;
}

void Union::initialize() {
	for (auto iterator = this->geometries.begin(); iterator != this->geometries.end(); iterator++) {
		(*iterator)->initialize();
	}
}

IntersectResult Union::intersect(Ray& ray) {
	double minDistance = Infinity;
	IntersectResult minResult = IntersectResult::noHit();
	for (auto iterator = this->geometries.begin(); iterator != this->geometries.end(); iterator++) {
		IntersectResult result = (*iterator)->intersect(ray);
		if (result.geometry&&result.distance < minDistance) {
			minDistance = result.distance;
			minResult = result;
		}
	}
	return minResult;
}


Union::~Union()
{
}
