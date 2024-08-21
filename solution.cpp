#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int value;
            while (true) {
                cout << "Enter item " << i + 1 << "X" << j + 1 << " (0 or 1): ";
                cin >> value;
                if (value == 0 || value == 1) {
                    matrix[i][j] = value;
                    break;
                } else {
                    cout << "Invalid input. Please enter 0 or 1." << endl;
                }
            }
        }
    }

    vector<vector<int>> newMatrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            pair<int, int> neighbors[8] = {
                make_pair(i - 1, j - 1), // Top-left
                make_pair(i - 1, j),     // Top
                make_pair(i - 1, j + 1), // Top-right
                make_pair(i, j - 1),     // Left
                make_pair(i, j + 1),     // Right
                make_pair(i + 1, j - 1), // Bottom-left
                make_pair(i + 1, j),     // Bottom
                make_pair(i + 1, j + 1)  // Bottom-right
            };

            int sum = 0;
            for (int k = 0; k < 8; ++k) {
                int ni = neighbors[k].first;
                int nj = neighbors[k].second;

                if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                    sum += matrix[ni][nj];
                }
            }

            if (matrix[i][j] == 1) {
                if (sum < 2 || sum > 3) {
                    newMatrix[i][j] = 0; 
                } else {
                    newMatrix[i][j] = 1;
                }
            } else {
                if (sum == 3) {
                    newMatrix[i][j] = 1; 
                } else {
                    newMatrix[i][j] = 0; 
                }
            }
        }
    }

    cout << "The resulting matrix is:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << newMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
