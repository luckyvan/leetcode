// Source : https://oj.leetcode.com/problems/max-points-on-a-line/
// Author : Fan Chou
// Date   : 2014-12-02

/**********************************************************************************
*
* Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*
**********************************************************************************/
#include "../Solution.h"
#include <map>
#include <set>

struct Ratio
{
	int x_;
	int y_;
	Ratio(int x, int y) :x_(x), y_(y) {}

};

bool operator<(Ratio r1, Ratio r2)
{
	return r1.x_*r2.y_ < r1.y_* r2.x_;
}

bool operator == (Ratio r1, Ratio r2)
{
	return r1.x_*r2.y_ == r1.y_* r2.x_;
}

bool operator<(Point p1, Point p2)
{
	return std::tie(p1.x, p1.y) < std::tie(p2.x, p2.y);
}

bool operator==(Point p1, Point p2)
{
	return p1.x == p2.x && p1.y == p2.y;
}

// O(n^2) time complexity solution
int Solution::maxPoints(vector<Point> &points)
{
	int max = 0;

	map<Ratio, vector<set<Point> > > ratio_lines;

	for (size_t i = 0; i < points.size(); i++)
	{
		for (size_t j = i + 1; j < points.size(); j++)
		{
			Point p1 = points[i];
			Point p2 = points[j];
			Ratio r = Ratio(p2.x - p1.x, p2.y - p1.y);
			set<Point> new_line = { p1, p2 };
			if (ratio_lines.find(r) == ratio_lines.end()) //new ratio
			{
				vector<set<Point> > new_lines = {new_line};
				ratio_lines[r] = new_lines;
			}
			else 
			{
				vector<set<Point> >& lines = ratio_lines[r];
				bool find = false;
				for (vector<set<Point> >::iterator it = lines.begin(); it != lines.end(); it++)
				{
					set<Point>& line = *it;
					Point p = *line.begin();
					if (
						(p == p1) ||
						(p == p2) ||
						(Ratio(p.x - p1.x, p.y - p1.y) == r)
						)
					{
						line.insert(p1);
						line.insert(p2);
						find = true;
						break;
					}
				}

				if (!find)
				{
					lines.push_back(
						set<Point>({p1, p2})
						);
				}
			}
			
		}
	}

	for (
		map<Ratio, vector<set<Point> > >::iterator it = ratio_lines.begin();
		it != ratio_lines.end();
	    it++
		)
	{
		for each (set<Point> line in (*it).second)
		{
			size_t size = line.size();
			max = max > size ? max : size;
		}
	}

	return max;
}

