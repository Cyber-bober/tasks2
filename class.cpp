#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TelephoneDirectory {
protected:
    string lastName; 
public:
    virtual ~TelephoneDirectory() = default;
    virtual void display() = 0; 

    bool search(const string& searchLastName) {
        return lastName == searchLastName;
    }
};

class Persona : public TelephoneDirectory {
private:
    string address, phone;
public:
    Persona(string lastName, string address, string phone)
        : address(address), phone(phone) {
        this->lastName = lastName; 
    }

    void display() { 
        cout << "Type: Persona\n";
        cout << "Last Name: " << lastName << "\n";
        cout << "Address: " << address << "\n";
        cout << "Phone Number: " << phone << "\n";
        cout << "-----------------------------\n";
    }
};

class Organization : public TelephoneDirectory {
private:
    string name, address, phone, fax;
public:
    Organization(string name, string address, string phone, string fax, string lastName)
        : name(name), address(address), phone(phone), fax(fax) {
        this->lastName = lastName; 
    }

    void display() { 
        cout << "Type: Organization\n";
        cout << "Organization Name: " << name << "\n";
        cout << "Address: " << address << "\n";
        cout << "Phone Number: " << phone << "\n";
        cout << "Fax: " << fax << "\n";
        cout << "Contact's Last Name: " << lastName << "\n";
        cout << "-----------------------------\n";
    }
};

class Friend : public TelephoneDirectory {
private:
    string address, phone, birthDate;
public:
    Friend(string lastName, string address, string phone, string birthDate)
        : address(address), phone(phone), birthDate(birthDate) {
        this->lastName = lastName; 
    }

    void display() { 
        cout << "Type: Friend\n";
        cout << "Last Name: " << lastName << "\n";
        cout << "Address: " << address << "\n";
        cout << "Phone Number: " << phone << "\n";
        cout << "Birth Date: " << birthDate << "\n";
        cout << "-----------------------------\n";
    }
};

class TelephoneDatabase {
private:
    vector<TelephoneDirectory*> entries; 
public:
    void add(TelephoneDirectory* entry) {
        entries.push_back(entry);
    }

    void displayAll() {
        for (int i = 0; i < entries.size(); i++) {
            entries[i]->display();
        }
    }

    void search(const string& lastName) {
        bool found = false;
        for (int i = 0; i < entries.size(); i++) {
            if (entries[i]->search(lastName)) { 
                entries[i]->display();
                found = true;
            }
        }
        if (!found) {
            cout << "No entries found with last name: " << lastName << "\n";
        }
    }

    void freeMemory() {
        for (int i = 0; i < entries.size(); i++) {
            delete entries[i];
        }
        entries.clear();
    }
};

int main() {
    TelephoneDatabase BD;

    BD.add(new Persona("Ivanov", "Moscow", "123-456"));
    BD.add(new Organization("SGU Inc.", "SPb", "987-654", "562-027", "Mironov"));
    BD.add(new Friend("Petrov", "Kazan", "555-123", "26 of May"));
    BD.add(new Organization("Tech Inc.", "SPb", "987-654", "562-027", "Ivanov"));

    cout << "All entries:\n";
    BD.displayAll();

    string lastName;
    cout << "Enter last name to search: ";
    cin >> lastName;
    BD.search(lastName);
    BD.freeMemory();

    return 0;
}