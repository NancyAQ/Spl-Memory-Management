#pragma once
#include "Party.h"
class Simulation;
class SelectionPolicy { 
public: 
    SelectionPolicy(){};
    virtual ~SelectionPolicy() {};
    virtual bool isMandate()=0;
    virtual void select(int id,Simulation &s)=0;
};

class MandatesSelectionPolicy: public SelectionPolicy{ 
public:
    MandatesSelectionPolicy()=default;
    ~MandatesSelectionPolicy() override;
    bool isMandate();
    void select(int id,Simulation &s) override;
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{ 
public:
    EdgeWeightSelectionPolicy()=default;
    ~EdgeWeightSelectionPolicy() override;
    bool isMandate();
    void select(int id,Simulation &s) override;
};

