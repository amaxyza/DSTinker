#include <iostream>
#include <Windows.h>
#include "memory.h"
#include "offsets.h"
#include "features.h"
#include "infSouls.h"
#include "header.h"
#include "weapon_map.h"

int main()
{
	char option = ' ';
	print_header();
	std::cout << "Begin cheat? [y/n] ";
	do
	{
		std::cin >> option;
		switch (option)
		{
			case 'y':
			{
				std::cout << "Loading weapon names and ids...\n";
				Weapon weapons;

				while (true)
				{
					int choice = 0;
					system("cls");
					print_header();
					std::cout << "[+] ---------- MENU ---------- [+]\n";
					std::cout << "\n[1] GODMODE\n";
					std::cout << "[2] INFINITE SOULS\n";
					std::cout << "[3] MAX HUMANITY\n";
					std::cout << "[4] WEAPON SWAP\n";
					std::cout << "[5] 99 TITANITE\n\n";

					std::cout << "Enter an option: ";
					std::cin >> choice;

					switch (choice)
					{
						case 1:
						{
							godmode();
							break;
						}
						case 2:
						{
							inf_souls();
							break;
						}
						case 3:
						{
							max_humanity();
							break;
						}
						case 4:
						{
							weapon_swap(weapons);
							break;
						}
						case 5:
						{
							inf_titanite();
							break;
						}
						case 0:
						{
							system("cls");
							return 0;
						}
					}
				}
				break;
			}
			
			case 'n':
			{
				std::cout << "Closing DSTinker . . .";
				return 0;
			}
			
			default:
			{
				std::cout << "Must be 'y' or 'n', please try again . . .\n";
			}
		}
	} while (option != 'y' && option != 'n');
}
