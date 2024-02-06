#include <iostream>
#include <Windows.h>
#include <cctype>
#include <map>
#include "memory.h"
#include "header.h"
#include "memoryinterface.h"
#include "offsets.h"
#include "features.h"
#include "weapon_map.h"

void godmode()
{
	int i = 0;
	int new_health = 999999999;
	const auto module_base = memory.GetModuleAddress("DarkSoulsRemastered.exe");
	const auto local_player_maxhp_ptr = memory.Read<std::uintptr_t>(module_base + offset::local_player_currency);
	const auto max_health_address = local_player_maxhp_ptr + offset::player_max_health;

	const auto local_player_ptr = memory.Read<std::uintptr_t>(module_base + offset::local_player);
	const std::uintptr_t health_temp_1 = local_player_ptr + offset::current_health_player_offset1;
	const auto health_address = memory.Read<std::uintptr_t>(health_temp_1) + offset::current_health_player_offset2;

	memory.Write<int>(max_health_address, new_health);
	memory.Write<int>(health_address, new_health);

}

void inf_souls()
{
	int new_souls = 999999999;
	const auto module_base = memory.GetModuleAddress("DarkSoulsRemastered.exe");
	const auto local_plr_currency = memory.Read<std::uintptr_t>(module_base + offset::local_player_currency);
	const auto souls_address = local_plr_currency + offset::souls;

	memory.Write<int>(souls_address, new_souls);
}

void max_humanity()
{
	int new_humanity = 99;
	const auto module_base = memory.GetModuleAddress("DarkSoulsRemastered.exe");
	const auto local_plr_currency = memory.Read<std::uintptr_t>(module_base + offset::local_player_currency);
	const auto humanities_address = local_plr_currency + offset::humanities;
	memory.Write<int>(humanities_address, new_humanity);
}

void weapon_swap(Weapon& weapons)
{
	system("cls");
	print_header();
	int chosen = -5;
	while (chosen != 0)
	{
		std::cout << "\nWeapon Number (-1 for a Weapon List, 0 to Quit to Menu, -2 to clear console): ";
		std::cin >> chosen;
		switch (chosen)
		{
			case -1:
			{
				system("cls");
				print_header();
				weapons.print_weapons();

				char co = 'c';
				std::cout << "\n Press any key to go back to menu. ";
				std::cin >> co;
				break;
			}
			case -2:
			{
				system("cls");
				print_header();
				break;
			}
			case 0:
			{
				break;
			}
			default:
			{
				if (chosen >= 1 && chosen <= 241)
				{
					const auto module_base = memory.GetModuleAddress("DarkSoulsRemastered.exe");
					const auto local_player_ptr = memory.Read<std::uintptr_t>(module_base + offset::local_player_currency);
					const std::uintptr_t weapon_temp = memory.Read<std::uintptr_t>(local_player_ptr + offset::right_weapon_offset1);
					const auto weapon_address = weapon_temp + offset::right_weapon_offset2;

					std::cout << "Changing right hand to " << weapons.weapon_from_small_id(chosen);
					memory.Write<int>(weapon_address, weapons.small_to_true(chosen));
				}
				else
				{
					std::cout << "Invalid weapon ID\n";
				}
				break;
			}
		}
	}
	
}

void inf_titanite()
{
	int amount = 33;

	const auto module_base = memory.GetModuleAddress("DarkSoulsRemastered.exe");
	const std::uintptr_t local_inv = memory.Read<std::uintptr_t>(module_base + offset::local_player_inventory);

	const std::uintptr_t a_1 = memory.Read<std::uintptr_t>(local_inv + offset::titanite_shard_offset1);
	const std::uintptr_t a_2 = memory.Read<std::uintptr_t>(a_1 + offset::titanite_shard_offset2);
	const auto titanite_address = a_2 + offset::titanite_shard_offset3;

	memory.Write<int>(titanite_address, amount);
}
