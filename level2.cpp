#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

bool tab[2001][2001];

int main()
{
    ios_base::sync_with_stdio(false);

    ifstream inputFile("inputs/level2/level2_5.in");
    ofstream outputFile("outputs/level2/output2_5.out");
    int n;
    inputFile >> n;

    while(n--)
    {
        string line;
        inputFile >> line;
        
        int i = 1000, j = 1000;
        int min_i = i, 
            max_i = i, 
            min_j = j,
            max_j = j;
        tab[i][j] = true;
        
        for (char c : line)
        {
            if (c == 'W')
            {
                ++i;
            } else if (c == 'S')
            {
                --i;
            } else if (c == 'A')
            {
                --j;
            } else if (c == 'D')
            {
                ++j;
            }
            tab[i][j] = true;
            
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
        outputFile << width << " " << height << endl;
    
        }
}