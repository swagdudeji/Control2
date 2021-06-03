#include "class_Menu.h"
#include <stdio.h>

void Menu::addition(fstream &out, Tour *data, int *arr_size){
      Tour *tmpData = new Tour[*arr_size+1];
      cout << "CHECK: " << data[0];
      for(int i=0; i<*arr_size-1; i++){
        tmpData[i] = data[i];
        cout << "CHECK: " << tmpData[i];
        }
      delete[] data;
      cout << "Введите Название, Место, Дату и Стоимость тура" << endl;
      cin >> tmpData[count-1];
      data = tmpData;
      tmpData = nullptr;
      for(int i=0; i<count; i++){
        cout << "CHECK: " << data[i];
        }
      out.seekg(0, ios::end);
      out << endl;
      out << data[count-1];
      count++;
      cout << "Тур успешно добавлен" << endl;
    };

    void Menu::show_all_entries(fstream &out, Tour *data){
      cout << data[0];
      for(int c =0; c<count-1; c++){
        cout << data[c];
      }
    }

    void Menu::find_tour_by_name(fstream &out, Tour *data){
      bool label = false;
      string name;
      cout << "Введите название тура" << endl;
      cin >> name;
      for(int c =0; c<count; c++){
        if(name == data[c].name){
          cout << data[c];
          label = true;
        }
      }
      if(label == false){
        cout << "Не существует тура с заданным именем" << endl;
      }
    }

    void Menu::find_tour_by_place(fstream &out, Tour *data){
      bool label = false;
      string place;
      cout << "Введите место тура" << endl;
      cin >> place;
      for(int c =0; c<count; c++){
        if(place == data[c].place){
          cout << data[c];
          label = true;
        }
      }
      if(label == false){
        cout << "Не существует тура с заданным местом" << endl;
      }
    }

    void Menu::find_tour_by_date(fstream &out, Tour *data){
      bool label = false;
      string date;
      cout << "Введите дату тура" << endl;
      cin >> date;
      if(date.length() != 7){
        cout << "Неверный формат даты" << endl;
      }
      else{
        for(int c =0; c<count; c++){
          if(date == data[c].date){
            cout << data[c];
            label = true;
          }
        }
        if(label == false){
          cout << "Не существует тура с заданной датой" << endl;
        }
      }
    }

    void Menu::find_tour_by_price(fstream &out, Tour *data){
      bool label = false;
      string price;
      cout << "Введите цену тура" << endl;
      cin >> price;
      for(int c =0; c<count; c++){
        if(price == data[c].price){
          cout << data[c];
          label = true;
          }
        }
      if(label == false){
          cout << "Не существует тура с заданной ценой" << endl;
        }
    }

    void Menu::removal(fstream &out, string link, Tour *data, int *arr_size){
      int num;
      char tmp;
      cout << "Введите номер удаляемого тура" << endl;
      cin >> num;
      count--;
      int stopCounter;
      Tour *tmpData = new Tour[*arr_size-1];
        for(int i=0; i<*arr_size-1; i++){
          if(num != i+1){
            tmpData[i] = data[i];
            }
          else{
            stopCounter = i;
            break;
            }
          }
        for(int i=stopCounter; i<*arr_size-1; i++){
          tmpData[i] = data[i+1];
        }
      delete[] data;
      data = tmpData;
      tmpData = nullptr;
      arr_size--;
      out.close();
      std::ofstream ofs;
      ofs.open(link, std::ofstream::out | std::ofstream::trunc);
      for(int c=0; c<count; c++){
        out << data[c];
      }
      ofs << endl;
      cout << "Тур успешно удален" << endl;
    }

  Tour * Menu::getFile(fstream &f, Tour *data, int &arr_size){
    string tmp1;
    while (!f.eof()) {
      getline(f, tmp1);
      count++;
      }
    count++;
    f.seekg(0, ios::beg);
    Tour *tmpData = new Tour[count];
    int i=0;
    while(!f.eof() && arr_size-1<count){
      f >> tmpData[i];
      i++;
      arr_size++;
      }
    data = tmpData;
    tmpData = nullptr;
    return data;
    }
