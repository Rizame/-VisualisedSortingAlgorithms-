#include<iostream>
#include<SFML/Graphics.hpp>
#include<vector>
#include<random>
#include"functions.h"
#include"Algorithms.h"


int main()
{
    tablica;
    init();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //clear
        window.clear();

        //update
        buttons();
        updateID();
        window.draw(tablica.table);
        window.draw(tablica.text);

        //display
        window.display();
    }
	return 0;
}