#include <string>
#include <vector>
#include "../ext/nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

class Film {
private:
    string name;
    string country;
    int year;
    vector<string> actors;

public:
    Film();
    Film(string name_, string country_, int year_, vector<string> actors_);
    string get_name();
    int get_year();
    void from_json(json data);
    json to_json();
    void print_as_json();
};


class FilmContainer {
private:
    vector<Film> films;

public:
    ~FilmContainer();
    void add_film(Film film);
    Film get_film(string name);
    void remove(string name);
    int read(string filename);
    json to_json(int after_year = 0);
    void print();
    int execute(string filename, int after_year = 0);
};
