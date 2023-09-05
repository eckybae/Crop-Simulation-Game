#include "Strawberry.h"

Strawberry::Strawberry() : Crop(), color("green-white") {}

string Strawberry::getColor() {
    return color;
}

void Strawberry::updateColor() {
    if (maturity <= 30) {
        color = "green-white";
    }
    else if ((maturity > 30) && (maturity <= 60)) {
        color = "light pink";
    }
    else if ((maturity > 60) && (maturity <= 90)) {
        color = "light red";
    }
    else if (maturity > 90) {
        color = "deep red";
    }
}

void Strawberry::addWater() {
    water += 5;
    if (health < 100) {
      health += 5;
    }
}

void Strawberry::addFertilizer() {
    fertilizer += 5;
    if (health < 100) {
      health += 5;
    }
}  

void Strawberry::lowerWater() {
  water -= 10;
}

void Strawberry::lowerFertilizer() {
  fertilizer -= 7;
}

void Strawberry::cleanCrop() {
  health += 3;
}


void Strawberry::lowerHealth() {
  if (water < 30) {
    health -= 5;
  }
  if (fertilizer < 25) {
    health -= 5;
  }
}

bool Strawberry::readyForPicking() {
    if (maturity > 90) {
        return true;
    }
    else {
        return false;
    }
}

void Strawberry::nextDay() {
    cout << "========================================================" << endl;
    cout << "Health: " << getHealth() << endl;
    cout << "Maturity: " << getMaturity() << endl;
    cout << "Water level: " << getWaterLevel() << endl;
    cout << "Fertilizer level: " << getFertilizerLevel() << endl;
    if (bugInfestation() == true) {
        cout << "Oh no! Bugs have infested the strawberry today." << endl;
    }
    if (animalInterference() == true) {
        cout << "Oh no! An animal has stepped on the strawberry today." << endl;
    }
    if (fungusInfestation() == true) {
        cout << "Oh no! Fungus has infested the strawberry today." << endl;
    }
    if (sunlightAvailable() == true) {
        cout << "Today is sunny! Our strawberry matured." << endl;
    }
    if (sunlightAvailable() == false) {
        cout << "No sunlight today :(" << endl;
    }
    cout << "Color: " << getColor() << endl;
    if (readyForPicking() == true) {
        cout << "Strawberry is ready for picking!" << endl;
    }
    if (readyForPicking() == false) {
        cout << "Strawberry is not ripe enough yet." << endl;
    }
    cout << "========================================================" << endl;
}

void Strawberry::saveInfo() {
    ofs.open("strawberry.txt");
    ofs << "Health: " << getHealth() << endl;
    ofs << "Maturity: " << getMaturity() << endl;
    ofs << "Water level: " << getWaterLevel() << endl;
    ofs << "Fertilizer level: " << getFertilizerLevel() << endl;
    ofs << "Color: " << getColor() << endl;
    if (readyForPicking() == true) {
        ofs << "Strawberry is ready for picking!" << endl;
    }
    if (readyForPicking() == false) {
        ofs << "Strawberry is not ripe enough yet." << endl;
    }
    ofs.close();
}

void Strawberry::loadInfo() {
  string line;
  ifs.open("strawberry.txt");
  while (getline(ifs, line)) {
    cout << line << endl;
  }
  ifs.close();
}
