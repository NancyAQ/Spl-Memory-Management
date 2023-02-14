#include "Simulation.h"
#include "Agent.h"
#include "Party.h"
#include <iostream>
class Agent;
class Party;
Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), numOfCoal(mAgents.size()), Coalitionvec()
{
    for( int j=0;j<=mGraph.getNumVertices();j++){
       vector<int> vec;
        Coalitionvec.push_back(vec);
    }
    for(int i=0;i<numOfCoal;i++){
        Coalitionvec[mAgents[i].getPartyId()].push_back(mAgents[i].getPartyId());
    }
}
Simulation::~Simulation(){
    mAgents.clear();
}
void Simulation::step()
{
    for(int i =0;i<mGraph.getNumVertices();i++){
       mGraph.getParty(i).step(*this);

    }
    for(unsigned int i=0;i<mAgents.size();i++){
        mAgents[i].step(*this);
    }

    
}
const vector<vector<int>> &Simulation::getColVect()const{
    return this->Coalitionvec;
}
bool Simulation::shouldTerminate() const
{
   int joinedNum=0;
   bool output=false;
   for(int i=0;(i<mGraph.getNumVertices())&!output;i++){
        if(mGraph.getParty(i).getState()==Joined){
            joinedNum=joinedNum+1;
            int mannum=this->colManNum(i,0);
            
            if(mannum>=61){
             output=true;
            }
            }
           
   }
   
   if(joinedNum==mGraph.getNumVertices()){
        output=true;
        
        }
      
   return output;
}

const Graph &Simulation::getGraph()const
{
    return mGraph;
   
}
 Graph &Simulation::getGraph() 
{
    return mGraph;
}
const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}
 vector<Agent> &Simulation::getAgents() 
{
    return mAgents;
}


const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}
 Party &Simulation::getParty(int partyId) 
{
    return mGraph.getParty(partyId);
}
Agent &Simulation::getAgent(int partyId) 
{
    Agent* a;
    for(unsigned int i=0;i<mAgents.size();i++){
       if(mAgents[i].getPartyId()==partyId)
         a = &mAgents[i];
    }
    return *a;
}
/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
   vector<vector<int>> output;
   vector<vector<int>>current=getColVect();
   for(unsigned int i=0;i<current.size();i++){
    if(!current[i].empty())
      output.push_back(current[i]);
   }

  return output;

}
void Simulation::ediColVec(int joinedto,int toad){
    this->Coalitionvec[joinedto].push_back(toad);
}
const int Simulation::colManNum(int pId,int cur)const{ //const method
    int output=cur;
    for(int i=0;i<this->mGraph.getNumVertices();i++){
        
        if(this->mGraph.getParty(pId).getColId()== this->mGraph.getParty(i).getColId())
        output=output+this->mGraph.getParty(i).getMandates();
    }
    return output;
}
