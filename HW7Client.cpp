//======================================
//HW: HW7P2 DFS of a Graph
//Name: Chris Morikawa
//Complier: g++
//File type: client for hw7p2
//======================================
#include <iostream>
#include "llist.h"
#include "stack.h"
#include "dgraph.h"
#include "hw3p3.h"
using namespace std;
int main()
{
 dgraph TheGraph; //initialize dgraph
 stack TheStack; // initialize stack 
 slist TheSlist; // initialize slist

 cout << "Filling the Table" << endl;
 TheGraph.fillTable(); // Fill the graph with the table.txt
 cout << "Displaying the Table" << endl;
 cout << "-------------------" << endl;
 TheGraph.displayGraph();//Display the graph before going throught the rest

 char vert = 'A'; //initialize a character for the slist
 TheSlist = TheGraph.findAdjacency(vert);
 
 int num = 1; // initialize a number for the visit vertex
 TheGraph.visit(num, vert);

 while(!TheSlist.isEmpty()) // Keep going til the The Slist is empty
 {
  TheSlist.deleteRear(vert);//delete the rear of the slist
  TheStack.push(vert);//push that character into the stack
 }
 TheStack.displayAll();

 // Keep going through the stack until all vertices are covered, and it's empty.
 while(!TheStack.isEmpty())
 {
  TheStack.pop(vert); // Pop the vertex.
  cout << "The Vertex Visit: " << vert << endl;
  
  if (!TheGraph.isMarked(vert))//Go through the if loop if not marked.
  {
    cout << "This Vertex: " << vert << " was not visited" << endl;
    num ++;//incerment the number for visit
    TheGraph.visit(num, vert);//Set up the visit number to the vertex
    cout << "The Adjaceny list for vertex: " << vert << endl;
    TheSlist = TheGraph.findAdjacency(vert);
    
    char adj;
    while (!TheSlist.isEmpty())//Keep going til the slist is empty
    {
      TheSlist.deleteRear(adj);//delete the rear of the link list
      TheStack.push(adj);//add it to the stack
    }
   cout << "The Stack contains after adding the adjacency of vertex: " << vert << endl;
   TheStack.displayAll();//display the stack
  }
  else
  {
  cout << vert << ": This vertex has been visited already" << endl;
  }
 }//end of while
 //Show the final graph.
cout << "The final Graph: " << endl;
TheGraph.displayGraph();
return 0;
} 
