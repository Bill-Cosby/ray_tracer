#ifndef SPHERE_HPP_INCLUDED
#define SPHERE_HPP_INCLUDED
#include "ray.hpp"


class primitive
{
public:
    sf::Vector3f pos;
    float radius;
    float reflection = 1.0f;
    float diffuseFactor = 1.0f;
    float specular = 1.0f;
    sf::Color color;

    primitive(sf::Vector3f tPos, float r, float rf, sf::Color tcolor);

    virtual bool intersect(Ray& ray, float& dist){};
    virtual sf::Vector3f GetNormal(sf::Vector3f& position){}
};

class sphere : public primitive
{
public:
    sphere(sf::Vector3f tPos, float r, float rf, sf::Color tcolor) : primitive(tPos, r, rf, tcolor){};
    sf::Vector3f GetNormal(sf::Vector3f& position){
        return (pos - position) * (1/radius);
    }
    bool intersect(Ray& ray, float& dist);
};

class Box : public primitive
{
public:

    sf::Vector3f points[8];
    sf::Vector3f bounds[2];

    Box(sf::Vector3f tPos, float r, float rf, sf::Color tcolor);

    bool intersect(Ray& ray, float& dist);
    sf::Vector3f GetNormal(sf::Vector3f& position);
};

#endif // SPHERE_HPP_INCLUDED
