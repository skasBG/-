#include <iostream>
#include <string>
#include <list>
// Анастас Илиев Анастасов 21621346

using namespace std;

// клас Студент
class Student {
public:
    string name;
    string fac_number;
    list<int> ocenki;

public:
    Student() {
        name = "";
        fac_number = "";
    }

    Student(string name, string fac_number) {
        this->name = name;
        this->fac_number = fac_number;
    }

    Student(const Student& other) {
        name = other.name;
        fac_number = other.fac_number;
        ocenki = other.ocenki;
    }

    string get_name() {
        return name;
    }

    double get_average() {
        if (ocenki.empty()) {
            return 0;
        }
        double sum = 0;
        for (int ocenka : ocenki) {
            sum += ocenka;
        }
        return sum / ocenki.size();
    }

    char get_ocenka() {
        double average = get_average();
        if (average >= 90) {
            return '6';
        }
        else if (average >= 80) {
            return '5';
        }
        else if (average >= 70) {
            return '4';
        }
        else if (average >= 60) {
            return '3';
        }
        else {
            return '2';
        }
    }

    void add_ocenki(int ocenka) {
        ocenki.push_back(ocenka);
    }
};

// клас Курс
class Course {
private:
    string name;
    list<Student> students;

public:
    Course(string name) {
        this->name = name;
    }

    Course(string filename, char delimiter = ',') {
    }

    string get_name() {
        return name;
    }

    void add_score(string fac_number, int score) {
        for (Student& student : students) {
            if (student.fac_number == fac_number) {
                student.add_ocenki(score);
                return;
            }
        }
        cout << "Студент с факултетен номер " << fac_number << " не е намерен." << endl;
    }

    void add_scores(string fac_number, list<int> scores) {
        for (Student& student : students) {
            if (student.fac_number == fac_number) {
                for (int score : scores) {
                    student.add_ocenki(score);
                }
                return;
            }
        }
        cout << "Студент с факултетен номер " << fac_number << " не е намерен." << endl;
    }

    void display_scores() {
        cout << "Курс: " << name << endl;
        for (Student& student : students) {
            cout << "Факултетен номер: " << student.fac_number << endl;
            cout << "Име: " << student.name << endl;
        };
    };
};