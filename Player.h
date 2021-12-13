#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;

class Player
{
	private:
		Sprite *playerSprite;
		Texture playerTexture;
		Image playerImage;
	public:
		Player(std::string imageName);
		void movePlayer(int xCoordinate, int yCoordinate);
		void checkObject(std::string object, int &currentIndex);
		void drawPlayer(RenderWindow& window,int height, int  width);
		Sprite* getSprite();
		



	
};

