#include "Crop.h"

Crop::Crop() {
    health = 70;
    maturity = 0;
    water = 60;
    fertilizer = 40;
}

int Crop::getHealth() {
    return health;
}

int Crop::getMaturity() {
    return maturity;
}
        
int Crop::getWaterLevel() {
    return water;
}

int Crop::getFertilizerLevel() {
    return fertilizer;
}

bool Crop::bugInfestation() {
    srand(time(0));
    int random = rand();
    if (random % 10 == 0) {
      health -= 2;
      return true;
    }
    else {
        return false;
    }
}

bool Crop::animalInterference() {
    srand(time(0));
    int random = rand();
    if (random % 5 == 0) {
      health -= 2;
      return true;
    }
    else {
        return false;
    }
}

bool Crop::fungusInfestation() {
    srand(time(0));
    int random = rand();
    if (random % 7 == 0) {
        health -=2;
        return true;
    }
    else {
        return false;
    }
}

bool Crop::sunlightAvailable() {
    srand(time(0));
    int random = rand();
    if (random % 2 == 0) {
        maturity++;
        return true;
    }
    else {
      maturity = maturity;
        return false;
    }
}

/*void Crop::mature() {
    if (sunlightAvailable() == false) {
        maturity = maturity;
    } 
    else {
        maturity++;
    }
}*/

void Crop::nextDay() {
    cout << "========================================================" << endl;
    cout << "Health: " << getHealth() << endl;
    cout << "Maturity: " << getMaturity() << endl;
    cout << "Water level: " << getWaterLevel() << endl;
    cout << "Fertilizer level: " << getFertilizerLevel() << endl;
    if (bugInfestation() == true) {
        cout << "Oh no! Bugs have infested the crop today." << endl;
    }
    if (animalInterference() == true) {
        cout << "Oh no! An animal has stepped on the crop today." << endl;
    }
    if (fungusInfestation() == true) {
        cout << "Oh no! Fungus has infested the crop today." << endl;
    }
    if (sunlightAvailable() == true) {
        cout << "Today is sunny! Our crop matured." << endl;
    }
    cout << "========================================================" << endl;
}

void Crop::saveInfo() {
    ofs.open("crop.txt");
    ofs << "Health: " << getHealth() << endl;
    ofs << "Maturity: " << getMaturity() << endl;
    ofs << "Water level: " << getWaterLevel() << endl;
    ofs << "Fertilizer level: " << getFertilizerLevel() << endl;
    ofs.close();
}

void Crop::loadInfo() {
  string line;
  ifs.open("crop.txt");
  while (getline(ifs, line)) {
    cout << line << endl;
  }
  ifs.close();
}

bool Crop::isDead() {
    if (health <= 0) {
        return true;
    }
    else {
        return false;
    }
}

