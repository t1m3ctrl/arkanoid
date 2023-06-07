#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <windows.h>
#include <cstdio>
#include <string>

constexpr int livesStart{3};
constexpr int windowWidth{800}, windowHeight{600};
constexpr float ballRadius{10.f}, ballVelocity{8.f};
constexpr float paddleWidth{100.f}, paddleHeight{10.f}, paddleVelocity{10.f};
constexpr float blockWidth{60.f}, blockHeight{20.f};
constexpr int countBlocksX{11}, countBlocksY{5};

int lives = livesStart;
int score = 0;

struct Rectangle
{
    sf::RectangleShape shape;
    float x() { return shape.getPosition().x; }
    float y() { return shape.getPosition().y; }
    float left() { return x() - shape.getSize().x / 2.f; }
    float right() { return x() + shape.getSize().x / 2.f; }
    float top() { return y() - shape.getSize().y / 2.f; }
    float bottom() { return y() + shape.getSize().y / 2.f; }
};

struct Paddle : public Rectangle
{
    sf::Vector2f velocity;
    sf::Image paddleImage;
    sf::Texture paddleTexture;

    Paddle(float mX, float mY)
    {
        paddleImage.loadFromFile("../res/images/paddle.png");
        paddleTexture.loadFromImage(paddleImage);

        shape.setTexture(&paddleTexture);
        shape.setPosition(mX, mY);
        shape.setSize({paddleWidth, paddleHeight});
        shape.setOrigin(paddleWidth / 2.f, paddleHeight / 2.f);
    }

    void update()
    {
        shape.move(velocity);

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) && (left() > 0))
            velocity.x = -paddleVelocity;
        else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) && (right() < windowWidth))
            velocity.x = paddleVelocity;
        else
            velocity.x = 0;
    }
};

struct Ball
{
    sf::CircleShape shape;
    sf::Vector2f velocity{0, 0};
    sf::Image ballImage;
    sf::Texture ballTexture;

    Ball(float mX, float mY)
    {
        ballImage.loadFromFile("../res/images/ball.png");
        ballTexture.loadFromImage(ballImage);

        shape.setTexture(&ballTexture);
        shape.setPosition(mX, mY);
        shape.setRadius(ballRadius);
        shape.setOrigin(ballRadius, ballRadius);
    }

    void update()
    {

        shape.move(velocity);

        if ((velocity.y == 0 && velocity.x == 0) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)))
        {
            velocity.x = ballVelocity;
            velocity.y = ballVelocity;
        }

        if (left() < 0)
            velocity.x = ballVelocity;
        else if (right() > windowWidth)
            velocity.x = -ballVelocity;

        if (top() < 0)
            velocity.y = ballVelocity;
        else if (bottom() > windowHeight)
        {
            velocity.y = 0;
            velocity.x = 0;
            lives--;
        }
    }

    float x() { return shape.getPosition().x; }
    float y() { return shape.getPosition().y; }
    float left() { return x() - shape.getRadius(); }
    float right() { return x() + shape.getRadius(); }
    float top() { return y() - shape.getRadius(); }
    float bottom() { return y() + shape.getRadius(); }
};

struct Brick : public Rectangle
{
    int durability;
    int constdur;
    bool destroyed = false;

    Brick(float mX, float mY, int durab)
    {
        shape.setPosition(mX, mY);
        shape.setSize({blockWidth, blockHeight});
        shape.setOrigin(blockWidth / 2.f, blockHeight / 2.f);
        constdur = durab;
        durability = durab;
    }
};

template <class T1, class T2>
bool isIntersecting(T1 &mA, T2 &mB)
{
    return mA.right() >= mB.left() && mA.left() <= mB.right() &&
           mA.bottom() >= mB.top() && mA.top() <= mB.bottom();
}

bool testCollision(Paddle &mPaddle, Ball &mBall)
{
    if (!isIntersecting(mPaddle, mBall))
        return false;
    mBall.velocity.y = -ballVelocity;

    if (mBall.x() < mPaddle.x())
        mBall.velocity.x = -ballVelocity;
    else
        mBall.velocity.x = ballVelocity;
    return true;
}

bool testCollision(Brick &mBrick, Ball &mBall)
{
    if (!isIntersecting(mBrick, mBall))
        return false;
    if (mBrick.durability == 0)
    {
        mBrick.destroyed = true;
        score += (mBrick.constdur + 1) * 10;
    }
    else
        mBrick.durability--;
    score++;

    float overlapLeft{mBall.right() - mBrick.left()};
    float overlapRight{mBrick.right() - mBall.left()};
    float overlapTop{mBall.bottom() - mBrick.top()};
    float overlapBottom{mBrick.bottom() - mBall.top()};

    bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
    bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

    float minOverlapX{ballFromLeft ? overlapLeft : overlapRight};
    float minOverlapY{ballFromTop ? overlapTop : overlapBottom};

    if (abs(minOverlapX) < abs(minOverlapY))
        mBall.velocity.x = ballFromLeft ? -ballVelocity : ballVelocity;
    else
        mBall.velocity.y = ballFromTop ? -ballVelocity : ballVelocity;
    return true;
}

