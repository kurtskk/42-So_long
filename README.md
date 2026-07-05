This project has been created as part of the 42 curriculum by kgagliar.

# so_long

## Description

so_long is a Graphics project from the 42 curriculum. The goal is to build a small 2D game in C using the MiniLibX library, where a player navigates a tile-based map, collects all items, and reaches the exit. The project covers window management, image rendering, keyboard input, map parsing, and pathfinding validation.

The bonus version adds animated sprites, moving enemies, and an on-screen move counter.

## Project Structure

```
so_long/
├── src/                   # Mandatory — game logic, rendering, input, map
├── bonus/
│   ├── src/               # Bonus — extended logic with enemies and animation
│   └── inc/               # Bonus header
├── inc/
│   └── so_long.h          # Mandatory header — structs and prototypes
├── assets/
│   ├── tiles/             # floor.xpm and wall.xpm
│   ├── images/            # Exit sprites (open/closed) and collectible
│   └── sprites/
│       ├── 2B/            # Player sprites (4 directions × 2 frames)
│       └── Emil/          # Enemy sprites (up/down × 2 frames)
├── lib/
│   ├── libft/             # Custom C library
│   └── minilibx-linux/    # MiniLibX — X11 graphics library
└── Makefile
```

## How It Works

### Map format

Maps are read from `.ber` files — plain text grids where each character represents a tile:

| Character | Meaning |
|-----------|---------|
| `1` | Wall |
| `0` | Empty floor |
| `P` | Player starting position (exactly 1) |
| `C` | Collectible (at least 1) |
| `E` | Exit (at least 1) |
| `M` | Enemy (bonus only) |

### Map validation

Before the game starts, the map goes through three checks:

**Rectangular** — every row must have the same length.

**Valid characters** — only `0`, `1`, `P`, `C`, `E`, and `M` are accepted. Invalid characters cause an error exit.

**Walls** — the entire border of the map must be walls (`1`). Any opening in the border causes an error.

**Correct counts** — exactly one `P`, at least one `C`, and at least one `E`.

**Reachable path** — a DFS (depth-first search) is run from the player's position on a copy of the map. If it cannot reach all collectibles and all exits, the map is rejected.

### Rendering

Each tile is a 60×60 XPM image rendered with `mlx_put_image_to_window`. The map is redrawn every frame. The exit sprite changes depending on whether all collectibles have been picked up — it appears closed until then, and open once the player is ready to leave.

### Player

The player moves with `W`, `A`, `S`, `D`. Each move increments the counter and triggers a frame switch for the walk animation (two frames per direction, four directions = eight sprites total). The move count is printed to stdout on each move.

### Bonus — Enemies

Enemies (`M` on the map) move vertically, bouncing between walls. They run on a tick counter inside `mlx_loop_hook` — every 1500 loop iterations they take one step. If the player occupies a cell in the enemy's path before or after the step, the game closes. Each enemy has its own up/down animation with two frames per direction.

### Bonus — On-screen move counter

The move count is displayed directly on the game window using `mlx_string_put`, updating every frame alongside the map redraw.

## Map Legend Example

```
1 1 1 1 1 1 1 1
1 P 0 C 0 0 0 1
1 0 1 1 0 1 0 1
1 0 0 0 0 0 C 1
1 0 1 M 1 1 0 1
1 0 0 0 0 E 0 1
1 1 1 1 1 1 1 1
```

## Controls

| Key | Action |
|-----|--------|
| `W` | Move up |
| `S` | Move down |
| `A` | Move left |
| `D` | Move right |
| `ESC` / `X` | Quit |

## Instructions

### Dependencies (Linux)

```bash
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

### Compile

```bash
make          # builds ./so_long (mandatory)
make bonus    # builds ./so_long_bonus
```

### Run

```bash
./so_long maps/map.ber
./so_long_bonus maps/map_bonus.ber
```

### Clean

```bash
make clean    # removes object files
make fclean   # removes object files and binaries
make re       # full rebuild
```

## Error Handling

The program writes an error message to stderr and exits on:

- Wrong number of arguments or non-`.ber` extension
- File not found or unreadable
- Non-rectangular map
- Invalid characters
- Missing or duplicate `P`, `C`, or `E`
- Map border not fully walled
- No valid path from player to all collectibles and exits
- MiniLibX or memory allocation failure

## Resources

- [MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [X11 events reference](https://tronche.com/gui/x/xlib/events/)
- [so_long — 42 project guide](https://harm-smits.github.io/42docs/projects/so_long)
- [DFS explanation](https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/)
