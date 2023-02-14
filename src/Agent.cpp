#include "Agent.h"
#include "SelectionPolicy.h"
Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
    // You can change the implementation of the constructor, but not the signature!
}
Agent::Agent(const Agent &other): mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(){//copy constructor to help with cloning
   
    if(other.mSelectionPolicy->isMandate())
        mSelectionPolicy = new MandatesSelectionPolicy;
    else
        mSelectionPolicy = new EdgeWeightSelectionPolicy;
}
Agent::~Agent(){ //destructor
    if(mSelectionPolicy) delete mSelectionPolicy;
}
Agent &Agent::operator=(const Agent&other){//copy assignment operator
   if(this!=&other){
     mAgentId=other.mAgentId;
     mPartyId=other.mPartyId;
     mSelectionPolicy=other.mSelectionPolicy;

   }
   return*this;

}
Agent & Agent ::operator=(Agent &&other){
    if (mSelectionPolicy)
    delete mSelectionPolicy;
    mAgentId=other.mAgentId;
    mPartyId=other.mPartyId;
    mSelectionPolicy=other.mSelectionPolicy;
    other.mSelectionPolicy=nullptr;
    return *this;

    
}
Agent ::Agent(Agent&&other):mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy){//move constructor
   other.mSelectionPolicy=nullptr;
}
int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}
int Agent::getPartyId() 
{
    return mPartyId;
}
 
void Agent::step(Simulation &sim)
{
    mSelectionPolicy->select(this->getPartyId(),sim);
}
void Agent::setPid(int i){
    this->mPartyId=i;
}
void Agent::setId(int i){
   this->mAgentId=i;
}