# Music Playlist Manager Using Doubly Linked List

## Project Overview

The Music Playlist Manager is a menu-driven C++ program that manages a list of songs using a **doubly linked list**. Each song stores its title and artist name, along with pointers to the previous and next songs.

This is a console-based simulation. It displays song information and simulates playlist navigation; it does not play actual audio files.

## Features

- Add a song with its title and artist name.
- Delete a song by entering its title.
- Display the playlist in forward order.
- Display the playlist in reverse order.
- Show the current song.
- Move to the next song or previous song.
- Display every song in the playlist in sequence.
- Simulate one cycle of the Repeat All feature.
- Handle an empty playlist and invalid menu input.
- Support song titles and artist names containing spaces.
- Release dynamically allocated song nodes when the playlist object is destroyed.

## Data Structure Used

### Doubly Linked List

Each node represents one song and contains:

- `title`: the song's title.
- `artist`: the artist's name.
- `prev`: pointer to the previous song node.
- `next`: pointer to the next song node.

The `Playlist` class maintains a `head` pointer to the first song and a `current` pointer to the current song.

Example structure:

```text
NULL <- [Song A] <-> [Song B] <-> [Song C] -> NULL
          head                         last
```

The `prev` and `next` pointers allow traversal in both directions.

## Menu Options

| Option | Operation | Description |
|---|---|---|
| 1 | Add Song | Adds a song title and artist to the end of the playlist. |
| 2 | Delete Song | Deletes the song matching the entered title. |
| 3 | Display Playlist Forward | Displays songs from first to last. |
| 4 | Display Playlist Reverse | Displays songs from last to first. |
| 5 | Play Current Song | Displays the current song. |
| 6 | Play Next Song | Moves to the next song if one exists. |
| 7 | Play Previous Song | Moves to the previous song if one exists. |
| 8 | Play Complete Playlist | Displays all songs in forward order and updates the current pointer as it goes. |
| 9 | Repeat All | Simulates one full cycle and resets the current song to the first song. |
| 10 | Show Current Song | Displays the current song. |
| 11 | Exit | Closes the program. |

## Requirements

- A C++ compiler such as GCC or MinGW.
- Visual Studio Code or another C++ editor (optional).
- C++11 or later; the provided compile command uses C++17.

## How to Compile and Run

### Using the terminal

1. Save the source code as `menudriven_corrected.cpp`.
2. Open a terminal in the folder containing the file.
3. Compile the program:

   ```bash
   g++ -std=c++17 menudriven_corrected.cpp -o music
   ```

4. Run it on Windows:

   ```powershell
   .\music.exe
   ```

   On Linux or macOS, run:

   ```bash
   ./music
   ```

### Using VS Code

Open the project folder in VS Code, open the terminal in that folder, and run the compile and run commands above. Ensure that a C++ compiler is installed and available in the terminal's PATH.

## Algorithm Summary

### Add Song

1. Create a new song node.
2. If the playlist is empty, set both `head` and `current` to the new node.
3. Otherwise, traverse to the last node.
4. Connect the last node's `next` pointer to the new node and the new node's `prev` pointer to the last node.

### Delete Song

1. Search for the node with the requested title.
2. If it is not found, display a message.
3. Otherwise, reconnect the previous and next nodes, updating `head` when the first node is deleted.
4. If the deleted node was the current song, move `current` to the next song if available; otherwise, move it to the previous song.
5. Delete the node from memory.

### Display in Reverse

1. Start at `head`.
2. Follow `next` pointers until the last node is reached.
3. Print each song while following `prev` pointers back to the beginning.

## Complexity Analysis

Let `n` be the number of songs in the playlist.

| Operation | Time Complexity | Reason |
|---|---|---|
| Add Song | O(n) | The program traverses to the last node. |
| Delete Song | O(n) | It may search through the playlist for the title. |
| Display Forward | O(n) | Each node is visited once. |
| Display Reverse | O(n) | It traverses to the end and then visits each node in reverse. |
| Play Next / Previous | O(1) | It follows one pointer after boundary checks. |
| Play Complete Playlist | O(n) | Each song is displayed once. |
| Repeat All | O(n) | One simulated cycle visits each song once. |

Each song node requires **O(1)** additional storage, so total playlist storage is **O(n)**.

## Limitations

- The program simulates playback by printing song details; it does not play audio.
- Song deletion matches the title exactly and removes the first matching title.
- Repeat All runs for one simulated cycle and then resets the current song to the first song; it does not loop forever.
- The playlist is stored in memory and is not saved to a file, so songs are lost when the program exits.

## Learning Outcomes

This project demonstrates:

- Classes and objects in C++.
- Dynamic memory allocation and deallocation.
- Doubly linked list insertion, deletion, and traversal.
- Pointer management and edge-case handling.
- Menu-driven programming using `switch` and loops.

## Repository Files

A simple GitHub repository can contain:

```text
Music-Playlist-Manager/
├── menudriven_corrected.cpp
├── README.md
└── output-screenshot.png   (optional: add a screenshot of the program running)
```

## Author

Add your name, class, department, and college details here if required for your submission.
