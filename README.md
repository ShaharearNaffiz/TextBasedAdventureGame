<div align="center">

```
███╗   ██╗███████╗██╗   ██╗
████╗  ██║██╔════╝██║   ██║
██╔██╗ ██║███████╗██║   ██║
██║╚██╗██║╚════██║██║   ██║
██║ ╚████║███████║╚██████╔╝
╚═╝  ╚═══╝╚══════╝ ╚═════╝
 T E X T   B A S E D   A D V E N T U R E   G A M E   I N   C
```

**A console-based, choice-driven adventure game built entirely in C.**
*Your story: surviving the first day at North South University.*

[![Made in C](https://img.shields.io/badge/Made%20in-C-00599C?style=flat-square&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Course](https://img.shields.io/badge/CSE115-Sec%2014-2ea44f?style=flat-square)](/)
[![Group](https://img.shields.io/badge/Group-1-e74c3c?style=flat-square)](/)
[![Type](https://img.shields.io/badge/Type-Text%20Adventure-blueviolet?style=flat-square)](/)
[![Status](https://img.shields.io/badge/Status-Active%20Dev-orange?style=flat-square)](/)
[![Endings](https://img.shields.io/badge/Endings-4-gold?style=flat-square)](/)

</div>

---

## 📖 Overview

This is a **text-based adventure game** written in C as a CSE115 group project. A text-based adventure game is an interactive fiction program where the player reads a narrative, makes choices by entering numbers, and those choices shape the story's outcome — no graphics, no sound engine, just C code and a terminal.

The game engine is built around three core mechanics:
- **Scene progression** — the story moves through connected locations one by one
- **A stat system** — choices silently modify player stats throughout the game
- **Multiple endings** — final stats are evaluated at the end to determine the outcome

**Our story setting:** A freshman's first day at North South University — getting through the gate, surviving a professor's surprise question, joining clubs, and making it to the plaza before the day ends. The story is original, but the underlying engine concepts apply to any text adventure.

---

## ⚡ Quick Start

```bash
# Step 1 — Compile
gcc main.c -o adventure

# Step 2 — Play
./adventure          # Linux / macOS
adventure.exe        # Windows
```

No external libraries. No dependencies. Standard C only.

> **No compiler?** Paste `main.c` into [OnlineGDB](https://www.onlinegdb.com) and run it instantly in your browser.

---

## 🏗️ How a Text-Based Adventure Game Works

A text-based adventure is made up of three building blocks:

```
┌─────────────────────────────────────────────────────────────┐
│                                                             │
│   SCENE          →    CHOICE         →    CONSEQUENCE       │
│                                                             │
│  Print narrative      Read player         Modify stats      │
│  Print options        input (1/2/3)       Call next scene   │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

In our implementation:
- Each **scene** is a C function that prints narrative text and a numbered menu
- Each **choice** is read and validated by `getChoice()`
- Each **consequence** modifies global stat variables and chains to the next scene

---

## 🗺️ Game Structure — Scene Flow

The story progresses through **5 scenes** in a fixed sequence. You cannot go back.

```
  ┌────────────────────────────────────────────────────────────────┐
  │                                                                │
  │  🚪 GATE ──► 🏢 ACADEMIC BLOCK ──► 📚 LIBRARY                 │
  │                                                                │
  │                          ──► 🎪 CLUB FAIR ──► ⛲ PLAZA         │
  │                                                                │
  │                                              └──► 🏆 ENDING   │
  └────────────────────────────────────────────────────────────────┘
```

| # | Scene | Story Context | Game Mechanic |
|---|---|---|---|
| 1 | 🚪 **Main Gate** | Security asks for admission proof | Confidence choice with 3 options |
| 2 | 🏢 **Academic Building** | Finding the CSE115 classroom | Branching path + optional nested quiz |
| 3 | 📚 **Central Library** | Printing your class schedule | Math puzzle — right answer = knowledge, wrong = mistake |
| 4 | 🎪 **Club Fair** | Clubs recruiting new students | Three-way choice affecting different stats |
| 5 | ⛲ **NSU Plaza** | Final moments of the first day | Last stat boost before ending is evaluated |

---

## 📊 The Stat System

Three global integers track the player's state across all scenes:

```c
int knowledge   = 0;    // 📖  Earned by solving puzzles and making smart choices
int confidence  = 0;    // 💪  Earned by social interactions and bold decisions
int mistakes    = 0;    // ❌  Accumulated from wrong answers — hurts the final score
```

Stats accumulate **silently** — the player never sees the scoreboard mid-game. Only the ending screen reveals the full picture. This is an intentional design choice that makes replaying the game meaningful.

---

## 🏆 The Four Endings

The ending is determined by evaluating all three stats at `showEnding()`. Four outcomes are possible:

```
╔══════════════════════════════════════════════════════════════════════╗
║                          ENDING  CHART                              ║
╠══════════════════╦══════════════════════════╦═══════════════════════╣
║ ✨ LEGENDARY     ║ knowledge ≥ 6            ║ You owned it.         ║
║                  ║ AND confidence ≥ 6       ║ Respect.              ║
╠══════════════════╬══════════════════════════╬═══════════════════════╣
║ 👍 GOOD DAY      ║ knowledge ≥ 3            ║ Solid first day.      ║
║                  ║ OR confidence ≥ 3        ║ Keep it up.           ║
╠══════════════════╬══════════════════════════╬═══════════════════════╣
║ 📚 NORMAL DAY    ║ mistakes < 2             ║ Quiet but clean.      ║
║                  ║                          ║ That counts.          ║
╠══════════════════╬══════════════════════════╬═══════════════════════╣
║ 😵 CHAOTIC DAY   ║ Everything else          ║ Happens to everyone.  ║
║                  ║                          ║ Probably.             ║
╚══════════════════╩══════════════════════════╩═══════════════════════╝
```

---

## 🧱 Code Architecture

### The Scene Chain — "Domino" Pattern

Every scene function ends by directly calling the next scene. The call stack itself tracks progress through the story:

```
main()
  └─► mainMenu()
        └─► startGame()              ← resets stats, reads player name
              └─► gate()                           Scene 1
                    └─► academicBlock()             Scene 2
                          └─► libraryPuzzle()       Scene 3
                                └─► clubFair()      Scene 4
                                      └─► plaza()   Scene 5
                                            └─► showEnding()
```

No game loop. No state machine. Just functions calling functions — clean and easy to extend.

### Bulletproof Input — `getChoice()`

Every single player input passes through one validation function:

```c
int getChoice(int min, int max) {
    int choice;
    while (1) {
        scanf("%d", &choice);
        if (choice >= min && choice <= max) return choice;
        printf("Invalid input! Enter between %d-%d: ", min, max);
    }
}
```

Type letters, symbols, or `99999` — the game never crashes. It simply re-prompts until valid input is received.

---

## 🔬 CSE115 Concepts in This Project

Every concept mapped to its exact location in `main.c`:

| CSE115 Topic | Exact Location in Code |
|---|---|
| `int`, `char` variables | `knowledge`, `confidence`, `mistakes`, `playerName[50]` |
| `if / else if / else` | Every scene decision + all 4 ending conditions in `showEnding()` |
| `while` loop | Validation loop inside `getChoice()` |
| `do-while` loop | Main menu — keeps running until user picks Exit |
| Function prototypes | All 9 functions declared at the top before `main()` |
| Parameters + return values | `getChoice(int min, int max)` → returns a validated `int` |
| Global variables | `knowledge`, `confidence`, `mistakes` shared across all scene functions |
| `char` array | `playerName[50]` — read with `scanf("%s")` in `startGame()` |
| `printf` format specifiers | `showEnding()` — displays all stats using `%d` |
| Nested conditionals | `academicBlock()` — the stairs path contains a follow-up question |

---

## 🚧 Roadmap

Planned features for upcoming commits:

- [ ] **Inventory System** — Pick up items (ID card, timetable, water bottle) that affect scene outcomes
- [ ] **True Branching** — Choices that unlock or skip entire scenes, not just stat changes
- [ ] **Save to File** — Write your final score to a `.txt` file using `fopen` / `fprintf`
- [ ] **More Scenes** — Cafeteria, Computer Lab, SAC Building
- [ ] **Random Events** — Chance encounters with seniors or professors mid-scene
- [ ] **Difficulty Modes** — Easy shows stat changes live; Hard hides everything until the ending

---

## 📁 Project Structure

```
Text-Adventure-Game/
│
├── main.c          ← Full game: all scenes, stats, menu, input validation
└── README.md       ← You are here
```

Single file. One compile command. Nothing to install.

---

## 👥 Team — CSE115 · Section 14 · Group 1

| Name | Student ID |
|---|---|
| Md. Shaharear Hossain Naffiz | 2611327042 |
| Chowdhury Rounak Jahan Bushra | 2612545042 |
| Sumaiya Karim Ilma | 2532746042 |
| Smita Elizabeth Biswas | 2611961042 |

---

<div align="center">

```
  GOOD LUCK ON YOUR FIRST DAY.
  ( You're going to need it. )
```

*CSE115 · Section 14 · Group 1 · North South University*

</div>
