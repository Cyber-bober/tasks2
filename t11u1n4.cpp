/*в файле input.txt содержатся сведения о группе студентов в формате :
-номер группы;
-запись о каждом студенте группы содержит следующие сведения :
фамилия, имя, отчество, год рождения, оценки по пяти предметам
Переписать данные файлы input.txt в файл output.txt, отсортировав их по убыванию суммы оценок методом вставки(сумму оценок вывести в файл output.txt для каждого студента); */

#include <iostream>
#include <fstream>
#include <sstream> // Для использования stringstream
using namespace std;

// Структура для хранения данных о студенте
struct Student {
    string surname;      
    string name;        
    string patronymic;    
    int birthYear;        
    int grades[5];        
    int totalScore = 0;   // Сумма оценок (инициализируется нулем)
};

// Функция для сортировки студентов методом вставки
void insertionSort(Student* students, int count) {
    for (int i = 1; i < count; i++) { // Начинаем с второго элемента
        int j = i;
        while (j > 0 && students[j - 1].totalScore < students[j].totalScore) {
            // Обмен значений через временную переменную
            Student temp = students[j];
            students[j] = students[j - 1];
            students[j - 1] = temp;
            j--; // Переходим к предыдущему элементу
        }
    }
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    if (!in) {
        cout << "Ошибка: Не удалось открыть файл input.txt" << endl;
        return 1;
    }

    if (!out) {
        cout << "Ошибка: Не удалось открыть файл output.txt" << endl;
        return 1;
    }

    // Чтение номера группы
    string groupNumber;
    getline(in, groupNumber);

    // Динамический массив для хранения студентов
    Student* students = nullptr;
    int studentCount = 0; // Текущее количество студентов
    int capacity = 0;     // Текущая вместимость массива

    // Чтение данных о студентах
    string line;
    while (getline(in, line)) {
        // Увеличиваем размер массива, если необходимо
        if (studentCount == capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2; // Удваиваем вместимость
            Student* newStudents = new Student[capacity];
            for (int i = 0; i < studentCount; i++) {
                newStudents[i] = students[i];
            }
            delete[] students; // Освобождаем старую память
            students = newStudents;
        }

        // Разбираем строку с помощью одного stringstream
        stringstream ss(line);
        ss >> students[studentCount].surname;
        ss >> students[studentCount].name;
        ss >> students[studentCount].patronymic;
        ss >> students[studentCount].birthYear;

        // Читаем оценки и вычисляем сумму
        students[studentCount].totalScore = 0;
        for (int i = 0; i < 5; i++) {
            ss >> students[studentCount].grades[i];
            students[studentCount].totalScore += students[studentCount].grades[i];
        }

        studentCount++; // Увеличиваем счетчик студентов
    }

    in.close();

    // Сортируем студентов по убыванию суммы оценок
    insertionSort(students, studentCount);

    // Записываем данные в output.txt
    out << groupNumber << endl;
    for (int i = 0; i < studentCount; i++) {
        out << students[i].surname << " "
            << students[i].name << " "
            << students[i].patronymic << " "
            << students[i].birthYear << " ";
        for (int j = 0; j < 5; j++) {
            out << students[i].grades[j] << " ";
        }
        out << students[i].totalScore << endl;
    }

    out.close();

    // Освобождаем память
    delete[] students;

    cout << "Данные успешно обработаны и записаны в файл output.txt" << endl;

    return 0;
}