#include "union-find.h"

union_find::union_find(int n)
{
    par = new int[n];
    for(int i=0;i<n;i++)
        par[i] = i;

    height = new int[n];
    for(int i=0;i<n;i++)
        height[i] = 1;
}

int union_find::find(int x) // Find the parent of the connected component of x
{
    //Expects x from 0 to n-1
    int i = x;
    while(i!=par[i])
    {
        i = par[i];
    }
    return i;
}

bool union_find::isconnected(int x, int y)
{
    int par_x = find(x);
    int par_y = find(y);
    if (par_x == par_y)
        return true;
    else
        return false;
}

void union_find::union_(int x, int y)
{
    //Expects x,y from 0 to n-1
    int par_x = find(x);
    int par_y = find(y);
    if (par_x == par_y)
        return;
    else
    {
        if(height[par_x] < height[par_y])
        {
            par[par_x] = par_y;
        }
        else if(height[par_x] < height[par_y])
        {
            par[par_y] = par_x;
        }
        else
        {
            par[par_x] = par_y;
            height[par_y]+=1;
        }  
    }   
}
