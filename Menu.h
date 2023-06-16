/**
* Created by adm on 20.05.2023.
*
* Declaration of methods implemented in "Menu.cpp".
*
* This class represents a menu in a game.
* The menu contains options for the main menu and the end menu.
* The main menu allows the player to navigate and select options.
* The end menu displays the final results of the game.
* Contains methods for drawing the menu, handling navigation, and returning selected options.
*/

#ifndef PROJEKT_MENU_H
#define PROJEKT_MENU_H

#include <SFML/Graphics.hpp>


class Menu {

public:

    /**
     * Constructor for the Menu class.
     *
     * @param width The width of the menu window.
     * @param height The height of the menu window.
     */
    Menu(float width, float height);


    /**
     * Array containing the main menu options
     */
    sf::Text main_menu[3];


    /**
     * Array containing the end menu options
     */
    sf::Text end_menu[3];



    /**
     * Draws the main menu on the specified render window.
     *
     * @param window The render window to draw the main menu on.
     */
    void draw(sf::RenderWindow &window);


    /**
     * Draws the end menu on the specified render window.
     *
     * @param window The render window to draw the end menu on.
     */
    void draw_end_menu(sf::RenderWindow &window);


    /**
     * Moves the menu selection up.
     * Changes the currently selected option when the up arrow key is pressed.
     */
    void move_up();


    /**
     * Moves the menu selection down.
     * Changes the currently selected option when the down arrow key is pressed.
     */
    void move_down();

    /**
     * Moves the menu selection to the left.
     * Changes the currently selected option when the left arrow key is pressed.
     */
    void move_left();


    /**
     * Moves the menu selection to the right.
     * Changes the currently selected option when the right arrow key is pressed.
     */
    void move_right();


    /**
     * Changes the text color of all options to white.
     */
    void all_on_white();


    /**
     * Returns the selected option in the menu.
     *
     * @return The index of the selected option.
     */
    int pressed()
    {
        return selected;
    }


    /**
     * Destructor for the Menu class.
     */
    ~Menu();

private:

    /**
     * Variable specifying the player's current selection
     */
    int selected;


    /**
     * Variable specifying the font
     */
    sf::Font font;

};

#endif