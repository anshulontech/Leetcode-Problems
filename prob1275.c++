// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/description/

class Solution
{
public:
    string tictactoe(vector<vector<int>> &moves)
    {
        vector<string> grid;

        for (int i = 0; i < 3; i++)
            grid.push_back("   ");

        int i = 0;

        for (; i < 4 && i < moves.size(); i++)
            if (i % 2 == 0)
                grid[moves[i][0]][moves[i][1]] = 'X';
            else
                grid[moves[i][0]][moves[i][1]] = 'O';

        for (; i < moves.size(); i++)
            if (i % 2 == 0)
            {
                grid[moves[i][0]][moves[i][1]] = 'X';
                string help = checkWin(grid);

                if (help != " ")
                    return help;
            }
            else
            {
                grid[moves[i][0]][moves[i][1]] = 'O';
                string help = checkWin(grid);

                if (help != " ")
                    return help;
            }

        if (moves.size() == 9)
            return "Draw";
        else
            return "Pending";
    }

    string checkWin(vector<string> &grid)
    {
        if (grid[0][0] != ' ' && grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2])
            if (grid[0][0] == 'X')
                return "A";
            else
                return "B";

        if (grid[1][0] != ' ' && grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2])
            if (grid[1][0] == 'X')
                return "A";
            else
                return "B";

        if (grid[2][0] != ' ' && grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2])
            if (grid[2][0] == 'X')
                return "A";
            else
                return "B";

        if (grid[0][0] != ' ' && grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0])
            if (grid[0][0] == 'X')
                return "A";
            else
                return "B";

        if (grid[0][1] != ' ' && grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1])
            if (grid[0][1] == 'X')
                return "A";
            else
                return "B";

        if (grid[0][2] != ' ' && grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2])
            if (grid[0][2] == 'X')
                return "A";
            else
                return "B";

        if (grid[0][0] != ' ' && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
            if (grid[0][0] == 'X')
                return "A";
            else
                return "B";

        if (grid[0][2] != ' ' && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
            if (grid[0][2] == 'X')
                return "A";
            else
                return "B";

        return " ";
    }
};