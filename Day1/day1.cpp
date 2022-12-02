//
// Created by Xander Voorvaart on 01/12/2022.
//

#include <iostream>
#include <fstream>
#include <map>

typedef std::map<uint32_t, uint32_t> map;

int32_t main(void)
{
	int32_t                        elfNumber = 1;
	uint32_t                       currentElf = 0;
	uint32_t                       highestElf = 0;
	std::string                    line;
    std::ifstream                  file("input.txt");
	map                            allElfs;

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
            allElfs[currentElf] = elfNumber;
			currentElf = 0;
			elfNumber++;
		}
	}

    uint32_t total = 0;
    map::reverse_iterator it = allElfs.rbegin();
    for (int32_t i = 0; i < 3; i++)
    {
        total += it->first;
        it++;
    }
    std::cout << total << std::endl;
	return (0);
}
