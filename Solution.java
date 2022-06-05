
import java.util.Arrays;

public class Solution {

    public int maximumWhiteTiles(int[][] tiles, int carpetLength) {

        Arrays.sort(tiles, (x, y) -> x[0] - y[0]);
        int currentCover = (tiles[0][1] - tiles[0][0] + 1 >= carpetLength) ? carpetLength : (tiles[0][1] - tiles[0][0] + 1);
        int maxCover = currentCover;
        int head = 1;
        int tail = 0;

        while (tail < tiles.length && head < tiles.length && maxCover < carpetLength) {

            if (tiles[head][1] - tiles[tail][0] + 1 <= carpetLength) {
                currentCover += tiles[head][1] - tiles[head][0] + 1;
                maxCover = Math.max(maxCover, currentCover);
                ++head;
            } else {
                int possiblePartialCoverOverCurrentHead = carpetLength - (tiles[head][0] - tiles[tail][0]);
                maxCover = Math.max(maxCover, currentCover + possiblePartialCoverOverCurrentHead);
                currentCover = currentCover - (tiles[tail][1] - tiles[tail][0] + 1);
                ++tail;
            }
        }
        return maxCover;
    }
}
