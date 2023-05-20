//
// Created by adm on 20.05.2023.
//

#ifndef PROJEKT_MENU_H
#define PROJEKT_MENU_H

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Menu
{
public:
    Text mainmenu[3];
    Menu(float width, float  height);
    void draw(RenderWindow& window);
    void MoveUp();
    void MoveDown();
    void setSelected(int n);
    int pressed()
    {
        return selected;
    }
    ~Menu();

private:
    int selected;
    Font font;

};
#endif