#include "include/gameobject.h"

class CollisionManager {
public:
  // Check collision between two objects
  static bool checkCollision(GameObject *obj1, GameObject *obj2) {
    return obj1->checkCollision(obj2);
  }
};
