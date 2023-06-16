/**
 * Created by wawru on 15.06.2023.
 *
 * Declaration of methods implemented in "Powerups.cpp".
 *
 * This class represents power-ups in a game. Each power-up has a position, shape, and various properties.
 * Power-ups can be activated, deactivated, and their effects can be applied during gameplay.
 * Contains methods for setting up the power-up, updating its position, handling activation, and removing it from the game.
 */


#ifndef PROJEKT_POWERUPS_H
#define PROJEKT_POWERUPS_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"


class Powerups {

public:

    /**
     * Constructor for the Powerups class.
     *
     * @param pos_X The initial X position of the power-up.
     * @param pos_Y The initial Y position of the power-up.
     */
    Powerups(float pos_X, float pos_Y);


    /**
     * Returns the shape of the power-up.
     *
     * @return Reference to the power-up's circle shape.
     */
    const sf::CircleShape &get_shape() const;


    /**
     * Updates the position of the power-up.
     */
    void update();


    /**
     * Sets up the settings of the power-up, such as color and velocity.
     */
    void settings_p();


    /**
     * Sets the color of the power-up.
     *
     * @param new_color The new color for the power-up.
     */
    void set_color(sf::Color new_color);


            /**
                  * Removes the power-up from the game.
                  */
    void remove();


            /**
             * Sets the position of the power-up.
             *
             * @param position_x The X position to set.
             * @param position_y The Y position to set.
             */
    void set_position(float position_x, float position_y);


    /**
     * Returns the position of the left edge of the power-up.
     *
     * @return Position of the left edge of the power-up.
     */
    float left();


    /**
     * Returns the position of the right edge of the power-up.
     *
     * @return Position of the right edge of the power-up.
     */
    float right();


    /**
     * Returns the position of the top edge of the power-up.
     *
     * @return Position of the top edge of the power-up.
     */
    float top();


    /**
     * Returns the position of the bottom edge of the power-up.
     *
     * @return Position of the bottom edge of the power-up.
     */
    float bottom();


    /**
     * Activates the power-up.
     */
    void activated();


    /**
     * Deactivates the power-up.
     */
    void not_activated();


    /**
     * Restores the power-up to its initial state.
     */
    void restore();


    /**
     * Draws the power-up on the target.
     *
     * @param target The target to draw on.
     * @param state The render state to use for drawing.
     */
    void draw(sf::RenderTarget &target, sf::RenderStates state) ;


    /**
     * The velocity vector of the power-up.
     */
    sf::Vector2f getPosition();

/**/
    bool active {false};


    /**
     * Object representing the shape of the power-up.
     */
    sf::CircleShape shape;


    /**
     * The radius of the power-up.
     */
    const float powerups_radius{15.0f};


    /**
       * The velocity of the power-up.
       * Determines how fast the power-up moves.
       */
    float powerups_velocity{0.7f};

    /**
     * The current velocity vector of the power-up.
     * The X component represents the horizontal velocity, and the Y component represents the vertical velocity.
     */
    sf::Vector2f velocity{0, 0};


        /**
         * The color of the power-up.
         */
    sf::Color color;

        /**
         * Stop the power-up.
        */
    void stop();

        /**
         * Restore the power-up velocity.
        */
    void restore_velocity();

};


#endif //PROJEKT_POWERUPS_H
