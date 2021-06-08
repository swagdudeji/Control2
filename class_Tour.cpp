#include "class_Tour.h"

std::ostream& operator<< (std::ostream &out, const Tour tour){
  cout << tour.getName() << " " << tour.getPlace() << " " << tour.getDate() << " " << tour.getPrice() << "\n";
  return out;
}

std::istream& operator>> (std::istream &in, Tour &tour){
  string name;
  string place;
  string date;
  string price;
  in >> name;
  in >> place;
  in >> date;
  in >> price;
  tour.setName(name);
  tour.setPlace(place);
  tour.setDate(date);
  tour.setPrice(price);
  return in;
}

std::ostream& operator<< (std::fstream &f, const Tour tour){
  string tmpName;
  string tmpPlace;
  string tmpDate;
  string tmpPrice;
  f << tour.getName() << " " << tour.getPlace() << " " << tour.getDate() << " " << tour.getPrice() << "\n";
  return f;
}

std::istream& operator>> (std::fstream &f, Tour &tour){
  string name;
  string place;
  string date;
  string price;
  f >> name;
  f >> place;
  f >> date;
  f >> price;
  tour.setName(name);
  tour.setPlace(place);
  tour.setDate(date);
  tour.setPrice(price);
  return f;
}