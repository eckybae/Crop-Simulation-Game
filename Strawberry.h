#ifndef STRAWBERRY_H
#define STRAWBERRY_H

#include "Crop.h"

class Strawberry: public Crop {
    public:
        Strawberry();
        string getColor();
        void updateColor();
        void addWater();
        void addFertilizer();
        void lowerHealth();
        void lowerWater();
        void lowerFertilizer();
        void cleanCrop();
        bool readyForPicking();
        void nextDay();
        void saveInfo();
        void loadInfo();

    private:
        string color;
};

#endif