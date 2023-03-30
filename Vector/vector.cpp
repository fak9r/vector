#include "vector.h"
#define TEMPLATE template<class T>

TEMPLATE vector<T>::vector() {
	arr = new T[items];
};

TEMPLATE vector<T>::vector(int items) {
	this->items = items;
	arr = new T[items];
}

TEMPLATE vector<T>::vector(int items, T values) {
	this->items = items;
	arr = new T[items];
	fill_array(values);
}

TEMPLATE vector<T>::~vector() {
	delete arr;
};

TEMPLATE T& vector<T>::operator[] (size_t index) {
	return arr[index];
}

TEMPLATE void vector<T>::clear() {
	vector::recover_array();
}

TEMPLATE bool vector<T>::empty() {
	return !count ? true : false;
}

TEMPLATE int vector<T>::size() {
	return vector::count;
}

TEMPLATE int vector<T>::capacity() {
	return items;
}

TEMPLATE T vector<T>::at(unsigned short int index) {
	return arr[index];
}

TEMPLATE T vector<T>::front() {
	return arr[0];
}

TEMPLATE T vector<T>::back() {
	return arr[count-1];
}

TEMPLATE void vector<T>::push_back(T arg) {
	if (!items) recover_array();
	if (count >= items - 1) overwrite_array();
	this->arr[count] = arg;
	count++;
}

TEMPLATE void vector<T>::pop_back() {
	if (!items) recover_array();
	if (count) count--;
	overwrite_array(items);
}

TEMPLATE void vector<T>::reserve(int items) {
	if (items > count) {
		this->items = items;
		overwrite_array(items);
	}
}

TEMPLATE void vector<T>::resize(int index) {
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

TEMPLATE void vector<T>::sort() {
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

TEMPLATE void vector<T>::recover_array() {
	count = NULL;
	if (!this->items) this->items++;
	delete[] arr;
	arr = new T[this->items];
}

TEMPLATE void vector<T>::overwrite_array(size_t items) {
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

TEMPLATE void vector<T>::fill_array(T value) {
	for (int i = 0; i < items; i++) {
		arr[i] = value;
	}
	count = items;
}