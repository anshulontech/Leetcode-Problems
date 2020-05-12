// https://leetcode.com/problems/flood-fill/

// Time Complexity:-O(N).
// Space Complexity:-O(N).

// Approach:-
//     In this what we are going to do is that we are going to traverse the grid starting from the given starting pixel 
// and traverse to all 4 directions to it. Initially we will store the original colour to a variable so that we can check 
// that is we have to change it or not. Now on moving for  directions if the colour is not same as original colour than 
// we will return from there else chage it's colour and than go for next 4 directions and so on.


class Solution
{
private:
    int original_colour;
    int new_colour;

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        original_colour = image[sr][sc];
        new_colour = newColor;
        image[sr][sc] = new_colour;

        if (original_colour == new_colour)
            return image;
        changecolour(image, sr - 1, sc);
        changecolour(image, sr + 1, sc);
        changecolour(image, sr, sc - 1);
        changecolour(image, sr, sc + 1);

        return image;
    }

    void changecolour(vector<vector<int>> &image, int i, int j)
    {
        if (i < 0 || i == image.size() || j < 0 || j == image[i].size() || image[i][j] != original_colour)
            return;

        image[i][j] = new_colour;

        changecolour(image, i - 1, j);
        changecolour(image, i + 1, j);
        changecolour(image, i, j - 1);
        changecolour(image, i, j + 1);
    }
};