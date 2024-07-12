#include<iostream>
using namespace std;
class node
{
    int data;
    node *left, *right;
    int rbit, lbit;
    friend class tbt;
};
class tbt
{
  node *root;
  node *head;
  public:

  void create_tbt();
  void inorder();
  node *inorder_successor(node *temp);
  void preorder();
};
// Create
void tbt :: create_tbt()
{
    head = new node(); // Corrected here
    root = new node();
    cout<<"Enter the root"<<endl;
    cin>>root->data;
    head->left = root;
    head->right = head;
    root->left = head;
    root->right = head;
    head->lbit = head->rbit = 1;
    root->lbit = root->rbit = 0;
    char c;
    do
    {
      node *temp = root;
      node *curr = new node();
      cout<<"Enter the new data"<<endl;
      cin>>curr->data;
      int flag = 0;
      char choice;
      while(flag == 0)

      {
        cout<<"Where do you want to attach the node (L/R) of "<<temp->data<<endl;
        cin>>choice;
        if(choice == 'l')
        {
          if(temp->lbit==0){
            curr->left = temp->left; // later the temp is overwritten
            curr->right = temp;
            temp->left = curr;
            curr->lbit = curr->rbit=0;
            flag = 1;
            temp->lbit = 1;
            }
        else
        {
          temp = temp->left;
          flag = 0;
        }
      }
    else
      {
        if(temp->rbit==0)
        {
          curr->right = temp->right;
          curr->left = temp;          
          temp->right = curr;
          curr->lbit = curr->rbit=0;
          flag = 1;
          temp->rbit = 1;
        }
        else
        {
          temp = temp->right;
          flag = 0;
        }
      }
    }
    
    cout<<"Do you want to continue"<<endl;
    cin>>c;
    }while(c == 'y');
}
void tbt :: inorder(){
  node *temp=head;
  while(1){
    temp = inorder_successor(temp);
    if(temp == head)
      break;
    else
      cout<<temp->data<<"->";
  }
}
node* tbt::inorder_successor(node *temp){
  node *x = temp->right;
  if(temp->rbit == 1){
    while(x->lbit !=0){
      x=x->left;
    }
  }
    return x;
  
}
void tbt :: preorder()
{
    node* temp = head->left;
    while(temp != head)
    {
        cout<<temp->data;
        while(temp->lbit !=0)
        {
          temp = temp->left;
          cout<<temp->data;
        }
        while(temp->rbit == 0)
        {
          temp = temp->right;
        }
          if(temp->rbit == 1)
            temp = temp->right;
    }
}
int main(){
  tbt t1;
  cout<<"Tree formation"<<endl;
  t1.create_tbt();
  cout<<"Inorder traversal "<<endl;
  t1.inorder();
  cout<<"Preorder traversal "<<endl;
  t1.preorder();
  return 0;
}

