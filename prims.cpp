#include<iostream>
#include<vector>
using namespace std;

const int V=5;

int minValue(bool visited[] , int key[] ){

    int min =999, min_ind;

    for(int i=0 ;i<V ;i++){
        if(visited[i]==false && key[i]<min){
            min_ind=i;
            min=key[i];
        }
    }
    return min_ind;
}

void printMST(int parent[] , int cost[V][V]){
    int minCost=0;
        cout<<"Edge\tWeight\n";
    for(int i=1 ;i<V ;i++){
        cout<<parent[i]<<" - "<<i<<"\t"<<cost[i][parent[i]]<<endl;
        minCost+=cost[i][parent[i]];
    }
    cout<<"Min Cost is : "<<minCost;
}

void prims(int cost[V][V]){

    int parent[V] , key[V];
    bool visited [V];

    for(int i=0 ;i<V ;i++){
        parent[i]=-1;
        visited[i]=false;
        key[i]=999;
    }

    key[0]=0;


    for (int i=0 ;i<V-1 ;i++){
        int u=  minValue(visited , key );
        visited[u]=true;
        for(int j=0 ;j<V ;j++){
            if(cost[u][j]!=0 && visited[j]==0 && cost[u][j]<key[j] ){
                key[j]=cost[u][j];

                parent[j]=u;
            }
        }
    }

    printMST(parent , cost);
}


int main(){

    int cost[V][V];
	cout<<"Enter the weigth repectively : \n";
    for (int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
			cin>>cost[i][j];
        }
    }
    
    for (int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
			cout<<cost[i][j]<<" ";
        }
        cout<<endl;
    }

	prims(cost);  
    return 0;
}