# Quoridor Game

## Project Overview

This project is a basic implementation of the Quoridor board game, developed as part of my advanced programming course. The game is designed to familiarize students with client-server architecture and the basics of game design using C++. The primary objective is to provide a simple functional multiplayer game where players can connect to a server, place walls, and try to reach the opposite side of the board.

## Features

- **Client-Server Architecture:**
  - The game uses sockets to enable network communication between clients and the server.
  - The server handles all game logic, including player turns, wall placement, and determining the winner.
  - Clients connect to the server, display the game board, and send player actions.

- **Gameplay:**
  - Players take turns moving their piece or placing a wall to block their opponent.
  - The goal is to be the first player to reach the opposite side of the board.
  - The game supports multiple players connecting to the server and playing until one would be the winner.

## Usage

1. **Server:**
   - Run the server program to start the game server.
   - The server will handle connections from multiple clients.

2. **Client:**
   - Run the client program to connect to the server.
   - The client displays the game board and allows players to make moves or place walls.

## Disclaimer

This is a simple project created for learning purposes in an advanced programming course. It is not intended to be a fully polished or complicated game.

