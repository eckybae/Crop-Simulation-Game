#include "Honeydew.h"

Honeydew::Honeydew() : Crop(), firmness("very soft") {}

string Honeydew::getFirmness() {
    return firmness;
}

void Honeydew::updateFirmness() {
    if (maturity <= 30) {
        firmness = "very soft";
    }
    else if ((maturity > 30) && (maturity <= 60)) {
        firmness = "soft";
    }
    else if ((maturity > 60) && (maturity <= 90)) {
        firmness = "slightly firm";
    }
    else if (maturity > 90) {
        firmness = "firm";
    }
}

void Honeydew::addWater() {
  water += 7;
  if (health < 100) {
    health += 6;
  }
}

void Honeydew::addFertilizer() {
  fertilizer += 4;
  health += 4;
}

void Honeydew::lowerWater() {
  water -= 10;
}

void Honeydew::lowerFertilizer() {
  fertilizer -= 7;
}

void Honeydew::cleanCrop() {
  health += 3;
}

void Honeydew::lowerHealth() {
  if (water < 45) {
    health -= 7;
  }
  if (fertilizer < 25) {
    health -= 3;
  }
}

void Honeydew::nextDay() {
    cout << "========================================================" << endl;
    cout << "Health: " << getHealth() << endl;
    cout << "Maturity: " << getMaturity() << endl;
    cout << "Water level: " << getWaterLevel() << endl;
    cout << "Fertilizer level: " << getFertilizerLevel() << endl;
    if (bugInfestation() == true) {
        cout << "Oh no! Bugs have infested the honeydew today." << endl;
    }
    if (animalInterference() == true) {
        cout << "Oh no! An animal has stepped on the honeydew today." << endl;
    }
    if (fungusInfestation() == true) {
        cout << "Oh no! Fungus has infested the honeydew today." << endl;
    }
    if (sunlightAvailable() == true) {
        cout << "Today is sunny! Our honeydew matured." << endl;
    }
    if (sunlightAvailable() == false) {
        cout << "No sunlight today :(" << endl;
    }
    cout << "Melon is " << getFirmness() << ".";
    if (maturity < 90) {
        cout << "It is not ripe yet." << endl;
    }
    if (maturity >= 90) {
        cout << "It is ripe!" << endl;
    }
    cout << "========================================================" << endl;
}

void Honeydew::saveInfo() {
    ofs.open("honeydew.txt");
    ofs << "Health: " << getHealth() << endl;
    ofs << "Maturity: " << getMaturity() << endl;
    ofs << "Water level: " << getWaterLevel() << endl;
    ofs << "Fertilizer level: " << getFertilizerLevel() << endl;
    ofs << "Melon is " << getFirmness() << ". ";
    if (maturity < 90) {
        ofs << "It is not ripe yet." << endl;
    }
    if (maturity >= 90) {
        ofs << "It is ripe!" << endl;
    }
    ofs.close();
}

void Honeydew::loadInfo() {
  string line;
  ifs.open("honeydew.txt");
  while (getline(ifs, line)) {
    cout << line << endl;
  }
  ifs.close();
}