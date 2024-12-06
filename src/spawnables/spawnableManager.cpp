#include "include/spawnables/spawnableManager.h"
#include "include/collisionmanager.h"

SpawnableManager::SpawnableManager(bool enemies, bool collectables) : enemies(enemies), collectables(collectables) {}

void SpawnableManager::update(float dt, std::vector<std::unique_ptr<Spawnable>> &spawnables, bool isEnemy, const Model_3DS &model, float groundSpeed){
    bool spawnableOutOfBound = false;

    if(collectables){
        collectable_last_spawned_at += dt;
    }
    if(enemies){
        enemy_last_spawned_at += dt;
    }
    
    spawn(spawnables, isEnemy, model, groundSpeed);

    for(auto& spawnable: spawnables){
        spawnable->update(dt);
        
        if(spawnable->position.z <= -10){
            spawnableOutOfBound = true;
        }
    }

    if(spawnableOutOfBound){
        spawnables.erase(spawnables.begin());
    }
}

void SpawnableManager::render(const std::vector<std::unique_ptr<Spawnable>> &spawnables) const {
    for(const auto& spawnable: spawnables){
        spawnable->render();
    }
}

void SpawnableManager::spawn(std::vector<std::unique_ptr<Spawnable>> &spawnables, bool isEnemy, const Model_3DS &model, float groundSpeed)
{
    if(collectable_last_spawned_at >= COLLECTABLE_SPAWN_RATE && !isEnemy){
        Vector3f pos(0, 3, 100), vel(0, 0, -groundSpeed), angle(0, 0, 0);

        auto newCollectable = std::make_unique<Collectable>(pos, vel, angle);
        newCollectable->setModel(model);
        spawnables.push_back(std::move(newCollectable));

        collectable_last_spawned_at = 0;
    }else if(enemy_last_spawned_at >= ENEMY_SPAWN_RATE && isEnemy){
        Vector3f pos(1, 3, 100), vel(0, 0, -groundSpeed), angle(0, 90, 0);

        auto newEnemy = std::make_unique<Enemy>(pos, vel, angle);
        newEnemy->setModel(model);
        spawnables.push_back(std::move(newEnemy));

        enemy_last_spawned_at = 0;
    }
}

int SpawnableManager::isColliding(Player &player, const std::vector<std::unique_ptr<Spawnable>> &spawnables) {
    for(int i = 0; i < spawnables.size(); i++){
        if (CollisionManager::checkCollision(player, *spawnables[i])) {
            return i;
        }
    }

    return -1;
}

void SpawnableManager::removeColliding(int index, std::vector<std::unique_ptr<Spawnable>> &spawnables){
    spawnables.erase(spawnables.begin() + index);
}