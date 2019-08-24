/*
	LABORATORIO DI INFORMATICA - Caso di Studio Carpooling
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
    P.S -- For a better visualization of the output it is preferable to put the window in full screen  --
*/

// -- Libraries --
#include <stdio.h>
#include <stdlib.h>
#include "File.h"

// -- Constant --
//#define ID_FILE_PATH "../Files/ID.dat" // This file is used in order to generate unique ID for drivers
#define DRIVERS_FILE_PATH "../Files/Drivers.dat"
#define TRAVELS_FILE_PATH "../Files/Travels.dat"

#define MAX_LENGHT_CHOOSE_INPUT 3

// -- Main --
int main(void)
{
	bool flag = true;
	char choose_input[MAX_LENGHT_CHOOSE_INPUT] = NULL_STRING;
	Menu_choose_t choose_menu = not_valid_choice;

	initializeCMD();

	if(!isValidFile(DRIVERS_FILE_PATH))
	{
		printfError("\nAn error has occured during the opening of the driver's file");
		flag = false;
	}
	if(!isValidFile(TRAVELS_FILE_PATH))
	{
		printfError("\nAn error has occured during the opening of the travel's file");
		flag = false;
	}
	/*if(!isValidFile(ID_FILE_PATH))
	{
		printfError("\nAn error has occured during the opening of the ID's file");
		flag = false;
	}*/

	while(flag)
	{
		// Reset variable
		strcpy(choose_input, NULL_STRING);
		choose_menu = not_valid_choice;

		showMenu();

		printf("\n\nEnter a choice: ");
		scanf("%2[^\n]s", choose_input);
		addNullCharacterString(choose_input);
		clearBuffer();
		if(isdigit(*choose_input))
		{
			choose_menu = (Menu_choose_t) strtol(choose_input, NULL, 10);
		}
		else
		{
			printfError("\nThe choice that you have made is not valid!");
		}

		Driver_t driver;

		switch(choose_menu)
		{
			case add_driver:

				driver = addDriver();
				readDriver(&driver);
				int a = writeFile(DRIVERS_FILE_PATH, &driver, sizeof(driver));
				printf("\n%d\n", a);
				printf("\n\n");
				system("PAUSE");
				break;
			case edit_driver:
				break;
			case delete_driver:
				break;
			case show_all_driver:
				break;
			case add_travel:
				break;
			case edit_travel:
				break;
			case delete_travel:
				break;
			case show_all_travel:
				break;
			case book_travel:
				break;
			case sort_driver:
				break;
			case sort_travel:
				break;
			case exit_menu:
				flag = false;
				break;
			default:
				break;
		}



		/*
		int a = readDriverFile(DRIVERS_FILE_PATH);
		printf("\n%d\n", a);*/
	}


	printf("\n\n");
	system("PAUSE");
    exit(EXIT_SUCCESS);
}
