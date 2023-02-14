#pragma once

#include <vector>

#include "Graph.h"
#include "Agent.h"

using std::string;
using std::vector;

class Agent;
class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);
    ~Simulation();
    void step();
    bool shouldTerminate() const;
    Graph &getGraph();
    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    vector<Agent> &getAgents();
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    Agent &getAgent(int partyId);
    Party &getParty(int partyId);
    int GetColManNum(int pId,int cur);// calculates and returns total number of mandates in coalition that the party is in
    const int colManNum(int pId,int cur)const;
    void ediColVec(int joinedto,int toad);
    const vector<vector<int>> &getColVect()const;
    
    
  

private:
    Graph mGraph;
    vector<Agent> mAgents;
    int numOfCoal;
    vector<vector<int>>Coalitionvec;
};
