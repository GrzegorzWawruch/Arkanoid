//
// Created by adm on 19.05.2023.
//

#ifndef PROJEKT_PADDLE_H
#define PROJEKT_PADDLE_H

#include <SFML/Graphics.hpp>


using namespace sf;

class Paddle{

public:

                                                            /**
                                                             * Constructor for Paddle.
                                                             *
                                                             * @param pos_X is the initial X position of the paddle.
                                                             * @param pos_Y is the initial Y position of the paddle.
                                                             */
    Paddle(float pos_X, float pos_Y);


        /**
         * Updates the position of the paddle and handles bouncing off the edges.
         */
    void update();


        /**
         * Return a constant reference to the paddle shape.
         */
            const  sf::RectangleShape &get_shape() const;


            /**
                                                 * Returns the position of the top edge of the paddle.
                                                  *
                                                         * @return the Y coordinate of the top edge of the paddle.
                                 */
    float left();


    /**
     * Returns the position of the right edge of the paddle.
     *
     * @return the X coordinate of the right edge of the paddle.
     */
    float right();


    /**
     * Returns the position of the top edge of the paddle.
     *
     * @return the Y coordinate of the top edge of the paddle.
     */
    float top();


    /**
     * Returns the position of the bottom edge of the paddle.
     *
     * @return the Y coordinate of the bottom edge of the paddle.
     */
    float bottom();


    /**
     * Restores the paddle's velocity after pausing the game.
     */
    void restore_velocity();


    /**
     * Stops the paddle when the "P" key is pressed on the keyboard.
     */
    void stop_paddle();


    /**
     * Resets the paddle to its initial position and velocity.
     */
    void reset_paddle();


    /**
     * Returns the position of the paddle.
     *
     * @return a vector that stores the coordinates of the paddle.
     */
    sf::Vector2f get_position();


    /**
     * Increases the size of the paddle.
     */
    void power_size();


        /**
         * Variable that stores the width of the paddle.
         */
    float paddle_width{130.0f};


    /**
     * An auxiliary variable that will allow restoring the initial value of the paddle when starting a new game.
     */
    const float paddle_helper_width {130.0f};


private:

        /**
         * Object representing the shape of the paddle.
         */
            sf::RectangleShape shape;


            /**
             * Stores the height of the paddle.
             */
    const float paddle_height{20.0f};


        /**
         * Stores the velocity of the paddle.
         */
    float paddle_velocity{6.0f};


                /**
                 * Vector storing the paddle's velocity.
                 */
    sf::Vector2f velocity{paddle_velocity, 0};


    /**
     * Function that draws the paddle.
     *
     * @param target is the render target to draw the paddle on.
     * @param state is the render states to use for drawing.
     */
    void draw( sf::RenderTarget &target,  sf::RenderStates state) const;
};


#endif //PROJEKT_PADDLE_H
