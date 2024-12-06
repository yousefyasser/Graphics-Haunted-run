#pragma once

#include <string>

#include "vector3f.h"
#include "camera.h"

namespace util
{
    float DEG2RAD(float a);

    void setupLights();
    void setupMaterials();
    void setupCamera(int width, int height, Camera &camera);
    void drawText(float x, float y, float z, const char *text);
    void drawText(float x, float y, const char *text);
    void drawText(float x, float y, float z, std::string text);
    void drawText(float x, float y, std::string text);

    template<typename Base, typename T>
    inline bool instanceof(const T *ptr);
}