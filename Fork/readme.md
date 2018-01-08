# Child Process
In mathematics, the Fibonacci numbers or Fibonacci series are the numbers in the following integer sequence :
> 0,    1,  1,  2,  3,  5,  8,  13, 21, 34, 55 , 89, 144 ....

By definition, the first two numbers in the Fibonacci sequence are 0 and 1, and each subsequent number is the sum of the previous two.

In mathematical terms, the sequence Fn of Fibonacci numbers is defined by the recurrence relation :
> ![Image of Yaktocat](http://www.sciweavers.org/upload/Tex2Img_1515390774/render.png)

Write a C program using the __fork()__ system call that generates the Fibonacci sequence in the child process.

For example, if 5 is provided, the first five numbers in the Fibonacci sequence will be output by the child process as the following :

> 0 , 1 , 1 , 2 , 3

Because the parent and child processes have their own copies of the data, it will be necessary for the child to output the sequence. Also provide that the parent will invoke __wait()__ system call for the child process to complete before exiting the program. Also each process will print their process identifier to the screen.




