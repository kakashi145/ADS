#include<iostream>
#include<string>
using namespace std;
//mirror copy delete level traversal
class node{
 string word;
 string mean;
 node *left,*right;
 friend class bst;
 friend class Queue;
};
class bst{
 node *root;
 friend class Queue;
 public:
  void create_bst();
  void inorder();
  void inorder(node* root);
   void preorder();
  void preorder(node* root);
  void postorder();
  void postorder(node* root);
  void levelwise();
  void levelwise(node *root);
  void mirror();
  void mirror(node *root);
  void copy();
  node* copy(node *root);
  void bstdelete();
};
//Queue
class Queue{
node *qu[20];
int front;
int rear;
friend class BST;
public:
Queue(){
front = -1;
rear = -1;
}
void insert(node *t){
rear++;
qu[rear]=t;
}
node *del(){
front++;
return(qu[front]);
}
int empty(){
if(front == rear)
return 1;
else
return 0;
}
};
//creation
void bst :: create_bst(){
  root = new node();
  cout<<"Enter the root word"<<endl;
  cin>>root->word;
  cout<<"Enter the meaning of "<<root->word<<endl;
  cin>>root->mean;
  root->left = root->right=NULL;
  node *temp,*curr;
  char choice;
  do{
  temp = root;
  int flag = 0;
curr = new node();
cout<<"Enter the new word"<<endl;
  cin>>curr->word;
cout<<"Enter the meaning of "<<curr->word<<endl;
  cin>>curr->mean;
  curr->left = curr->right=NULL;
  while(flag == 0){
  if(curr->word <= temp->word){
  if(temp->left== NULL){
  temp->left=curr;
  flag = 1;
  break;
  }
  else{
  temp = temp->left;
  flag = 0;
  }
  }
  if(curr->word >= temp->word){
  if(temp->right== NULL){
  temp->right=curr;
  flag = 1;
  break;
  }
  else{
  temp = temp->right;
  flag = 0;
  }
  }
  }
cout<<"Do you want to continue"<<endl;
cin>>choice;
  }while(choice == 'y');
}
//mirror
void bst :: mirror(){
 mirror(root);
}
void bst ::mirror(node *root){
node *temp;
temp = root->left;
root ->left = root->right;
root->right = temp;
  if(root->left!=NULL){
  mirror(root->left);
  }
  if(root->right != NULL)
  mirror(root->right);
}
void bst :: copy(){
node *t = copy(root);
inorder(t);
}
node* bst :: copy(node * root){
node *temp = NULL;
if(root!=NULL){
temp =new node();
temp->word = root->word;
temp->left = copy(root->left);
temp->right =  copy(root->right);
}
return(temp);
}
// traversal
void bst :: inorder(){
 inorder(root);
}
void bst :: inorder(node *root){
if(root !=NULL){
inorder(root->left);
cout<<root->word;
inorder(root->right);
}
}
void bst :: preorder(){
 preorder(root);
}
void bst :: preorder(node *root){
if(root !=NULL){
cout<<root->word;
preorder(root->left);
preorder(root->right);
}
}
void bst :: postorder(){
 postorder(root);
}
void bst :: postorder(node *root){
if(root !=NULL){
postorder(root->left);
postorder(root->right);
cout<<root->word;
}
}
void bst :: levelwise(){
levelwise(root);
}
  void bst::levelwise(node *root){
  node *temp;
temp = new node();
Queue q;
q.insert(root);
while(!q.empty()){
temp = q.del();
cout<<temp->word<<"/n";
if(temp -> left != NULL)
q.insert(temp -> left);
if(temp -> right != NULL)
q.insert(temp -> right);
}
  }
void bst::bstdelete(){
    string key;
    cout<<"Enter the word which you want to delete"<<endl;
    cin>>key;
    node *temp = root;
    node *parent;
    while(temp != NULL){
      if(temp ->word == key){
        break;
      }
      else if(temp-> word > key){
       parent = temp;
        temp = temp->left;
      }
      else{
        parent = temp;
        temp = temp->right;
      }
          }
          if(temp!=root){
        if(temp->left == NULL && temp ->right == NULL){
            if(parent->right == temp){
                parent->right = NULL;}
              else{
                parent->left = NULL;}
              delete(temp);
            }
          else if(temp->left == NULL && temp->right != NULL){
            if(parent->right == temp){
                parent->right = temp->right;}
              else{
                parent->left = temp->right;
              temp->right = NULL ;
              }
              delete(temp);
          }
          else if(temp->left != NULL && temp->right ==NULL){
            if(parent->right == temp){
                parent->right = temp->left;
                }
              else{
                parent->left = temp->left;
                }
              temp->left = NULL ;
              delete(temp);
          }
          else{
            node *s = temp->left;
            node *r = temp->right;
            if(parent->right == temp){
                parent->right = r;
            }
            else{
              parent->left = r;
            }
            while(r->left !=NULL){
              r= r->left;
            }
            r->left = s;
            temp->right =NULL;
            delete(temp);
          }
        }
        else{
          if(temp->left == NULL && temp->right == NULL){
            root = NULL;
          }
          else if(temp->left != NULL && temp->right == NULL){
            root = temp->left;
            delete(temp);
          }
          else if(temp->left == NULL && temp->right != NULL){
            root = temp->right;
            delete(temp);
          }
          else{
            root = temp->right;
            node *s =temp->left;
            node *r =temp->right;
            while(r->left != NULL){
              r= r->left;
            }
            r->left = s;
            temp->right = NULL;
            delete(temp);
          }
        }
      
      }
int main(){
bst dic;
dic.create_bst();
char choice;
  int ch;
  string a;
  do{
  cout<<"\n1.inorder\n2.preorder\n3.postorder\n4.mirror\n 5 copy\n 6 level-wise\n 7 delete"<<endl;
  cin>>ch;
  switch(ch){
  case 1:
  cout<<"The inorder traversal ->   ";
dic.inorder();
cout<<endl;
  break;
  case 2:
  cout<<"The preorder traversal ->   ";
dic.preorder();
cout<<endl;
  break;
  case 3:
 cout<<"The postorder traversal ->   ";
dic.postorder();
cout<<endl;
  break;
  case 4:
  dic.mirror();
  cout<<"inorder of mirror image is ->";
  dic.inorder();
  cout<<endl;
  break;
  case 5:
  cout<<"the copy->"<<endl;
  dic.copy();
  break;
  case 6:
  cout<<"The level-wise traversal ->   ";
dic.levelwise();
cout<<endl;
break;
case 7:
   dic.bstdelete();
   break;
  default:
  cout<<"Invaild choice"<<endl;
  break;
  }
  cout<<"do you want to continue"<<endl;
  cin>>choice;
  }while(choice=='y' || choice=='Y');



return 0;
}
