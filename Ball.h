#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <chrono>
#include <thread>


using namespace sf;

class Ball {

public:

    /**
        * Constructor for the Ball class.
        *
        * @param pos_X The initial X position of the ball.
        * @param pos_Y The initial Y position of the ball.
        */
    Ball(float pos_X, float pos_Y);


    /**
     * Returns the shape of the ball.
     *
     * @return Reference to the ball's circle shape.
     */
    const sf::CircleShape &get_shape() const;


    /**
     * Updates the position of the ball based on its velocity.
     * Handles bouncing off the screen edges.
     */
    void update();


    /**
     * Moves the ball downwards.
     */
    void move_down_ball();


    /**
     * Moves the ball to the right.
     */
    void move_right_ball();


    /**
     * Moves the ball to the left.
     */
    void move_left_ball();


    /**
     * Moves the ball upwards.
     */
    void move_up_ball();


    /**
     * Sets the ball under the paddle, stopping its movement.
     */
    void under_paddle();


    /**
     * Stops the game by freezing the ball in its current position.
     */
    void stop_game();


    /**
     * Resets the ball to its initial state.
     */
    void reset_ball();


    /**
     * Returns the current position of the ball.
     *
     * @return Vector representing the position of the ball.
     */
    sf::Vector2f getPosition();


    /**
     * Returns the position of the left edge of the ball.
     *
     * @return Position of the left edge of the ball.
     */
    float left();


    /**
     * Returns the position of the right edge of the ball.
     *
     * @return Position of the right edge of the ball.
     */
    float right();


    /**
     * Returns the position of the top edge of the ball.
     *
     * @return Position of the top edge of the ball.
     */
    float top();


    /**
     * Returns the position of the bottom edge of the ball.
     *
     * @return Position of the bottom edge of the ball.
     */
    float bottom();


    /**
     * Sets up the settings of the ball, such as radius and color.
     */
    void settings();

    /**
     * Helper variable for storing the ball's X velocity when stopped.
     */
    float ball_velocity_helper_x;


        /**
         * Helper variable for storing the ball's Y velocity when stopped.
         */
    float ball_velocity_helper_y;


    /**
     * Variable indicating whether the ball is currently stopped.
     */
    bool is_stopped = false;


    /**
     * Variable indicating whether the ball is currently under the paddle.
     */
    bool ball_under_paddle = false;


        /**
         * Text displayed during pause.
         */
        sf::Text pause;


private:
    CircleShape shape;  //object represent a ball shape
    const float ball_radius{25.0f};  //variable that stores a ball radius
    float ball_velocity{5.0f};       //variable that stores a ball rvelocity
    Vector2f velocity{ball_velocity, ball_velocity};  //vector that stores information about ball velocity
    void draw(RenderTarget &target, RenderStates state) const;  //function that draw a ball

};

#endif
