#include<iostream>
using namespace std;

template<class T>
class node{
        public:
                T info;
                node<T> *next;
                node<T>(T i,node<T> *n=NULL){
                        info=i;
                        next=n;
                }
};

template<class T>
class Queue{
        node<T> *front,*rear;
        public:
                Queue<T>(){
                    front=rear=NULL;
                }

                bool isEmpty(){
                        return front==NULL;
                }
                void enqueue(T);
                T dequeue();
};

template<class T>
void Queue<T>::enqueue(T x){
    if(!isEmpty()){
          node<T> *temp=new node<T>(x);
          rear->next=temp;
          rear=temp;
        }
        else
        front=rear=new node<T>(x);
}

template<class T>
T Queue<T>::dequeue(){
        if(isEmpty()){
                cout<<"\nQueue is empty";
                return NULL;
        }

        node<T> *temp=front;
        front=temp->next;
        T returnValue=temp->info;
        delete temp;
        return returnValue;
}

class BSTNode{
        public:
                BSTNode *left,*right;
                int data;
                BSTNode(int key){
                        data=key;
                        left=NULL;
                        right=NULL;
                }
};

class BST{
        BSTNode *root;
        public:
                BST(){
                        root=NULL;
                }

                BSTNode* getRoot(){
                        return root;
                }

                void insert(int);

                void inOrder(BSTNode*);
                void inOrder(){
                        if(root==NULL){
                                cout<<"\nEmpty tree";
                                return;
                        }
                        inOrder(root);
                }

                void preOrder(BSTNode*);
                void preOrder(){
                        if(root==NULL){
                                cout<<"\nEmpty tree";
                                return;
                        }
                        preOrder(root);
                }

                void postOrder(BSTNode*);
                void postOrder(){
                        if(root==NULL){
                                cout<<"\nEmpty tree";
                                return;
                        }
                        postOrder(root);
                }

                void levelByLevel();

                void searchKey(BSTNode*&,int,BSTNode*&);
                void searchKey(int key){
                        BSTNode *curr=root,*parent=NULL;
                        searchKey(curr,key,parent);
                        if(curr==NULL)
                        cout<<"\nElement not found in tree.";
                        else
                        cout<<"\nElement is in tree.";
                }

                void deleteNode(int);
                BSTNode* deleteNode(BSTNode*,int);

                void deletionByMerging(BSTNode*&);
                void findAndDeleteByMerging(int);

                int countLeaf(BSTNode*);
                int countLeaf(){
                        return countLeaf(root);
                }

                int countNonLeaf(BSTNode*);
                int countNonLeaf(){
                        return countNonLeaf(root);
                }

                void mirrorImage(BSTNode*);
                void mirrorImage(){
                        mirrorImage(root);
                }

                int heightOfTree(BSTNode*);
                void heightOfTree(){
                        cout<<"\nHeight of tree is: "<<heightOfTree(root);
                }
};

