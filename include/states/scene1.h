#include "basestate.h"
#include "../camera.h"
#include "../sun.h"
#include "../player.h"
#include "../tilemanager.h"

#include <glut.h>

class Scene1 : public BaseState
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
    Scene1();

    void enter(const BaseParams& params) override;
    void exit() override;
    void update(float dt) override;
    void render() const override;

public:
    int keyMode = 0;
    Camera camera;
    Sun sun;
    Player player;
    TileManager tileManager;
};