
#include <vector>
using namespace std;

class Solution {
    
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLength) {

        sort(tiles.begin(), tiles.end(), [](const vector<int>& v1, const vector<int>& v2){return v1[0] < v2[0];});
        int currentCover = (tiles[0][1] - tiles[0][0] + 1 >= carpetLength) ? carpetLength : (tiles[0][1] - tiles[0][0] + 1);
        int maxCover = currentCover;
        int head = 1;
        int tail = 0;

        while (tail < tiles.size() && head < tiles.size() && maxCover < carpetLength) {

            if (tiles[head][1] - tiles[tail][0] + 1 <= carpetLength) {
                currentCover += tiles[head][1] - tiles[head][0] + 1;
                maxCover = max(maxCover, currentCover);
                ++head;
            } else {
                int possiblePartialCoverOverCurrentHead = carpetLength - (tiles[head][0] - tiles[tail][0]);
                maxCover = max(maxCover, currentCover + possiblePartialCoverOverCurrentHead);
                currentCover = currentCover - (tiles[tail][1] - tiles[tail][0] + 1);
                ++tail;
            }
        }
        return maxCover;
    }
};
