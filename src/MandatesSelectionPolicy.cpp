#include "Party.h"
#include "SelectionPolicy.h"
#include "Agent.h"
#include "JoinPolicy.h"
#include <iostream>

bool MandatesSelectionPolicy::isMandate(){
    return true;
}
MandatesSelectionPolicy::~MandatesSelectionPolicy(){}
 void MandatesSelectionPolicy::select(int id,Simulation &s){
    int max=0;
    int maxid=0;
    for(int i=0;i<s.getGraph().getNumVertices();i++){
        bool neighbours=s.getGraph().areNeighbours(i,id);//check if they are neighbours
        bool requested=s.getGraph().getParty(id).isSamCol( id,s.getGraph().getParty(i).getOffers(),s);
        if((!requested)&(neighbours)&(i!=id)&(s.getGraph().getParty(i).getMandates()>max)&(s.getGraph().getParty(i).getState()!=Joined)){
           max=s.getGraph().getParty(i).getMandates();
           maxid=i;
        }
    }
    //here check if another party from same coalition already offered  
    if(max!=0){
    s.getGraph().getParty(maxid).addOffer(id); //added the agents id to the offers vector}
    s.getGraph().getParty(maxid).setState(CollectingOffers);

}
}