Brainfuck-string-generator
==========================

This is a c program which reads string from input file and generates a [BrainFuck](http://en.wikipedia.org/wiki/Brainfuck) program which will print the same string as output. This is not the most efficient program that can do the same thing. To print the string specified below, it generates Brainfuck program which has 3280 characters  

```
abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+[]\{}|;':",./<>?
```

How to run
----------
 - run following command to execute the project  
 ```
 g++ -o bf_string_generator bf_string_generator.c converter_helper.c
 ```
 - save string in file eg **input.txt**
 - run following command
 ```
 ./bf_string_generator.exe input.txt
 ```
 - Output on stdin is the desired BrainFuck program