BSTNode * minValueNode(BSTNode* node) 
{ 
    BSTNode* current = node; 
  
    while (current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

BSTNode* BST::deleteNode(BSTNode* root, int key) 
{ 
    if (root == NULL) 
	    return root; 
  
    if (key < root->data) 
        root->left = deleteNode(root->left, key); 
    else if (key > root->data) 
        root->right = deleteNode(root->right, key); 
    else
    { 
        if (root->left == NULL) 
        { 
            BSTNode *temp = root->right; 
            delete root; 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            BSTNode *temp = root->left; 
            delete root; 
            return temp; 
        } 
        BSTNode* temp = minValueNode(root->right); 
        root->data = temp->data; 
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
} 

void BST::deleteNode(int key){
	deleteNode(root,key);
}

int BST::heightOfTree(BSTNode *p){
   if (p==NULL)
       return 0;

    int lheight = heightOfTree(p->left);
    int rheight = heightOfTree(p->right);

    if (lheight > rheight)
       return(lheight+1);
    return(rheight+1);
}

void BST::levelByLevel(){
        Queue<BSTNode*> q;

        if(root==NULL){
                cout<<"\nEmpty tree\n";
                return;
        }
        cout<<"\n";
        BSTNode *temp=root;
        if(temp!=NULL){
                q.enqueue(temp);
                while(!q.isEmpty()){
                        temp=q.dequeue();
                        cout<<temp->data<<" ";
                        if(temp->left!=NULL){
                                q.enqueue(temp->left);
                        }

                        if(temp->right!=NULL){
                                q.enqueue(temp->right);
                        }
                }
        }
}

void BST::searchKey(BSTNode *&curr, int key, BSTNode *&parent){
        while(curr!=NULL && curr->data != key){
                parent = curr;
                if(key < curr->data)
                curr=curr->left;
                else
                curr=curr->right;
        }
}

void BST::insert(int x){
        BSTNode *prev=NULL;
        BSTNode *curr=root;

        if(root==NULL){
                root=new BSTNode(x);
                return;
        }
        while(curr!=NULL){
                prev=curr;
                if(curr->data < x){
                        curr=curr->right;
                }else{
                        curr=curr->left;
                }
        }

        if(prev->data > x){
                prev->left=new BSTNode(x);
        }else{
                prev->right=new BSTNode(x);
        }
}

void BST::findAndDeleteByMerging(int x){
        BSTNode *curr=root;
        BSTNode *parent=NULL;
        searchKey(curr,x,parent);

        if(curr!=NULL && curr->data==x){
                if(curr==root)
                        deletionByMerging(root);
                else if(parent->left==curr)
                        deletionByMerging(parent->left);
                else
                        deletionByMerging(parent->right);
        }
        else if(root!=NULL)
                cout<<"\nValue not found in tree";
        else
                cout<<"\nTree is empty";
}

void BST::deletionByMerging(BSTNode *&node){
        BSTNode *temp=node;
        if(node!=NULL){
                if(node->right==NULL)
                node=node->left;
                else if(node->left==NULL)
                node=node->right;
                else{
                        temp=node->left;
                        while(temp->right!=NULL)
                        temp=temp->right;

                        temp->right=node->right;

                        temp=node;
                        node=node->left;
                }
                delete temp;
        }
}

int BST::countLeaf(BSTNode *n){
        if(n==NULL)
        return 0;
        if(n->left==NULL && n->right==NULL)
        return 1;
        else
        return countLeaf(n->left)+countLeaf(n->right);
}

int BST::countNonLeaf(BSTNode *n){
        if(n==NULL || (n->left==NULL && n->right==NULL))
        return 0;
        else
        return countNonLeaf(n->left)+countNonLeaf(n->right)+1;
}

void BST::mirrorImage(BSTNode *n){
        if(n==NULL)
        return;

        BSTNode *temp=n->left;
        n->left=n->right;
        n->right=temp;

        mirrorImage(n->left);
        mirrorImage(n->right);
}

void BST::inOrder(BSTNode *v){
        if(v==NULL)
        return;

        inOrder(v->left);
        cout<<v->data<<" ";
        inOrder(v->right);
}

void BST::preOrder(BSTNode *v){
        if(v==NULL)
        return;

        cout<<v->data<<" ";
        preOrder(v->left);
        preOrder(v->right);
}

void BST::postOrder(BSTNode *v){
        if(v==NULL)
        return;

        postOrder(v->left);
        postOrder(v->right);
        cout<<v->data<<" ";
}

int main(){
        BST bst;

        bst.insert(6);
        bst.insert(2);
        bst.insert(1);
        bst.insert(11);
        bst.insert(8);
        bst.insert(15);
        bst.insert(9);
        bst.insert(10);
//        bst.insert(73);
//        bst.insert(80);
//        bst.insert(96);
//        bst.insert(85);
//        bst.insert(100);
//        bst.insert(97);
//        bst.insert(105);
//        bst.insert(103);
//        bst.insert(110);

        char choice;
        do{
                cout<<"\na) Insert";
                cout<<"\nb) Deletion by copying";
                cout<<"\nc) Deletion by merging";
                cout<<"\nd) Search a number";
                cout<<"\ne) Display preorder,postorder and inorder traversals";
                cout<<"\nf) Display level-by-level traversals";
                cout<<"\ng) Number of leaf and non-leaf nodes";
                cout<<"\nh) Display height of tree";
                cout<<"\ni) Create a mirror image of tree";
                cout<<"\nj) Exit";
                cout<<"\n Enter your choice: ";
                cin>>choice;

                if(choice=='a'){
                        int x;
                        cout<<"\nEnter value to be inserted: ";
                        cin>>x;
                        bst.insert(x);
                }else if(choice=='b'){
                        int x;
                        cout<<"\nEnter value to delete: ";
                        cin>>x;
                        bst.deleteNode(x);
                }else if(choice=='c'){
                        int x;
                        cout<<"\nEnter value to delete: ";
                        cin>>x;
                        bst.findAndDeleteByMerging(x);
                }else if(choice=='d'){
                        int x;
                        cout<<"\nEnter value to searched: ";
                        cin>>x;
                        bst.searchKey(x);
                }else if(choice=='e'){
                        cout<<"\nPreorder traversal: ";
                        bst.preOrder();
                        cout<<"\nPostorder traversal: ";
                        bst.postOrder();
                        cout<<"\nInorder traversal: ";
                        bst.inOrder();
                }else if(choice=='f'){
                        cout<<"\nlevel-by-level traversal: ";
                        bst.levelByLevel();
                }else if(choice=='g'){
                        cout<<"\nNumber of leaf nodes: "<<bst.countLeaf();
                        cout<<"\nNumber of non-leaf nodes: "<<bst.countNonLeaf();
                }else if(choice=='h'){
                        bst.heightOfTree();
                }else if(choice=='i'){
                        cout<<"\nMirror:\n";
                        bst.mirrorImage();
                }else if(choice=='j'){
                        break;
                }
        }while(true);

        return 0;
}
