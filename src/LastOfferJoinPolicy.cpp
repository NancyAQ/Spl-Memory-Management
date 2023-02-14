#include "Party.h"
#include "JoinPolicy.h"
#include "Simulation.h"
#include <iostream>
class Simulation;


bool LastOfferJoinPolicy::isMandate(){
  return false;
}
LastOfferJoinPolicy::~LastOfferJoinPolicy(){}
void LastOfferJoinPolicy::Join(int pId,Simulation &s,vector<int>offers){
    s.getGraph().getParty(pId).setcolid(s.getGraph().getParty(offers.back()).getColId()); //basically making them have the same coalition id
    s.getGraph().getParty(pId).setState(Joined);
    int joinedtoId=offers.back();//id of joined party
    //code under clones the offering agent
    Agent clone= Agent(s.getAgent(joinedtoId));
    clone.setId(s.getAgents().size());
    clone.setPid(pId);
    s.getAgents().push_back(clone);
    s.ediColVec(s.getGraph().getParty(joinedtoId).getColId(),pId);
}