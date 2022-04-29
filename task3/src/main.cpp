#include <ctime>
#include <iostream>
#include <string>
#include "../inc/film_gen.h"

#if !defined(FROM_FILE)
#define FROM_FILE 0
#endif

using namespace std;

void print_help(void);

int main(void) {
    FilmGenerator gen;
    FilmContainer my_films;
    string cmd, name;
    char raw_name[100];
    int year;

    srand((unsigned)time(0));

    if (FROM_FILE) {
        if (!my_films.read("my_films.json"))
            return 0;
    }
    else
        my_films = gen.films();

    print_help();

    while (cin >> cmd) {
        if (cmd == "exit") {
            break;
        }
        else if (cmd == "help") {
            print_help();
        }
        else if (cmd == "print") {
            my_films.print();
        }
        else if (cmd == "save") {
            if (!(cin >> year)) {
                cout << "Invalid year" << endl;
                continue;
            }
            my_films.execute("output.json", year);
            cout << "> Saved to output.json" << endl;
        }
        else if (cmd == "add") {
            cin.getline(raw_name, 100);
            name = string(raw_name);
            name.erase(0, 1);
            my_films.add_film(gen.film(name));
            cout << "> Added " << name << endl;
        }
        else if (cmd == "delete") {
            cin.getline(raw_name, 100);
            name = string(raw_name);
            name.erase(0, 1);
            my_films.remove(name);
            cout << "> Deleted " << name << endl;
        }
        else {
            cout << "Unknown command" << endl;
        }
    }
    cout << "\nFinished" << endl;

    return 0;
}

void print_help(void) {
    cout << "--------------------------" << endl;
    cout << "Commands:" << endl;
    cout << "  exit - finish the program" << endl;
    cout << "  help - prints this text" << endl;
    cout << "  print - prints all films" << endl;
    cout << "  add <name> - adds a random film with this name" << endl;
    cout << "  delete <name> - removes a film with this name" << endl;
    cout << "  save <year> - saves to output.json all films after this year" << endl;
    cout << "--------------------------" << endl;
}
