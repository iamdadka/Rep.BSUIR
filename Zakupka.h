#pragma once
struct zakupka {
	int invoice_number; //����� ���������
	int demand; //����������� ����������� � ��������� (�����) �� ������������ ������
	int remainder_of_material; //������� ��������� �� ������ �� ������ �������
	int ordered_to_supplier; //���������� ����������, �� �� ����������� �� ����� ������ ���������
};
 void input_array(zakupka * array_zakupok, int amount_materials);
 void sorting_array(zakupka* array_zakupok, int amount_materials);
 void printf_array(zakupka* array_zakupok, int amount_materials);

