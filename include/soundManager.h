#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <SFML/Audio.hpp>
#include <unordered_map>
#include <string>

class SoundManager
{
public:
    SoundManager();
    ~SoundManager();

    void loadSound(const std::string &name, const std::string &filename);
    void playSound(const std::string &name);
    void stopSound(const std::string &name);
    void setVolume(const std::string &name, float volume);
    sf::Sound::Status getSoundStatus(const std::string &name);

private:
    std::unordered_map<std::string, sf::SoundBuffer> soundBuffers;
    std::unordered_map<std::string, sf::Sound> sounds;
};

#endif // SOUNDMANAGER_H