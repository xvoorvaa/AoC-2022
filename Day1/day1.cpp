//
// Created by Xander Voorvaart on 01/12/2022.
//

#include <iostream>
#include <fstream>
#include <vector>

std::ifstream OpenFile(const std::string& path)
{
	std::ifstream file(path);

	if (!file.is_open())
	{
		std::cerr << "Deos not exists" << std::endl;
		std::exit(1);
	}
	return file;
}

int32_t main(void)
{
	int32_t             elfNumber = 1;
	uint32_t            currentElf = 0;
	uint32_t            highestElf = 0;
	std::string         line;
	std::ifstream       file = OpenFile("input.txt");
	std::vector<uint32_t>   allElfs;

	while (std::getline(file, line))
	{
		if (!line.empty())
		{
			currentElf += std::stoi(line);
		}
		else
		{
			if (currentElf > highestElf)
			{
				std::cout << "Elf: " << elfNumber << " has the highest calo, which is: " << currentElf << "\n";
				highestElf = currentElf;
			}
			allElfs.push_back(currentElf);
			currentElf = 0;
			elfNumber++;
		}
	}

	if (currentElf > highestElf)
	{
		std::cout << "Elf: " << elfNumber << " has the highest calo, which is: " << currentElf << "\n";
		highestElf = currentElf;
	}
	std::cout << "current: " << currentElf << std::endl;
	allElfs.push_back(currentElf);

	uint64_t total = 0;
	std::vector<uint32_t>::iterator it = allElfs.begin();
	uint32_t second = 0;

	for (;it != allElfs.end(); it++)
	{
		if (second < *it && highestElf != *it)
			second = *it;
	}

	it = allElfs.begin();
	uint32_t third = 0;

	for (;it != allElfs.end(); it++)
	{
		if (third < *it && highestElf != *it && second != *it)
			third = *it;
	}

	total = highestElf + second + third;
	std::cout << "Total: " << total << std::endl;

	return (0);
}
