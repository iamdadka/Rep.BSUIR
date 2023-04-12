#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include "Zakupka.h"

int main() {
	setlocale(LC_ALL, "ru");

	
    static zakupka* array_zakupok;
	int amount_materials;
	int answer;

	do {
	
	   do{
	     printf("Введите количество закупок: ");
	     scanf_s("%d", &amount_materials);
	   } while (amount_materials < 0);

	   array_zakupok = (zakupka*)malloc((amount_materials) * sizeof(zakupka));
	   printf("\n");

	   input_array(array_zakupok, amount_materials);


	   sorting_array(array_zakupok, amount_materials);


	   printf_array(array_zakupok, amount_materials);


	   free(array_zakupok);

	   printf("\n");
	   printf("1.Продолжить работу\n2.Закончить работу\n");
	   scanf_s("%d", &answer);
	   printf("\n");

	} while (answer != 2);
}

