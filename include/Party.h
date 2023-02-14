#pragma once
#include <string>
#include<vector>

using std::string;
using std::vector;


class JoinPolicy;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
   //rule of 5:
    Party(int id, string name, int mandates, JoinPolicy *); //constructor
    Party(const Party&);//copy constructor
    ~Party();// destructor
    Party& operator=(const Party&);//copy assignment operator
    Party (Party&&other);//move constructor
    Party& operator=( Party&& other);
    //end of rule of 5
    State getState() const;
    int getId();
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    //new methods and fields
    int getTimer();
    void setTimer(int t);
    void addOffer(int id);
    vector<int> getOffers();
    int getColId();
    const int getColId()const;
    void setcolid(int id);
    int GetColManNum(int pId,Simulation&s,int cur);// calculates and returns total number of mandates in coalition that the party is in
    const int colManNum(int pId,Simulation s,int cur)const;
    bool isSamCol(int pId,vector<int>currOffers,Simulation&s);// checks if party from same coalition offered party x to join or not
    


private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    vector<int>offers;
    //new fields
    int timer;
    int colid;
   
};
