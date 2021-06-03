#include "class_Tour.h"

std::ostream& operator<< (std::ostream &out, const Tour tour){
  cout << tour.name << " " << tour.place << " " << tour.date << " " << tour.price << endl;
  return out;
}

std::istream& operator>> (std::istream &in, Tour &tour){
  in >> tour.name;
  in >> tour.place;
  in >> tour.date;
  in >> tour.price;
  return in;
}

std::ostream& operator<< (std::fstream &f, const Tour tour){
  f << tour.name << " " << tour.place << " " << tour.date << " " << tour.price << endl;
  return f;
}

std::istream& operator>> (std::fstream &f, Tour &tour){
  f >> tour.name >> tour.place >> tour.date >> tour.price;
  return f;
}