#pragma once

#include "basestate.h"
#include "../camera.h"
#include "../sun.h"
#include "../player.h"
#include "../groundmanager.h"
#include "../wallmanager.h"
#include "../FlickeringLights.h"

#include <glut.h>

class Scene : public BaseState
{
public:
    struct EnterParams: public BaseParams
    {
        GLdouble fovy;
        GLdouble aspectRatio;
        GLdouble zNear;
        GLdouble zFar;

        EnterParams(GLdouble fovy, GLdouble aspectRatio, GLdouble zNear, GLdouble zFar)
            : fovy(fovy), aspectRatio(aspectRatio), zNear(zNear), zFar(zFar) {}
    };

public:
    Scene();
    virtual void enter(const BaseParams& params) override;
    virtual void exit() override;
    virtual void update(float dt) override;
    virtual void render() const override;

public:
    int keyMode;
    Camera camera;
    Sun sun;
    Player player;

    GroundManager groundManager;
    WallManager wallManagerLeft;
    WallManager wallManagerRight;

    FlickeringLights fl1;
    FlickeringLights fl2;
};