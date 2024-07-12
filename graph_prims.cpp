#include<iostream>
using namespace std;
class graph{
  int cost[20][20];
  int n,e;
  public:
    void create();
    void display();
    void prims();
};
void graph::create(){
  cout<<"Enter number of vertices: ";
  cin>>n;
  cout<<"Enter number of edges: ";
  cin>>e;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cost[i][j] = 99999;
    }
  }
  int s,d,c;
  for(int i = 0;i<e;i++){
    cout<<"Enter source,destination,cost of edge"<<i<<endl;
    cin>>s>>d>>c;
    cost[s][d] = c;
    cost[d][s] = c;
  }
}
void graph::display(){
  cout<<"cost matrix is >>>>"<<endl;
  cout<<"\t";
  for(int i=0;i<n;i++){
    cout<<"("<<i<<")"<<"\t";
  }
  cout<<endl;
  for(int i = 0;i<n;i++){
    cout<<"("<<i<<")"<<"\t";
    for(int j = 0;j<n;j++)
      cout<<cost[i][j]<<"\t";
    cout<<endl;
  }
}
void graph::prims(){
  int nearest[20];
  int r[10][3];
  cout<<"Enter the start vector";
  int s;   
  cin>>s;
  nearest[s] = -1;
  for(int i=0;i<n;i++){
    if(i!=s)
      nearest[i] = s;
  }
  int j;
  int m = 0;
  int mincost = 0;
  for(int i = 0;i<n-1;i++){
    int min =9999;
    for(int k =0;k<n;k++){
      if(nearest[k] != -1 && min>cost[k][nearest[k]]){
      min = cost[k][nearest[k]];
      j=k;
      }
    }
    r[m][0] = nearest[j];
    r[m][2] = cost[j][nearest[j]];
    r[m][1] = j;
    m++;
    mincost+= cost[j][nearest[j]];
    nearest[j] = -1;
    for(int k=0;k<n;k++){
      if(nearest[k] != -1 &&cost[j][k]<cost[k][nearest[k]])
        nearest[k] = j;
    }
  }
  for(int i=0;i<m;i++){
    for(int x=0;x<3;x++)
      cout<<r[i][x]<<" ";
    cout<<endl;
  }
  cout<<"mincost is >> "<< mincost<<endl;
}
int main(){
  graph g;
  g.create();
  g.display();
  g.prims();
}
