#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        map<int, int> freq;
        for (int card : hand) {
            freq[card]++;
        }

        // Always process from the smallest available card
        while (!freq.empty()) {
            int start = freq.begin()->first;  // smallest card

            // Try to create a group starting from 'start'
            for (int i = 0; i < groupSize; ++i) {
                int card = start + i;

                if (freq[card] == 0) return false; // missing or used up
                freq[card]--;

                // Clean up to keep map small
                if (freq[card] == 0) {
                    freq.erase(card);
                }
            }
        }

        return true;
    }
};
