#include <stdio.h>
#include <windows.h>

#define INV_SLOTS 10
#define MAX_ITEMS 10
const char* item_names[MAX_ITEMS] = {"Пусто", "Дерево", "Камень", "Семена", "Железо",
							  "Золото", "Алмаз", "Аура", "Молот", "Инструкция по бонсмешу"};

void items_id()
{
	printf("0 - Ничего \n1 - Дерево \n2 - Камень \n3 - Семена \n4 - Железо \n5 - Золото \n6 - Алмаз \n7 - Аура \n8 - Молот \n9 - Инструкция по бонсмешу \n\n");
}

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
	int inventory[INV_SLOTS] = {9,8,7,7,7,7,7,7,7,7};		// Инициализация основных переменных

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
		printf("6. Любимый ресурс.\n");
		printf("0. Выход\n\n");

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
			printf("\nВыберите индекс слота 0-%d\n\n", INV_SLOTS-1);
			
			int index = safeInt();
			
			if (index < 0 || index >= INV_SLOTS) 
			{
				printf("\nОшибка! Такого слота не существует\n");
				break; 
			}
			
			printf("\nВыберите предмет\n\n");
			items_id();
			int id = safeInt();

			if (id == 0) 
			{ 
				printf("\nЗачем ложить в слот \"Ничего\", если можно выкинуть предмет, ты дурак?\n");
				break;
			}
			if (id < 0 || id >= MAX_ITEMS) 
			{
				printf("\nНеверный ID предмета\n");
				break;
			}

			inventory[index] = id;
			printf("\nПредмет \"%s\" положен в слот [%d]\n", item_names[id], index);
			break;

		case 5:		//Выбросить предмет
			printf("\nВыберите индекс слота 0-%d\n\n", INV_SLOTS - 1);

			int indexdel = safeInt();

			if (indexdel < 0 || indexdel >= INV_SLOTS)
			{
				printf("\nОшибка! Такого слота не существует\n");
				break;
			}

			inventory[indexdel] = 0;
			printf("\nСлот %d очищен!\n", indexdel);
			break;

		case 6: {		//Любимый ресурс Вариант 7
			int counts[MAX_ITEMS] = { 0 };
			int bestId = 0;

			for (int i = 0; i < INV_SLOTS; i++) {
				int id = inventory[i];
				if (id == 0) continue;               // пустые слоты не считаем
				counts[id]++;
				if (counts[id] > counts[bestId]) bestId = id;
			}

			if (bestId == 0) {
				printf("\nИнвентарь пуст.\n");
			}
			else {
				printf("\nСамый частый предмет: [%d] - %s, занимает слотов: %d\n", bestId, item_names[bestId], counts[bestId]);
			}
			break;
		}

		default: 
			printf("Нет такого пункта меню.\n"); //На случай введения цифры не соответствующей какому-либо пункту меню
			break;

		}
	} while (choice != 0);


	return 0;
}
