#include <iostream>
#include <string>
using namespace std;

class TelephoneDirectory {  // Абстрактный класс для всех типов записей
public:
    virtual ~TelephoneDirectory() = default; // Виртуальный деструктор
    virtual void display() const = 0;       
    virtual bool search(const string& lastName) const = 0; 
};

class Persona : public TelephoneDirectory {
private:
    string lastName, address, phone;
public:
    Persona(const string& lastName, const string& address, const string& phone)
        : lastName(lastName), address(address), phone(phone) {
    }
    void display() const override { 
        cout << "Type: Persona\n";
        cout << "Last Name: " << lastName << "\n";
        cout << "Address: " << address << "\n";
        cout << "Phone Number: " << phone << "\n";
        cout << "-----------------------------\n";
    }
    bool search(const string& lastName) const override { 
        return this->lastName == lastName;
    }
};

class Organization : public TelephoneDirectory {
private:
    string name, address, phone, fax, contact;
public:
    Organization(const string& name, const string& address, const string& phone,
        const string& fax, const string& contact)
        : name(name), address(address), phone(phone), fax(fax), contact(contact) {
    }
    void display() const override { 
        cout << "Type: Organization\n";
        cout << "Name: " << name << "\n";
        cout << "Address: " << address << "\n";
        cout << "Phone Number: " << phone << "\n";
        cout << "Fax Number: " << fax << "\n";
        cout << "Contact Person: " << contact << "\n";
        cout << "-----------------------------\n";
    }
    bool search(const string& lastName) const override { 
        return false;
    }
};
class Friend : public TelephoneDirectory {
private:
    string lastName, address, phone, birthDate;
public:
    Friend(const string& lastName, const string& address, const string& phone,
        const string& birthDate)
        : lastName(lastName), address(address), phone(phone), birthDate(birthDate) {
    }

    void display() const override { 
        cout << "Type: Friend\n";
        cout << "Last Name: " << lastName << "\n";
        cout << "Address: " << address << "\n";
        cout << "Phone Number: " << phone << "\n";
        cout << "Birth Date: " << birthDate << "\n";
        cout << "-----------------------------\n";
    }

    bool search(const string& lastName) const override { 
        return this->lastName == lastName;
    }
};

class TelephoneDatabase {  // Класс для управления базой данных
private:
    static const int MAX = 100; 
    TelephoneDirectory* entries[MAX]; 
    int count = 0; 
public:
    ~TelephoneDatabase() { // Деструктор для освобождения памяти
        for (int i = 0; i < count; ++i) delete entries[i];
    }
    void add(TelephoneDirectory* entry) { 
        if (count < MAX) entries[count++] = entry;
        else cout << "Error: Database is full.\n";
    }
    void displayAll() const { 
        for (int i = 0; i < count; ++i) entries[i]->display();
    }
    void search(const string& lastName) const { // Поиск по фамилии
        bool found = false;
        for (int i = 0; i < count; ++i) {
            if (entries[i]->search(lastName)) {
                entries[i]->display();
                found = true;
            }
        }
        if (!found) cout << "No entries found with last name: " << lastName << "\n";
    }
};

int main() {
    TelephoneDatabase BD; // Создание базы данных

    BD.add(new Persona("Ivanov", "Moscow", "123-456"));
    BD.add(new Organization("Tech Inc.", "SPb", "987-654", "123-456", "John Doe"));
    BD.add(new Persona("Petrov", "Kazan", "555-123"));
    cout << "All entries:\n";
    BD.displayAll();
    string lastName;
    cout << "Enter last name to search: ";
    cin >> lastName;
    BD.search(lastName);  // поиск по фамилии
    return 0;
}
