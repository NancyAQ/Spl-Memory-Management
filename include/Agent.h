#pragma once

#include <vector>
#include "Graph.h"
#include "Simulation.h"

class SelectionPolicy;
class Simulation;

class Agent
{
public:
   // rule of 5:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);//constructor
    Agent(const Agent&other);//copy constructor
    ~Agent();// destructor
    Agent& operator=(const Agent&);//copy assignment operator
    Agent (Agent&&other);//move constructor
    Agent& operator=( Agent&& other);
    //end of rule of 5
    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    int getPartyId();
    void setPid(int i);
    void setId(int i);

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
};
