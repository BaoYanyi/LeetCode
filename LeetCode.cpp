#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

char ReverseDirection(char dir)
{
	switch (dir)
	{
	case 'R':
		return 'L';
	case 'L':
		return 'R';
	case 'U':
		return 'D';
	case 'D':
		return 'U';
	}
}

// code 657
bool judgeCircle(string moves) 
{
	map<char, int> direction;
	direction['R'] = 0;
	direction['L'] = 0;
	direction['U'] = 0;
	direction['D'] = 0;
	for (int i = 0; i < moves.size(); i++)
	{
		direction[moves[i]]++;
		direction[ReverseDirection(moves[i])]--;
	}
	return (direction['R'] == 0 && direction['L'] == 0 && direction['U'] == 0 && direction['D'] == 0);
}

// code 461
int hammingDistance(int x, int y) 
{
	int dif = 0;
	do 
	{
		if ((x & 1) != (y & 1))
			dif++;
		x = x >> 1;
		y = y >> 1;
	} while (x > 0 || y > 0);
	return dif;
}

// code 804
int uniqueMorseRepresentations(vector<string>& words) 
{
	map<string, int> result;
	string list[26] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
	for (int i = 0; i < words.size(); i++)
	{
		string des = "";
		for (int j = 0; j < words[i].size(); j++)
		{
			des = des + list[(words[i][j] - 'a')];
		}
		result[des] = 0;
	}
	return result.size();
}

// code 617
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void MergeChild(TreeNode* t1, TreeNode* t2)
{
	if (t2)
	{
		t1->val = t1->val + t2->val;

		if (t1->left == NULL && t2->left)
			t1->left = new TreeNode(0);

		if (t1->right == NULL && t2->right)
			t1->right = new TreeNode(0);

		MergeChild(t1->left, t2->left);
		MergeChild(t1->right, t2->right);
	}
}

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
	if (t1 == NULL && t2)
		t1 = new TreeNode(0);
	TreeNode* loot = t1;
	MergeChild(t1, t2);
	return loot;
}


int main()
{

}