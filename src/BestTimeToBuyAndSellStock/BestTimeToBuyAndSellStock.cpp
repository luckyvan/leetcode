// Source : https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Author : Fan Chou
// Date   : 2014-11-08

/**********************************************************************************
*
* Say you have an array for which the ith element is the price of a given stock on day i.
*
* If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock),
* design an algorithm to find the maximum profit.
*
**********************************************************************************/
#include "../Solution.h"

int Solution::maxProfit(vector<int> &prices) {

	int max = 0;
	int cur_min = prices[0];
	for (int i = 0; i < prices.size(); i++) {
		if (prices[i] < cur_min)
		{
			cur_min = prices[i];
		}
		else
		{
			int profit = prices[i] - cur_min;
			max = (profit > max) ? profit : max;
		}
	}

	return max;

}


// Source : https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Author : Fan Chou
// Date   : 2014-11-08
/**********************************************************************************
*
* Say you have an array for which the ith element is the price of a given stock on day i.
*
* Design an algorithm to find the maximum profit. You may complete as many transactions
* as you like (ie, buy one and sell one share of the stock multiple times). However,
* you may not engage in multiple transactions at the same time (ie, you must sell the
* stock before you buy again).
*
**********************************************************************************/

int Solution::maxProfitWithMultipleTransactions(vector<int> &prices){
	//Since one can only buy after sell a stock, we should find all asending days to 
	//maxify profit. That equals to accumulate all adjcent positive profit
	vector<int> delta;
	for (size_t i = 1; i < prices.size(); i++)
	{
		delta.push_back(prices[i] - prices[i - 1]);
	}

	int profit = 0;
	for (int i = 0; i < delta.size(); i++)
	{
		if (delta[i] > 0) profit += delta[i];
	}
	return profit;
}

// Source : https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// Author : Fan Chou
// Date   : 2014-11-08

/**********************************************************************************
*
* Say you have an array for which the ith element is the price of a given stock on day i.
*
* Design an algorithm to find the maximum profit. You may complete at most two transactions.
*
* Note:
* You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*
**********************************************************************************/

template<class T>
vector<int> maxProfits(T begin, T end)
{
	vector<int> maxProfits;
	int cur_min = *begin;
	int max = 0;
	for (T i = begin; i != end; i++) {
		if (*i < cur_min)
		{
			cur_min = *i;
		}
		else
		{
			int profit = *i - cur_min;
			max = (profit > max) ? profit : max;
			maxProfits.push_back(max);
		}
	}

	return maxProfits;
}

int Solution::maxProfitWithTwoTransactions(vector<int>& prices)
{
	//divide-and-conquer
	// divide: divide the array into two sub arrays [0..i], [i+1, n], find the max profits in them.
	// conquer: find the maximum out come from divide stage in all possible i position.
	vector<int> forwardMaxProfits = maxProfits(prices.begin(), prices.end());
	vector<int> backwardMaxProfits = maxProfits(prices.rbegin(), prices.rend());

	int max = 0;
	vector<int>::iterator forward_it = forwardMaxProfits.begin();
	vector<int>::reverse_iterator backward_it = backwardMaxProfits.rbegin();
	for (; forward_it != forwardMaxProfits.end(); forward_it++, backward_it++)
	{
		int sum = *forward_it + *backward_it;
		max = max > sum ? max : sum;
	}
	return max;
}