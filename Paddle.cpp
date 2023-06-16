/**
 * Created by adm on 19.05.2023.
 *
 * @file Paddle.cpp
 *
 * Implementation of methods declared in "Paddle.h".
 */

#include "Paddle.h"


Paddle::Paddle(float pos_X, float pos_Y) {
    shape.setPosition(pos_X, pos_Y);
    shape.setSize(sf::Vector2f(this->paddle_width, this->paddle_height));
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(this->paddle_width / 2.f, this->paddle_height / 2.f);
}

const sf::RectangleShape &Paddle::get_shape() const {
    return shape;
}

void Paddle::draw(sf::RenderTarget &target, sf::RenderStates state) const {
    target.draw(this->shape, state);
}

void Paddle::update() {
    this->shape.move(this->velocity);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && this->left() > 0) {
        velocity.x = -paddle_velocity;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) &&
               this->right() < 1650)
    {
        velocity.x = paddle_velocity;
    } else {
        velocity.x = 0;
    }
}

void Paddle::stop_paddle() {
    paddle_velocity = 0;
}

float Paddle::left() {
    return shape.getPosition().x - shape.getSize().x / 2.f;
}

float Paddle::right() {
    return shape.getPosition().x + shape.getSize().x / 2.f;
}

float Paddle::top() {
    return shape.getPosition().y - shape.getSize().y / 2.f;
}

float Paddle::bottom() {
    return shape.getPosition().y + shape.getSize().y / 2.f;
}

sf::Vector2f Paddle::get_position() {
    return shape.getPosition();
}

void Paddle::reset_paddle() {
    paddle_velocity = 7.0f;
    shape.setPosition(825, 950);
    paddle_width = paddle_helper_width;
    shape.setSize(sf::Vector2f(this->paddle_width, this->paddle_height));
    shape.setOrigin(this->paddle_width / 2.f, this->paddle_height / 2.f);
}

void Paddle::restore_velocity() {
    paddle_velocity = 7.0f;
}
void Paddle::power_size() {

        paddle_width = paddle_width + 20.0f;
        shape.setSize(sf::Vector2f(this->paddle_width, this->paddle_height));
        shape.setOrigin(this->paddle_width / 2.f, this->paddle_height / 2.f);

}