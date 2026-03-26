# 🎓 Student Course Management System

A C++ console application that manages students and their enrolled courses, built using object-oriented programming principles including inheritance, encapsulation, and STL containers.

---

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Requirements](#requirements)
- [Getting Started](#getting-started)
  - [Option A: Visual Studio (Windows)](#option-a-visual-studio-windows)
  - [Option B: g++ Command Line (Windows / Linux / macOS)](#option-b-g-command-line-windows--linux--macos)
- [Usage](#usage)
- [OOP Design](#oop-design)
- [README Best Practices Reference](#readme-best-practices-reference)
- [License](#license)

---

## Overview

The Student Course Management System is a terminal-based C++ application that lets an administrator add and manage students, enroll them in courses, search and sort records, and view enrolled course lists — all through an interactive console menu.

---

## Features

- ➕ Add a new student (name, ID, GPA)
- ❌ Remove a student by ID
- 🔍 Search for a student by ID
- 📋 Display all registered students
- 📚 Enroll a student in a course
- 🗂️ View all courses a student is enrolled in
- 📊 Sort students by GPA (descending)

---

## Project Structure

```
Student-Course-Management-System/
│
├── Capstone_project.cpp        # Entry point — instantiates and runs MenuManager
├── MenuManager.h               # MenuManager class declaration
├── MenuManager.cpp             # Menu logic and all student operations
├── Student.h                   # Student class declaration (inherits Person)
├── Student.cpp                 # Student class implementation
├── Person.h                    # Base Person class declaration
├── Person.cpp                  # Person class implementation
│
├── Capstone_project.vcxproj    # Visual Studio project file
├── Capstone_project.vcxproj.filters
├── Capstone_project.vcxproj.user
└── x64/Debug/                  # Build output directory (Visual Studio)
```

---

## Requirements

### Compiler & Language
| Requirement | Minimum Version |
|---|---|
| C++ Standard | C++11 or later |
| g++ (GCC) | 7.0+ |
| Clang | 5.0+ |
| MSVC (Visual Studio) | Visual Studio 2017 or later |

### Operating System
| Platform | Supported |
|---|---|
| Windows 10 / 11 | ✅ (Visual Studio or MinGW g++) |
| Linux (Ubuntu, Fedora, etc.) | ✅ (g++) |
| macOS (10.14+) | ✅ (Clang or g++ via Homebrew) |

### Required Tools
- A C++11-compatible compiler (see above)
- Git (to clone the repository)

> **No external libraries are required.** The project uses only the C++ Standard Library (`<iostream>`, `<string>`, `<map>`, `<set>`).

---

## Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/muhammadRashwan1101/Student-Course-Management-System-Console-Application-.git
cd Student-Course-Management-System-Console-Application-
```

---

### Option A: Visual Studio (Windows)

> Recommended if you are on Windows. The `.vcxproj` project file is included.

**Step 1 — Open the project**
- Launch **Visual Studio 2017** (or later).
- Go to **File → Open → Project/Solution**.
- Navigate to the cloned folder and select `Capstone_project.vcxproj`.

**Step 2 — Set build configuration**
- In the toolbar, set the configuration to **Debug** or **Release** and the platform to **x64**.

**Step 3 — Build the project**
- Press **Ctrl + Shift + B** or go to **Build → Build Solution**.
- The compiled binary will be placed in `x64/Debug/` or `x64/Release/`.

**Step 4 — Run the application**
- Press **Ctrl + F5** (Start Without Debugging) to run it in the console.
- Or navigate to the output folder and double-click `Capstone_project.exe`.

---

### Option B: g++ Command Line (Windows / Linux / macOS)

> Use this method if you prefer the terminal or are on Linux/macOS.

**Prerequisites (Linux/macOS)**
```bash
# Ubuntu / Debian
sudo apt update && sudo apt install g++ git

# macOS (via Homebrew)
brew install gcc
```

**Prerequisites (Windows with MinGW)**
- Install [MinGW-w64](https://www.mingw-w64.org/) and ensure `g++` is in your system PATH.

**Step 1 — Navigate to the project folder**
```bash
cd Student-Course-Management-System-Console-Application-
```

**Step 2 — Compile all source files**
```bash
g++ -std=c++11 -o StudentManager \
    Capstone_project.cpp \
    Person.cpp \
    Student.cpp \
    MenuManager.cpp
```

**Step 3 — Run the application**
```bash
# Linux / macOS
./StudentManager

# Windows (Command Prompt)
StudentManager.exe
```

---

## Usage

Once launched, the application presents an interactive console menu:

```
===== Student Course Management System =====
1. Add Student
2. Remove Student
3. Search Student
4. Display All Students
5. Enroll Student in Course
6. Show Student Courses
7. Sort Students by GPA
0. Exit
============================================
Enter your choice:
```

Navigate by entering the number corresponding to the desired action and following the on-screen prompts.

---

## OOP Design

The project demonstrates core object-oriented programming concepts:

| Class | Responsibility |
|---|---|
| `Person` | Base class holding a student's name via protected inheritance |
| `Student` | Inherits `Person`; adds ID, GPA, and a `std::set` of enrolled courses |
| `MenuManager` | Manages a `std::map<int, Student>` and drives the interactive menu loop |

**Key design decisions:**
- `Student` inherits from `Person` (single inheritance)
- `const` methods prevent unintended data mutation
- `std::set` ensures each course name is stored only once per student
- `std::map` provides O(log n) lookup of students by ID
- Course names are passed by `const` reference to avoid unnecessary string copies

---

## README Best Practices Reference

The following best practices were applied in writing this README, for your future reference:

1. **Start with a clear title and one-sentence description** — Readers should immediately understand what the project does.
2. **Use a Table of Contents** — Essential for longer READMEs; lets readers jump to what they need.
3. **Add a features section** — A quick bullet list of capabilities helps users evaluate the project at a glance.
4. **Show the project structure** — A file tree with brief annotations removes confusion about what each file does.
5. **Separate requirements from setup steps** — List software/version requirements in a dedicated section before any build instructions.
6. **Provide multiple setup paths** — Different users have different environments. Covering both GUI (Visual Studio) and CLI (g++) increases accessibility.
7. **Use numbered steps for procedures** — Sequential steps are clearer than prose paragraphs for install/build instructions.
8. **Include copy-pasteable code blocks** — Wrap all terminal commands in fenced code blocks with the correct language tag.
9. **Show expected output** — Even a short sample of what the running application looks like sets expectations and aids debugging.
10. **Document design decisions** — A brief architecture or design section helps contributors and reviewers understand the codebase quickly.
11. **Keep language simple and consistent** — Avoid jargon where possible; use the same terms throughout (e.g., don't switch between "student ID" and "student number").
12. **Use visual hierarchy** — Headers (`##`, `###`), tables, and emoji markers guide the eye and break up long text blocks.
13. **Note what is NOT required** — Explicitly stating "no external libraries needed" saves users from unnecessary searching.
14. **Include a license section** — Even a placeholder signals to contributors that licensing has been considered.
15. **Keep the README up to date** — Treat the README as living documentation; update it whenever features, dependencies, or build steps change.

---

## License

This project is open for educational use. If you wish to use or redistribute this project, please credit the original author:

**Muhammad Rashwan** — [GitHub Profile](https://github.com/muhammadRashwan1101)
