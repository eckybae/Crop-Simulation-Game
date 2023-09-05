#include "Crop.h"
#include "Honeydew.h"
#include "Strawberry.h"
#include <stdlib.h>

int main() {
  cout << "========================================================" << endl;
  cout << "Welcome to the Fruit Farm!" << endl;
  while (true) {
    cout << "Start game? (press 'y' to start)" << endl;
    char option;
    cin >> option;
    if (option == 'y') {
      char option2;
      while (true) {
        cout << "========================================================" << endl;
        cout << "Plant a crop! ('s' for strawberry, 'h' for honeydew)" << endl;
        cin >> option2;
        if (option2 == 's') {
          cout << "You planted a strawberry!" << endl;
          Strawberry strawberry;
          int day = 1;
          while (strawberry.isDead() == false) {
            system("clear");
            cout << "========================================================" << endl;
            cout << "Day " << day << ":" << endl;
            strawberry.nextDay();
            char yesOrNo;
            cout << "Water strawberry? (press y)" << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'y') {
              if (strawberry.getWaterLevel() > 70) {
                cout << "No need for water today!" << endl;
                cout << "========================================================" << endl;
              } 
              else {
                strawberry.addWater();
                cout << "Strawberry watered." << endl;
                cout << "========================================================" << endl;
              }
            } 
            else {
              cout << "Strawberry not watered." << endl;
              cout << "========================================================" << endl;
            }
            cout << "Add fertilizer? (press y)" << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'y') {
              if (strawberry.getFertilizerLevel() > 60) {
                cout << "No need for fertilizer today!" << endl;
                cout << "========================================================" << endl;
              } 
              else {
                strawberry.addFertilizer();
                cout << "Strawberry fertilized." << endl;
                cout << "========================================================" << endl;
              }
            } 
            else {
              cout << "Strawberry not fertilized." << endl;
              cout << "========================================================" << endl;
            }
            cout << "Spray bug-cleaning solution? (press y)" << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'y') {
                strawberry.cleanCrop();
                cout << "Strawberry cleaned." << endl;
                cout << "========================================================" << endl;
              } 
            else {
              cout << "Strawberry not cleaned." << endl;
              cout << "========================================================" << endl;
            }
            cout << "Saving data..." << endl;
            strawberry.saveInfo();
  
            strawberry.lowerWater();
            strawberry.lowerFertilizer();
            cout << "Continue playing? (press y)" << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'y') {
              day++;
              continue;
            } 
            else {
              system("clear");
              cout << "========================================================" << endl;
              cout << "Thanks for playing!" << endl;
              cout << "Game data:" << endl;
              strawberry.loadInfo();
              cout << "========================================================" << endl;
              break;
            }
          }
          if (strawberry.isDead() == true) {
            system("clear");
            cout << "========================================================" << endl;
            cout << "Your strawberry has died! :(" << endl;
            cout << "GAME OVER" << endl;
            cout << "========================================================" << endl;
          }
          break;
        } 
        else if (option2 == 'h') {
          cout << "You planted a honeydew!" << endl;
          Honeydew honeydew;
          int day = 1;
          while (honeydew.isDead() == false) {
            int day;
            cout << "Day " << day << ":" << endl;
            honeydew.nextDay();
            char yesOrNo;
            cout << "Water honeydew? (press y)" << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'y') {
              if (honeydew.getWaterLevel() > 70) {
                cout << "No need for water today!" << endl;
                cout << "========================================================" << endl;
              } else {
                honeydew.addWater();
                cout << "Honeydew watered." << endl;
                cout << "========================================================" << endl;
              }
            } 
            else {
              cout << "Honeydew not watered." << endl;
              cout << "========================================================" << endl;
            }
            cout << "Add fertilizer? (press y)" << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'y') {
              if (honeydew.getFertilizerLevel() > 60) {
                cout << "No need for fertilizer today!" << endl;
                cout << "========================================================" << endl;
              } else {
                honeydew.addFertilizer();
                cout << "Honeydew fertilized." << endl;
                cout << "========================================================" << endl;
              }
            } else {
              cout << "Honeydew not fertilized." << endl;
              cout << "========================================================" << endl;
            }
            cout << "Spray bug-cleaning solution? (press y)" << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'y') {
                honeydew.cleanCrop();
                cout << "Honeydew cleaned." << endl;
                cout << "========================================================" << endl;
            } 
            else {
              cout << "Honeydew not cleaned." << endl;
              cout << "========================================================" << endl;
            }
            cout << "saving data..." << endl;
            honeydew.saveInfo();
  
            honeydew.lowerWater();
            honeydew.lowerFertilizer();
            cout << "Continue playing? (press y)" << endl;
            cin >> yesOrNo;
            if (yesOrNo == 'y') {
              day++;
              continue;
            } 
            else {
              system("clear");
              cout << "========================================================" << endl;
              cout << "Thanks for playing!" << endl;
              cout << "Game data:" << endl;
              honeydew.loadInfo();
              cout << "========================================================" << endl;
              break;
            }
          }
          if (honeydew.isDead() == true) {
            system("clear");
            cout << "========================================================" << endl;
            cout << "Your honeydew has died! :(" << endl;
            cout << "GAME OVER" << endl;
            cout << "========================================================" << endl;
          }
          break;
        } 
        else {
          cout << "Option not valid. Please select 's' or 'h.'" << endl;
        }
      }
      break;
    }
    else {
      exit(0);
    }
  }
  return 0;
}