#ifndef RAY_HPP_INCLUDED
#define RAY_HPP_INCLUDED
#include "VectorFunctions.h"

class Ray
{
public:
    int sign[3];
    Ray();
    Ray(sf::Vector3f Origin, sf::Vector3f Direction);

    sf::Vector3f& GetOrigin()    {return orig;};
    sf::Vector3f& GetDirection() {return dir; };
    sf::Vector3f invdir;
    sf::Vector3f orig;

private:
    sf::Vector3f dir;
};

#endif // RAY_HPP_INCLUDED
