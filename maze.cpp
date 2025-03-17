#include <iostream>
#include <vector>
#include <stack>
#include <random>
#include <chrono>

using namespace std;

class Maze {
private:
    int rows, cols;
    vector<vector<char>> grid;
    pair<int, int> start, end;
    
    // Direction arrays for moving in 4 directions
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};

public:
    Maze(int r, int c) : rows(r), cols(c) {
        grid = vector<vector<char>>(rows, vector<char>(cols, '#'));
        generateMaze();
    }

    void generateMaze() {
        // Initialize with walls
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                grid[i][j] = '#';
            }
        }

        // Set random seed
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        default_random_engine generator(seed);

        // Start from (1,1)
        stack<pair<int, int>> st;
        grid[1][1] = ' ';
        st.push({1, 1});

        while(!st.empty()) {
            auto current = st.top();
            vector<int> directions = {0, 1, 2, 3};
            shuffle(directions.begin(), directions.end(), generator);
            
            bool found = false;
            for(int dir : directions) {
                int nx = current.first + dx[dir] * 2;
                int ny = current.second + dy[dir] * 2;
                
                if(nx > 0 && nx < rows-1 && ny > 0 && ny < cols-1 && grid[nx][ny] == '#') {
                    grid[nx][ny] = ' ';
                    grid[current.first + dx[dir]][current.second + dy[dir]] = ' ';
                    st.push({nx, ny});
                    found = true;
                    break;
                }
            }
            
            if(!found) st.pop();
        }

        // Set start and end points
        start = {1, 1};
        end = {rows-2, cols-2};
        grid[start.first][start.second] = 'S';
        grid[end.first][end.second] = 'E';
    }

    bool solveDFS() {
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        stack<pair<int, int>> st;
        st.push(start);
        visited[start.first][start.second] = true;

        while(!st.empty()) {
            auto current = st.top();
            st.pop();

            if(current == end) return true;

            for(int i = 0; i < 4; i++) {
                int nx = current.first + dx[i];
                int ny = current.second + dy[i];

                if(nx >= 0 && nx < rows && ny >= 0 && ny < cols && 
                   !visited[nx][ny] && grid[nx][ny] != '#') {
                    if(grid[nx][ny] != 'S' && grid[nx][ny] != 'E') {
                        grid[nx][ny] = '.';
                    }
                    visited[nx][ny] = true;
                    st.push({nx, ny});
                }
            }
        }
        return false;
    }

    void printMaze() {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                cout << grid[i][j] << ' ';
            }
            cout << endl;
        }
    }
};

int main() {
    int rows = 15, cols = 15;
    Maze maze(rows, cols);
    
    cout << "Generated Maze:" << endl;
    maze.printMaze();
    
    cout << "\nSolving maze using DFS..." << endl;
    if(maze.solveDFS()) {
        cout << "\nSolution found:" << endl;
        maze.printMaze();
    } else {
        cout << "No solution exists!" << endl;
    }
    
    return 0;
}