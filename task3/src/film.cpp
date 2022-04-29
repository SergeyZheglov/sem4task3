#include <iostream>
#include <fstream>
#include "../inc/film.h"

using namespace std;

Film::Film() {}

Film::Film(string name_, string country_, int year_, vector<string> actors_) {
    name = name_;
    country = country_;
    year = year_;
    actors = actors_;
}

string Film::get_name() {
    return name;
}

int Film::get_year() {
    return year;
}

void Film::from_json(json data) {
    name = data["name"];
    country = data["country"];
    year = data["year"];

    auto data_actors = data["actors"];
    for (auto p = data_actors.begin(); p != data_actors.end(); p++)
        actors.push_back(*p);
}

json Film::to_json() {
    json result = {
        {"name", name},
        {"country", country},
        {"year", year},
        {"actors", actors}
    };
    return result;
}

void Film::print_as_json() {
    cout << setw(4) << to_json() << endl;
}


FilmContainer::~FilmContainer() {
    vector<Film>().swap(films);
}

void FilmContainer::add_film(Film film) {
    films.push_back(film);
}

Film FilmContainer::get_film(string name) {
    Film empty;
    for (auto p = films.begin(); p != films.end(); p++) {
        if ((*p).get_name() == name) {
            return *p;
        }
    }
    return empty;
}

void FilmContainer::remove(string name) {
    for (auto p = films.begin(); p != films.end(); p++) {
        if ((*p).get_name() == name) {
            films.erase(p);
            break;
        }
    }
}

int FilmContainer::read(string filename) {
    ifstream fp;
    json data;

    fp.open(filename);
    if (!fp)
    {
        cout << "Failed to open '" << filename << "'" << endl;
        return 0;
    }
    fp >> data;
    fp.close();
    for (auto p = data.begin(); p != data.end(); p++)
    {
        Film new_film;
        new_film.from_json(*p);
        films.push_back(new_film);
    }
    return 1;
}

json FilmContainer::to_json(int after_year) {
    json arr = json::array();
    for (auto p = films.begin(); p != films.end(); p++) {
        if ((*p).get_year() >= after_year)
            arr.push_back((*p).to_json());
    }
    return arr;
}

void FilmContainer::print() {
    cout << setw(4) << to_json() << endl;
}

int FilmContainer::execute(string filename, int after_year) {
    ofstream fp;

    fp.open(filename);
    if (!fp) {
        cout << "Failed to open '" << filename << "'" << endl;
        return 0;
    }

    fp << setw(4) << to_json(after_year);
    fp.close();
    return 1;
}
