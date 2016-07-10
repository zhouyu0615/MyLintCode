#include <iostream>
#include <vector>
#include <sstream>


using namespace std;



/* Definition of TreeNode:*/
class TreeNode {
 public:
     int val;
     TreeNode *left, *right;
     TreeNode(int val) {
         this->val = val;
         this->left = this->right = NULL;
     }
};

class Solution {
public:
	/**
	* This method will be invoked first, you should design your own algorithm
	* to serialize a binary tree which denote by a root node to a string which
	* can be easily deserialized by your own "deserialize" method later.
	*/
	string serialize(TreeNode *root) {
		// write your code here
		
		if (root==NULL)
		{
			treeStr.append("*,");
			return  treeStr;
		}

		treeStr.append(IntToString(root->val));
		treeStr.append(",");

		serialize(root->left);
		serialize(root->right);
		return treeStr;
	}

	/**
	* This method will be invoked second, the argument data is what exactly
	* you serialized at method "serialize", that means the data is not given by
	* system, it's given by your own serialize method. So the format of data is
	* designed by yourself, and deserialize it here as you serialize it in
	* "serialize" method.
	*/
	TreeNode *deserialize(string data) {
		// write your code here
		pos = 0;
		TreeNode* root;
		myDes(&root);
		return root;
	}
private:
	string treeStr;

	string IntToString(int a)
	{
		string str;
		stringstream ss;
		ss << a;
		ss >> str;
		return str;
	}


	void myDes(TreeNode** pRoot)
	{
		int number;
		
		if (ReadData(treeStr,number))
		{
			*pRoot = new TreeNode(number);
			(*pRoot)->val = number;
			myDes(&(*pRoot)->left);
			myDes(&(*pRoot)->right);
		}
	}


	static int pos;
	bool ReadData(string& str, int &Num)
	{
		if (pos==str.length())
		{
			return false;
		}

		if (str[pos]=='*')
		{
			pos += 2;
			return false;
		}

		int num = 0;
		while (str[pos]!=',')
		{   
			if (str[pos]>='0'&&str[pos]<='9')
			{
				num = num * 10 + (str[pos] - '0');
			}			
			pos++;
		}
		Num = num;
		pos++;
		return true;
	}
};




class Solution {
public:
	/**
	* This method will be invoked first, you should design your own algorithm
	* to serialize a binary tree which denote by a root node to a string which
	* can be easily deserialized by your own "deserialize" method later.
	*/
	string serialize(TreeNode *root) {
		// write your code here
		vector<int> pre, in;
		inOrder(root, in);
		preOrder(root, pre);
		stringstream ss;
		for (int i = 0; i < in.size(); ++i) {
			ss << in[i];
			if (i != in.size() - 1) {
				ss << ' ';
			}
		}
		ss << '#';
		for (int i = 0; i < pre.size(); ++i) {
			ss << pre[i];
			if (i != pre.size() - 1) {
				ss << ' ';
			}
		}
		return ss.str();
	}

	void inOrder(TreeNode *curr, vector<int> &v) {
		if (!curr) return;
		inOrder(curr->left, v);
		v.push_back(curr->val);
		inOrder(curr->right, v);
	}

	void preOrder(TreeNode *curr, vector<int> &v) {
		if (!curr) return;
		v.push_back(curr->val);
		preOrder(curr->left, v);
		preOrder(curr->right, v);
	}

	/**
	* This method will be invoked second, the argument data is what exactly
	* you serialized at method "serialize", that means the data is not given by
	* system, it's given by your own serialize method. So the format of data is
	* designed by yourself, and deserialize it here as you serialize it in
	* "serialize" method.
	*/
	TreeNode *deserialize(string data) {
		// write your code here
		if (data == "#") return NULL;
		int br;
		for (br = 0; br < data.length() && data[br] != '#'; ++br);
		string front = data.substr(0, br);
		string rear = data.substr(br + 1, data.length() - br - 1);
		vector<int> in = getVector(front);
		vector<int> pre = getVector(rear);
		TreeNode *root = NULL;
		createTree(in, 0, in.size() - 1, pre, 0, pre.size() - 1, root);
		return root;
	}

	vector<int> getVector(string s) {
		vector<int> v;
		stringstream ss;
		ss << s;
		int count = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == ' ') ++count;
		}
		++count;
		for (int i = 0; i < count; ++i) {
			int num;
			ss >> num;
			v.push_back(num);
		}
		return v;
	}

	void createTree(vector<int> &in, int ii, int ij, vector<int> &pre, int pi, int pj, TreeNode *&curr) {
		if (ii > ij && pi > pj) {
			curr = NULL;
			return;
		}
		int mid = pre[pi];
		int br;
		for (br = ii; br <= ij; ++br) {
			if (in[br] == mid) break;
		}
		curr = new TreeNode(mid);
		createTree(in, ii, br - 1, pre, pi + 1, pi + br - ii, curr->left);
		createTree(in, br + 1, ij, pre, pi + br - ii + 1, pj, curr->right);
	}
};






int main()
{
	Solution testCase;
	getchar();
	return 0;
}
