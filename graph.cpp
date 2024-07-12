#include<iostream>
using namespace std;
class node
{
    int id;
    string username;
    node* next;  
    friend class graph;
};
class graph
{
  node *head[20];
  int n;
  public:
  void create();
  void display(int i);
};
void graph :: create()
{
    cout<<"Enter number of users "<<endl;
    cin>>n;
    node *temp;
    for(int i = 0;i<n;i++)
    {
      head[i] = new node();
      cout<<"Enter the name of username of "<<i+1<<endl;
      cin>>head[i]->username;
      head[i]->id = i;
      head[i]->next = NULL;
    }
    for(int i = 0;i<n;i++)
    {
      temp= head[i];
        char c;
      do
      {
        node *curr = new node();
        cout<<"enter the id of friend"<<endl;
        cin>>curr->id;
        curr->username = head[id]->username;
        curr->next = NULL;
        temp->next = curr;
        temp = curr;
        cout<<"Do you want to continue"<<endl;
        cin>>c;
      }while(c =='y');
    }
}
void graph :: display(int i){
    node* curr = head[i];
        while (curr != NULL) {
            cout << "ID : "<<curr->id << "Name: "<<curr->username<<" ->";
            curr = curr->next;
        }
}
int main(){
  graph g;
  g.create();
  cout<<"Enter the id "<<endl;
  int i;
  g.display(i);
return 0;
}

