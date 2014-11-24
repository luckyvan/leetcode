#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
* Definition for binary tree with next pointer.
*/
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
	TreeLinkNode() : val(0), left(NULL), right(NULL), next(NULL) {}
};

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
ostream& operator<<(ostream& o, const Interval& i);
bool operator==(const Interval& i1, const Interval& i2);


class Solution{
public:
	/* String */
	bool isValid(string s);
	string convert(string s, int nRows);
	int romanToInt(string s);
	string intToRoman(int i);
	string longestCommonPrefix(vector<string> &strs);
	int atoi(const char *s);
	char* strStr(char *haystack, char *needle);
	vector<int> computePrefixFunction(char* patten); // helper function for KMP
	char* strStr_kmp(char *haystack, char *needle);
	int longestSubstringWithoutRepeatingCharacters(string s);
	bool isMatch(char *text, char*reg);  //regularExpressionMatching
	bool matchStar(char c, char *reg, char *text);
	string reverseWords(string& str);
	vector<string> generateParentheses(int n);
	bool isInterleave(string s1, string s2, string s3);
	int longestValidParentheses(string s);

	/*DP*/
	int distinctSubsequences(string S, string T);
	int uniquePaths(int m, int n);
	int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid);
	int maximamRectangle(vector<vector<int> >& matrix);
	int maximumSubarray(int a[], size_t n);
	int minDistance(string word1, string word2);
	int maxProfit(vector<int>& prices);
	int maxProfitWithMultipleTransactions(vector<int>& prices);
	int maxProfitWithTwoTransactions(vector<int>& prices);
	bool isScramble(string s1, string s2);
	int ladderLength(string start, string end, unordered_set<string> &dict);
	vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict);
	string minWindow(string S, string T);

	/*tree*/
	vector<int> postorderTraversal(TreeNode *root);
	vector<int> preorderTraversal(TreeNode *root);
	vector<int> inorderTraversal(TreeNode *root);
	bool compareTree(TreeNode* root1, TreeNode* root2);
	TreeNode* buildTreePI(vector<int> pre, vector<int> in); //preorder inorder
	TreeNode* buildTreeIP(vector<int> in, vector<int> post); //preorder inorder
	void flatten(TreeNode* root);
	void connect(TreeLinkNode* root);
	void recoverTree(TreeNode *root);
	int maxPathSum(TreeNode *root);

	/*rectangle*/
	int largestRectangleInHistogram(vector<int>& heights);

	/*array*/
	int firstMissingPositive(int array[], int size);
	int findMin(vector<int> &num);
	int findMinWithDuplication(vector<int> &num);
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval);
};