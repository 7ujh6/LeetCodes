#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {

        int n = matrix.size();

        // transpose matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int tmp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
        // reverse each row
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = tmp;
            }
        }
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> matrix {
        {1,2,3},{4,5,6},{7,8,9}
    };

    solution.rotate(matrix);

    for (vector<int> v : matrix)
    {
        cout << "[";
        for (int elem : v)
            cout << elem << " ";
        cout << "]";
    }

    return 0;
}