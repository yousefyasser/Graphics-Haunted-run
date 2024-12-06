#include "include/spawnables/spawnable.h"

void Spawnable::update(float dt){
    position += velocity * dt;
}