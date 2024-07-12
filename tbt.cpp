#include<iostream>
using namespace std;
class node{
  int data;
  node *left, *right;
  int rbit, lbit;
  friend class tbt;
};
class tbt{
node *root;
node *head;
 public:
  void create_tbt();
  void inorder();
  node *inorder_successor(node *temp);
};
// create tbt
void tbt :: create_tbt(){
  node *head = new node();
  root = new node();
  cout<<"Enter root data"<<endl;
  cin>>root->data;
  head->left = root;
  head->right = head;
  root->left = head;
  root->right = head;
  head->lbit = head->rbit = 1;
  root->lbit = root->rbit = 0;
  do{
    node *temp = root;
    node *curr = new node();
    cout<<"Enter the new data"<<endl;
    cin>>curr->data;
    int flag = 0;
    char choice;
    while(flag == 0){
      cout<<"Where do you want to attach the node (L/R) of "<<temp->data;
      cin>>choice;
      if(choice == 'l'){
        if(temp->lbit==0){
          temp->left = curr;
          flag = 1;
          break;
        }
        else{
          temp = temp->left;
          flag = 0;
      }
    }
    else{
      if(temp->rbit==0){
          temp->right = curr;
          flag = 1;
          break;
        }
        else{
          temp = temp->right;
          flag = 0;
      }
    }
    
    char c;
    cout<<"Do you want to continue"<<endl;
    cin>>c;
  }while(c == 'y');
}
}
node* tbt :: inorder(){
  node *temp=head;
  while(1){
    temp = inorder_successor(temp);
    if(temp == head)
      break;
    else
      cout<<temp->data;
  }
}
void tbt::inorder_successor(node *temp){
  node *x = temp->right;
  if(temp->rbit == 1){
    while(x->lbit !=0){
      x=x->left;
    }
    return(x);
  }
}
int main(){
  tbt t1;
  cout<<"Tree formation"<<endl;
  t1.create_tbt();
  cout<<"Inorder traversal "<<endl;
  t1.inorder();
  return 0;
}
