# push_swap

*Because Swap_push isn’t as natural* :bar_chart:

This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, you will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting. 

You have at your disposal a set of integer values, 2 stacks, and a set of instructions to manipulate both stacks. The instructions are as follows:

|operation|description|
|--|--|
| sa (swap a) | Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements. |
|sb (swap b)| Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements. |
|ss| sa and sb at the same time. |
|pa (push a)| Take the first element at the top of b and put it at the top of a. Do nothing if b is empty. |
|pb (push b)| Take the first element at the top of a and put it at the top of b. Do nothing if a is empty. |
|ra (rotate a)| Shift up all elements of stack a by 1. The first element becomes the last one. |
|rb (rotate b)| Shift up all elements of stack b by 1. The first element becomes the last one. |
|rr| ra and rb at the same time |
|rra (reverse rotate a)| Shift down all elements of stack a by 1. The last element becomes the first one. |
|rrb (reverse rotate b)| Shift down all elements of stack b by 1. The last element becomes the first one. |
| rrr|rra and rrb at the same time.|

## Why is push_swap important?

Writing a sorting algorithm is always a very important step in a developer’s journey. It is often the first encounter with the concept of complexity. Sorting algorithms and their complexity are part of the classic questions discussed during job interviews. It’s probably a good time to look at these concepts since you’ll have to face them at some point. The learning objectives of this project are rigor, use of C, and use of basic algorithms. Especially focusing on their complexity. Sorting values is simple. To sort them the fastest way possible is less simple. Especially because from one integers configuration to another, the most efficient sorting solution can differ.

## Implementation

I choose to implement a slightly modified  _radix_ sorting algorithm. It is fully documented at each file of this repository.

## Grade and Badge

![Sem título](https://user-images.githubusercontent.com/85964972/177241815-ea672483-c7a1-4c4c-bb44-f684b34a16b8.png)
![image](https://user-images.githubusercontent.com/85964972/177241853-89ff412e-727c-4fed-be9a-cd7295d928b2.png)

## Skills

- Rigor
- Unix
- Imperative programming
- Algorithms & AI
