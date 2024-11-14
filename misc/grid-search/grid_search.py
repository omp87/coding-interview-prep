


def search_map(grid, search_queue, width, height, island_size):
    this_y = search_queue[0][0]
    this_x = search_queue[0][1]
    island_size = island_size + 1
    grid[this_y][this_x] = 0
    search_queue.pop(0)

    if(this_y - 1 >= 0 and grid[this_y -1][this_x]):
        search_queue.append([this_y - 1,this_x])
        island_size, grid = search_map(grid, search_queue, width, height, island_size)

    if(this_y + 1 < height and grid[this_y + 1][this_x]):
        search_queue.append([this_y + 1,this_x])
        island_size, grid = search_map(grid, search_queue, width, height, island_size)

    if(this_x - 1 >= 0 and grid[this_y][this_x - 1]):
        search_queue.append([this_y,this_x-1])
        island_size, grid = search_map(grid, search_queue, width, height, island_size)

    if(this_x + 1 < width and grid[this_y][this_x + 1]):
        search_queue.append([this_y,this_x+1])
        island_size, grid = search_map(grid, search_queue, width, height, island_size)

    return island_size, grid


grid = [[0,1,0,1,0,1], [1,1,0,1,0,0],[0,0,0,1,0,0],[1,1,0,0,0,0]]
height = len(grid)
width = len(grid[0])

search_flag = True
search_queue = []
while(search_flag == True):
    for y in range(height):
        for x in range(width):
            if(grid[y][x] == 1):
                search_queue.append([y,x])
                island_size = 0
                island_size, grid = search_map(grid, search_queue, width, height, island_size)