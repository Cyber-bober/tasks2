#include <iostream> // Подключаем библиотеку для работы с вводом/выводом
#include <fstream>  // Подключаем библиотеку для работы с файлами

using namespace std;

int main() {
    ofstream out("powers_of_three.bin", ios::binary); // Открываем бинарный файл для записи

    for (int i = 0; i < 10; ++i) { // Цикл для записи первых 10 степеней числа 3
        int power = static_cast<int>(pow(3, i)); // Вычисляем степень числа 3
        out.write(reinterpret_cast<const char*>(&power), sizeof(power)); // Записываем степень в файл
    }

    out.close(); // Закрываем файл после записи

    ifstream in("powers_of_three.bin", ios::binary); // Открываем бинарный файл для чтения
    if (!in) { // Проверяем, открылся ли файл
        cerr << "Ошибка открытия файла." << endl; // Выводим сообщение об ошибке
        return 1; // Завершаем программу с кодом ошибки
    }

    int power; // Переменная для чтения степеней из файла
    int index = 0; // Индекс для отслеживания порядкового номера

    while (in.read(reinterpret_cast<char*>(&power), sizeof(power))) { // Читаем данные из файла
        if (index % 2 == 0) { // Проверяем, четный ли порядковый номер
            cout << "Степень 3 в позиции " << index << ": " << power << endl; // Выводим степень на экран
        }
        index++; // Увеличиваем порядковый номер
    }

    in.close(); // Закрываем файл после чтения
    return 0; // Завершаем программу успешно
}