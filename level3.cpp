#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    ifstream inputFile("inputs/level3/level3_5.in");
    ofstream outputFile("outputs/level3/output3_5.out");
    int lawns;
    inputFile >> lawns;
    while (lawns--)
    {
        bool is_valid = true;
        int a, b;
        inputFile >> a >> b;
        
        int tree_x = -1, tree_y = -1;
        char tab[b][a];
        for (int i = 0; i < b; ++i)
        {
            for (int j = 0; j < a; ++j)
            {
                inputFile >> tab[i][j];
                
                if (tab[i][j] == 'X')
                {
                    tree_x = i;
                    tree_y = j;
                }
            }
            
        }

        // linia z trawnikiem 1.2
        string line;
        inputFile >> line;
        
        bool visited[2003][2003] = {false};
        for (int i = 0; i < 2003; i++)
        {
            visited[i][0] = true;
            visited[i][2002] = true;
            visited[0][i] = true;
            visited[2002][i] = true;
        }
        int i = 1001, j = 1001;
        int min_i = 999999999,
            max_i = 0,
            min_j = 999999999,
            max_j = 0;
        visited[i][j] = true;

        for (char c : line)
        {
            if (c == 'W')
            {
                --i;
            }
            else if (c == 'S')
            {
                ++i;
            }
            else if (c == 'A')
            {
                --j;
            }
            else if (c == 'D')
            {
                ++j;
            }

            if (visited[i][j])
            {
                is_valid = false;
                break;
            }
            else
            {
                visited[i][j] = true;
            }

            if (i < min_i)
            {
                min_i = i;
            }
            if (i > max_i)
            {
                max_i = i;
            }
            if (j < min_j)
            {
                min_j = j;
            }
            if (j > max_j)
            {
                max_j = j;
            }
        }
        int width, height;
        width = max_j - min_j + 1;
        height = max_i - min_i + 1;
        if (width != a || height != b)
        {
            is_valid = false;
        }

        if (is_valid)
        {
            int counter = 0;
            for (int x = min_i; x <= max_i; ++x)
            {
                for (int y = min_j; y <= max_j; ++y)
                {
                    if (!visited[x][y])
                    {
                        ++counter;
                        if (!(x - min_i == tree_x && y - min_j == tree_y))
                        {
                            is_valid = false;
                            break;
                        }
                    }
                }
            }
            if (is_valid)
            {

                if (!counter)
                {
                    is_valid = false;
                }
            }
        }

        if (is_valid)
            outputFile << "VALID" << endl;
        else
            outputFile << "INVALID" << endl;
    }

    outputFile.close();
}