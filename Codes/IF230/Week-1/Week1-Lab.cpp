#include <iostream>
#include <string>
using namespace std;

void strUpper(string *str) {
  for (char &in : *str) {
    if (in >= 'a' && in <= 'z') {
      in -= 32;
    }
  }
}

void strLower(string *str) {
  for (char &in : *str) {
    if (in >= 'A' && in <= 'Z') {
      in += 32;
    }
  }
}

void strSwitch(string *str) {
  for (char &in : *str) {
    if (in >= 'A' && in <= 'Z') {
      in += 32;
    } else if (in >= 'a' && in <= 'z') {
      in -= 32;
    }
  }
}

int main() {
  while (true) {
    int menu;
    string kata;

    cout << "1. Uppercase" << endl;
    cout << "2. Lowercase" << endl;
    cout << "3. Switching" << endl;
    cout << "4. Exit" << endl;
    cout << "Pilihan : ";

    cin >> menu;
    cin.ignore();

    if (menu >= 4)
      break;

    cout << "Masukkan kata: ";
    getline(cin, kata);

    switch (menu) {
    case 1:
      strUpper(&kata);
      break;
    case 2:
      strLower(&kata);
      break;
    case 3:
      strSwitch(&kata);
      break;
    }

    cout << kata << endl;
    cout << endl;
  }
}
