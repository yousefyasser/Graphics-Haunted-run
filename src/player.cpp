#include "include/player.h"

void Player::update(float dt)
{
  position += velocity;
}

void Player::render() const
{
  glPushMatrix();
  glTranslatef(position.x, position.y, position.z);
  glScalef(0.01f, 0.01f, 0.01f);
  glRotatef(angle.y, 0, 1, 0);
  model.Draw();
  glPopMatrix();
}

void Player::load()
{
  model.Load("Models/boy/boy.3DS");
}