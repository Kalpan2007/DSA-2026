class Robot {
public:
bool moved = false;
int pos;
vector<vector<int>> path;  

Robot(int w, int h) {
    int perimeter = 2 * (w + h - 2);
    path = vector<vector<int>>(perimeter, vector<int>(3));

    pos = perimeter - 1;
    int idx = 0;

    
    for (int x = 1; x < w; x++) {
        path[idx++] = {x, 0, 1};
    }

    
    for (int y = 1; y < h; y++) {
        path[idx++] = {w - 1, y, 0};
    }

    
    for (int x = w - 2; x >= 0; x--) {
        path[idx++] = {x, h - 1, 3};
    }

    for (int y = h - 2; y >= 0; y--) {
        path[idx++] = {0, y, 2};
    }
}

void step(int num) {
    if (!moved) moved = true;
    pos = (pos + num) % path.size();
}

vector<int> getPos() {
    return {path[pos][0], path[pos][1]};
}

string getDir() {
    if (!moved) return "East";

    switch (path[pos][2]) {
        case 0: return "North";
        case 1: return "East";
        case 2: return "South";
        case 3: return "West";
    }
    return ""; 
}
};
/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */