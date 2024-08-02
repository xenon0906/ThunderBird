# Thunderbird Quiz Program

Welcome to the Thunderbird Quiz Program! This simple quiz application, written in C, tests your knowledge about India, covering various aspects such as geography, history, culture, and more. The program features an interactive menu, colorful console output, a timing mechanism, and a scoring system to enhance your quiz experience.

## Key Features

### 1. Menu Display
- The program begins by displaying a menu that outlines the rules of the quiz.
- Users are provided with options to either start the quiz or exit the program.

### 2. Colorful Console Output
- To enhance the visual presentation, the program uses console text colors for questions and answers.
- Functions like `setConsoleColor` and `resetConsoleColor` are used to set and reset text colors, making the quiz visually appealing.

### 3. Timing Mechanism
- Each question comes with a time limit of 10 seconds.
- The program records the time when the question is displayed and compares it with the time when the user provides an answer.
- If the user exceeds the time limit, a message is displayed indicating that the time is up.

### 4. Scoring
- The program evaluates the user's answers and keeps track of the number of correct responses.
- At the end of the quiz, the total number of correct answers and the percentage of correct answers are displayed.

### 5. User Interaction
- The program utilizes a loop to allow users to navigate the menu and enter their quiz answers.
- Users receive feedback on their performance at the end of the quiz.

## How to Use
1. Run the program.
2. The main menu will be displayed with options to start the quiz or exit.
3. If you choose to start the quiz, the questions will be displayed one by one.
4. Answer each question within the 10-second time limit.
5. After answering all questions, the program will display your score and the percentage of correct answers.
6. You can then choose to take the quiz again or exit the program.

## Dependencies
- This program requires a C compiler to compile and run.

## Compilation and Execution
1. Compile the program using a C compiler. For example:
   ```bash
   gcc quiz_program.c -o quiz_program
   ```
2. Run the compiled program:
   ```bash
   ./quiz_program
   ```

Enjoy testing your knowledge about India with the Thunderbird Quiz Program!
