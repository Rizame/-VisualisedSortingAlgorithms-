#pragma once
#include<SFML/Graphics.hpp>
#include<random>
#include<vector>
#include"functions.h"

int partition(int start, int end);

void BubbleSort()
{
    if (i == numbers.size() && isColored == 0)
    {
        for (int i = 0; i < numbers.size(); i++)
        {
            numbers[i].setFillColor(sf::Color::Green);
        }
        isColored = 1;
    }
    if (isColored == 0)
    {
        for (i; i < numbers.size(); i++)
        {
            for (int j = 0; j < numbers.size() - i - 1; j++)
            {
                float a = numbers[j].getSize().y;
                float b = numbers[j + 1].getSize().y;
                if (a > b) {
                    Selswap(j, j + 1);
                }
            }
            i++;
            return;
        }
    }
}
void SelectionSort()
{
    if (k == numbers.size() && isColored == 0)
    {
        for (int i = 0; i < numbers.size(); i++)
        {
            numbers[i].setFillColor(sf::Color::Green);
        }
        isColored = 1;
    }
    if (isColored == 0)
    {
        for (k; k < numbers.size(); k++)
        {
            int min_id = k;
            for (int p = k + 1; p < numbers.size(); p++)
            {
                if (numbers[p].getSize().y < numbers[min_id].getSize().y) {
                    min_id = p;
                }
            }
            Selswap(min_id, k);
            k++;
            return;
        }
    }
}
void InsertionSort()
{
    if (j == numbers.size()-1 && isColored == 0)
    {
        for (int i = 0; i < numbers.size(); i++)
        {
            numbers[i].setFillColor(sf::Color::Green);
        }
        isColored = 1;
    }
    if (isColored == 0)
    {
        for (j; j < numbers.size() - 1; j++)
        {
            for (int k = j + 1; k > 0; k--)
            {
                int index = k - 1;
                if (numbers[k].getSize().y < numbers[k - 1].getSize().y)
                {
                    Selswap(k, index);
                }
            }
            j++;
            return;
        }
    }
}
void quickSort(int Start, int End) //[0], [799]
{
    if (Start >= End)
    {
        return;
    }
    index = partition(Start, End);
    quickSort(Start, index - 1);
    quickSort(index + 1, End);
    inputQuick.x = Start;
    inputQuick.y = End;
    std::cout << "\none cycle in quick";
    //std::cout << "\nstart: " << Start << "\n end: " << End;
    return;
}
int partition(int start, int end)
{
    std::cout << "\nentered partition";
    int id = start;
    float pivot = numbers[end].getSize().y;
    for (i = start; i < end; i++)
    {
        if (numbers[i].getSize().y < pivot)
        {
            Selswap(i, id);
            id++;
        }
    }
    Selswap(id, end);
    std::cout << "\nleft partition";
    return id;
}