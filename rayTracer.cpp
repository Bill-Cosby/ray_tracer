#include "rayTracer.hpp"

//void rayTracer::render()
//{
//    for (int y = -300; y < 300; y++){
//        for (int x = -400; x < 400; x++){
//            sf::Vector3f dir = sf::Vector3f(x,y,0) - cameraPos;
//            dir = normalize(dir);
//
//            Ray ray(cameraPos, dir);
//
//            img->setPixel(x+400,y+300,traceRay(ray,0));
//        }
//    }
//}

void rayTracer::render()
{
    //img->create(600,800,sf::Color::Black);
    if (nextLine > 600)nextLine = 0;

    for (int y = 0; y < 600; y++){
        currentX = ViewPlaneX1;

        for (int x = 0; x < 800; x++){

            sf::Vector3f dir = sf::Vector3f(currentX, currentY, ViewPlaneZ) - cameraPos;

            dir = normalize(dir);

            Ray ray(cameraPos, dir);

            sf::Color pixelColor = traceRay(ray, 1);

            img->setPixel(x, y, pixelColor);

            currentX += DeltaX;
        }

        currentY += DeltaY;
        nextLine++;
    }
}

sf::Color rayTracer::traceRay(Ray& ray, int depth)
{
    if (depth == 6)return sf::Color(0,0,0);

    sf::Color litColor, reflectedColor;
    float distanceToIntersect = 10000;

    sf::Vector3f intersection;
    primitive* nearestSphere = NULL;

    nearestSphere = getNearestSphere(ray, distanceToIntersect);

    if (!nearestSphere)return sf::Color(0,0,0);

    else{
        intersection = ray.GetOrigin() + ray.GetDirection() * distanceToIntersect;
        //litColor = calculateLight(nearestSphere, intersection, ray.GetDirection());
        litColor = nearestSphere->color;

        float reflectionFactor = nearestSphere->reflection;

        if (reflectionFactor > 0){
            sf::Vector3f normal = nearestSphere->GetNormal(intersection);
            sf::Vector3f reflected = ray.GetDirection() - normal * (2.0f * dotProduct(ray.GetDirection(), normal));

            Ray reflectedRay = Ray(intersection + reflected * .0001f, reflected);
            reflectedColor = traceRay(reflectedRay, depth + 1);
            reflectedColor.r*=reflectionFactor;
            reflectedColor.g*=reflectionFactor;
            reflectedColor.b*=reflectionFactor;
        }

        return litColor + reflectedColor;
    }
}

primitive* rayTracer::getNearestSphere(Ray& ray, float& distanceToIntersect)
{
    primitive* nearestSphere = NULL;

    float dist = 10000;

    for (primitive* tPrimitive : primitives){
        if (tPrimitive->intersect(ray,dist)){
            if (dist < distanceToIntersect and dist > 0){
                distanceToIntersect = dist;
                nearestSphere = tPrimitive;
            }
        }
    }

    return nearestSphere;
}

sf::Color rayTracer::calculateLight(primitive* Sphere, sf::Vector3f& intersection, sf::Vector3f rayDirection)
{
    sf::Color colorAtIntersection(0,0,0);

    for (Light& light : lights){
        if (light.GetType() == LIGHT_POINT){
            sf::Vector3f normal = Sphere->GetNormal(intersection);
            sf::Vector3f toLight = light.pos - intersection;

            float distToLight = magnitude(toLight, intersection);
            toLight.x*=1/distToLight;
            toLight.y*=1/distToLight;
            toLight.z*=1/distToLight;

            bool inLight = true;
            sf::Vector3f shadowRayOrig;

            shadowRayOrig.x = intersection.x + toLight.x * .0001f;
            shadowRayOrig.y = intersection.y + toLight.y * .0001f;
            shadowRayOrig.z = intersection.z + toLight.z * .0001f;

            Ray shadowRay = Ray(shadowRayOrig, toLight);

            for (primitive* tPrimitive : primitives){
                if (tPrimitive->intersect(shadowRay, distToLight)){
                    inLight = false;
                    break;
                }
            }
            if (inLight){
                float diffuseIntensity = dotProduct(toLight, normal)*Sphere->diffuseFactor;

                if (diffuseIntensity > 0){

                    sf::Color diffusedColor;
                    diffusedColor.r = Sphere->diffuseFactor * light.GetColor().r * diffuseIntensity;
                    diffusedColor.g = Sphere->diffuseFactor * light.GetColor().g * diffuseIntensity;
                    diffusedColor.b = Sphere->diffuseFactor * light.GetColor().b * diffuseIntensity;

                    colorAtIntersection += diffusedColor;
                }

                sf::Vector3f reflectedLight = toLight - normal * (2.0f * dotProduct(toLight, normal));
                float reflectedLightAlongRay = dotProduct(rayDirection, reflectedLight);

                if (reflectedLightAlongRay){
                    float specularIntensity = pow(reflectedLightAlongRay, 25) * Sphere->specular;
                    sf::Color specularedLight = light.GetColor();
                    specularedLight.r *= specularIntensity;
                    specularedLight.g *= specularIntensity;
                    specularedLight.b *= specularIntensity;
                    colorAtIntersection += specularedLight;
                }
            }
        }
    }
    return colorAtIntersection;
}

rayTracer::rayTracer(sf::Image* image, sf::Vector3f cam) : rayTracer()
{
    img = image;
    cameraPos = cam;
}


rayTracer::rayTracer()
{
    nextLine = bufferIndex = 0;

    ViewPlaneX1 = -8;
    ViewPlaneX2 = 8;
    ViewPlaneY1 = currentY = 6;
    ViewPlaneY2 = -6;

    DeltaX = (float)(ViewPlaneX2 - ViewPlaneX1) / 800;
    DeltaY = (float)(ViewPlaneY2 - ViewPlaneY1) / 600;
}



void rayTracer::moveCam(sf::Vector3f dist)
{

    cameraPos += dist;

    ViewPlaneX1 += dist.x;
    ViewPlaneX2 += dist.x;

    ViewPlaneY1 += dist.y;
    ViewPlaneY2 += dist.y;

    ViewPlaneZ += dist.z;

    currentX += dist.x;
    currentY = ViewPlaneY1;

    //DeltaX = (float)(ViewPlaneX2 - ViewPlaneX1) / 800;
    //DeltaY = (float)(ViewPlaneY2 - ViewPlaneY1) / 600;

}
