#ifndef LIGHT_HPP_INCLUDED
#define LIGHT_HPP_INCLUDED
#include "sphere.hpp"
enum LightType
{
	LIGHT_NONE,
	LIGHT_POINT,
	LIGHT_DIRECTIONAL,
	LIGHT_SPOT,
};

class Light
{
public:
    Light(sf::Vector3f tpos, sf::Color tcolor);
    sf::Vector3f pos;

    LightType GetType(){return type;}
    sf::Color GetColor(){return color;}

    sf::Color calculateSphereLightingAtPoint(sphere& Sphere, sf::Vector3f& intersectionPoint);
    float getAttenuation(float dist);

private:
    LightType type = LIGHT_POINT;
    sf::Color color;

    float range;
    float AttenuationConstant = 0.0f;
    float AttenuationLinear = 1.0f;
    float AttenuationQuadratic = 0.0f;
};

#endif // LIGHT_HPP_INCLUDED
