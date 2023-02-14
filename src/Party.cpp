#include "Party.h"
#include "Simulation.h"
#include "JoinPolicy.h"
#include <iostream>
using namespace std;



class Simulation;
Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting),offers(),timer(0), colid(id)
{
    
    
}

Party::Party(const Party& other): mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(), mState(other.mState),offers(),timer(other.timer), colid(other.mId)
{
    if(other.mJoinPolicy->isMandate())
        mJoinPolicy = new MandatesJoinPolicy;
    else
        mJoinPolicy = new LastOfferJoinPolicy;
}
Party::~Party(){
    if(mJoinPolicy) delete mJoinPolicy;
}
Party& Party::operator=(const Party& other)
{  
    if(this!=&other){
    mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    mJoinPolicy = other.mJoinPolicy;
    mState = other.mState;
    timer = other.timer;
    colid = other.mId;
    int length=other.offers.size();
    for (int j=0;j<length;j++){
        this->offers.push_back(other.offers[j]);
    }

    }
    return *this;
}
Party & Party ::operator=(Party &&other){
    if (mJoinPolicy)
    delete mJoinPolicy;
     mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    mJoinPolicy = other.mJoinPolicy;
    mState = other.mState;
    timer = other.timer;
    colid = other.mId;
    offers=other.offers;
    other.mJoinPolicy=nullptr;
    return *this;
}
Party ::Party(Party && other):mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy), mState(other.mState),offers(other.offers),timer(other.timer), colid(other.mId){
    other.mJoinPolicy=nullptr;
}
State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}
int Party::getId(){
    return this->mId;
}

const string & Party::getName() const
{
    return mName;
}
int Party::getTimer(){
    return timer;
}
void Party::setTimer(int t){
    timer=t;
}
void Party::addOffer(int id){
    this->offers.push_back(id);
}
vector<int> Party::getOffers(){
    return offers;
}
void Party::setcolid(int idtoSet){
    this->colid=idtoSet;
}
int Party::getColId(){
    return this->colid;
}
const int Party::getColId()const{
    return this->colid;
}
int Party::GetColManNum(int pId,Simulation&s,int cur){
    int output=cur;
    
    for(int i=0;i<s.getGraph().getNumVertices();i++){
        
        if(s.getGraph().getParty(pId).getColId()== s.getGraph().getParty(i).getColId())
        output=output+s.getGraph().getParty(i).getMandates();
    }
    return output;
    
}
const int Party::colManNum(int pId,Simulation s,int cur)const{ //const method
    int output=cur;
    for(int i=0;i<s.getGraph().getNumVertices();i++){
        
        if(s.getGraph().getParty(pId).getColId()== s.getGraph().getParty(i).getColId())
        output=output+s.getGraph().getParty(i).getMandates();
    }
    return output;
}
bool Party::isSamCol(int pId,vector<int>currOffers,Simulation&s){
    bool output=false;
    for(unsigned int i=0;i<currOffers.size();i++){
         if(s.getGraph().getParty(pId).getColId()== s.getGraph().getParty(currOffers[i]).getColId())
         output=true;
    }
   return output;
}
void Party::step(Simulation &s)
{
    if(this->getState()!=Joined){
        if((this->getState()==CollectingOffers)&(this->getOffers().size()>0)&(this->getTimer()!=3)){
            this->setTimer(this->getTimer()+1);
        }
    }
    if((this->getTimer()==3 )&(this->getState()!=Joined)){
      mJoinPolicy->Join(this->getId(),s,this->getOffers());
      }
      
}
