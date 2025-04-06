# Wordle - Terminal Game in C

This project is a text-based version of the popular Wordle game, implemented in the C programming language.

## What is Wordle?

Wordle is a word guessing game where the objective is to guess a hidden 5-letter word within 6 attempts. It's a game of logic, vocabulary, and deduction.

## Game Rules

1. **Guess the Word**:  
   You have to guess a 5-letter English word.

2. **Feedback After Each Guess**:  
   After each guess, the game provides feedback for every letter in your word:
   - 🟩 **Green**: The letter is in the correct position.
   - 🟨 **Yellow**: The letter exists in the word but is in the wrong position.
   - 🟥 **Red**: The letter is not in the word at all.

3. **Win or Lose**:
   - You win if you guess the word correctly within 6 tries.
   - If you run out of tries, the correct word is revealed.

## Example

Let's say the target word is `PLANT` and the player guesses `PARTY`:


This means:
- 'P' is correct and in the correct position (🟩)
- 'A' is in the word but in the wrong position (🟨)
- 'R', 'T', and 'Y' are not in the word (🟥)

## Game Objectives

- Encourage logical thinking and pattern recognition.
- Improve vocabulary and spelling.
- Fun and challenging brain exercise.

## Customization

- You can modify the word list (`wordl.txt`) to change the difficulty or language.
- The number of attempts and word length can be adjusted in the code for variations.

---

# Wordle Game in C – Setup and Execution Steps

## 📁 Files Required

- `Wordle_Final.c` – Main source code
- `Wordle.h` – Header file
- `wordl.txt` – List of 5-letter words

## ⚙️ Prerequisites

- GCC compiler installed (`gcc`)
- Terminal or command prompt
- All files placed in the same folder

## 🛠️ Steps to Compile and Run

1. **Open the terminal**  
   Navigate to the folder containing the files
2. **Compile the code using gcc**
   gcc Wordle_Final.c -o wordle
3. **Run the program**
   On Linux/macOS: ./wordle
   
   On Windows: wordle.exe
   

