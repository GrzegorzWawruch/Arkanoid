//
// Created by wawru on 13.06.2023.
//

#ifndef PROJEKT_ICOLLIDABLE_H
#define PROJEKT_ICOLLIDABLE_H
#include "Ball.h"
#include "Paddle.h"
#include "Block.h"


class ICollidable {
    virtual void collide(ICollidable *Other);
    void handle_collisions();
};


#endif //PROJEKT_ICOLLIDABLE_H
