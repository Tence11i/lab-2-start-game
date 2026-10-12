#include <stdio.h>
#include <windows.h>

#define INV_SLOTS 10

const char* item_names[10] = {"Пусто", "Дерево", "Камень", "Семена", "Железо",
							  "Золото", "Алмаз", "Аура", "Молот", "Инструкция для бонсмеша"};

int safeInt() //Защита от дурака для ввода чисел
{
	int x;
	while (scanf("%d", &x) != 1) {
		printf("Ошибка, введите число: \n");
		while (getchar() != '\n');
	}
	return x;
}

int main()
{
	SetConsoleOutputCP(65001); //Без этого вместо русских букв консоль пугает страшными символами

	int current_day = 1;
	int current_hour = 8;
	int inventory[INV_SLOTS] = { 0 };		// Инициализация основных переменных

	int choice;
	int hours;


	do {
		printf("\n====Меню====\n");
		printf("Введите номер действия:\n");
		printf("1. Посмотреть на часы.\n");
		printf("2. Поработать.\n");
		printf("3. Посмотреть инвентарь.\n");
		printf("4. Положить предмет в слот.\n");
		printf("5. Выбросить предмет.\n");
		printf("6. Любимый ресурс.\n\n");

		choice = safeInt();

		switch (choice) {
		
		case 0:
			printf("\nВыход...");
			break;

		case 1:		//Посмотреть на часы
			printf("\nТекущее время: День %d, %d : 00 \n", current_day, current_hour);
			break;

		case 2:		//Поработать
			printf("\nСколько часов работать?\n");
			hours = safeInt();
			current_day = current_day + (current_hour + hours) / 24;
			current_hour = (current_hour + hours) % 24;
			printf("\nТекущее время: День %d, %d : 00 \n", current_day, current_hour);
			break;

		case 3:		//Посмотреть инвентарь
			printf("\n====Инвентарь====\n");
			for (int i = 0; i < INV_SLOTS; i++) {
				printf("Слот %d: [%d] - %s\n", i, inventory[i], item_names[inventory[i]]);
			}
			break;

		case 4:		//Положить предмет в слот
			printf("Данная функция ещё не реализована...\n");
			break;

		case 5:		//Выбросить предмет
			printf("Данная функция ещё не реализована...\n");
			break;

		case 6:		//Любимый ресурс
			printf("Данная функция ещё не реализована...\n");
			break;

		default: 
			printf("Нет такого пункта меню.\n"); //На случай введения цифры не соответствующей какому-либо пункту меню
			break;

		}
	} while (choice != 0);


	return 0;
}
