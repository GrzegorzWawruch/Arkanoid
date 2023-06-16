/**
 * Created by adm on 19.05.2023.
 *
 * This is the main.cpp file for a game called "Arcanoid."
 * The program includes several classes such as Ball, Paddle, Block,
 * Explosiveblock, Movingblock, and Powerups, which define the behavior
 * and properties of the game elements.
 *
 * @file main.cpp
 */

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <chrono>
#include <thread>
#include "Ball.h"
#include "Paddle.h"
#include "Menu.h"
#include "Block.h"
#include "Explosiveblock.h"
#include "Movingblock.h"
#include "Powerups.h"

using namespace std;


/**
 * Determines whether a collision exists between two objects.
 *
 * @tparam C1 the type of the first object
 * @tparam C2 the type of the second object
 * @param A a reference to the first object
 * @param B a reference to the second object
 * @return true if a collision exists between the objects, false otherwise
 */
template<class C1, class C2>
bool exist_Collision(C1 &A, C2 &B) {
    return A.right() >= B.left() && A.left() <= B.right()
           && A.bottom() >= B.top() && A.top() <= B.bottom();
}


/**
 * Checks for a collision between a paddle and a ball.
 *
 * @param paddle the paddle object
 * @param ball the ball object
 * @return true if a collision occurred and updates the ball's position accordingly, false otherwise
 */
bool collision(Paddle &paddle, Ball &ball) {
    if (!exist_Collision(paddle, ball)) {
        return false;
    }
    ball.move_up_ball();


    if (ball.getPosition().x < paddle.get_position().x) {
        ball.move_left_ball();
    } else if (ball.getPosition().x > paddle.get_position().x) {
        ball.move_right_ball();
    }
    return true;
}//declaration function that describe collision between ball and paddle

int score = 0;
int power = 0;



Explosiveblock exblock(500, 500, 100, 60);
Movingblock moveblock(500, 325, 100,60);

bool collision(Powerups &powerup, Paddle &paddle)
{
    if (!exist_Collision(powerup, paddle)) {
        return false;
    }
    power++;
    if(power ==1)
    {}

    paddle.power_size();
    powerup.not_activated();
    return true;

}
Powerups powerup( 5000000, 5000000);
bool collision(Block &block, Ball &ball) {

    if (!exist_Collision(block, ball)) {
        return false;
    }

    if (!block.destroyed) {
        if (exist_Collision(exblock, ball)) {
            exblock.destroy();
            score = score + 50;
        }

        block.destroy();
        score++;

        float overlap_Left{ball.right() - block.left()};
        float overlap_Right{block.right() - ball.left()};
        float overlap_Top{ball.bottom() - block.top()};
        float overlap_Bottom{block.bottom() - ball.top()};

        bool ball_from_left(abs(overlap_Left) < abs(overlap_Right));
        bool ball_from_top(abs(overlap_Top) < abs(overlap_Bottom));

        float min_overlap_x{ball_from_left ? overlap_Left : overlap_Right};
        float min_overlap_y{ball_from_top ? overlap_Top : overlap_Bottom};

        if (abs(min_overlap_x) < abs(min_overlap_y)) {
            ball_from_left ? ball.move_left_ball() : ball.move_right_ball();
        } else {
            ball_from_top ? ball.move_up_ball() : ball.move_down_ball();
        }


        return true;
    }

}   //declaration function that describe collision between ball and blocks
bool collision(Movingblock & moveblock, Ball &ball) {
    if (!exist_Collision(moveblock, ball)) {

        return false;
    }

            moveblock.powers();


        float overlap_Left{ball.right() - moveblock.left()};
        float overlap_Right{moveblock.right() - ball.left()};
        float overlap_Top{ball.bottom() - moveblock.top()};
        float overlap_Bottom{moveblock.bottom() - ball.top()};

        bool ball_from_left(abs(overlap_Left) < abs(overlap_Right));
        bool ball_from_top(abs(overlap_Top) < abs(overlap_Bottom));

        float min_overlap_x{ball_from_left ? overlap_Left : overlap_Right};
        float min_overlap_y{ball_from_top ? overlap_Top : overlap_Bottom};

        if (abs(min_overlap_x) < abs(min_overlap_y)) {
            ball_from_left ? ball.move_left_ball() : ball.move_right_ball();
        } else {
            ball_from_top ? ball.move_up_ball() : ball.move_down_ball();
        }

        return true;

}

