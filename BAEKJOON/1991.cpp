#include <iostream>
#include <string>
using namespace std;
#define NULLL 0

template <typename T>
class TreeNode
{
private:
	T data;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode(T data = 0, TreeNode* left = NULL, TreeNode* right = NULL)
	{
		this->data = data;
		this->left = left;
		this->right = right;
	}

	void setleft(TreeNode<T>* target)
	{
		this->left = target;
	}
	void setright(TreeNode<T>* target)
	{
		this->right = target;
	}

	TreeNode<T> getleft()
	{
		return this->left;
	}
	TreeNode<T> getright()
	{
		return this->right;
	}
	T getdata()
	{
		return this->data;
	}
};

template <typename T>
class Tree {
private:
	TreeNode<T>* root;
public:
	Tree(T data = 0) {
		root = new TreeNode<T>(data);
	}

	TreeNode<T>* getroot()
	{
		return root;
	}

	//1이 왼쪽 0이 오른쪽
	void search(T target,TreeNode<T>* current,int side)
	{
		if (current != NULL)
		{
			if (current.getdata() == target)
			{
				if (side)
				{
					TreeNode<T>* temp = new TreeNode<T>(target);
					current.setleft(temp);
				}
				else
				{
					TreeNode<T>* temp = new TreeNode<T>(target);
					current.setright(temp);
				}
			}
			search(target,current.getleft(),side);
			cout << current.getdata() << endl;
			search(target,current.getright(),side);

		}
	}
};


int main()
{
	int n;
	string a, b, c;
	scanf("%d", &n);
	Tree<string> tree("A");

	for (int i = 0; i < n; i++)
	{
		scanf("%s %s %s", &a, &b, &c);
		if (b.compare("."))
		{
			tree.search(b, tree.getroot(), 1);
		}
		if (c.compare("."))
		{
			tree.search(c, tree.getroot(), 0);
		}
	}


	return 0;
}