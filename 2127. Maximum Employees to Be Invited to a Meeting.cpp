// 2127. Maximum Employees to Be Invited to a Meeting
// Solved
// Hard
// Topics
// Companies
// Hint
// A company is organizing a meeting and has a list of n employees, waiting to be invited. They have arranged for a large circular table, capable of seating any number of employees.

// The employees are numbered from 0 to n - 1. Each employee has a favorite person and they will attend the meeting only if they can sit next to their favorite person at the table. The favorite person of an employee is not themself.

// Given a 0-indexed integer array favorite, where favorite[i] denotes the favorite person of the ith employee, return the maximum number of employees that can be invited to the meeting.

 

// Example 1:


// Input: favorite = [2,2,1,2]
// Output: 3
// Explanation:
// The above figure shows how the company can invite employees 0, 1, and 2, and seat them at the round table.
// All employees cannot be invited because employee 2 cannot sit beside employees 0, 1, and 3, simultaneously.
// Note that the company can also invite employees 1, 2, and 3, and give them their desired seats.
// The maximum number of employees that can be invited to the meeting is 3. 
// Example 2:

// Input: favorite = [1,2,0]
// Output: 3
// Explanation: 
// Each employee is the favorite person of at least one other employee, and the only way the company can invite them is if they invite every employee.
// The seating arrangement will be the same as that in the figure given in example 1:
// - Employee 0 will sit between employees 2 and 1.
// - Employee 1 will sit between employees 0 and 2.
// - Employee 2 will sit between employees 1 and 0.
// The maximum number of employees that can be invited to the meeting is 3.
// Example 3:


// Input: favorite = [3,0,1,4,1]
// Output: 4
// Explanation:
// The above figure shows how the company will invite employees 0, 1, 3, and 4, and seat them at the round table.
// Employee 2 cannot be invited because the two spots next to their favorite employee 1 are taken.
// So the company leaves them out of the meeting.
// The maximum number of employees that can be invited to the meeting is 4.
 

// Constraints:

// n == favorite.length
// 2 <= n <= 105
// 0 <= favorite[i] <= n - 1
// favorite[i] != i

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 50.5K
// Submissions
// 88.8K
// Acceptance Rate
// 56.9%
// Topics
// Companies
// Hint 1
// Hint 2
// Hint 3
// Similar Questions
// Discussion (166)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved

// 1.4K


// 166




class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<vector<int>> reversedGraph(n);
        for (int person = 0; person < n; ++person) {
            reversedGraph[favorite[person]].push_back(person);
        }

        // Helper function for BFS
        auto bfs = [&](int startNode, unordered_set<int>& visitedNodes) -> int {
            queue<pair<int, int>> q;
            q.push({startNode, 0});
            int maxDistance = 0;
            while (!q.empty()) {
                auto [currentNode, currentDistance] = q.front();
                q.pop();
                for (int neighbor : reversedGraph[currentNode]) {
                    if (visitedNodes.count(neighbor)) continue;
                    visitedNodes.insert(neighbor);
                    q.push({neighbor, currentDistance + 1});
                    maxDistance = max(maxDistance, currentDistance + 1);
                }
            }
            return maxDistance;
        };

        int longestCycle = 0, twoCycleInvitations = 0;
        vector<bool> visited(n, false);

        // Find all cycles
        for (int person = 0; person < n; ++person) {
            if (!visited[person]) {
                unordered_map<int, int> visitedPersons;
                int current = person;
                int distance = 0;
                while (true) {
                    if (visited[current]) break;
                    visited[current] = true;
                    visitedPersons[current] = distance++;
                    int nextPerson = favorite[current];
                    if (visitedPersons.count(nextPerson)) {  // Cycle detected
                        int cycleLength = distance - visitedPersons[nextPerson];
                        longestCycle = max(longestCycle, cycleLength);
                        if (cycleLength == 2) {
                            unordered_set<int> visitedNodes = {current,
                                                               nextPerson};
                            twoCycleInvitations +=
                                2 + bfs(nextPerson, visitedNodes) +
                                bfs(current, visitedNodes);
                        }
                        break;
                    }
                    current = nextPerson;
                }
            }
        }

        return max(longestCycle, twoCycleInvitations);
    }
};