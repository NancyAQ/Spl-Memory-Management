#pragma once
#include "Party.h"
class Simulation;
class JoinPolicy {
public:
    JoinPolicy(){};
    virtual ~JoinPolicy(){};
    virtual bool isMandate()=0;
    virtual void Join(int pId,Simulation &s,vector<int>offers)=0;
};

class MandatesJoinPolicy : public JoinPolicy {
public:
    MandatesJoinPolicy(){};
    ~MandatesJoinPolicy();
    bool isMandate();
    virtual void Join(int pId,Simulation &s,vector<int>offers) ;
};

class LastOfferJoinPolicy : public JoinPolicy {
public:
    LastOfferJoinPolicy(){};
    ~LastOfferJoinPolicy();
    bool isMandate();
    virtual void Join(int pId,Simulation &s,vector<int>offers);
};