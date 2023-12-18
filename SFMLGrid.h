//
// Created by Kristal Hong on 2/28/23.
//

#ifndef DYNAMIC2DARRAY_LAB_SFMLGRID_H
#define DYNAMIC2DARRAY_LAB_SFMLGRID_H
#include <SFML/Graphics.hpp>
#include "../drawable_project.h"

class SFMLGrid : public DrawableProject
{
private:
    sf::RectangleShape** arr;
    int rows, columns;

    //dynamically create an array of current row and col size
    sf::RectangleShape** createArray();

    //fills the array with sf::RectangleShapes, that was created with the createArray.
    //inside the fill array, use newRectangleShape to fill it.
    void fillArray();

    //returns a rectangle shape that is positioned at x and y
    sf::RectangleShape newRectangleShape(float x, float y);

    //deletes the arr
    void deleteArray();
public:
    ////Big Three Goes here
    SFMLGrid(const SFMLGrid& item);//Copy constructor


    SFMLGrid& operator = (const SFMLGrid& item);//Assignment operator
    //OR Vector& operator = (const Vector& item);

    ~SFMLGrid(); //Destructor



    SFMLGrid();
    SFMLGrid(int passed_rows);

    //loop through 2D array and draw each rectangle
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //increases the array size when right arrow is pressed, decreases when left is pressed
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update(sf::RenderWindow &window, sf::Event event);
};


#endif //DYNAMIC2DARRAY_LAB_SFMLGRID_H
