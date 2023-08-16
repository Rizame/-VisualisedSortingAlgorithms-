#pragma once
#include<SFML/Graphics.hpp>
#include<random>
std::random_device dev;
std::mt19937 rng(dev());
std::vector<sf::RectangleShape> numbers;

const int WIDTH = 800;
const int HEIGHT = 500;
int i = 0;
int j = 0;
int k = 0;
int index = 0;
int sortID = 0;
bool isColored = 0;

sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Algorithm Sort");
sf::RectangleShape line;
sf::Vector2i inputQuick;

class tables
{
public:
    sf::RectangleShape table;
    std::string Bubble = "bubble sort";
    std::string Select = "selection sort";
    std::string Insert = "insertion sort";
    std::string Quick = "quick sort";
    sf::Text text;
    tables()
    {
        font.loadFromFile("Carrinady.ttf");
        text.setFont(font);
        text.setFillColor(sf::Color::Black);
        text.setPosition(sf::Vector2f(12.f, 10.f));
        text.setString(Bubble);
        table.setSize(sf::Vector2f(150.f, 50.f));
        table.setFillColor(sf::Color::White);
        table.setPosition(sf::Vector2f(10.f, 10.f));
    }
private:
    sf::Font font;
};
tables tablica;

void BubbleSort();
void SelectionSort();
void InsertionSort();
void quickSort(int Start, int End);

float generateRand()
{
    std::uniform_int_distribution<std::mt19937::result_type> random(0, HEIGHT);
    float randomDistribution = random(rng);
    return randomDistribution;
}
void Selswap(int j, int jplus)
{
    float temp = numbers[j].getSize().y;
    numbers[j].setSize(sf::Vector2f(1.f, numbers[jplus].getSize().y));
    numbers[jplus].setSize(sf::Vector2f(1.f, temp));
}
void draw()
{
    for (int i = 0; i < numbers.size(); i++)
    {
        window.draw(numbers[i]);
    }
}
void init()
{
    line.setSize(sf::Vector2f(1.f, 0.f));
    line.setFillColor(sf::Color::White);
    inputQuick.x = 0;
    inputQuick.y = 799;
    for (int i = 0; i < WIDTH; i++)
    {
        numbers.push_back(line);
        numbers[i].setPosition(sf::Vector2f(i, HEIGHT));
        numbers[i].setSize(sf::Vector2f(1.f, generateRand()));
        numbers[i].setRotation(180);
    }
}
void updateID()
{
    switch (sortID)
    {
    case 0:
        BubbleSort();
        draw();
        tablica.text.setString(tablica.Bubble);
        break;
    case 1:
        SelectionSort();
        draw();
        tablica.text.setString(tablica.Select);
        break;
    case 2:
        InsertionSort();
        draw();
        tablica.text.setString(tablica.Insert);
        break;
    case 3:
        std::cout << "\nentered quick";
        quickSort(inputQuick.x, inputQuick.y);
        draw();
        tablica.text.setString(tablica.Quick);
        std::cout << "\nleft quick";
        break;
    default:
        break;
    }
}
void buttons()
{
    static bool isPressed = 0;
    static bool SpcIsPressed = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && isPressed == 0)
    {
        for (int i = 0; i < WIDTH; i++)
        {
            numbers[i].setFillColor(sf::Color::White);
            numbers[i].setPosition(sf::Vector2f(i, HEIGHT));
            numbers[i].setSize(sf::Vector2f(1.f, generateRand()));
        }
        i = 0;
        k = 0;
        j = 0;
        index = 0;
        inputQuick.x = 0;
        inputQuick.y = 799;
        isColored = 0;
        isPressed = 1;
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::R)) isPressed = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && SpcIsPressed == 0)
    {
        if (sortID < 2)
            sortID++;
        else sortID = 0;
        SpcIsPressed = 1;
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) SpcIsPressed = 0;
}