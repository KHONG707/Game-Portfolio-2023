//
// Created by Kristal Hong on 2/14/23.
//

#ifndef SFML_CARDPROJECT_RANK_H
#define SFML_CARDPROJECT_RANK_H
#include <SFML/Graphics.hpp>
#include "Ranks.h"

class Rank : public sf::Drawable
{
public:
    Rank();
    Rank(CARDPROJECT::Ranks rank);
    void setText(const std::string& text);
    void setTopPosition(float x, float y);
    void setBottomPosition(float x, float y);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
private:
    sf::Text top, bottom;
     std::vector<sf::Texture> ranks;
     std::string getPath(CARDPROJECT::Ranks rank);
};


#endif //SFML_CARDPROJECT_RANK_H
