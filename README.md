# Idle MMORPG Engine

A lightweight C++ MMORPG engine prototype focused on modular game systems, data-driven design, and scalable architecture.

The project provides the foundation for an idle MMORPG experience with character creation, combat, items, enemies, quests, world systems, and networking abstraction.

## Features

### Core Engine

- Modular C++ architecture
- Data-driven game configuration using JSON
- Centralized logging system
- Game lifecycle management
- Save/load foundation

### Character System

- Character creation flow
- Multiple races
- Multiple classes
- Stats system
- Inventory management
- Equipment handling

### Combat System

- Turn-based combat framework
- Enemy spawning
- Enemy definitions loaded from JSON
- Damage and defense calculations
- Experience and reward foundation

### Items

- Weapons
- Armor
- Item definitions
- Equipment system foundation
- Loot-ready architecture

### World Systems

- Zones
- NPC framework
- Quest system foundation

### Networking

- Network service abstraction layer
- Designed for future client/server communication

## Architecture

```text
IdleMMORPGEngine
│
├── Character
│ ├── Classes
│ ├── Stats
│ └── Inventory
│
├── Combat
│ ├── Enemies
│ ├── Combat System
│ └── Spawning
│
├── Core
│ ├── Game Loop
│ ├── Data Manager
│ └── Logger
│
├── Items
│
├── Network
│
├── Quests
│
├── UI
│
└── World
```

## Data Driven Design

Game content is stored externally in JSON files:

```text
data/
├── classes.json
├── races.json
├── enemies.json
├── items.json
├── quests.json
└── loot.json
```

This allows adding new content without changing engine code.

Example:

```json
{
  "id": "guardian",
  "name": "Guardian",
  "primary_stat": "strength",
  "health": 120,
  "damage": 12,
  "armor": 20
}
```

## Requirements

- C++17 compatible compiler
- CMake 3.20+
- Git

Supported platforms:

- Linux
- macOS
- Windows (via compatible C++ toolchain)

## Build and Run

The project includes a universal startup script.

Clone:

```bash
git clone https://github.com/istvzsig/idle-mmorpg-engine.git
cd idle-mmorpg-engine
```

Run:

```bash
chmod +x ./start
./start.sh
```

The script will:

- Configure CMake
- Build the engine
- Launch the game

## Example Startup

```text
================================
        IdleMMORPG
================================

Version: 0.1.0

Initializing game engine

Loaded class: guardian
Loaded race: valorian
Loaded enemy: forest_rat

Character Creation
...
```

## Project Goals

The long-term goal is to evolve this project into a complete idle MMORPG framework with:

- Persistent world simulation
- Server architecture
- Multiplayer support
- Economy systems
- Guilds
- Crafting
- Procedural content
- Web/mobile clients

## Current Status

Version: `0.1.0`

Current stage:

- Engine foundation complete
- Character creation working
- Combat framework working
- Data pipeline working
- Networking abstraction introduced

## License

[MIT License](LICENSE)
