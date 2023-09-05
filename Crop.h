#ifndef CROP_H
#define CROP_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Crop {
    public:
        Crop();
        int getHealth();
        int getMaturity();
        int getWaterLevel();
        int getFertilizerLevel();
        bool bugInfestation();
        bool animalInterference();
        bool fungusInfestation();
        bool sunlightAvailable();
        virtual void lowerHealth() = 0;
        virtual void addWater() = 0;
        virtual void addFertilizer() = 0;
        virtual void lowerWater() = 0;
        virtual void lowerFertilizer() = 0;
        virtual void cleanCrop() = 0;
        virtual void nextDay();
        virtual void saveInfo();
        virtual void loadInfo();
        bool isDead();
        ifstream ifs;
        ofstream ofs;
    protected:
        int health;
        int water;
        int fertilizer;
        int maturity;
};

#endif