#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cmath>

template <class T>
class vector {
private:
	T *arr       = NULL; // ������������ ������
	size_t items = 2; // ���-�� ����������������� ���������
	size_t count = NULL; // ���-�� ����. ���������
public: 
	vector(); // ����������� ��� ����������
	vector(int items); // � ���-��� ���������
	vector(int items, T values); // � ���-��� ��������� � �� ����������
	~vector(); 

public:
	T& operator[] (size_t index); // ���������� ��������� []

	void clear(); // ������� �������
	bool empty(); // �������� �� ������ ������
	int size(); // ������ �������
	int capacity(); // ������ ������� � ������ �������
	T at(unsigned short int index); // ������� �������� ��������
	T front(); // �������� ������� ��������
	T back(); // �������� ���������� ��������
	void push_back(T arg); // ���������� ������ ��������
	void pop_back(); // �������� ���������� ��������
	void reserve(int items); // ���������� ����� ���������
	void resize(int index); // ��������� ������� �������
	void sort(); // ���������� �������

private:

	void recover_array(); // ������� �������
	void overwrite_array(size_t items = NULL); // ���������� �������
	void fill_array(T value); // ���������� �������
};

#include "vector.cpp"
#endif