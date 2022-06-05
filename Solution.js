
/**
 * @param {number[][]} tiles
 * @param {number} carpetLength
 * @return {number}
 */
var maximumWhiteTiles = function (tiles, carpetLength) {

    tiles.sort((x, y) => x[0] - y[0]);
    let currentCover = (tiles[0][1] - tiles[0][0] + 1 >= carpetLength) ? carpetLength : (tiles[0][1] - tiles[0][0] + 1);
    let maxCover = currentCover;
    let head = 1;
    let tail = 0;

    while (tail < tiles.length && head < tiles.length && maxCover < carpetLength) {

        if (tiles[head][1] - tiles[tail][0] + 1 <= carpetLength) {
            currentCover += tiles[head][1] - tiles[head][0] + 1;
            maxCover = Math.max(maxCover, currentCover);
            ++head;
        } else {
            let possiblePartialCoverOverCurrentHead = carpetLength - (tiles[head][0] - tiles[tail][0]);
            maxCover = Math.max(maxCover, currentCover + possiblePartialCoverOverCurrentHead);
            currentCover = currentCover - (tiles[tail][1] - tiles[tail][0] + 1);
            ++tail;
        }
    }
    return maxCover;
};
