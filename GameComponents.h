#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>


class Elements
{
	/*The order of the elements, in each of the arrays below is: Rose, Violet, Sunflower
	which are corresponding to their respective type of flower */
public:
	sf::Texture flower_tex[3];
	sf::Texture bee1_right;
	sf::Texture bee2_right;
	sf::Texture bee1_left;
	sf::Texture bee2_left;
	sf::Texture painting;

	const int WIDTH = 1000;
	const int HEIGHT = 600;


	sf::RectangleShape background;
	sf::RectangleShape flowers[3];
	sf::RectangleShape player1;
	

public:

	Elements()
	{
		if (!flower_tex[0].loadFromFile("Images/Scenario/flowers/rose_full.png"))
		{
			std::cout << "Could not find 'rose_full.png' image...\n";
		}

		if (!flower_tex[1].loadFromFile("Images/Scenario/flowers/violet_full.png"))
		{
			std::cout << "Could not find 'violet_full.png' image...\n";
		}

		if (!flower_tex[2].loadFromFile("Images/Scenario/flowers/sunflower_full.png"))
		{
			std::cout << "Could not find 'sunflower_full.png' image...\n";
		}

		if (bee1_right.loadFromFile("Images/bee_worker_flying_1_right.png") == false)
		{
			std::cout << "Could not find 'bee_worker_flying_1_right.png' image...\n";
		}
		if (bee2_right.loadFromFile("Images/bee_worker_flying_2_right.png") == false)
		{
			std::cout << "Could not find 'bee_worker_flying_2_right.png' image...\n";
		}

		if (bee1_left.loadFromFile("Images/bee_worker_flying_1_left.png") == false)
		{
			std::cout << "Could not find 'bee_worker_flying_1_left.png' image...\n";
		}
		if (bee2_left.loadFromFile("Images/bee_worker_flying_2_left.png") == false)
		{
			std::cout << "Could not find 'bee_worker_flying_2_left.png' image...\n";
		}

		if (painting.loadFromFile("Images/Scenario/Background/landscape under stormy sky .png") == false)
		{
			std::cout << "Could not find 'landscape under stormy sky .png' image...\n";
		}
	}

	//This loads the image on the window, placing each of the RectangleShape objects in a certain place
	void load_flowers()
	{
		for (int i = 0; i < 3; i++)
		{
			flowers[i].setSize(sf::Vector2f(100, 100));
			flowers[i].setPosition((i +1)* 200, 500);
			flowers[i].setTexture(&flower_tex[i]);
		}
	}

	sf::RectangleShape getFlower(int index)
	{
		return flowers[index];
	}

	void load_background()
	{
		background.setSize(sf::Vector2f(WIDTH, HEIGHT));
		background.setPosition(0, 0);
		background.setTexture(&painting);
	}

	sf::RectangleShape getBackground()
	{
		return background;
	}

	void load_player1()
	{
		player1.setSize(sf::Vector2f(30, 30));
		player1.setPosition(800, 200);
		player1.setTexture(&bee1_right);
	}
	sf::RectangleShape getPlayer1()
	{
		return player1;
	}
};