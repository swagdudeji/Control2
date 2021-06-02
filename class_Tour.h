#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Tour{

  public:

    string name;
    string place;
    string date;
    string price;

    friend std::ostream& operator<< (std::ostream &out, const Tour tour);
    friend std::istream& operator>> (std::istream &in, Tour tour);
    friend std::ostream& operator<< (std::fstream &f, const Tour tour);
    friend std::istream& operator>> (std::fstream &f, Tour &tour);
};
