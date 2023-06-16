/**
*
* Created by adm on 19.05.2023.
*
* Declaration of methods implemented in "Block.cpp".
*
* This class represents a block in a game.
* Each block has a position, size, and a shape.
* The main task of a block object is to interact with the game, such as collision detection and scoring.
* Blocks can be destroyed or restored based on game events.
* Contains methods for retrieving block information, checking block status, and modifying block state.
*/


#ifndef PROJEKT_BLOCK_H
#define PROJEKT_BLOCK_H

#include <SFML/Graphics.hpp>

class Block{
public:

    /**
     * Constructor for Paddle.
     *
     * @param pos_X The initial X position of the block.
     * @param pos_Y The initial Y position of the block.
     * @param width The width of the block.
     * @param height The height of the block.
     */
    Block(float pos_X, float pos_Y, float width, float height);


    /**
     * Returns the shape of the block.
     *
     * @return Reference to the block's rectangle shape.
     */
    const sf::RectangleShape &get_shape() const;


    /**
     * Returns the position of the block.
     *
     * @return Vector representing the coordinates of the block.
     */
    sf::Vector2f position();


    /**
     * Returns the size of the block.
     *
     * @return Vector representing the size of the block.
     */
    sf::Vector2f size();


    /**
     * Returns the position of the left edge of the block.
     *
     * @return Position of the left edge of the block.
     */
    float left();


    /**
     * Returns the position of the right edge of the block.
     *
     * @return Position of the right edge of the block.
     */
    float right();


    /**
     * Returns the position of the top edge of the block.
     *
     * @return Position of the top edge of the block.
     */
    float top();


    /**
     * Returns the position of the bottom edge of the block.
     *
     * @return Position of the bottom edge of the block.
     */
    float bottom();


    /**
     * Checks if the block is destroyed.
     *
     * @return True if the block is destroyed, false otherwise.
     */
    bool is_destroyed();


        /**
              * Destroys the block.
              * Changes the destroyed value of the block to true.
              */
    void destroy();


    /**
     * Restores the block.
     * Changes the destroyed value of the block to false.
     */
    void restore();


        /**
         * Variable that stores the value of whether the block is destroyed.
         */
    bool destroyed{false};


        /**
         * Variable that stores the points value of the block.
         */
    int points;


    /**
     * Object representing the shape of the block.
     */
    sf::RectangleShape shape;

private:

    /**
     * Draws the block on the render target.
     *
     * @param target The render target to draw the block on.
     * @param state  The render states to use for drawing.
     */
    void draw(sf::RenderTarget &target, sf::RenderStates state) const; //function that draw a block
};


#endif //PROJEKT_BLOCK_H
