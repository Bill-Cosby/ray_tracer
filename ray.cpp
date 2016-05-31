#include "ray.hpp"

Ray::Ray(sf::Vector3f Origin, sf::Vector3f Direction)
{
    orig = Origin;
    dir = Direction;
    invdir = sf::Vector3f(1/dir.x,1/dir.y,1/dir.z);
    sign[0] = invdir.x < 0;
    sign[1] = invdir.y < 0;
    sign[2] = invdir.z < 0;

}
