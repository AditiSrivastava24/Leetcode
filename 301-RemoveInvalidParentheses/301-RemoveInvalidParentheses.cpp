// Last updated: 10/8/2026, 10:12:50 AM
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

class Solution {
private:
    // Helper function to check if a string has valid parentheses
    bool isValid(const std::string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) return false; // More closing than opening
            }
        }
        return count == 0;
    }

public:
    std::vector<std::string> removeInvalidParentheses(std::string s) {
        std::vector<std::string> result;
        if (s.empty()) return {""};

        std::queue<std::string> q;
        std::unordered_set<std::string> visited;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            std::string current = q.front();
            q.pop();

            // If a valid string is found, we process the current level completely
            if (isValid(current)) {
                result.push_back(current);
                found = true;
            }

            // If we found a valid string at this level, do not generate deeper states
            if (found) continue;

            // Generate all possible states by removing one parenthesis
            for (int i = 0; i < current.length(); i++) {
                if (current[i] != '(' && current[i] != ')') continue;

                // Create a new string by removing the character at index i
                std::string nextState = current.substr(0, i) + current.substr(i + 1);

                // If not visited, push to queue
                if (visited.find(nextState) == visited.end()) {
                    visited.insert(nextState);
                    q.push(nextState);
                }
            }
        }

        return result;
    }
};
