//
// Created by wawru on 13.06.2023.
//

#include "ICollidable.h"

void ICollidable::collide(ICollidable* other){
    if (Ball* ball = dynamic_cast<Ball*>(other)) {
        ball->move_up_ball();
        Paddle* paddle;
        if (ball->getPosition().x < paddle->get_position().x) {
            ball->move_left_ball();
        } else if (ball->getPosition().x > paddle->get_position().x) {
            ball->move_right_ball();
        }

    } else if (Block* block = dynamic_cast<Block*>(other)) {
        // Kolizja z blokiem
        // Zaimplementuj odpowiednie działania dla kolizji z blokiem
    } else {
        // Inna kolizja
        // Zaimplementuj odpowiednie działania dla innych rodzajów kolizji
    }
}
/*void handle_collisions() {
    // Wykrywanie kolizji i wywołanie collide() dla odpowiednich obiektów
    for (int i = 0; i < objects.size(); i++) {
        for (int j = i + 1; j < objects.size(); j++) {
            if (exist_Collision(objects[i], objects[j])) {
                objects[i].collide(&objects[j]);
                objects[j].collide(&objects[i]);
            }
        }
    }
}*/