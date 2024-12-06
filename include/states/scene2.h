#include "basestate.h"
#include "../camera.h"
#include "../sun.h"
#include "../player.h"
#include "../spawnables/spawnableManager.h"
#include "../groundmanager.h"
#include "../wallmanager.h"

#include <glut.h>

class Scene2 : public BaseState
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
    Scene2();

    void enter(const BaseParams& params) override;
    void exit() override;
    void update(float dt) override;
    void render() const override;

public:
    int keyMode;
    Camera camera;
    Sun sun;
    Player player;
    SpawnableManager spawnableManager;

    Model_3DS enemyModel;

    std::vector<std::unique_ptr<Spawnable>> enemies;
    GroundManager groundManager;
    WallManager wallManagerLeft;
    WallManager wallManagerRight;
};