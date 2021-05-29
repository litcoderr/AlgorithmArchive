from typing import List, Tuple
from math import pow

def is_bound(x: int, y: int, center: List[int], radius: int) -> bool:
    x_dist = x - center[0]
    y_dist = y - center[1]
    sq_dist = int(pow(x_dist, 2)) + int(pow(y_dist, 2))
    sq_radius = int(pow(radius, 2))

    if sq_dist >= sq_radius - 20 and sq_dist <= sq_radius + 20: return True
    else: return False

def generate_circle(grid: List[List[str]], N: int):
    center: List[int] = [N//2 - N//6, N//2+N//6]
    radius: int = N//3

    for i in range(N):
        for j in range(N):
            if is_bound(i, j, center, radius): grid[i][j] = 'X'
            else: grid[i][j] = ' '

def print_grid(grid: List[List[str]], N: int):
    for g in grid:
        for c in g:
            print(c, end='')
        print('')

def valid_point(p: Tuple[int, int], grid: List[List[str]], N: int) -> bool:
    valid: bool = True

    # out of range
    if p[0]<0 or p[0]>=N or p[1]<0 or p[1]>=N: valid = False
    else:
        # already colored or is boundary
        if grid[p[0]][p[1]] == 'O' or grid[p[0]][p[1]] == 'X': valid = False

    return valid

def flood_fill(fill_point: Tuple[int, int], grid: List[List[int]], N: int):
    que: List[Tuple[int, int]] = []
    que.append(fill_point)

    while(len(que) > 0):
        p: Tuple[int, int] = que.pop(0)

        adj_points: List[Tuple[int, int]] = [(p[0], p[1]-1),(p[0], p[1]+1),(p[0]-1, p[1]),(p[0]+1, p[1])]
        for adj in adj_points:
            if valid_point(adj, grid, N):
                que.append(adj)

                # color
                grid[adj[0]][adj[1]] = 'O'

if __name__ == "__main__":
    N = 30
    grid = [[' ' for _ in range(N)] for _ in range(N)]

    generate_circle(grid, N)
    print_grid(grid, N)

    fill_point: Tuple[int, int] = (0, 0)
    flood_fill(fill_point, grid, N)
    print_grid(grid, N)