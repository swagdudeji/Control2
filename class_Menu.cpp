#include "class_Menu.h"

void Menu::addition(fstream &out, Tour *data, int *arr_size){
      Tour *tmpData = new Tour[*arr_size+1];
      for(int i=0; i<*arr_size-1; i++){
        tmpData[i] = data[i];
        }
      delete[] data;
      cout << "Введите Название, Место, Дату и Стоимость тура" << endl;
      cin >> tmpData[count];
      data = tmpData;
      tmpData = nullptr;
      out.seekg(0, ios::end);
      out << data[count];
      count = count + 1;
      cout << "Тур успешно добавлен" << endl;
    };

    void Menu::show_all_entries(fstream &out, Tour *data){
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

    void Menu::removal(fstream &out, Tour *data, int *arr_size){
      int num;
      char tmp;
      cout << "Введите номер удаляемого тура" << endl;
      cin >> num;
      count--;
      Tour *tmpData = new Tour[*arr_size-1];
        for(int i=0; i<*arr_size-1; i++){
          if(num != i+1){
            tmpData[i] = data[i];
            }
          else{
            continue;
            }
        }
      delete[] data;
      data = tmpData;
      tmpData = nullptr;
      arr_size--;
      (out).seekg(0, ios::beg);
      for(int c=0; c<count; c++){
        out << data[c];
      }
      cout << "Тур успешно удален" << endl;
    }

  Tour * Menu::getFile(fstream &f, Tour *data, int &arr_size){
    string tmp1;
    while (!f.eof()) {
      getline(f, tmp1);
      count++;
      }
    count = count;
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
