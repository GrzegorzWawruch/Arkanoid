/**
 * Created by wawru on 15.06.2023.
 *
 * @file Powerups.cpp
 *
 * Implementation of methods declared in "Powerups.h".
 */


#include "Powerups.h"

Powerups::Powerups(float pos_X, float pos_Y){
    shape.setPosition(pos_X, pos_Y);
    shape.setRadius(this->powerups_radius);
    shape.setFillColor(sf::Color::Yellow);
    //ustawienie położenie punktu odniesienia, czyli wskazanie na środek piłki
    shape.setOrigin(this->powerups_radius, this->powerups_radius);
}


void Powerups::draw(sf::RenderTarget &target, sf::RenderStates state)  {
    target.draw(this->shape, state);
}
void Powerups::settings_p() {
    velocity.x = 0;
    velocity.y = powerups_velocity;
}
void Powerups ::set_color(sf::Color new_color) {
    color=new_color;
}
const sf::CircleShape &Powerups::get_shape() const {
    return shape;
}
void Powerups::update() {
    shape.move(this->velocity);
}
float Powerups::left() {
    return shape.getPosition().x - shape.getRadius();
}

float Powerups::right() {
    return shape.getPosition().x + shape.getRadius();
}

float Powerups::top() {
    return shape.getPosition().y - shape.getRadius();
}

float Powerups::bottom() {
    return shape.getPosition().y + shape.getRadius();
}
void Powerups::remove() {
    shape.setFillColor(sf::Color::Black);
    velocity.x = 0;
    velocity.y = 0;
}

void Powerups::restore() {
    shape.setFillColor(sf::Color::Yellow);
    velocity.y = powerups_velocity;
}

void Powerups::set_position(float position_x, float position_y) {
    shape.setPosition(position_x,position_y);
}
void Powerups::activated() {
    this-> active = true;
}
void Powerups::not_activated() {
    this->active = false;

}
sf::Vector2f Powerups::getPosition() {
    return shape.getPosition();
}