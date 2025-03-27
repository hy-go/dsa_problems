# Activity Selection

"""
You are given a set of activities, each with a start time and a finish time, represented by the arrays start[] and finish[], respectively. 
A single person can perform only one activity at a time, meaning no two activities can overlap. 
Your task is to determine the maximum number of activities that a person can complete in a day.

Example1:
    Input: start[] = [1, 3, 0, 5, 8, 5], finish[] = [2, 4, 6, 7, 9, 9]
    Output: 4
    Explanation: A person can perform at most four activities. The maximum set of activities that can be executed is {0, 1, 3, 4}

Example2:
    Input: start[] = [10, 12, 20], finish[] = [20, 25, 30]
    Output: 1
    Explanation: A person can perform at most one activity.

Example3:
    Input: start[] = [1, 3, 2, 5], finish[] = [2, 4, 3, 6]
    Output: 3
    Explanation: A person can perform activities 0, 1 and 3.
    
Expected Time Complexity: O(nlogn)
Expected Space Complexity: O(n)

Constraints:
    1 ≤ start.size() = finish.size() ≤ 2*10^5
    1 ≤ start[i] ≤ finish[i] ≤ 10^9
"""

class Solution:
    def activitySelection(self, start, finish):
        activities = sorted(zippedList, key=lambda x: (x[1], -x[0]))
        # No need of this, we can also do: activities = sorted(zip(finish, start)),
        # then update the loop accordingly
        count = 0
        endTime = -1
        for start, end in activities:
            if endTime < start:
                endTime = 
                count +=1
        return count

def main():
    t = int(input().strip())  # Number of test cases

    for _ in range(t):
        # Read the start times
        start = list(map(int, input().strip().split()))

        # Read the finish times
        finish = list(map(int, input().strip().split()))

        # Create solution object and call activitySelection
        obj = Solution()
        print(obj.activitySelection(start, finish))
        print("~")


if __name__ == "__main__":
    main()

