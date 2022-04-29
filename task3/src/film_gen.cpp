#include "../inc/film_gen.h"

int FilmGenerator::randint(int a, int b) {
    return rand() % (b - a + 1) + a;
}

template<typename T>
T FilmGenerator::randchoice(vector<T> vect) {
    return vect[randint(0, (int)vect.size() - 1)];
}

string FilmGenerator::actor() {
    return randchoice(NAMES) + " " + randchoice(FAMILY_NAMES);
}

vector<string> FilmGenerator::actors() {
    vector<string> result;
    for (int i = 0; i < randint(2, 7); i++)
        result.push_back(actor());
    return result;
}

string FilmGenerator::country() {
    return randchoice(COUNTRIES);
}

string FilmGenerator::film_name() {
    string result = randchoice(NOUNS);
    if (randint(0, 2))
        return randchoice(ADJECTIVES) + " " + result;
    return "The " + result;
}

int FilmGenerator::year() {
    return randint(1941, 2022);
}

Film FilmGenerator::film(string name) {
    if (name == "-")
        return Film(film_name(), country(), year(), actors());
    return Film(name, country(), year(), actors());
}

FilmContainer FilmGenerator::films(int _min, int _max) {
    FilmContainer cont;
    int length = randint(_min, _max);
    for (int i = 0; i < length; i++) {
        cont.add_film(film());
    }
    return cont;
}
