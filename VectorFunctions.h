#ifndef VECTORFUNCTIONS_H_INCLUDED
#define VECTORFUNCTIONS_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>


template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

float dotProduct(sf::Vector3f v1, sf::Vector3f v2);

sf::Vector3f crossProduct(sf::Vector3f v1, sf::Vector3f v2);

float magnitude(sf::Vector3f vec, sf::Vector3f orig);

sf::Vector3f add(sf::Vector3f v1, sf::Vector3f v2);

sf::Vector3f subtract(sf::Vector3f v1, sf::Vector3f v2);

sf::Vector3f normalize(sf::Vector3f &vec);

sf::Vector3f inverse(sf::Vector3f vec);

float distance(sf::Vector3f p1, sf::Vector3f p2);
#endif // VECTORFUNCTIONS_H_INCLUDED
