#include<iostream>
#include<stdlib.h>
using namespace std;


int sum(int freq[] , int i , int j){
    int s=0;

    for(int k=i ;k<=j ;k++){
        s=s+ freq[k];
    }

    return s;
}

int optCost(int freq[] , int i , int j){
    if(j<i){
        return 0;
    }

    if(i==j){
        return freq[i];
    }

    int fsum = sum(freq , i ,j);
    
    int min= 999999;
    for(int k=i ; k<=j ; k++){
        int cost = optCost(freq , i , k-1) +optCost(freq , k+1 , j);

        if(cost<min){
            min=cost;
        }
    }

    return fsum + min;

}

int optimalSearchTree(int keys[],int freq[], int n)
{
	return optCost(freq, 0, n - 1);
}

int main(){

    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n= sizeof(keys)/sizeof(keys[0]);

    cout<<"Min cost is "<<optimalSearchTree(keys , freq, n );

    return 0;
}