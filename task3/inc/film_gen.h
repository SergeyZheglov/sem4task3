#include <string>
#include <vector>
#include "../inc/film.h"

using namespace std;

class FilmGenerator {
private:
    vector<string> NAMES = {
        "Mark",
        "Thomas",
        "Andrew",
        "Apollo",
        "Arthur",
        "Michel",
        "Brian",
        "Brandon",
        "James",
        "Antony",
        "Jane",
        "Julia",
        "Katarina",
        "Martha",
        "Jenipher",
        "Bob",
        "Bruce",
        "Hue",
        "Harry"
    };

    vector<string> FAMILY_NAMES = {
        "Pitt",
        "Brown",
        "Green",
        "Keeper",
        "Williams",
        "Armstrong",
        "Eyecloser",
        "Loudshouter",
        "Walker",
        "Walls",
        "Dooropener",
        "Bloomberg",
        "Lee",
        "Spenser",
        "Bishop",
        "Harrison"
    };

    vector<string> ADJECTIVES = {
        "Glorious",
        "Frightening",
        "Unavoidable",
        "Triangular",
        "Spinning",
        "Signalling",
        "Screaming",
        "Antipodal"
    };

    vector<string> NOUNS = {
        "Fear",
        "Paradise",
        "Tennet",
        "Train",
        "House",
        "Square",
        "Death",
        "Cremation",
        "Shining",
        "Apocalypse",
        "Track"
    };

    vector<string> COUNTRIES = {
        "Russia",
        "USA",
        "North Korea",
        "UK",
        "India",
        "Japan",
        "Italy",
        "Germany",
        "Finland",
        "France",
        "Spain"
    };

public:
    int randint(int a, int b);

    template<typename T>
    T randchoice(vector<T> vect);

    string actor();

    vector<string> actors();

    string country();

    string film_name();

    int year();

    Film film(string name = "-");

    FilmContainer films(int _min = 2, int _max = 5);
};
