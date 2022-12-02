//
// Created by Xander Voorvaart on 01/12/2022.
//

#include <iostream>
#include <fstream>
#include <map>

#define ROCK 'A'
#define PAPER 'B'
#define SCISSORS 'C'

enum MyWeapons
{
    MY_ROCK = 'X',
    MY_PAPER = 'Y',
    MY_SCISSORS = 'Z'
};

uint32_t WhoWon(const std::string& line)
{
    char Me = line[2];
    char Enemy = line[0];

    if (Me == MY_ROCK && Enemy == SCISSORS)
        return (6);
    else if (Me == MY_ROCK && Enemy == ROCK)
        return (3);

    if (Me == MY_PAPER && Enemy == ROCK)
        return (6);
    else if (Me == MY_PAPER && Enemy == PAPER)
        return (3);

    if (Me == MY_SCISSORS && Enemy == PAPER)
        return (6);
    else if (Me == MY_SCISSORS && Enemy == SCISSORS)
        return (3);

    return (0);
}

void Part1(void)
{
    std::string     line;
    std::ifstream   file("input.txt");
    uint32_t        totalPoints = 0;

    while (std::getline(file, line))
    {
        totalPoints += WhoWon(line);
        switch (line[2])
        {
            case MY_ROCK:
                totalPoints += 1;
                break;
            case MY_PAPER:
                totalPoints += 2;
                break;
            case MY_SCISSORS:
                totalPoints += 3;
                break;
        }
    }

    std::cout << "Total Points Part 1: " << totalPoints << std::endl;
}

enum HOW_TO_WIN
{
    LOSE = 0,
    DRAW = 1,
    WIN = 2
};

uint32_t getGut(const std::string& line, HOW_TO_WIN status)
{
    char Enemy = line[0];

    if (Enemy == ROCK)
    {
        switch (status)
        {
            case LOSE:
                return (3);
            case DRAW:
                return (1);
            case WIN:
                return (2);
        }
    }

    if (Enemy == PAPER)
    {
        switch (status)
        {
            case LOSE:
                return (1);
            case DRAW:
                return (2);
            case WIN:
                return (3);
        }
    }

    if (Enemy == SCISSORS)
    {
        switch (status)
        {
            case LOSE:
                return (2);
            case DRAW:
                return (3);
            case WIN:
                return (1);
        }
    }

    return (0);
}

void Part2(void)
{
    std::string     line;
    std::ifstream   file("input.txt");
    uint32_t        totalPoints = 0;

    while (std::getline(file, line))
    {
        switch (line[2])
        {
            case 'X':
                totalPoints += getGut(line, LOSE);
                break;
            case 'Y':
                totalPoints += getGut(line, DRAW) + 3;
                break;
            case 'Z':
                totalPoints += getGut(line, WIN) + 6;
                break;
        }
    }

    std::cout << "Total Points Part 2: " << totalPoints << std::endl;
}

int32_t main(void)
{
    Part1();
    Part2();

	return (0);
}
