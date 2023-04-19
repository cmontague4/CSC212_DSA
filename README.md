# CSC 212 - DSA (Recursive Graphics)

## Summary

Our project utilizes both C++ and Python in order to draw recursive fractals in Python's "Turtle" environment. The 3 fractals that our project covers are the Sierpinski Triangle, Koch Snowflake, and the Hilbert Curve. For each of the 3 shapes, there exists a C++ file which will use recursion to generate a string of commands, write said string to a .csv file, which a seperate Python script then interprets in order to draw the shapes. The commands are in the format `Direction,Value`, where `Direction` is either `F/B/L/R`, representing forwards, backwards, left, and right, and `Value` is an integer representing the amount of pixels/degrees to move or turn.
