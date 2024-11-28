#pragma once

#include <string>

#include "vector3f.h"
#include "camera.h"

namespace util
{
    void setupLights();
    void setupCamera(int width, int height, Camera &camera);
    void drawText(float x, float y, float z, const char *text);
    void drawText(float x, float y, const char *text);
    void drawText(float x, float y, float z, std::string text);
    void drawText(float x, float y, std::string text);
}