/******************************************************************************
* Степанов Артём Андреевич,ПИ-231
* Share-Link:https://onlinegdb.com/6pWn_QjpyL
* Тема: Обработка массивов, вариант 20  
*******************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream file("Вино.txt");
    
    if (file.is_open()) {
        string lini;
        while (getline(file, line)) {
            cout << lini << endl; // Выводим содержимое файла
        }
        file.close(); // Закрываем файл
    } else {
        cout << "Не удалось открыть файл." << endl;
    }
    string name;
    int obiom, year;
    double prise;
    int oldest_year = 1927;
    double srznuh = 0;
    int colvo = 0;
    int year_filt;
    cout << "Введите год изготовления для фильтрации: ";
    cin >> year_filt;
    cout << "К сожалению я дурак и не понимаю как дальше делать :( ";

}
