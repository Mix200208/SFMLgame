#include "GameTextBuilder.h"



GameText GameTextBuilder::textPlayer(std::string text)
{
    return GameText("clash.ttf",text,40, sf::Color::Blue,sf::Text::Bold);

}

GameText GameTextBuilder::textPlayerStats(std::string text)
{
    return GameText("clash.ttf", text, 20, sf::Color::Black, sf::Text::Bold);
}

GameText GameTextBuilder::textFacts(std::string text)
{
    return GameText("Montserrat-LightItalic.ttf", text, 20, sf::Color::Black, sf::Text::Regular);
}

GameText GameTextBuilder::textTitleFacts(std::string text)
{
    return GameText("clash.ttf", text, 35, sf::Color::Magenta, sf::Text::Bold);
}

