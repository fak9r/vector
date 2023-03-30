#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cmath>

template<class T>
class vector {
private:
	T *arr       = NULL; // Динамический массив
	size_t items = 2; // Кол-во зарезервированных элементов
	size_t count = NULL; // Кол-во иниц. элементов
public: 
	vector() { // Конструктор без параметров
		arr = new T[items];
	};

	vector(int items) { // С кол-вом элементов
		this->items = items;
		arr = new T[items];
	}

	vector(int items, T values) { // С кол-вом элементов и их значениями
		this->items = items;
		arr = new T[items];
		fill_array(values);
	}

	~vector() {
		delete arr;
	}

public:
	T& operator[] (size_t index) { // Перегрузка оператора []
		return arr[index];
	}

	void clear() { // Очистка массива
		recover_array();
	}

	bool empty() { // Проверка на пустой массив
		return !count ? true : false;
	}

	int size() { // Размер массива
		return count;
	}

	int capacity() { // Размер массива с учетом резерва
		return items;
	}

	T at(unsigned short int index) { // Вывести значение элемента
		return arr[index];
	}

	T front() { // Значение первого элемента
		return arr[0];
	}

	T back() { // Значение последнего элемента
		return arr[count - 1];
	}

	void push_back(T arg) { // Добавление нового элемента
		if (!items) recover_array();
		if (count >= items - 1) overwrite_array();
		this->arr[count] = arg;
		count++;
	}

	void pop_back() {  // Удаление последнего элемента
		if (!items) recover_array();
		if (count) count--;
		overwrite_array(items);
	}

	void reserve(int items) {  // Резервация новых элементов
		if (items > count) {
			this->items = items;
			overwrite_array(items);
		}
	}

	void resize(int index) {  // Изменение размера массива
		unsigned short int old_items = items;
		items = index;
		count = index;
		overwrite_array(index);

		if (index > old_items) {
			for (int i = old_items; i < index; i++) {
				arr[i] = 0;
			}
		}
	}

	void sort() { // Сортировка массива
		bool swapped = true;
		while (swapped) {
			swapped = false;
			for (int i = 0; i < size(); i++) {
				if (arr[i] > arr[i + 1] && (i + 1) < size()) {
					T buf = arr[i + 1];
					arr[i + 1] = arr[i];
					arr[i] = buf;
					swapped = true;
				}
			}
		}
	}

private:
	void recover_array() {
		count = NULL;
		if (!this->items) this->items++;
		delete[] arr;
		arr = new T[this->items];
	}

	void overwrite_array(size_t items = NULL) {
		T* arr_buffer = new T[this->items];
		for (int i = 0; i < this->items; i++) {
			arr_buffer[i] = arr[i];
		}
		delete[] arr;
		if (!items) this->items = this->items + ((1 + sqrt(this->items)));
		else this->items = items;
		arr = new T[this->items];
		for (int i = 0; i < this->items; i++) {
			arr[i] = arr_buffer[i];
		}
		delete[] arr_buffer;
	}

	void fill_array(T value) {
		for (int i = 0; i < items; i++) {
			arr[i] = value;
		}
		count = items;
	}
};

#endif