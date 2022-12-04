//
// Created by Xander Voorvaart on 03/12/2022.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <array>

uint32_t getValue(int8_t c)
{
	if (std::isupper(c) == true)
		return c - 'A' + 27;
	if (std::islower(c) == true)
		return c - 'a' + 1;
	return (0);
}

void Part1(void)
{
	std::string     line;
	std::ifstream   file("input.txt");
	std::vector<int8_t> duplicateChars;

	bool            newLine = true;
	std::string     splitLine1;
	std::string     splitLine2;

	while (std::getline(file, line))
	{
		splitLine1 = line.substr(0, line.length() / 2);
		splitLine2 = line.substr(line.length() / 2, line.length());

		for (int32_t i = 0; splitLine1[i]; i++)
		{
			for (int32_t j = 0; splitLine2[j]; j++)
			{
				if (splitLine1[i] == splitLine2[j] &&
				    (std::find(duplicateChars.begin(), duplicateChars.end(), splitLine1[i]) == duplicateChars.end() ||
				     newLine == true))
				{
					duplicateChars.push_back(splitLine1[i]);
					newLine = false;
				}
			}
		}
		newLine = true;
	}

	uint32_t total = 0;
	std::vector<int8_t>::iterator it = duplicateChars.begin();

	for (; it != duplicateChars.end(); it++)
		total += getValue(*it);

	std::cout << total << "\n";
	file.close();
}

std::array<std::string, 3> fillArray(std::ifstream& file)
{
	uint64_t                    i = 0;
	std::string                 line;
	std::array<std::string, 3>  rucksack;

	while (i < rucksack.size() && std::getline(file, line))
	{
		rucksack[i] = line;
		i++;
	}
	return (rucksack);
}

void Part2(void)
{
	int8_t                      c;
	uint32_t                    total = 0;
	std::string                 line;
	std::array<std::string, 3>  rucksack;
	std::ifstream               file("input.txt");

	while (!file.eof())
	{
		rucksack = fillArray(file);

		for (uint64_t i = 0; rucksack[0][i] && !rucksack[2].empty(); i++)
		{
			c = rucksack[0][i];
			if (rucksack[1].find(c) != std::string::npos && rucksack[2].find(c) != std::string::npos)
			{
				total += getValue(c);
				break ;
			}
		}
	}

	std::cout << total << std::endl;
	file.close();
}

int32_t main(void)
{
	Part1();
	Part2();

	return (0);
}