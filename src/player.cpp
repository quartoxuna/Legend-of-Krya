#include <player.hpp>

#include <stdexcept> // std::runtime_error

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

namespace pacman
{

/**
 * Constructor
 */
Player::Player()
: mTexture()
, mSprite()
, mCurrentDirection(Player::Direction::RIGHT)
, mCurrentAnimationFrame(0)
, mTimePassed(sf::Time::Zero)
, mTimePerFrame(sf::milliseconds(50))
, mAnimationFrames()
, mSpeed(2.5f)
, mSoundBuffer()
, mSound()
{
    // Load and set texture to sprite
    if (!mTexture.loadFromFile("../assets/pacman.png"))
        throw std::runtime_error("Cannot load pacman texture");
    mSprite.setTexture(mTexture);

    // Store animation frames
    mAnimationFrames.push_back(sf::IntRect(0, 0, 32, 32));
    mAnimationFrames.push_back(sf::IntRect(32, 0, 32, 32));
    mAnimationFrames.push_back(sf::IntRect(64, 0, 32, 32));
    mAnimationFrames.push_back(sf::IntRect(32, 0, 32, 32));

    // Store sounds
    mSoundBuffer.loadFromFile("../assets/pacman.wav");
    mSound.setBuffer(mSoundBuffer);
    mSound.setLoop(true);
    mSound.play();

    // Set texture section
    mSprite.setTextureRect(mAnimationFrames[mCurrentAnimationFrame]);

    // Set position
    sf::FloatRect bounds = mSprite.getLocalBounds();
    mSprite.setOrigin(bounds.width/2.f, bounds.height/2.f);
    mSprite.setPosition(50.f, 50.f);
}


/**
 * Updates the player
 */
void Player::update(sf::Time deltaTime)
{
    // Move
    sf::Vector2f movement(0.f, 0.f);
    if (mCurrentDirection == Player::Direction::UP)
        movement.y -= mSpeed;
    else if (mCurrentDirection == Player::Direction::DOWN)
        movement.y += mSpeed;
    else if (mCurrentDirection == Player::Direction::LEFT)
        movement.x -= mSpeed;
    else if (mCurrentDirection == Player::Direction::RIGHT)
        movement.x += mSpeed;
    mSprite.move(movement);

    // Tick animation
    mTimePassed += deltaTime;
    if (mTimePassed >= mTimePerFrame)
    {
        mTimePassed = sf::Time::Zero;

        mCurrentAnimationFrame++;
        if (mCurrentAnimationFrame >= mAnimationFrames.size())
        {
            mCurrentAnimationFrame = 0;
        }
    
        sf::IntRect textureRect(mAnimationFrames[mCurrentAnimationFrame]);
        mSprite.setTextureRect(textureRect);
    }
}


/**
 * Process input
 */
void Player::processEvent(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            mCurrentDirection = Player::Direction::UP;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            mCurrentDirection = Player::Direction::DOWN;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            mCurrentDirection = Player::Direction::LEFT;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            mCurrentDirection = Player::Direction::RIGHT;
    }

    // Rotate according to direction
    if (mCurrentDirection == Player::Direction::RIGHT)
        mSprite.setRotation(0.f);
    else if (mCurrentDirection == Player::Direction::DOWN)
        mSprite.setRotation(90.f);
    else if (mCurrentDirection == Player::Direction::LEFT)
        mSprite.setRotation(180.f);
    else if (mCurrentDirection == Player::Direction::UP)
        mSprite.setRotation(270.f);
}


/**
 * Render the player
 */
void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite);
}

} // end of namespace pacman
