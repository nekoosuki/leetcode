#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> helper(vector<vector<int>>& image, int sr, int sc,
                               int newColor, int src) {
        int r = image.size(), c = image[0].size();
        image[sr][sc] = newColor;
        if (sr > 0 && image[sr-1][sc]==src) image = helper(image, sr - 1, sc, newColor, src);
        if (sr < r - 1&& image[sr+1][sc]==src) image = helper(image, sr + 1, sc, newColor, src);
        if (sc > 0&& image[sr][sc-1]==src) image = helper(image, sr, sc - 1, newColor, src);
        if (sc < c - 1&& image[sr][sc+1]==src) image = helper(image, sr, sc + 1, newColor, src);
        return image;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int src = image[sr][sc];
        if(newColor == src)return image;
        image[sr][sc] = newColor;
        int r = image.size(), c = image[0].size();
        if (sr > 0 && image[sr-1][sc]==src) image = helper(image, sr - 1, sc, newColor, src);
        if (sr < r - 1&& image[sr+1][sc]==src) image = helper(image, sr + 1, sc, newColor, src);
        if (sc > 0&& image[sr][sc-1]==src) image = helper(image, sr, sc - 1, newColor, src);
        if (sc < c - 1&& image[sr][sc+1]==src) image = helper(image, sr, sc + 1, newColor, src);
        return image;
    }
};