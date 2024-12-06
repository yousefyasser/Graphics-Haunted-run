#include "include/spawnables/spawnableManager.h"

void SpawnableManager::update(float dt, std::vector<std::unique_ptr<Spawnable>> &spawnables, Model_3DS enemy_model, Model_3DS collectable_model, float groundSpeed){
    bool spawnableOutOfBound = false;
    enemy_last_spawned_at += dt;
    collectable_last_spawned_at += dt;

    spawn(spawnables, enemy_model, collectable_model, groundSpeed);

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

void SpawnableManager::spawn(std::vector<std::unique_ptr<Spawnable>> &spawnables, const Model_3DS &enemy_model, const Model_3DS &collectable_model, float groundSpeed)
{   
    if(collectable_last_spawned_at >= COLLECTABLE_SPAWN_RATE){
        Vector3f pos(0, 3, 100), vel(0, 0, -groundSpeed), angle(0, 0, 0);

        auto newCollectable = std::make_unique<Collectable>(pos, vel, angle);
        newCollectable->setModel(collectable_model);
        spawnables.push_back(std::move(newCollectable));

        collectable_last_spawned_at = 0;
    }else if(enemy_last_spawned_at >= ENEMY_SPAWN_RATE){
        Vector3f pos(1, 3, 100), vel(0, 0, -groundSpeed), angle(0, 90, 0);

        auto newEnemy = std::make_unique<Enemy>(pos, vel, angle);
        newEnemy->setModel(enemy_model);
        spawnables.push_back(std::move(newEnemy));

        enemy_last_spawned_at = 0;
    }
}
