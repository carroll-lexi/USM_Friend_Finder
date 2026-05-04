# USM_Friend_Finder

**Author:** Team Friend Finder, Group S02G4: Lexi Carroll, Toby (Tawnie) Holekamp, Valencia Watson

**Course:** CSC 307 H002

**Semester:** Spring 2026

--- 

## 1. Prerequisites & Environment 

Before running this project, ensure your system meets the following requirements: 

* **Operating System:** Windows 7 or later, Linux with glibc 2.12 or newer, macOS 15.2+

* **Compiler:** g++ (MSYS2 UCRT64), C++17 or newer

 
### Required Libraries 
No external frameworks used

Only Standard C++ Libraries Used:
- <iostream>
- <vector>
- <map>
- <queue>
- <fstream>
- <sstream>
- <algorithm>
- <string>

--- 

## 2. Installation & Setup 

1. Clone the repo: `git clone https://github.com/carroll-lexi/USM_Friend_Finder.git`

2. Navigate into the project directory.

3. Ensure all .cpp and .h files are in the same folder

--- 

## 3. Build Instructions 
**Using Command Line:** 

cd [project_directory]

g++ main.cpp Graph.cpp FileIO.cpp -o main.exe


**Using IDE:** 

* Open Visual Studio 2022. 

* Create a new Empty C++ Project

* Add all .cpp and .h files to the project

* Set the build configuration to **Release / x64**. 

* Press `Ctrl+Shift+B` to build. 

* Run the program using Local Windows Debugger

--- 

## 4. Execution Guide 

* **Executable Name:** `main.exe` 

* **Entry Point:** No command-line arguments required

* **Assets:** No specific directory needed to run executables.

--- 

## 5. Troubleshooting / Known Issues 

* All source files must be in the same directory when compiling
* If compilation fails, ensure that g++ is installed and added to PATH
* File loading requires the saved data file to be in the same directory as the executable