int main()
{
    FreeConsole();
    Ball ball{windowWidth / 2, windowHeight / 2};
    Paddle paddle{windowWidth / 2, windowHeight - 50};

    sf::Event event;
    sf::Font font;
    font.loadFromFile("../res/fonts/Aglettericademicondensedc.otf");
    sf::Text livesText("", font, 20);
    sf::Text scoreText("", font, 20);
    sf::Text gameoverText("GAME OVER", font, 80);
    sf::Text victoryText("Victory!", font, 80);
    gameoverText.setFillColor(sf::Color::Red);
    victoryText.setFillColor(sf::Color::Green);

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    sf::Image brickImage;
    sf::Texture brickTexture;

    sf::RenderWindow window{{windowWidth, windowHeight}, "Arkanoid"};
    window.setFramerateLimit(60);

    backgroundTexture.loadFromFile("../res/images/background.jpg");
    backgroundSprite.setTexture(backgroundTexture);

    brickImage.loadFromFile("../res/images/brick.png");
    brickTexture.loadFromImage(brickImage);

    std::vector<Brick> bricks;
    for (int iX = 0; iX < countBlocksX; ++iX)
        for (int iY = 0; iY < countBlocksY; ++iY)
            bricks.emplace_back((iX + 1) * (blockWidth + 3) + 22, (iY + 2) * (blockHeight + 3), countBlocksY - 1 - iY);

    for (auto &brick : bricks)
    {
        brick.shape.setTexture(&brickTexture);
        if (brick.durability == 0)
            brick.shape.setTextureRect(sf::IntRect(0, 0, 32, 16));
        if (brick.durability == 1)
            brick.shape.setTextureRect(sf::IntRect(32, 0, 32, 16));
        if (brick.durability == 2)
            brick.shape.setTextureRect(sf::IntRect(64, 0, 32, 16));
        if (brick.durability == 3)
            brick.shape.setTextureRect(sf::IntRect(96, 0, 32, 16));
        if (brick.durability == 4)
            brick.shape.setTextureRect(sf::IntRect(128, 0, 32, 16));
        if (brick.durability == 5)
            brick.shape.setTextureRect(sf::IntRect(160, 0, 32, 16));
    }

    sf::Music music;
    music.openFromFile("../res/sound/music/Music-0" + std::to_string(rand() % 4 + 1) + ".ogg");
    music.setVolume(30);
    music.play();

    sf::SoundBuffer hitBuffer, destroyedBuffer, lostBuffer, victoryBuffer;
    hitBuffer.loadFromFile("../res/sound/sfx/hit.wav");
    destroyedBuffer.loadFromFile("../res/sound/sfx/destroyed.wav");
    lostBuffer.loadFromFile("../res/sound/sfx/lost.wav");
    victoryBuffer.loadFromFile("../res/sound/sfx/victory.wav");
    sf::Sound hitSound(hitBuffer), destroyedSound(destroyedBuffer), lostSound(lostBuffer), victorySound(victoryBuffer);
    hitSound.setVolume(60);
    while (window.isOpen())
    {
        window.clear();
        window.draw(backgroundSprite);

        while (window.pollEvent(event))
        {
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) || (event.type == sf::Event::Closed))
                window.close();
        }
        ball.update();
        if ((ball.bottom() > windowHeight) || (ball.velocity == sf::Vector2f{0, 0}))
            ball.shape.setPosition(paddle.shape.getPosition() + sf::Vector2f{0, -paddleHeight * 2});

        paddle.update();
        if (testCollision(paddle, ball))
            hitSound.play();
        for (auto &brick : bricks)
            if (testCollision(brick, ball))
                hitSound.play();

        bricks.erase(remove_if(begin(bricks), end(bricks), [](const Brick &mBrick)
                               { return mBrick.destroyed; }),
                     end(bricks));

        livesText.setString("Lives: " + std::to_string(lives));
        livesText.setPosition(5, 5);

        scoreText.setString("Score: " + std::to_string(score));
        scoreText.setPosition(100, 5);

        if (lives <= 0)
        {
            lives = 0;
            gameoverText.setPosition(window.getSize().x / 2 - gameoverText.getGlobalBounds().width / 2, window.getSize().y / 2 - gameoverText.getGlobalBounds().height / 2);
            window.draw(gameoverText);
            // lostSound.play();
            ball.velocity = {0.001, 0.001};
        }
        if (bricks.empty() && (lives > 0))
        {
            victoryText.setPosition(window.getSize().x / 2 - victoryText.getGlobalBounds().width / 2, window.getSize().y / 2 - victoryText.getGlobalBounds().height / 2);
            window.draw(victoryText);
            // victorySound.play();
            score *= lives;
            ball.velocity = {0.001, 0.001};
        }

        window.draw(scoreText);
        window.draw(livesText);
        window.draw(ball.shape);
        window.draw(paddle.shape);
        for (auto &brick : bricks)
            window.draw(brick.shape);
        window.display();
    }

    return 0;
}