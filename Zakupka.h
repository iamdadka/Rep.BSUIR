#pragma once
struct zakupka {
	int invoice_number; //номер накладной
	int demand; //потребность предприятия в материале (сырье) за определенный период
	int remainder_of_material; //остаток материала на складе на начало периода
	int ordered_to_supplier; //заказанная поставщику, но не поступившая на склад партия материала
};
 void input_array(zakupka * array_zakupok, int amount_materials);
 void sorting_array(zakupka* array_zakupok, int amount_materials);
 void printf_array(zakupka* array_zakupok, int amount_materials);

