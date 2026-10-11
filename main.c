#include <stdio.h>




int main()
{
	SetConsoleOutputCP(65001); //Без этого вместо русских букв консоль пугает страшными символами

	int current_day = 1;
	int current_hour = 8;
	int inventory[10] = { 0 };		// Инициализация основных переменных
	
	int choice;

	do {
		printf("Введите номер действия:\n");
		scanf("%d", &choice);

		switch (choice) {
		
		default: 
			printf("Нет такого пункта меню.(Или ещё не готов)"); //На случай введения цифры не соответствующей какому-либо пункту меню
		case 0:
			printf("Выход...");
		case 1:
			printf("Текущее время: День %d, %d : 00 \n", current_day, current_hour);


		}
	} while (choice != 0);


	return 0;
}
