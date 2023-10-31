#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,nb,i,j;
    cout<<"Enter Number of routers: ";
    cin>>n;
    vector<char> rou(n);
    char src;
    cout<<"Enter names of routers: ";
    for(i=0;i<n;i++)
    {
        cin>>rou[i];
    }
    cout<<"Enter the name of router from which you want to find estimated delay: ";
    cin>>src;
    cout<<"Enter number of neighbours of "<<src<<" : ";
    cin>>nb;
    vector<char> neighbours(nb);
    for(i=0;i<nb;i++)
    {
        cin>>neighbours[i];
    }
    vector<vector<int>> dis(n,vector<int>(nb));
    for(i=0;i<n;i++)
    {
        for(j=0;j<nb;j++)
        {
            cout<<"Enter the distance between router "<<rou[i]<<" and router "<<neighbours[j]<<" :";
            cin>>dis[i][j];
            if(rou[i]==neighbours[j])
            dis[i][j]=0;
        }
    }
    vector<int> delay(nb);
    for(i=0;i<nb;i++)
    {
        cout<<"Enter the delay between routers "<<src<<" and "<<neighbours[i]<<" :";
        cin>>delay[i];
    }
    vector<int> ndelay(n);
    vector<char> srcdelay(n);
    for(i=0;i<n;i++)
    {
        int ans=INT_MAX;
        char st;
        for(j=0;j<nb;j++)
        {
            int cval=dis[i][j]+delay[j];
            if(cval<ans)
            {
                ans=cval;
                st=neighbours[j];
            }
        }
        ndelay[i]=ans;
        srcdelay[i]=st;
    }
    cout<<endl<<"New Estimated delay from "<<src<<endl;
    for(i=0;i<n;i++)
    {
        cout<<ndelay[i]<<" "<<srcdelay[i]<<endl;
    }
}