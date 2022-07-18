#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;
};


class BST
{
public:
	BST()
	{
		root = NULL;
	}

	void insert(int element)
	{
		node* newptr = new node;
		newptr->data = element;
		newptr->left = NULL;
		newptr->right = NULL;
		//cout << "Here" << endl;

		if (root == NULL)
		{
			root = newptr;
		}
		else
		{
			node* p = root;
			node* parent = NULL;
			while ((p != NULL) && (p->data != element)) //find the right location for the new node
			{
				if (element < p->data)
				{
					parent = p;
					p = p->left;
				}
				else
				{
					parent = p;
					p = p->right;
				}
			}

			if (p == NULL) 
			{
				if (element < parent->data)
					parent->left = newptr;
				else
					parent->right = newptr;
			}
			else
				cout << "node duplicate!" << endl;
		}
	}

	void remove(int element)
	{
		node* p = root;
		node* parent = NULL;
		while ((p != NULL) && (p->data != element)) //find the correct location for the new node
		{
			if (element < p->data)
			{
				parent = p;
				p = p->left;
			}
			else
			{
				parent = p;
				p = p->right;
			}
		}

		if (p->left == NULL && p->right == NULL) //case 1
		{
			if (element < parent->data)
				parent->left = NULL;
			else
				parent->right = NULL;
			delete p;
		}

		else if (p->left != NULL && p->right == NULL) //case 2
		{
			if (element < parent->data)
				parent->left = p->left;
			else
				parent->right = p->left;
			delete p;
		}

		else if (p->left == NULL && p->right != NULL) //case 2
		{
			if (element < parent->data)
				parent->left = p->right;
			else
				parent->right = p->right;
			delete p;

		}

		else //case 3
		{
			int min_of_right_child = findmin(p->right);
			remove(min_of_right_child);
			p->data = min_of_right_child;
		}


	}

	int findmin(node* p)
	{
		while (p->left != NULL)
			p = p->left;
		return p->data;
	}

	int findmax(node* p)
	{
		while (p->right != NULL)
			p = p->right;
		return p->data;
	}

	void inorder(node* p)
	{
		if (p != NULL)
		{
			inorder(p->left);
			cout << p->data << " ";
			inorder(p->right);
		}

	}

	void preorder(node* p)
	{
		if (p != NULL)
		{
			cout << p->data << " ";
			preorder(p->left);
			preorder(p->right);
		}
	}

	void postorder(node* p)
	{
		if (p != NULL)
		{
			postorder(p->left);
			postorder(p->right);
			cout << p->data << " ";
		}
	}

	void traversal()
	{
		cout << " Min value: " << findmin(root);
		cout << " Max value: " << findmax(root);
		cout << " Inorder: ";
		inorder(root);
		cout << " Preorder: ";
		preorder(root);
		cout << " Postorder: ";
		postorder(root);
		cout << endl;
	}

	void search(int x)
	{
		
		node* t = root; //Starts target at the root

		cout << "\nSearching for " << x << ": " << t->data << "   ";

		while (t != NULL)  //Progresses through the tree until it reaches the end
		{
			if (x < t->data) // if the target is less than the value at the node, it moves to the left
			{
				t = t->left;
				cout << t->data << "   ";

				if (t->data == x) //Prevents the display from showing the target twice at the end
				{
					break;
				}
			}

			else if (x > t->data) // if the target is greater than the value at the node, it moves to the right
			{
				t = t->right;
				cout << t->data << "   ";

				if (t->data == x) //Prevents the display from showing the target twice at the end
				{
					break;
				}
			}

		}

		cout << endl;

	}

private:
	node* root;


};



void main()
{
	BST* t1 = new BST();
	t1->insert(5);
	t1->insert(8);
	t1->insert(3);
	t1->insert(1);
	t1->insert(4);
	t1->insert(9);
	t1->insert(18);
	t1->insert(20);
	t1->insert(19);
	t1->insert(2);
	t1->traversal();
	t1->search(3);
	t1->search(18);
	t1->search(19);
	t1->remove(9);
	t1->traversal();
	t1->remove(2);
	t1->traversal();
	t1->remove(8);
	t1->traversal();
	t1->remove(3);
	t1->traversal();
	t1->remove(5);
	t1->traversal();

}