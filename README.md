# 4241 4-bit Microprocessor

Registers: r0 r1

1-byte Instructions

* 0 = Halt
* 1 = Add (r0 = r0 + r1)
* 2 = Subtract (r0 = r0 - r1)
* 3 = Increment r0 
* 4 = Increment r1
* 5 = Decrement r0
* 6 = Decrement r1
* 7 = Swap registers and ring bell.

2-byte Instructions; Next byte interpreted as [data]

* 8  = Print [data]  (as a number)
* 9  = Load value at address [data] into r0
* 10 = Load value at address [data] into r1
* 11 = Store r0 into address [data]
* 12 = Store r1 into address [data]
* 13 = Jump to address [data]
* 14 = Jump to address [data] if r0 == 0
* 15 = Jump to address [data] if r0 != 0

-----

To run a program, write it out in a textfile, one hexadecimal character per instruction.  Run `test4241` with stdin redirected towards your program file.

Example program:
```
9F54
81F2
0000
0004
```
Execution:
`$ ./bin/test4241 < test.txt`

Whitespace and non-hexadecimal characters are ignored.
