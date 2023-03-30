#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cmath>

template <class T>
class vector {
private:
	T *arr       = NULL; // Динамический массив
	size_t items = 2; // Кол-во зарезервированных элементов
	size_t count = NULL; // Кол-во иниц. элементов
public: 
	vector(); // Конструктор без параметров
	vector(int items); // С кол-вом элементов
	vector(int items, T values); // С кол-вом элементов и их значениями
	~vector(); 

public:
	T& operator[] (size_t index); // Перегрузка оператора []

	void clear(); // Очистка массива
	bool empty(); // Проверка на пустой массив
	int size(); // Размер массива
	int capacity(); // Размер массива с учетом резерва
	T at(unsigned short int index); // Вывести значение элемента
	T front(); // Значение первого элемента
	T back(); // Значение последнего элемента
	void push_back(T arg); // Добавление нового элемента
	void pop_back(); // Удаление последнего элемента
	void reserve(int items); // Резервация новых элементов
	void resize(int index); // Изменение размера массива
	void sort(); // Сортировка массива

private:

	void recover_array(); // Очистка массива
	void overwrite_array(size_t items = NULL); // Перезапись массива
	void fill_array(T value); // Заполнение массива
};

#include "vector.cpp"
#endif