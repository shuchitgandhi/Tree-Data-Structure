#include <iostream>
using namespace std;
class BST{
	private:
	struct node{
		int data;
		node *left;
		node *right;
		node *parent;
	}*root;
	int rank;
	public:
	BST(){
		root = NULL;
	}
	node* search(int key){
		node *temp = root;
		while(temp != NULL){
			if(temp->data == key){
				// cout<<"Element found\n";
				return temp;
			}
			else if (key > temp->data){
				temp = temp->right;
			}
			else{
				temp = temp->left;
			}
		}
		cout<<"Element not found\n";
		return NULL;
	}
	void insert(int key){

		node *newNode = new node;
		newNode->data = key;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->parent = NULL;
		
		if(root == NULL){
			root = newNode;
		}
		else{
			node *temp = root;
			node *father = root;
			while(temp != NULL){
				father = temp;
				if(key > temp->data){
					temp = temp->right;
				}
				else{
					temp = temp->left;
				}
				if(temp != NULL)
					temp->parent = father;
			}
			temp = newNode;
			newNode->parent = father;
			if(key < father->data)
				father->left = newNode;
			else
				father->right = newNode;
		}
	}

	int max (int a, int b){
		return a>b ? a : b; 
	}

	int height(node *t){
		if(t->left != NULL && t->right != NULL)
			return 1 + max(height(t->left), height(t->right));
		else if(t->left != NULL)
			return 1 + height(t->left);
		else if(t->right != NULL)
			return 1 + height(t->right);
		else
			return 0;
	}

	int heightNode(int key){
		node *t = search(key);
		return height(t);
	} 

	

	int depthNode (int key){
		int depth = 0;
		node *t = search(key);
		while(t->parent != NULL){
			depth++;
			t = t->parent;
		}
		return depth;
	}

	int getRank(node *t, int key){
		if(t != NULL){
			getRank(t->left, key);
			if(t->data != key)
				rank++;
			else
				return rank;
			getRank(t->right, key);
		}
	}

	int findRank(int key){
		node *t = search(key);
		rank = 0;
		return	getRank(t, key);
	}

};

int main(int argc, char** argv){
	BST b1;
	b1.insert(20);
	b1.insert(10);
	b1.insert(30);
	b1.insert(6);
	b1.insert(3);
	
	cout<<"\nHeight of Subtree --> "<<b1.heightNode(20)<<endl;
	cout<<"\nHeight of 6 --> "<<b1.heightNode(6)<<endl;
	cout<<"\nDepth of 6 --> "<<b1.depthNode(6)<<endl;
	cout<<"\nRank of 6 --> "<<b1.findRank(6)<<endl;
	
	getchar();
	return 0;
}
