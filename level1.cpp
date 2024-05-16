#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    ifstream inputFile("inputs/level1/level1_5.in");
    ofstream outputFile("outputs/level1/output1_5.out");
    
    int n;
    inputFile >> n;
    
    

    while (n--)
    {
        string line;
        inputFile >> line;
        int w, s, a, d;
        w = count(line.begin(), line.end(), 'W');
        s = count(line.begin(), line.end(), 'S');
        a = count(line.begin(), line.end(), 'A');
        d = count(line.begin(), line.end(), 'D');
        outputFile << w << " " << d << " " << s << " " << a;
        outputFile << endl;
    }

    outputFile.close();

}
