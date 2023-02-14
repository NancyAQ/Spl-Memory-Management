
#include "SelectionPolicy.h"
#include "Agent.h"
#include "JoinPolicy.h"
#include <iostream>

bool EdgeWeightSelectionPolicy::isMandate(){
    return false;
}

EdgeWeightSelectionPolicy::~EdgeWeightSelectionPolicy(){}
 void EdgeWeightSelectionPolicy::select(int id,Simulation &s){
    int max=0;
    int maxid=0;
    for(int i=0;i<s.getGraph().getNumVertices();i++){
        bool neighbours=s.getGraph().areNeighbours(i,id);//check if the are neighbours
        bool requested=s.getGraph().getParty(id).isSamCol( id,s.getGraph().getParty(i).getOffers(),s);
        if((!requested)&(neighbours)&(i!=id)&(s.getGraph().getEdgeWeight(i,id)>max)&(s.getGraph().getParty(i).getState()!=Joined)){
            max=s.getGraph().getEdgeWeight(i,id);
            maxid=i; 

        }
    }
    if(max!=0){
     s.getGraph().getParty(maxid).addOffer(id); // added the agents party id to the offers vector 
     s.getGraph().getParty(maxid).setState(CollectingOffers);
    }
    

}