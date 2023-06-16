/**
 * Created by wawru on 13.06.2023.
 *
 * Declaration of methods implemented in "Explosiveblock.cpp".
 *
 * This class represents an explosive block in a game, which is a type of block.
 * Each explosive block inherits properties and behaviors from the Block class.
 * Explosive blocks have additional features such as drawing numbers and setting positions.
 * Contains methods for drawing numbers on the explosive block and setting its position.
 */

#ifndef PROJEKT_EXPLOSIVEBLOCK_H
#define PROJEKT_EXPLOSIVEBLOCK_H

#include "Block.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

class Explosiveblock : public Block {
public:

    /**
     * Constructor for the Explosiveblock class.
     *
     * @param pos_X The initial X position of the explosive block.
     * @param pos_Y The initial Y position of the explosive block.
     * @param width The width of the explosive block.
     * @param height The height of the explosive block.
     */
    Explosiveblock(float pos_X, float pos_Y, float width, float height);


    /**
     * Draws a random number on the explosive block.
     */
    void draw_number();


            /**
                              * Sets the position of the explosive block.
                              */
    void set_position();


         /**
          *Variable that stores the drawn number for the X position.
          */
    float draw_number_x;


        /**
         *Variable that stores the drawn number for the Y position.
         */
    float draw_number_y;

};


#endif //PROJEKT_EXPLOSIVEBLOCK_H