int main() {


    int menu_options = 1;
/**
 * @brief Menu Options and Corresponding Functions
 *\n ____________________________________
 * \n|..menu_options.|..Function....|
 * \n|--------------|---------------|
 * \n|.......-1.....|.....close.....|
 * \n|........0.....|.....Game......|
 * \n|........1.....|...MainMenu....|
 * \n|........2.....|..Instructions.|
 * \n|........3.....|...............|
 */

    Ball ball(500, 500);
    Paddle paddle(950, 950);
    sf::RenderWindow window(sf::VideoMode(1650, 1050), "Arcanoid");
    Menu menu(1920, 1080);
    sf::Texture mainmenu_photo;
    sf::Texture instruction_photo;
    instruction_photo.loadFromFile("instrukcja.png");
    mainmenu_photo.loadFromFile("obraz.png");
    sf::Sprite photo;
    sf::Text endgame;
    photo.setTexture(mainmenu_photo);
    window.setFramerateLimit(60);
    sf::Event event;
    std::chrono::milliseconds waiting_time(200);
    unsigned blocks_x{15}, blocks_y{4}, block_width{100}, block_height{60};
    vector<Block> blocks;
    exblock.draw_number();
    powerup.remove();
    for (int i = 0; i < blocks_y; i++) {
        for (int j = 0; j < blocks_x; j++) {
            if (i == exblock.draw_number_y && j == exblock.draw_number_x) {

                exblock.set_position();
                blocks.emplace_back(exblock);
            } else {
                Block block((j + 1) * (block_width + 5), (i + 1) * (block_height + 5), block_width, block_height);
                blocks.emplace_back(block);
            }
        }
    } //block making loop

    while (true) //main loop
    {
        if (menu_options == 1) {
            while (window.isOpen()) {
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                        return 0;
                    }

                    if (event.type == sf::Event::KeyPressed) {
                        if (event.key.code == sf::Keyboard::Up) {
                            menu.move_up();
                        } else if (event.key.code == sf::Keyboard::Down) {
                            menu.move_down();
                        } else if (event.key.code == sf::Keyboard::Return) {
                            if (menu.pressed() == 0) {
                                menu_options = 0;
                            }
                            if (menu.pressed() == 1) {
                                menu_options = 2;
                            }
                            if (menu.pressed() == 2) {
                                menu_options = -1;
                            }
                        }
                    }

                } //loop with mein menu
                window.clear();
                if (menu_options != 1) {
                    break;
                }
                window.draw(photo);
                menu.draw(window);
                window.display();
            }

            if (menu_options == -1) //close game option
            {
                window.close();
                return 0;
            } else if (menu_options == 0) //play game option
            {
                while (menu_options == 0) {
                    while (window.isOpen()) {

                        window.clear(sf::Color::Black);
                        window.pollEvent(event);

                        if (event.type == sf::Event::Closed) {
                            window.close();
                            return 0;
                        }

                        ball.settings();
                        powerup.settings_p();
                        powerup.update();
                        ball.update();
                        paddle.update();
                        moveblock.update();
                        collision(paddle, ball);
                        collision(moveblock, ball);
                        collision(powerup, paddle);

                        for (auto &block: blocks) {

                            if (collision(block, ball)) {

                                break;
                            }
                        }

                        auto iterator = remove_if(begin(blocks), end(blocks),
                                                  [](Block &block) { return block.is_destroyed(); });
                        blocks.erase(iterator, end(blocks));

                        if (exblock.destroyed == true) {
                            for (auto &block: blocks) {
                                if ((((block.position().x == (((exblock.draw_number_x + 1) - 1) * 105) &&
                                       block.position().y == ((exblock.draw_number_y + 1) - 1) * 65)))
                                    || (((block.position().x == (((exblock.draw_number_x + 1) + 1) * 105) &&
                                          block.position().y == ((exblock.draw_number_y + 1)) * 65)))
                                    || (((block.position().x == (((exblock.draw_number_x + 1) - 1) * 105) &&
                                          block.position().y == (exblock.draw_number_y + 1) * 65)))
                                    || (((block.position().x == (((exblock.draw_number_x + 1) - 1) * 105) &&
                                          block.position().y == ((exblock.draw_number_y + 1) + 1) * 65)))
                                    || (((block.position().x == (((exblock.draw_number_x + 1)) * 105) &&
                                          block.position().y == ((exblock.draw_number_y + 1) + 1) * 65)))
                                    || (((block.position().x == ((exblock.draw_number_x + 1) * 105) &&
                                          block.position().y == ((exblock.draw_number_y + 1) - 1) * 65)))
                                    || (((block.position().x == (((exblock.draw_number_x + 1) + 1) * 105) &&
                                          block.position().y == ((exblock.draw_number_y + 1) + 1) * 65)))
                                    || (((block.position().x == (((exblock.draw_number_x + 1)) * 105) &&
                                          block.position().y == ((exblock.draw_number_y + 1)) * 65)))
                                    || (((block.position().x == (((exblock.draw_number_x + 1) + 1) * 105) &&
                                          block.position().y == ((exblock.draw_number_y + 1) - 1) * 65)))) {
                                    block.destroy();
                                }
                            }
                        }

                        if(moveblock.activated==true)
                        {
                            if(powerup.active == false)
                            {
                                powerup.set_position(moveblock.position().x,((moveblock.position().y)+30));
                                powerup.activated();
                                moveblock.delete_powers();
                                powerup.restore();

                            }
                        }
                        if(powerup.active == true)
                        {
                            window.draw(powerup.get_shape());
                            power = 0;
                        }
                        if(powerup.getPosition().y > paddle.top())
                        {
                            powerup.not_activated();
                        }

                        if (ball.getPosition().y > paddle.top()) {
                            powerup.not_activated();
                            paddle.stop_paddle();
                            ball.under_paddle();
                            moveblock.stop();
                            sf::Font font;
                            if (!font.loadFromFile("Bambuchinnox.ttf")) {
                                return -1;
                            }
                            sf::Text endgame("THE END", font, 100);
                            endgame.setFillColor(sf::Color::White);
                            endgame.setPosition(window.getSize().x / 2.f - endgame.getGlobalBounds().width / 2.f,
                                                window.getSize().y / 2.f - endgame.getGlobalBounds().height / 2.f -
                                                15.f);
                            window.draw(endgame);

                            sf::Text score_text("Total Score: " + to_string(score), font, 60);
                            score_text.setFillColor(sf::Color::White);
                            score_text.setPosition(window.getSize().x / 2.f - score_text.getGlobalBounds().width / 2.f,
                                                   window.getSize().y / 2.f + endgame.getGlobalBounds().height / 2.f +
                                                   score_text.getGlobalBounds().height / 2.f);
                            window.draw(score_text);
                            moveblock.stop();
                            paddle.stop_paddle();
                            menu.draw_end_menu(window);
                            if (event.type == sf::Event::KeyPressed) {
                                if (event.key.code == sf::Keyboard::Left) {
                                    menu.move_left();
                                    std::this_thread::sleep_for(waiting_time);
                                } else if (event.key.code == sf::Keyboard::Right) {
                                    menu.move_right();
                                    std::this_thread::sleep_for(waiting_time);
                                } else if (event.key.code == sf::Keyboard::Return) {
                                    if (menu.pressed() == 0) //new game options
                                    {
                                        menu.all_on_white();
                                        ball.reset_ball();
                                        moveblock.move();
                                        paddle.reset_paddle();
                                        for (auto &block: blocks) {
                                            if (!block.destroyed) {
                                                block.destroy();
                                            }
                                        }
                                        exblock.restore();
                                        exblock.restore();
                                        exblock.draw_number();
                                        for (int i = 0; i < blocks_y; i++) {
                                            for (int j = 0; j < blocks_x; j++) {
                                                if (i == exblock.draw_number_y && j == exblock.draw_number_x) {
                                                    exblock.set_position();
                                                    blocks.emplace_back(exblock);
                                                } else {
                                                    Block block((j + 1) * (block_width + 5),
                                                                (i + 1) * (block_height + 5), block_width,
                                                                block_height);
                                                    blocks.emplace_back(block);
                                                }
                                            }
                                        }
                                        score = 0;
                                        break;
                                    }
                                    if (menu.pressed() == 1)
                                    {
                                        score = 0;
                                        menu_options = 1;
                                        menu.all_on_white();
                                        ball.reset_ball();
                                        paddle.reset_paddle();
                                        moveblock.move();
                                        paddle.stop_paddle();
                                        exblock.restore();
                                        for (auto &block: blocks) {
                                            if (!block.destroyed) {
                                                block.destroy();
                                            }
                                        }
                                        exblock.draw_number();
                                        for (int i = 0; i < blocks_y; i++) {
                                            for (int j = 0; j < blocks_x; j++) {
                                                if (i == exblock.draw_number_y && j == exblock.draw_number_x) {
                                                    Explosiveblock exblock((j + 1) * (block_width + 5),
                                                                           (i + 1) * (block_height + 5), block_width,
                                                                           block_height);
                                                    blocks.emplace_back(exblock);
                                                } else {
                                                    Block block((j + 1) * (block_width + 5),
                                                                (i + 1) * (block_height + 5), block_width,
                                                                block_height);
                                                    blocks.emplace_back(block);
                                                }
                                            }
                                        }
                                        break;

                                    }
                                    if (menu.pressed() == 2) {
                                        return 0;
                                    }
                                }
                            }
                            paddle.reset_paddle();
                        }
                        paddle.restore_velocity();
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
                            ball.stop_game();
                            moveblock.movingblock_stop_game();
                        }
                        if (ball.is_stopped == true)
                        {
                            if (ball.getPosition().y <= paddle.top())
                            {

                                paddle.stop_paddle();
                                sf::Font font;
                                moveblock.stopped = true;
                                if (!font.loadFromFile("Bambuchinnox.ttf")) {
                                    return -1;
                                }
                                sf::Text pause("PAUSE", font, 100);
                                pause.setFillColor(sf::Color::White);
                                pause.setPosition(1650 / 2.f - pause.getGlobalBounds().width / 2.f,
                                                  1050 / 2.f - pause.getGlobalBounds().height / 2.f);
                                window.draw(pause);

                            }
                        }

                        sf::Font font;
                        if (!font.loadFromFile("Bambuchinnox.ttf")) {
                            return -1;
                        }
                        sf::Text score_text("Score: " + to_string(score), font, 20);
                        score_text.setFillColor(sf::Color::White);
                        score_text.setPosition(10.f, 10.f);
                        window.draw(score_text);
                        ball.update();
                        powerup.update();
                        paddle.update();
                        moveblock.update();
                        window.draw(ball.get_shape());
                        window.draw(paddle.get_shape());
                        window.draw(moveblock.get_shape());
                        powerup.update();

                        for (auto &block: blocks) {
                            window.draw(block.get_shape());
                        } //draw a blocks
                        window.display();
                        if (blocks.empty()) {
                            exblock.draw_number();
                            for (int i = 0; i < blocks_y; i++) {
                                for (int j = 0; j < blocks_x; j++) {
                                    if (i == exblock.draw_number_y && j == exblock.draw_number_x) {
                                        Explosiveblock exblock((j + 1) * (block_width + 5),
                                                               (i + 1) * (block_height + 5), block_width, block_height);
                                        blocks.emplace_back(exblock);
                                    } else {
                                        Block block((j + 1) * (block_width + 5), (i + 1) * (block_height + 5),
                                                    block_width, block_height);
                                        blocks.emplace_back(block);
                                    }
                                }
                            }
                        }
                    }
                }

            } else if (menu_options == 2) {
                while (window.isOpen()) {
                    window.clear(sf::Color::Black);
                    window.pollEvent(event);

                    if (event.type == sf::Event::Closed) {
                        return 0;
                    }
                    sf::Sprite instructionSprite(instruction_photo);
                    float posX = (window.getSize().x - instructionSprite.getGlobalBounds().width) / 2.f;
                    float posY = (window.getSize().y - instructionSprite.getGlobalBounds().height) / 2.f;
                    instructionSprite.setPosition(posX, posY);

                    window.draw(instructionSprite);

                    sf::RectangleShape backButton(sf::Vector2f(100.f, 40.f));
                    backButton.setFillColor(sf::Color::Red);
                    backButton.setPosition(
                            posX / 5 + instructionSprite.getGlobalBounds().width - 7 * backButton.getSize().x,
                            posY + instructionSprite.getGlobalBounds().height - backButton.getSize().y - 200.f);
                    window.draw(backButton);

                    sf::Font font;
                    if (!font.loadFromFile("Bambuchinnox.ttf"))
                    {
                        return -1;
                    }
                    sf::Text backText("Back", font, 20);
                    backText.setFillColor(sf::Color::White);
                    backText.setPosition(backButton.getPosition().x + backButton.getSize().x / 2.f -
                                         backText.getGlobalBounds().width / 2.f,
                                         backButton.getPosition().y + backButton.getSize().y / 3.f -
                                         backText.getGlobalBounds().height / 2.f);
                    window.draw(backText);

                    window.display();

                    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                        menu_options = 1;
                        break;
                    }

                    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2f mousePosition = window.mapPixelToCoords(
                                sf::Vector2i(event.mouseButton.x, event.mouseButton.y));

                        if (backButton.getGlobalBounds().contains(mousePosition)) {
                            menu_options = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
}

