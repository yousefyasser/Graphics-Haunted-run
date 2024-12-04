#include "include/player.h"

Player::Player(const Vector3f &initialPosition, const Vector3f &initialVelocity, const Vector3f &initialAngle) 
            : GameObject(initialPosition, initialVelocity, initialAngle)
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
	position += velocity;
}

void Player::render() const {
	glPushMatrix();
  glTranslatef(position.x, position.y, position.z);
	glScalef(0.01f, 0.01f, 0.01f);
	glRotatef(angle.y, 0, 1, 0);
	model_player.Draw();
	glPopMatrix();
}