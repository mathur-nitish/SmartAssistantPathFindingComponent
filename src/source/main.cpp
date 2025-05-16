#include "../headers/NECESSARY_HEADER.h"
#include "../headers/GridPathFinder.h"
using namespace std;
using shelfNumber = int;
using coordinates = pair<int, int>;

#define print_coordinates(coordinate) cout<<"("<<coordinate.first<<","<<coordinate.second<<")";

unordered_map<shelfNumber, coordinates> dt;
coordinates INVALID_COORDINATE = { -1,-1 };

// 7x9 grid
vector<vector<int>> grid = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 0, 0, 1, 1, 1, 1}
};

void initialize_DB() {
    // adding dummy data
    dt[1] = { 1,2 };
    dt[4] = { 2,9 };
    dt[3] = { 4,7 };
    dt[2] = { 2,3 };
}

void get_DB() {

    for (auto& i : dt) {
        shelfNumber shelf = i.first;
        coordinates coordinate = i.second;
        cout << shelf << " : ";
        cout << "(" << coordinate.first << "," << coordinate.second << ")";
        cout << endl;
    }
}

coordinates get_coordinates(shelfNumber num) {
    if (dt.empty()) {
        return { -1,-1 };
    }

    return dt[num];
}


void testCode() {
    // Grid size constants (same as JS)
    const int rows = 28;
    const int cols = 40;

    // Create the grid (0 = free, 1 = blocked) same as your generateMap() in JS
    vector<vector<int>> grid(rows, vector<int>(cols, 0));

    // Blocking cells same as your JS function
    for (int i = 0; i <= 2; i++)
        for (int j = 0; j < cols; j++)
            grid[i][j] = 1;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j <= 4; j++)
            grid[i][j] = 1;

    for (int j = 0; j < cols; j++)
        grid[rows - 1][j] = 1;

    for (int i = 0; i <= 2; i++)
        for (int j = 35; j < cols; j++)
            grid[i][j] = 1;

    for (int i = 0; i < rows; i++)
        for (int j = 35; j < cols; j++)
            grid[i][j] = 1;

    for (int i = 7; i <= 9; i++)
        for (int j = 25; j <= 31; j++)
            grid[i][j] = 1;

    for (int i = 11; i <= 12; i++)
        for (int j = 25; j <= 31; j++)
            grid[i][j] = 1;

    for (int i = 15; i <= 17; i++)
        for (int j = 25; j <= 31; j++)
            grid[i][j] = 1;

    for (int i = 19; i <= 21; i++)
        for (int j = 25; j <= 31; j++)
            grid[i][j] = 1;

    for (int i = 7; i <= 9; i++)
        for (int j = 9; j <= 15; j++)
            grid[i][j] = 1;

    for (int i = 11; i <= 12; i++)
        for (int j = 9; j <= 15; j++)
            grid[i][j] = 1;

    for (int i = 15; i <= 17; i++)
        for (int j = 9; j <= 15; j++)
            grid[i][j] = 1;

    for (int i = 19; i <= 21; i++)
        for (int j = 9; j <= 15; j++)
            grid[i][j] = 1;

    // Define start point (22, 20)
    coordinates start = { 22, 20 };
    coordinates shelf2 = { 10, 26 };

    GridPathFinder pathFinder(grid);
    vector<coordinates> shortestPath = pathFinder.get_shortestDistanceOpti(start, shelf2);

    if (shortestPath.empty()) {
        cout << "No path found from start to shelf 2." << endl;
    }
    else {
        cout << "Shortest path from start to shelf 2:" << endl;
        for (auto& coord : shortestPath) {
            cout << "(" << coord.first << ", " << coord.second << ") ";
        }
        cout << endl;
    }
}


int main() {
    initialize_DB();
    get_DB();

    // using Optimized Function
    testCode();

    //cout << endl;
    //pair<int, int> temp = get_coordinates(2);
    //print_coordinates(temp);

    //cout << "\nHere!" << endl;

    //coordinates startPnt = { 6,4 };
    //GridPathFinder finder(grid);
    //vector<coordinates> ans = finder.get_shortestDistanceOpti(startPnt, temp);
    //cout << ans.size() << endl;

    //for (auto i : ans) {
    //    print_coordinates(i);
    //}


    return 0;
}
