#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node* newNode(int data){
	struct node* Node = (struct node*)malloc(sizeof(struct node));
	Node->data =data;
	Node->left = NULL;
	Node->right =NULL;
	return (Node);
}

bool check_two_binary_tree(node* root1 , node* root2){
	if(root1 ==NULL && root2 == NULL)
		return true;
	if(root1 ==NULL || root2 ==NULL)
		return false;
	
	if(root1->data = root2->data && check_two_binary_tree(root1->left ,root2->left) && check_two_binary_tree(root1->right,root2->right))
		return true;
}
int main(){
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
	struct node* root1 = newNode(1);
	root1->left = newNode(2);
	root1->right = newNode(3);
	root1->left->left = newNode(4);
	root1->left->right = newNode(5);
	if(check_two_binary_tree( root, root1))
		cout <<"given binary trees are same\n";
	else
		cout << "given binary trees are not equal\n"; 
	return 0;
}
