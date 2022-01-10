#include <iostream>
#include <stdbool.h>
#include <SFML/Graphics.hpp>

#define WIDTH 1600
#define HEIGHT 400

void randomize_array(int values[400]);

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Sort Algorithm Visualizer");

	// An array of 400 integers from 0 - 400
	int values[400];
	for (int i = 0; i < 400; i++) values[i] = (float)i + 1.f;

	// For selection sort
	int min = 0;
	bool started = false;

	randomize_array(values);

	// Window Loop
	while (window.isOpen())
	{
		// Poll through all the events that happened since the last iteration of the window.isOpen loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
					case sf::Keyboard::Return:
						started = true;
						break;
				}
			}

		}

			// One iteration of selection sort if it has begun
		if (started && min <= 400)
		{
			int smallest_number = values[min];
			int index = min;
			for (int i = min; i < 400; i++)
			{
				if (values[i] < smallest_number)
				{
					index = i;
					smallest_number = values[i];
				}
			}
			values[index] = values[min];
			values[min] = smallest_number;
			min++;
		}

		// Rendering happens between this and the window.display()
		window.clear(sf::Color::Black);

		// Drawing all of the rectangles that are in the values array
		for (int i = 0; i < 400; i++)
		{
			sf::RectangleShape rectangle;
			rectangle.setSize(sf::Vector2f(4.f, values[i]));
			rectangle.setFillColor(sf::Color::White);
			rectangle.setPosition(sf::Vector2f(i * 4.f, HEIGHT - values[i]));
			window.draw(rectangle);
		}

		window.display();
	}

	return 0;
}

void randomize_array(int values[400])
{
	for (int i = 0; i < 400; i++)
	{
		int temp = values[i];
		int randomNum = rand() % 400; // The rand generates a random int between 0 - 399 for indexing a random position
		values[i] = values[randomNum];
		values[randomNum] = temp;
	}
}