#include <iostream>
#include <queue>

typedef struct Point {
    int x;
    int y;
} Point;

char** generate_circle(int N);
bool is_bound(Point p, Point center, int radius);
void print_map(char** map, int N);
void flood_fill(char** map, int N, Point fill_point);
bool valid_point(char** map, int N, Point point);

int main(int argc) {
    int N = 30;

    char** map = generate_circle(N);
    print_map(map, N);

    Point fill_point = {0, 0};

    // compute flood fill
    flood_fill(map, N, fill_point);
    print_map(map, N);

    for(int i=0;i<N;i++) {
        delete[] map[i];
    }
    delete[] map;
    return 0;
}

char** generate_circle(int N) {
    Point center = {N/2 - N/6, N/2+N/6}; 
    int radius = N/3;

    char** map = new char*[N];
    for(int i=0;i<N;i++) {
        map[i] = new char[N];
        for(int j=0;j<N;j++) {
            Point p = {i, j};
            if(is_bound(p, center, radius)) map[i][j] = 'X';
            else map[i][j] = ' ';
        }
    }

    return map;
}

bool is_bound(Point p, Point center, int radius) {
    int x_dist = p.x - center.x;
    int y_dist = p.y - center.y;
    int sq_dist = x_dist * x_dist + y_dist * y_dist;
    int sq_radius = radius * radius;

    if(sq_dist >= sq_radius-20 && sq_dist <= sq_radius+20) return true;
    else return false;
}

void print_map(char** map, int N) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void flood_fill(char** map, int N, Point fill_point) {
    std::queue<Point> que; 
    que.push(fill_point);

    while(!que.empty()) {
        Point p = que.front();
        que.pop();

        Point left = {p.x, p.y-1};
        Point right = {p.x, p.y+1};
        Point top = {p.x-1, p.y};
        Point bottom = {p.x+1, p.y};
        Point adj_points[] = {left, right, top, bottom};

        for(int i=0;i<4;i++) {
            if(valid_point(map, N, adj_points[i])) {
                que.push(adj_points[i]);

                // color
                map[adj_points[i].x][adj_points[i].y] = 'O';
            }
        }
    }
}

bool valid_point(char** map, int N, Point point) {
    bool valid = true;

    // out of range
    if(point.x<0||point.x>=N||point.y<0||point.y>=N) valid = false;
    else {
        // already colored or is boundary
        if(map[point.x][point.y]=='O' || map[point.x][point.y]=='X') valid = false;
    }
    return valid;
}