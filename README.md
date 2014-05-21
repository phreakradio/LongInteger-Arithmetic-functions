LongInteger-Arithmetic-functio
================================

Application that deal with Long Integers written in C++

listadt.cpp
- Uses linked lists to construct large integers (>18 digits)
- Contains functionality to alter list

longInt.h
- Header file

longInt.cpp
- Contains arithmetic functions 
- Implements longIntegers
- Converts string input to longInt
- FUNCTIONS:
    - INITIALIZE: TAKES STRING INPUT AND CONVERTS IT TO longInt OBJECT
    - GETSIGN: RETURNS SIGN OF longInt OBJECT
    - SETSIGN: SETS SIGN OF longInt OBJECT
    - GETDIGITCOUNT: RETURNS # OF DIGITS IN longInt OBJECT
    - PRINT: PRINTS longInt OBJECT
    - GREATERTHAN: COMPARES THE longInt OBJECT THAT CALLS THE FUNCTION AGAINST A longInt PARAMETER
    - LESSTHAN: (same as above)
    - EQUALTO: (same as above)
    - OVER_FLOW: MAINTAINS STRUCTURE OF NODES IN longInt OBJECT. SOMETIMES, NODES ARE OUT OF BOUNDS AND MUST BE ADJUSTED
    - DIGIT: RETURNS # OF DIGITS IN longInt NODE
    - ARITHMETIC FUNCTIONS: ADD, SUBTRACT, MULTIPLY, DIVIDE, POWER
