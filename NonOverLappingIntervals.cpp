#include <bits/stdc++.h>
using namespace std;

class Interval {
public:
    int start, end;
    bool operator < (const Interval& interval) {
        return start < interval.start;
    }
};

vector<Interval> findFreeIntervals(vector<Interval> intervalsArr) {
    vector<Interval> freeIntervals;
    sort(intervalsArr.begin(), intervalsArr.end());
    for (int i = 1; i < intervalsArr.size() - 1; i++) {
        if (intervalsArr[i - 1].end < intervalsArr[i].start && intervalsArr[i].end < intervalsArr[i + 1].start)
            freeIntervals.emplace_back(intervalsArr[i]);
    }
    return freeIntervals;
}

//function to print the free intervals
void printFreeIntervals(vector<Interval> freeIntervals) {
    for (int i = 0; i < freeIntervals.size(); i++) {
        cout << freeIntervals[i].start << " " << freeIntervals[i].end << endl;
    }
}


int main()
{
    vector<Interval> intervalsArr = { {1,3},{2,5},{6,10},{12,15},{11,12},{13,16} };
    printFreeIntervals(findFreeIntervals(intervalsArr));


}