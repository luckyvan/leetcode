// Source : https://oj.leetcode.com/problems/insert-interval/
// Author : Fan Chou
// Date   : 2014-08-26

/********************************************************************************** 
* 
* Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
* 
* You may assume that the intervals were initially sorted according to their start times.
* 
* Example 1:
* Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
* 
* Example 2:
* Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
* 
* This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
* 
*               
**********************************************************************************/

#include "../Solution.h"

//just reuse the solution of "Merge Intervals", quite straight forward
bool operator==(const Interval& i1, const Interval& i2)
{
	return (i1.start == i2.start) && (i1.end == i2.end);
}

ostream& operator<<(ostream& o, const Interval& i)
{
	return o<<i.start << " " << i.end << endl;
}

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
	//[first_overlapping .. last_overlapping) 
	size_t first_overlapping = -1;
	size_t last_overlapping = -1;

	for (size_t i = 0; i < intervals.size(); i++)
	{
		if ((first_overlapping == -1) && 
			(intervals[i].end > newInterval.start))
		{
			first_overlapping = i;
			
		}
		if ((last_overlapping == -1) &&
			(intervals[i].start > newInterval.end))
		{
			last_overlapping = i;
		}
	}


	if (-1 == last_overlapping) // all intervals is before newInterval
	{
		vector<Interval> newIntervals(intervals.begin(), intervals.end());
		newIntervals.push_back(newInterval);
		return newIntervals;
	}
	else
	{
		vector<Interval> newIntervals(intervals.begin(), intervals.begin() + first_overlapping);

		if (first_overlapping != last_overlapping) //not empty, merge
		{
			Interval first = intervals[first_overlapping];
			Interval last = intervals[last_overlapping - 1];

			int start = first.start < newInterval.start ? first.start : newInterval.start;
			int end = last.end > newInterval.end ? last.end : newInterval.end;
			newIntervals.push_back(Interval(start, end));
		}
		else // all intervals after new interval
		{
			newIntervals.push_back(newInterval);
		}

		for (size_t i = last_overlapping; i < intervals.size(); i++)
		{
			newIntervals.push_back(intervals[i]);
		}
		return newIntervals;
	}
}

