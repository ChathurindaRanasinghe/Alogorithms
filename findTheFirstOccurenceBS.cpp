#include <iostream>


int findFirstOccurrence(int nums[], int n, int target)
{
    int low = 0, high = n - 1;

    int result = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (target == nums[mid])
        {
            result = mid;
            high = mid - 1;
        }

        else if (target < nums[mid]) {
            high = mid - 1;
        }

        else {
            low = mid + 1;
        }
    }

    return result;
}
