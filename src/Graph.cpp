#include "Graph.h"

Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges) 
{
    // You can change the implementation of the constructor, but not the signature!
}
Graph::~Graph(){
    mEdges.clear();
    mVertices.clear();
}
int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}
int Graph::getEdgeWeight(int v1, int v2) 
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return mVertices.size();
}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}
 Party &Graph::getParty(int partyId) 
{
    return mVertices[partyId];
}
bool Graph::areNeighbours(int id1,int id2){
    bool output=false;
    if(getEdgeWeight(id1,id2)!=0)
     output=true;
    return output;
    
}