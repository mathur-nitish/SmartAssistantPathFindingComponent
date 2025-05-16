#include"../headers/GridPathFinder.h"

GridPathFinder::GridPathFinder(vector<vector<int>> grid) {
	this->GridPathFinder::grid = grid;
    this->GridPathFinder::visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));

}

bool GridPathFinder::isValid(int x, int y) const {
	return x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size()
		&& grid[x][y] == 0 && visited[x][y] == 0;
}

vector<coordinates> GridPathFinder::get_shortestDistance(coordinates st, coordinates en) {
    struct node {
        int x, y;
        vector<coordinates> pathTillNow;
    };
    vector<coordinates> path;
    queue<node> q;
    vector<int> distX = { 0,0,1,-1 };
    vector<int> distY = { 1,-1,0,0 };
    q.push({ st.first, st.second, {{st.first, st.second}} });
    visited[st.first][st.second] = true;

    while (!q.empty()) {
        node tempNode = q.front();
        q.pop();
        int x = tempNode.x;
        int y = tempNode.y;
        vector<coordinates> tempPath = tempNode.pathTillNow;

        if (x == en.first && y == en.second) {
            path = tempPath;
            return path; // found the shortest path
        }

        for (int i = 0; i < distX.size(); i++) {
            int newX = x + distX[i];
            int newY = y + distY[i];

            if (isValid(newX, newY)) {
                visited[newX][newY] = true;
                tempPath.push_back({ newX,newY });
                q.push({ newX,newY,tempPath });
                tempPath.pop_back();
            }

        }

    }

    // resetting visited for next pathFinding
    this->GridPathFinder::visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
    
    return path;

}

vector<coordinates> GridPathFinder::get_shortestDistanceOpti(coordinates st, coordinates en) {
    struct node {
        int x, y;
    };
    vector<coordinates> path;
    queue<node> q;
    vector<int> distX = { 0,0,1,-1 };
    vector<int> distY = { 1,-1,0,0 };
    unordered_map<coordinates, coordinates,pair_hash> parentTracker;
    q.push({ st.first, st.second });
    visited[st.first][st.second] = true;

    while (!q.empty()) {
        node tempNode = q.front();
        q.pop();
        int x = tempNode.x;
        int y = tempNode.y;

        if (x == en.first && y == en.second) {
            break; // found the shortest path
        }

        for (int i = 0; i < distX.size(); i++) {
            int newX = x + distX[i];
            int newY = y + distY[i];

            if (isValid(newX, newY)) {
                visited[newX][newY] = true;
                parentTracker[{newX, newY}] = { x,y };
                q.push({ newX,newY });
            }

        }

    }

    vector<coordinates> finalPath = {};
    coordinates curr = en;
    // re-constructing the path using ParentTracker
    while(curr!=st) {
        // running loop for number of elements in tracker
        coordinates temp = parentTracker[curr];
        finalPath.push_back(temp);
        curr = temp;
    }
    reverse(finalPath.begin(), finalPath.end());

    // resetting visited for next pathFinding
    this->GridPathFinder::visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));

    return finalPath;

}