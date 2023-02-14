#include "Party.h"
#include "JoinPolicy.h"
#include "Agent.h"
#include <iostream>


bool MandatesJoinPolicy::isMandate(){
  return true;
}
MandatesJoinPolicy::~MandatesJoinPolicy(){}
void MandatesJoinPolicy::Join(int pId,Simulation &s,vector<int>offers){
    int joinedtoId=0;
    int max=0;
    int cur=s.getGraph().getParty(pId).getMandates();
    for(unsigned int i=0;i<offers.size();i++){
     if(s.getGraph().getParty(offers[i]).GetColManNum(offers[i],s,cur)>max){
      joinedtoId=offers[i];
      max=s.getGraph().getParty(offers[i]).GetColManNum(offers[i],s,cur);
      }
    }
     s.getGraph().getParty(pId).setcolid(s.getGraph().getParty(joinedtoId).getColId());
     s.getGraph().getParty(pId).setState(Joined);
     Agent clone= Agent(s.getAgent(joinedtoId));
    clone.setId(s.getAgents().size());
    clone.setPid(pId);
    s.getAgents().push_back(clone);
    s.ediColVec(s.getGraph().getParty(joinedtoId).getColId(),pId);
}