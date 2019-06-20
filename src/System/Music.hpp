#pragma once
#include <SFML/Audio.hpp>
#include "Thread.hpp"
#include <string>
#include <iostream>

using namespace std;

class Music : public Thread {
    private:
        float vol;
        bool loop;
        sf::SoundBuffer buffer;
        sf::Music music;
        std::string filename;

    public:
        Music(std::string filename);
        ~Music();
        void setVolume(float _vol){ vol = _vol; }
        void setLoop(bool _loop){ loop = _loop; }
        void play();
        void pause();
        void stop();

        virtual void run();
};