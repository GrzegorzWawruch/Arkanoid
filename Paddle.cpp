//
// Created by adm on 19.05.2023.
//

#include "Paddle.h"

Paddle::Paddle(float pos_X, float pos_Y) {
    shape.setPosition(pos_X, pos_Y);
    shape.setSize(Vector2f(this->paddle_width,this->paddle_high));
    shape.setFillColor( Color::Green);

    //ustawienie położenie punktu odniesienia
    shape.setOrigin(this->paddle_width/2.f, this->paddle_high);
}

const RectangleShape& Paddle::getShape() const {
    return shape;
}

void Paddle::draw(RenderTarget &target, RenderStates state) const {
    target.draw(this->shape, state);
}

void Paddle::update() {
    this->shape.move(this->velocity);
    if(Keyboard::isKeyPressed(sf::Keyboard::Key::Left)&& this->left() >0){
        velocity.x= -paddle_velocity;
    }
    else if(Keyboard::isKeyPressed(sf::Keyboard::Key::Right)&& this->right() <1000) {
     velocity.x= paddle_velocity;
    }
    else{
        velocity.x=0;
    }
}

float Paddle::left() {
    return shape.getPosition().x - shape.getSize().x/2.f;
}
float Paddle::right() {
    return shape.getPosition().x + shape.getSize().x/2.f;
}
float Paddle::top() {
    return shape.getPosition().y + shape.getSize().y/2.f;
}
float Paddle::bottom() {
    return shape.getPosition().y - shape.getSize().y/2.f;
}