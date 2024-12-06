#include "SoundManager.h"
#include <iostream>

SoundManager::SoundManager() {}

SoundManager::~SoundManager() {}

void SoundManager::loadSound(const std::string &name, const std::string &filename)
{
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(filename))
    {
        std::cerr << "Error loading sound file: " << filename << std::endl;
        return;
    }
    soundBuffers[name] = buffer;
    sounds[name].setBuffer(soundBuffers[name]);
}

void SoundManager::playSound(const std::string &name)
{
    if (sounds.find(name) != sounds.end())
    {
        sounds[name].play();
    }
}

void SoundManager::stopSound(const std::string &name)
{
    if (sounds.find(name) != sounds.end())
    {
        sounds[name].stop();
    }
}

void SoundManager::setVolume(const std::string &name, float volume)
{
    if (sounds.find(name) != sounds.end())
    {
        sounds[name].setVolume(volume);
    }
}

sf::Sound::Status SoundManager::getSoundStatus(const std::string &name)
{
    if (sounds.find(name) != sounds.end())
    {
        return sounds[name].getStatus();
    }
    return sf::Sound::Stopped;
}