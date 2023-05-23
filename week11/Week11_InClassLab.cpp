#include<bits/stdc++.h>
using namespace std;

#define V 6		//Number of vertices

int selectMinVertex(vector<int>& value,vector<bool>& setMST)
{
	int minimum = int_max;
	int vertex;
	for(int i=0;i<V;++i)
	{
		if(setMST[i]==false && value[i]<minimum)
		{
			vertex = i;
			minimum = value[i];
		}
	}
	return vertex;
}

void findMST(int graph[V][V])
{
	int parent[V];		//Storing the MST
	vector<int> value(V,int_max);	
	vector<bool> setMST(V,false);	//TRUE implies the Vertex is included in MST

	//Assuming start point as Node-0 (as in the question)
	parent[0] = -1;	//Start node has no parent
	value[0] = 0;	//start node has value=0 to get picked 1st

	//Form MST with (V-1) edges
	for(int i=0;i<V-1;++i)
	{
		//Select the best Vertex by using the greedy method
		int U = selectMinVertex(value,setMST);
		setMST[U] = true;	//adding the new Vertex to the MST so far

        // releasing adjacent vertices which are not added to the MST so far
		for(int j=0;j<V;++j)
		{
			/* 3 constraints to release:-
			      1.An Edge is present from U to j.
			      2.Vertex j is not included in MST
			      3.Edge weight is smaller than current edge weight
			*/
			if(graph[U][j]!=0 && setMST[j]==false && graph[U][j]<value[j])
			{
				value[j] = graph[U][j];
				parent[j] = U;
			}
		}
	}
	//Print MST
	for(int i=1;i<V;++i)
		cout<<"U->V: "<<parent[i]<<"->"<<i<<"  weight = "<<graph[parent[i]][i]<<"\n";
}

int main()
{
	int graph[V][V] = { {0, 3, 0, 0, 0, 1},
						{3, 0, 2, 1, 10, 0},
						{0, 2, 0, 3, 0, 5},
						{0, 1, 3, 0, 5, 0},
						{0, 10, 0, 5, 0, 4},
						{1, 0, 5, 0, 4, 0} };

	findMST(graph);	
	return 0;
}
