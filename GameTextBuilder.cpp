#include "GameTextBuilder.h"



GameText GameTextBuilder::textPlayer(std::string text)
{
    return GameText("Harry Potter.ttf",text,50, sf::Color::Blue,sf::Text::Italic);

}

GameText GameTextBuilder::textPlayerStats(std::string text)
{
    return GameText("clash.ttf", text, 20, sf::Color::Black, sf::Text::Italic);
}

GameText GameTextBuilder::textFacts(std::string text)
{
    return GameText("Harry Potter.ttf", text, 20, sf::Color::Black, sf::Text::Regular);
}

GameText GameTextBuilder::textTitleFacts(std::string text)
{
    return GameText("clash.ttf", text, 35, sf::Color::Black, sf::Text::Bold);
}

