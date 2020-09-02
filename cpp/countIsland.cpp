
#include <iostream>

using namespace std;


#define ROW 5
#define COL 5

bool isSafe(int M[][COL], int row, int col, bool visited[][COL]){
    
    return (row >= 0) && (row < ROW) &&
           (col >= 0) && (col < COL) &&
           (M[row][col] && !visited[row][col]);
}

void dfs(int M[][COL], int row, int col, int neighbors, int rowNbr[], int colNbr[], bool visited[][COL]) {

    visited[row][col] = true;

    for (int k = 0; k < neighbors; k++)
        if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited))
            dfs(M, row + rowNbr[k], col + colNbr[k], neighbors, rowNbr, colNbr, visited);
}

int countIslands(int M[][COL], int neighbors, int rowNbr[], int colNbr[]) {

    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));

    int count = 0;
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            if (M[i][j] && !visited[i][j]) {
                dfs(M, i, j, neighbors, rowNbr, colNbr, visited);
                count++;
            }
    return count;
}

int main(int argc, char** argv) {

    if (argc < 2) {
        cout << "Number of neighbors argument is missing." << endl;
        exit(1);
    }

    static int eight_rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int eight_colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    static int four_rowNbr[] = {-1, 0, 0, 1};
    static int four_colNbr[] = {0, -1, 1, 0};
    
    int count = 0;
    int num_of_neighbors = atoi(argv[1]);

    int mat[][COL] = {{1, 1, 0, 0, 0},
                   {1, 1, 0, 0, 0},
                   {0, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1},
                   {0, 0, 0, 0, 0}};
    cout << "Number of arguments: " << argc << endl;
    cout << "numbber of neighbors: " << num_of_neighbors << endl;
    if (num_of_neighbors == 4) {
        count = countIslands(mat, num_of_neighbors, four_rowNbr, four_colNbr);
    } else if (num_of_neighbors == 8) {
        count = countIslands(mat, num_of_neighbors, eight_rowNbr, eight_colNbr);
    }
    cout << "Number of islands: " << count << endl;
    return 0;
}
