#include "include/player.h"

Player::Player(const Vector3f &initialPosition) : GameObject(initialPosition)
{
  boundingBox = calculateBoundingBox();
}

BoundingBox Player::calculateBoundingBox()
{
  return BoundingBox(
      Vector3f(position.x - 0.05, position.y, position.z - 0.05),
      Vector3f(position.x + 0.05, position.y + 0.2, position.z + 0.05));
}

void Player::update(float dt){

}

void Player::render() const {
	glPushMatrix();
	glScalef(0.01f, 0.01f, 0.01f);
	glRotatef(180, 0, 1, 0);
	model_player.Draw();
	glPopMatrix();
}