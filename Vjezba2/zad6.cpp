#include <iostream>
#include <string>

struct Student
{
    std::string ime;
    std::string jmbag;
    int godStudija;
    int ECTS;
    double prosjek;
};

void filter_students(Student s[], int n, void (*action)(Student&), bool (*cond)(const Student&)){

    for (int i = 0; i < n; i++) {
        if (cond(s[i])) {
            action(s[i]);
        }
    }
}

void printaj(Student& s) {
    std::cout << "Ime: " << s.ime << ", JMBAG: " << s.jmbag << ", Godina: " << s.godStudija << ", ECTS: " << s.ECTS << ", Prosjek: " << s.prosjek << std::endl;
}

void godina(Student& s) {
    s.godStudija++;
}

int main(){

    Student studenti[] = {
        {"Stipe Anic", "0246012345", 1, 30, 4.2},
        {"Josip Katic", "0246543210", 1, 0, 3.1},
        {"Bruno Dokic", "0246111222", 2, 55, 3.8},
        {"Borislav", "0246999888", 3, 48, 2.9}
    };
    int n = sizeof(studenti)/sizeof(studenti[0]);

std::cout << "Studenti 1. godine s barem polozenim ispitom" << std::endl;
    filter_students(studenti, n, printaj, [](const Student& s) {
        return s.godStudija == 1 && s.ECTS > 0;
    });

    std::cout << std::endl;


    std::cout << "Studenti s prosjekom > 3.5" << std::endl;
    filter_students(studenti, n, printaj, [](const Student& s) {
        return s.prosjek > 3.5;
    });

    std::cout << std::endl;


    std::cout << "Povecanje godine za studente s >= 45 ECTS" << std::endl;
    std::cout << "Stanje prije promjene godine:" << std::endl;
    for(int i = 0; i < n; i++) {
        std::cout << studenti[i].ime << " je na " << studenti[i].godStudija << ". godini (ECTS: " << studenti[i].ECTS << ")" << std::endl;
    }

    filter_students(studenti, n, godina, [](const Student& s) {
        return s.ECTS >= 45;
    });

    std::cout << "\nStanje nakon promjene godine:" << std::endl;
    for(int i = 0; i < n; i++) {
        std::cout << studenti[i].ime << " je sada na " << studenti[i].godStudija << ". godini" << std::endl;
    }


}