#ifndef RAY_HPP_INCLUDED
#define RAY_HPP_INCLUDED
#include "VectorFunctions.h"

class Ray
{
public:
    Ray();
    Ray(sf::Vector3f Origin, sf::Vector3f Direction);

    sf::Vector3f& GetOrigin()    {return orig;};
    sf::Vector3f& GetDirection() {return dir; };

private:
    sf::Vector3f dir;
    sf::Vector3f orig;
};

#endif // RAY_HPP_INCLUDED
