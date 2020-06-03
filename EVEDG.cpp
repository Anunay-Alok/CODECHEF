#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > myVec;
vector<int> temp;
class Graph 
{ 
    int V;    
    list<int> *adj; 
    void DFSUtil(int v, bool visited[]); 
public: 
    Graph(int V);
    void addEdge(int v, int w); 
    void connectedComponents(); 
}; 
void Graph::connectedComponents() 
{ 
    bool *visited = new bool[V]; 
    for(int v = 0; v < V; v++) 
        visited[v] = false; 
  
    for (int v=0; v<V; v++) 
    { 
        if (visited[v] == false) 
        { 
            
            DFSUtil(v, visited); 
            myVec.emplace_back(temp);
            temp.clear();
        } 
    } 
} 
  
void Graph::DFSUtil(int v, bool visited[]) 
{ 
   
    visited[v] = true; 
    temp.emplace_back(v);
    list<int>::iterator i; 
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
    adj[v].emplace_back(w); 
    adj[w].emplace_back(v); 
} 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N,M;
        cin>>N>>M;
        vector<int> arr;
        Graph g(N);
        for(int i=0;i<N;i++)
          arr.emplace_back(0);
        for(int i=0;i<M;i++)
        {
            int pahla;
            int doosra;
            cin>>pahla>>doosra;
            arr[pahla-1]++;
            arr[doosra-1]++;
            g.addEdge(pahla-1,doosra-1);
        }
        if(M%2==0)
        {    
            cout<<1<<endl;
             for(int i=0;i<N;i++)
               cout<<1<<" ";
               cout<<endl;
        }
        else
        {
             g.connectedComponents(); 
             int x=-1;
             int min=INT_MAX;
             int minIndex=-1;
             int flag=1;
            
             
             int jhandagin=0;
             for(int i=0;i<myVec.size();i++)
             {
                 int sum1=0;
                 int xx=-1;
                 for (int j = 0; j < myVec[i].size(); j++) 
                        sum1+=arr[myVec[i][j]];
                 
                 int edge1=sum1/2;
                 if(edge1%2==0)
                 {

                 for(int p=0;p<myVec[i].size();p++)
                      {
                          if(arr[myVec[i][p]]%2!=0)
                           {
                             flag=0;
                             if(xx==-1)
                             {
                                xx=myVec[i][p];
                                break;
                             }
                           }
                       }

              if(xx!=-1) 
                  {
                      
                      cout<<2<<endl;
                      int a=xx;
                      for(int i=0;i<N;i++)
                        if(i==a)
                        cout<<2<<" ";
                        else cout<<1<<" ";

                      cout<<endl;
                      jhandagin=1;
                     break;     
                  }
                 }
             }
             if(jhandagin!=1)
              
             {

              for (int i = 0; i < myVec.size(); i++) 
              {
                  int sum=0;
                  for (int j = 0; j < myVec[i].size(); j++) 
                        sum+=arr[myVec[i][j]];
                  
                       
                  int edge=sum/2;
                  if(edge%2!=0)
                  {   
                      flag=1;
                      for(int p=0;p<myVec[i].size();p++)
                      {
                          if(arr[myVec[i][p]]%2!=0)
                           {
                             flag=0;
                             if(x==-1)
                                x=myVec[i][p];
                           }
                       }
                       if(flag==1)
                       {

                          if(edge<min)
                          {
                              min=edge;
                              minIndex=i;

                          }
                       }      
                    }
                    if(flag==0)
                       break;
                }
                if(x!=-1)
                {     
                     cout<<2<<endl;
                    for(int i=0;i<N;i++)
                        if(i==x)
                        cout<<2<<" ";
                        else cout<<1<<" ";
                    
                    cout<<endl;
                }
                else
                {   
                    cout<<3<<endl;
                    int a=myVec[minIndex][0];
                    int b=myVec[minIndex][1];
                    for(int i = 0;i<N;i++)
                    {
                     
                        if(i==a)
                          cout<<2<<" ";
                        else if(i==b)
                          cout<<3<<" ";
                        else cout<<1<<" ";
                    }
                    cout<<endl;
                }
          }
        }

    myVec.clear();
     
    }

}
