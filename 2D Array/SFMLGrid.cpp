//
// Created by Kristal Hong on 2/28/23.
//

#include "SFMLGrid.h"
#include "iostream"
SFMLGrid::SFMLGrid()
{
    rows = 1;
    columns = rows;
    arr = createArray();
    fillArray();
}

SFMLGrid::SFMLGrid(int passed_rows)
{
    rows = passed_rows;
    columns = rows;
    arr = createArray();
    fillArray();
}


SFMLGrid::SFMLGrid(const SFMLGrid& item) : SFMLGrid(item.rows) //Copy constructor
{
    *this = item;
}


SFMLGrid::~SFMLGrid() //Destructor
{
    deleteArray();
}


SFMLGrid &SFMLGrid::operator = (const SFMLGrid& item)
{
    if(this == &item)
    {
        return *this;
    }

    columns = item.columns;
    rows = item.rows;
    createArray();
    fillArray();


    return *this;

}




sf::RectangleShape** SFMLGrid::createArray()
{
    sf::RectangleShape **temp = new sf::RectangleShape *[rows];
    for (int i = 0; i < rows; i++)
    {
        *(temp + i) = new sf::RectangleShape[columns];
    }
    return temp;
}



void SFMLGrid::fillArray()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            arr[i][j] = newRectangleShape(j,i);
        }
    }
}



void SFMLGrid::deleteArray()
{
    for (int i = 0; i < rows; ++i)
    {
        delete [] *(arr + i);
    }
    delete [] arr;
}



sf::RectangleShape SFMLGrid::newRectangleShape(float x, float y)
{
    float color1, color2, color3;
    color1= rand() % 255;
    color2= rand() % 255;
    color3= rand() % 255;

    sf::RectangleShape name({50,50});
    name.setPosition((55)*x + 250, (55)*y + 150);
    name.setFillColor(sf::Color(color1, color2, color3));
    return name;
}


void SFMLGrid::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            window.draw(arr[i][j]);
        }
    }
}

void SFMLGrid::update(sf::RenderWindow &window, sf::Event event) {

}

void SFMLGrid::eventHandler(sf::RenderWindow& window, sf::Event event)
{

    if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left))
    {

        if ((rows > 0) && (rows < 30) && (columns > 0) && (columns < 30)) {
            std::cout << "row: " << rows << " cols: " << columns << std::endl;
            this->~SFMLGrid();
//            deleteArray();
            if (rows != 1) {
                rows--;
            }
            if (columns != 1) {
                columns--;
            }
            arr = createArray();
            fillArray();
        }
    }

    if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right))
    {
        if ((rows > 0) && (rows < 30) && (columns > 0) && (columns < 30)) {
            std::cout << "row: " << rows << " cols: " << columns << std::endl;
            this->~SFMLGrid();
//            deleteArray();
            if (rows != 29) {
                rows++;
            }
            if (columns != 29) {
                columns++;
            }
            arr = createArray();
            fillArray();
        }
    }
}
