# -*- coding: utf-8 -*-
import time
import os
from maze import Maze
from collections import deque

s = deque()


script_dir = os.path.dirname(os.path.abspath(__file__))
maze_csv_path = os.path.join(script_dir, "labirinto1.txt")
maze = Maze() 

maze.load_from_csv(maze_csv_path)

# Exibir o lab
maze.run()
maze.init_player()

p = maze.get_init_pos_player()

maze.mov_player(p)

visited = set()
s.append(p)

directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

found = False

while s:
    current = s.pop()

    if current in visited:
        continue

    visited.add(current)

    if maze.find_prize(current):
        print("Tesouro encontrado em", current)
        found = True
        break

    maze.mov_player(current)
    time.sleep(0.05)

    for d in directions:
        new_pos = (current[0] + d[0], current[1] + d[1])
        if maze.is_free(new_pos) and new_pos not in visited:
            s.append(new_pos)

if not found:
    print("Tesouro nao foi encontrado.")


