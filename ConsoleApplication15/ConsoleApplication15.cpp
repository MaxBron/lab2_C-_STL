#include <iostream>
#include <algorithm>
#include <chrono>
#include <list>

int binSearch(const std::list <int> &thisList, int key) {
    
    int Left, Right, central;
    Left = 0; Right = thisList.size();
    while (Left < Right - 1) {
        central = (Left + Right) / 2; 
        auto it = thisList.begin();
        std::advance(it, central);
        if (key < *it) {
            Right = central;
        }
        else {
            Left = central;
        }
    }
    auto it = thisList.begin();
    std::advance(it, Left);
    if (*it == key) {
        return *it;
    }
    else {
        return -1;
    }
}

int cinChecker() {
    int cinVar;
    while (!(std::cin >> cinVar)) {
        std::cin.clear();
        while (std::cin.get() != '\n')
            continue;
        std::cout << "\a:Ошибка, введите снова: ";
    }
    return cinVar;
}

int main()
{
    setlocale(LC_ALL, "ru");
    std::list <int> numbers;
    int lenList, xFind, listItem;
    std::cout << "Введите число элементов списка: ";
    lenList = cinChecker();
    numbers.sort();
    while (numbers.size() < lenList) {
        numbers.push_back(rand());
    }

    std::cout << "Список: ";
    for (const auto &elem : numbers) {
        std::cout << elem << " ";
    }

    std::cout << std::endl;
    std::cout << "Введите элемент для поиска: ";
    xFind = cinChecker();
    numbers.sort();
    auto start = std::chrono::steady_clock::now();
    find(numbers.begin(), numbers.end(), xFind);
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    if (find(numbers.begin(), numbers.end(), xFind) != numbers.end()) {
        std::cout << "нашли" << std::endl;
    }
    else {
        std::cout << "не нашли" << std::endl;
    }

    std::cout << "Время выполнения функции find: " << duration << std::endl << std::endl;
    start = std::chrono::steady_clock::now();
    binSearch(numbers, xFind);
    end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    if (binSearch(numbers, xFind) != -1) {
        std::cout << "нашли" << std::endl;
    }
    else {
        std::cout << "не нашли" << std::endl;
    }

    std::cout << "Время выполнения линейного поиска: " << duration << std::endl;
    return 0;
}
