#ifndef HONEYDEW_H
#define HONEYDEW_H

#include "Crop.h"

class Honeydew: public Crop {
    public:
        Honeydew();
        string getFirmness();
        void updateFirmness();
        void addWater();
        void addFertilizer();
        void lowerWater();
        void lowerFertilizer();
        void cleanCrop();
        void lowerHealth();
        void nextDay();
        void saveInfo();
        void loadInfo();
        
    private:
        string firmness;
};

#endif