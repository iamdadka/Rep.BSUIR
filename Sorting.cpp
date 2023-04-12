#include "Zakupka.h"
#include <stdio.h>

zakupka* array_zakupok;

extern void input_array(zakupka* array_zakupok, int amount_materials) {
	for (register int i = 0; i < amount_materials; i++) {
		do {
			printf("Введите номер накладной: ");
			scanf_s("%d", &array_zakupok[i].invoice_number);
		} while (array_zakupok[i].invoice_number < 0);
		do {
			printf("Введите потребность предприятия в материале (сырье) за определенный период : ");
			scanf_s("%d", &array_zakupok[i].demand);
		} while (array_zakupok[i].demand < 0);
		do {
			printf("Введите остаток материала на складе на начало периода : ");
			scanf_s("%d", &array_zakupok[i].remainder_of_material);
		} while (array_zakupok[i].remainder_of_material < 0);
		do {
			printf("Введите количество сырья, заказанного поставщику, но не поступившего на склад: ");
			scanf_s("%d", &array_zakupok[i].ordered_to_supplier);
		} while (array_zakupok[i].ordered_to_supplier < 0);
		printf("\n");
		printf("\n");

	}
};


extern void sorting_array(zakupka* array_zakupok, int amount_materials) {
	int left = 0, right = amount_materials - 1;
	int flag = 1;
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (register int i = left; i < right; i++) {
			if (array_zakupok[i].invoice_number > array_zakupok[i + 1].invoice_number) {
				int t = array_zakupok[i].invoice_number;
				array_zakupok[i].invoice_number = array_zakupok[i + 1].invoice_number;
				array_zakupok[i + 1].invoice_number = t;
				flag = 1;
			}
		}
		right--;
		for (register int i = right; i > left; i--) {
			if (array_zakupok[i - 1].invoice_number > array_zakupok[i].invoice_number) {
				int t = array_zakupok[i].invoice_number;
				array_zakupok[i].invoice_number = array_zakupok[i - 1].invoice_number;
				array_zakupok[i - 1].invoice_number = t;
				flag = 1;
			}
		}
		left++;
	};
}


extern void printf_array(zakupka* array_zakupok, int amount_materials) {

	printf("____________________________________________________________________________________________"); printf("\n");
	printf("|Номер накладной|Потребность предприятия в материале|Остаток|    Количество сырья  |ОБЪЕМ  |"); printf("\n");
	printf("|               |        за определенный период     |       |заказанного поставщику|ЗАКУПКИ|"); printf("\n");
	printf("--------------------------------------------------------------------------------------------"); printf("\n");


	for (register int i = 0; i < amount_materials; i++) {
		if (array_zakupok[i].demand > (array_zakupok[i].remainder_of_material + array_zakupok[i].ordered_to_supplier)) {
			printf("|%15d|%35d|%7d|%22d|%7d|",
				array_zakupok[i].invoice_number, array_zakupok[i].demand, array_zakupok[i].remainder_of_material, array_zakupok[i].ordered_to_supplier,
				array_zakupok[i].demand - array_zakupok[i].remainder_of_material - array_zakupok[i].ordered_to_supplier);
		}
		else {
			printf("|%15d|%35d|%7d|%22d|      0|",
				array_zakupok[i].invoice_number, array_zakupok[i].demand, array_zakupok[i].remainder_of_material, array_zakupok[i].ordered_to_supplier);
		};

		printf("\n");
		printf("--------------------------------------------------------------------------------------------");
		printf("\n");
	}
};
	

	

