# push_swap

 [![Intro](https://img.shields.io/badge/Cursus-Push_Swap-success?style=for-the-badge&logo=42)](https://github.com/Apeslx/push_swap)
 
 [![Stars](https://img.shields.io/github/stars/Apeslx/push_swap?color=ffff00&label=Stars&logo=Stars&style=?style=flat)](https://github.com/Apeslx/push_swap)
 [![Size](https://img.shields.io/github/repo-size/Apeslx/push_swap?color=blue&label=Size&logo=Size&style=?style=flat)](https://github.com/Apeslx/push_swap)
 [![Activity](https://img.shields.io/github/last-commit/Apeslx/push_swap?color=red&label=Last%20Commit&style=flat)](https://github.com/Apeslx/push_swap)
 
This project focuses on algorithmics. I've developed an algorithm capable of sorting, from smallest to bigest, an undefined number of unique values. To achieve this, it utilizes two stacks and a specific set of instructions outlined below. Additionally, a visualizer is included to illustrate the sorting process for better comprehension.

To develop this algorithm, I was restricted from using any C functions other than 'malloc,' 'free,' 'write,' 'read,' and 'exit'.

## Getting Started

### Prerequisites

Before you can start installing push_swap, make sure you have the following prerequisites installed on your computer:

- C Compiler (e.g., GCC)
- Make
  
For the visualizer:

- Python3 (with tkinter)

### Installation

1. Clone the push_swap repository to your local machine:

   ```shell
   git clone https://github.com/Apeslx/push_swap.git push_swap
2. Change your current working directory to the project folder:
   
   ```shell
   cd push_swap
3. Compile the game using the provided Makefile:

   ```shell
   make

## Running the program

To launch push_swap, use the following command.

   ```shell
   ./push_swap [num1] [num2] [num3] ...
   ```
Replace '[num1] ...' with the list of numbers you want to sort. They can be negative numbers. If two or more numbers are the same or if an argument is invalid, an error message will be displayed. If launched correctly, push_swap will print every instruction it takes to sort the numbers.<br><br>
If you want to launch push_swap with the visualizer use this command.

   ```shell
   python3 python_visualizer.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
   ```

The numbers in parenthesis indicate the numbers to sort. Ex: (1..100) = from 1 to 100.

## About the algorithm

This is a concise overview of its functioning. If you aim to reproduce it, there are several additional factors to consider.

### How it works

1. The algorithm begins by pushing two numbers from stack A to stack B. This is necessary as it requires both a maximum and a minimum number to function properly.

2. Next, it compares the number of instructions needed for each number in stack A to be correctly placed in stack B. The numbers in stack B are arranged from largest to smallest. This ensures that when they are pushed back to stack A, they are correctly sorted from smallest to largest.

3. The cheapest number is moved to the top of stack A. <br>
If the number being pushed is either a new maximum or minimum, it is placed just above the old maximum number.

4. Stack B is then rotated to position the number from stack A correctly when puhsing.
   
5. Steps 2 - 3 are repeated until every number has been pushed to stack B.

6. Finally, all numbers are pushed back to stack A. If the smallest number is not at the top of the stack, stack A is rotated until it is.

### Instructions

The algorithm only uses the following instructions when sorting:

- Swap stack A (`sa`): Swaps the first two elements of stack A.
- Swap stack B (`sb`): Swaps the first two elements of stack B.
- Swap both (`ss`): Swaps the first two elements of both stacks.
- Push to stack B (`pb`): Pushes the first element from stack A to the first position of stack B.
- Push to stack A (`pa`): Pushes the first element from stack B to the first position of stack A.
- Rotate stack A (`ra`): Shift all elements of stack A up by one position, so that the first element becomes the last.
- Rotate stack B (`rb`): Shift all elements of stack B up by one position, so that the first element becomes the last.
- Rotate both (`rr`): Rotates both stacks.
- Reverse rotate stack A (`rra`): Shift all elements of stack A down by one position, so that the last element becomes the first.
- Reverse rotate stack B (`rrb`): Shift all elements of stack B down by one position, so that the last element becomes the first.
- Reverse rotate both (`rrr`): Reverse rotates both stacks.

## Screenshots

![Demo GIF](https://github.com/Apeslx/push_swap/blob/main/screenshots/ScreenRecording.gif)
