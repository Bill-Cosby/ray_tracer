#ifndef SPHERE_HPP_INCLUDED
#define SPHERE_HPP_INCLUDED
#include "ray.hpp"


class sphere
{
public:
    sf::Vector3f pos;
    float radius;
    float reflection = 1.0f;
    sf::Color color;

    sphere(sf::Vector3f tPos, float r, float rf, sf::Color tcolor){
        pos = tPos;
        radius = r;
        reflection = rf;
        color = tcolor;
    }

    bool intersect(Ray& ray, float& dist);
};

#endif // SPHERE_HPP_INCLUDED
