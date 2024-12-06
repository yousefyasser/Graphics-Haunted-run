#include "include/player.h"

float Player::PLAYER_Y = 5;
float Player::JUMP_SPEED = 0.2f;
float Player::JUMP_HEIGHT = Player::PLAYER_Y + 5;

BoundingBox Player::calculateBoundingBox()
{
  return BoundingBox(
      Vector3f(position.x - 1, position.y - 5, position.z - 0.05f),
      Vector3f(position.x + 1, position.y + 5, position.z + 0.05f));
}

void Player::update(float dt)
{
  position += velocity;

  if (falling && !jumping) {
    position.y -= MAX_SPEED;
    if (position.y < -15) {
      position.y = PLAYER_Y;
      falling = false;
      startInvincibility();
    }
  }

  if(jumping){
    if(position.y >= JUMP_HEIGHT) {
      velocity.y = -JUMP_SPEED;
    }else if(position.y <= PLAYER_Y){
      position.y = PLAYER_Y;
      velocity.y = 0;
      jumping = false;
    }
  }

  if (invincible) {
    auto now = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - invincibilityTimer);
    if (elapsed.count() > 3)
      invincible = false;
  }
}

void Player::render() const
{
  float alpha = invincible ? 0.7f : 1.0f;
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glColor4f(1.0f, 1.0f, 1.0f, alpha);

  glPushMatrix();
  glTranslatef(position.x, position.y, position.z);
  glScalef(0.01f, 0.01f, 0.01f);
  glRotatef(angle.y, 0, 1, 0);
  model.Draw();
  glPopMatrix();

  glDisable(GL_BLEND);
  glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
}

void Player::load()
{
  model.Load("Models/boy/boy.3DS");
}

void Player::startFalling() {
  falling = true;
}

void Player::startInvincibility() {
  invincible = true;
  invincibilityTimer = std::chrono::high_resolution_clock::now();
}

void Player::jump(){
  if(falling) {
    return;
  }
  
  jumping = true;
  velocity.y = JUMP_SPEED;
}

bool Player::isFalling() const {return falling;}
bool Player::isJumping() const {return jumping;}
bool Player::isInvincible() const {return invincible;}