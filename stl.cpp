#include <iostream>
#include "Vector/vector.h"

int main()
{
    vector<int>n_int(10, 0);
    vector<char>n_char(10, 'O');
    vector<float>n_float(10, 0.1);

    std::cout << "[0]\t[1]\t[2]\t[3]\t[4]\t[5]\t[6]\t[7]\t[8]\t[9]\tsize\tcap\tempty\n";
    for (int i = 0; i < n_int.size(); i++) {
        std::cout << n_int[i] << "\t";
    }
    std::cout << n_int.size() << "\t" << n_int.capacity() << "\t" << n_int.empty() << "\n";
    n_int.clear();

    for (int i = 0; i < n_int.size(); i++) {
        std::cout << n_int[i] << "\t";
    }
    std::cout << "\t\t\t\t\t\t\t\t\t\t";
    std::cout << n_int.size() << "\t" << n_int.capacity() << "\t" << n_int.empty() << "\n";

    n_int.push_back(0); n_int.push_back(1); n_int.push_back(2);
    n_int.push_back(3); n_int.push_back(4); n_int.push_back(5);
    n_int.push_back(6); n_int.push_back(7); n_int.push_back(8);
    n_int.push_back(9);

    for (int i = 0; i < n_int.size(); i++) {
        std::cout << n_int[i] << "\t";
    }
    std::cout << n_int.size() << "\t" << n_int.capacity() << "\t" << n_int.empty() << "\n";

    n_int.pop_back(); n_int.pop_back(); n_int.pop_back();

    for (int i = 0; i < n_int.size(); i++) {
        std::cout << n_int[i] << "\t";
    }
    std::cout << "\t\t\t";
    std::cout << n_int.size() << "\t" << n_int.capacity() << "\t" << n_int.empty() << "\n";

    std::cout << n_int.front() << "\t" << n_int.at(n_int.size() / 2) << "\t" << n_int.back();
    n_int.reserve(50);
    std::cout << "\t\t\t\t\t\t\t\t";
    std::cout << n_int.size() << "\t" << n_int.capacity() << "\t" << n_int.empty() << "\n";
    n_int.resize(5); n_int.resize(10);
    for (int i = 0; i < n_int.size(); i++) {
        std::cout << n_int[i] << "\t";
    }
    std::cout << n_int.size() << "\t" << n_int.capacity() << "\t" << n_int.empty() << "\n";
    for (int i = 0; i < n_int.size(); i++) {
        n_int[i] = rand() % 9;
        std::cout << n_int[i] << "\t";
    }
    std::cout << n_int.size() << "\t" << n_int.capacity() << "\t" << n_int.empty() << "\n";
    n_int.sort();
    for (int i = 0; i < n_int.size(); i++) {
        std::cout << n_int[i] << "\t";
    }
    std::cout << n_int.size() << "\t" << n_int.capacity() << "\t" << n_int.empty() << "\n";
}
