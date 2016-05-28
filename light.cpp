#include "light.hpp"

Light::Light(sf::Vector3f tpos, sf::Color tcolor)
{
    pos = tpos;
    color = tcolor;
    range = 2000;
}

