/**
 * Created by wawru on 13.06.2023.
 *
 * Declaration of methods implemented in "Movingblock.cpp".
 *
 * This class represents a moving block in a game, which is a type of block.
 * Each moving block inherits properties and behaviors from the Block class.
 * Moving blocks have the ability to move horizontally.
 * Contains methods for updating the block's position, stopping the block, handling powers, and more.
 */

#ifndef PROJEKT_MOVINGBLOCK_H
#define PROJEKT_MOVINGBLOCK_H

#include "Block.h"


class Movingblock : public Block{

public:

        /**
         * Constructor for the Movingblock class.
         *
         * @param pos_X The initial X position of the moving block.
         * @param pos_Y The initial Y position of the moving block.
         * @param width The width of the moving block.
         * @param height The height of the moving block.
         */
    Movingblock(float pos_X, float pos_Y, float width, float height);


    /**
     * Updates the position of the moving block.
     */
    void update();


    /**
     * Stops the moving block from moving.
     */
    void stop();


    /**
     * Moves the moving block horizontally.
     */
    void move();


    /**
     * Stops the game when the moving block is stopped.
     */
    void movingblock_stop_game();


    /**
     * Restores the velocity of the moving block.
     */
    void restore_velocity();


    /**
     * Returns the position of the moving block.
     *
     * @return The position of the moving block.
     */
    sf::Vector2f get_position();


    /**
     * Deletes powers associated with the moving block.
     */
    void delete_powers();


    /**
     * Handles the powers of the moving block.
     */
    void powers();


        /**
         * Variable indicating if the moving block is stopped.
         */
    bool stopped = false;


        /**
         * Variable indicating if the moving block is activated.
         */
    float activated = false;


        /**
         * Helper variable for the moving block's velocity.
         */
    float movingblock_velocity_helper_x;


private:

        /**
         * Velocity of the moving block.
         */
    float movingblock_velocity{3.0f};


        /**
         * Velocity vector of the moving block.
         */
    sf::Vector2f velocity{movingblock_velocity, 0};

};


#endif //PROJEKT_MOVINGBLOCK_H
