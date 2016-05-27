#include "VectorFunctions.h"
float dotProduct(sf::Vector3f v1, sf::Vector3f v2)
{
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

sf::Vector3f crossProduct(sf::Vector3f v1, sf::Vector3f v2)
{
    sf::Vector3f crossproduct;

    crossproduct.x = (v1.y * v2.z) - (v1.z * v2.y);
    crossproduct.y = (v1.z * v2.x) - (v1.x * v2.z);
    crossproduct.z = (v1.x * v2.y) - (v1.y * v2.x);

    return crossproduct;
}

float magnitude(sf::Vector3f vec, sf::Vector3f orig)
{
    return sqrt(pow(vec.x-orig.x,2)+pow(vec.y-orig.y,2)+pow(vec.z-orig.z,2));
}

sf::Vector3f add(sf::Vector3f v1, sf::Vector3f v2)
{
    return sf::Vector3f(v1.x + v2.x , v1.y + v2.y , v1.z + v2.z);
}

sf::Vector3f subtract(sf::Vector3f v1, sf::Vector3f v2)
{
    return sf::Vector3f(v1.x - v2.x , v1.y - v2.y , v1.z - v2.z);
}

sf::Vector3f normalize(sf::Vector3f vec)
{
    if (magnitude(vec,sf::Vector3f(0,0,0)) != 0){
        sf::Vector3f normalized;

        float factor = 1.0f / magnitude(vec,sf::Vector3f(0,0,0));

        normalized.x = vec.x * factor;
        normalized.y = vec.y * factor;
        normalized.z = vec.z * factor;

        return normalized;
    }

    return vec;
}

sf::Vector3f inverse(sf::Vector3f vec)
{
    return sf::Vector3f(-vec.x,-vec.y,-vec.z);
}
