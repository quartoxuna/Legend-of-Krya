#pragma once

#include <vector>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

namespace pacman
{

class Player : public sf::Transformable, public sf::Drawable
{

    enum Direction {
        RIGHT,
        LEFT,
        UP,
        DOWN
    };

    public:
        Player();

    public:
        void processEvent(sf::Event);
        void update(sf::Time deltaTime);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        sf::Texture  mTexture;
        Direction    mCurrentDirection;
        sf::Sprite   mSprite;

        std::vector<sf::IntRect> mAnimationFrames;
        int          mCurrentAnimationFrame;
        sf::Time     mTimePerFrame;
        sf::Time     mTimePassed;
        sf::SoundBuffer mSoundBuffer;
        sf::Sound       mSound;
        float        mSpeed;

};

} // end of namespace pacman
