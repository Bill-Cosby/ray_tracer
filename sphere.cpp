#include "sphere.hpp"

bool sphere::intersect(Ray& ray, float& dist)
{
    bool result = false;

    sf::Vector3f e = pos - ray.GetOrigin();
    float        a = dotProduct(ray.GetDirection(),e);

    float f = pow(radius,2) - dotProduct(e,e) + (a * a);

    if (f < 0.0f)return result;
    else{
        float t = a - sqrtf(f);

        if (t > 0.1f and t < 1000){
            dist = t;
            result = true;
        }
    }
    return result;
}

bool Box::intersect(Ray& ray, float& dist)
{
    float tmin, tmax, tymin, tymax, tzmin, tzmax;

    tmin = (bounds[ray.sign[0]].x - ray.orig.x) * ray.invdir.x;
    tmax = (bounds[1-ray.sign[0]].x - ray.orig.x) * ray.invdir.x;
    tymin = (bounds[ray.sign[1]].y - ray.orig.y) * ray.invdir.y;
    tymax = (bounds[1-ray.sign[1]].y - ray.orig.y) * ray.invdir.y;

    if ((tmin > tymax) || (tymin > tmax))
        return false;
    if (tymin > tmin)
        tmin = tymin;
    if (tymax < tmax)
        tmax = tymax;

    tzmin = (bounds[ray.sign[2]].z - ray.orig.z) * ray.invdir.z;
    tzmax = (bounds[1-ray.sign[2]].z - ray.orig.z) * ray.invdir.z;

    if ((tmin > tzmax) || (tzmin > tmax))
        return false;
    if (tzmin > tmin)
        tmin = tzmin;
    if (tzmax < tmax)
        tmax = tzmax;

    dist = tmin;

    return true;
}

sf::Vector3f Box::GetNormal(sf::Vector3f& position)
{
    sf::Vector3f normal;
    sf::Vector3f localPoint = position - pos;
    float min = std::numeric_limits<float>::max();
    float distance = std::abs(radius - std::abs(localPoint.x));
    if (distance < min) {
        min = distance;
        normal = sf::Vector3f(1, 0, 0);
        normal.x *= sgn(localPoint.x);
        normal.y *= sgn(localPoint.x);
        normal.z *= sgn(localPoint.x);
    }
    distance = std::abs(radius - std::abs(localPoint.y));
    if (distance < min) {
        min = distance;
        normal = sf::Vector3f(0, 1, 0);
        normal.x *= sgn(localPoint.y);
        normal.y *= sgn(localPoint.y);
        normal.z *= sgn(localPoint.y);
    }
    distance = std::abs(radius - std::abs(localPoint.z));
    if (distance < min) {
        min = distance;
        normal = sf::Vector3f(0, 0, 1);
        normal.x *= sgn(localPoint.z);
        normal.y *= sgn(localPoint.z);
        normal.z *= sgn(localPoint.z);
    }
    return normal;
}
Box::Box(sf::Vector3f tPos, float r, float rf, sf::Color tcolor) : primitive(tPos, r, rf, tcolor)
{
    float hr = r*.5;
    points[0] = sf::Vector3f(tPos.x-hr, tPos.y-hr, tPos.z-hr);
    points[1] = sf::Vector3f(tPos.x+hr, tPos.y-hr, tPos.z-hr);
    points[2] = sf::Vector3f(tPos.x+hr, tPos.y-hr, tPos.z+hr);
    points[3] = sf::Vector3f(tPos.x-hr, tPos.y-hr, tPos.z+hr);
    points[4] = sf::Vector3f(tPos.x-hr, tPos.y+hr, tPos.z-hr);
    points[5] = sf::Vector3f(tPos.x+hr, tPos.y+hr, tPos.z-hr);
    points[6] = sf::Vector3f(tPos.x+hr, tPos.y+hr, tPos.z+hr);
    points[7] = sf::Vector3f(tPos.x-hr, tPos.y+hr, tPos.z+hr);
    bounds[0] = points[0];
    bounds[1] = points[6];
}

primitive::primitive(sf::Vector3f tPos, float r, float rf, sf::Color tcolor)
{
        pos = tPos;
        radius = r;
        reflection = rf;
        color = tcolor;
}
