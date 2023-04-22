# CSC 212 - DSA: Recursive Graphics

## Summary

Our project utilizes both C++ and Python in order to draw recursive fractals in Python's `Turtle` environment. The 3 fractals that our project covers are the Sierpinski Triangle, Koch Snowflake, and the Hilbert Curve. For each of the 3 shapes, there exists a C++ file which will write to a `csv` file a list of commands, which a seperate Python script then interprets in order to draw the shapes. The commands are in the format `Direction,Value`, where `Direction` is either `F/B/L/R`, representing forwards, backwards, left, and right, and `Value` is an integer representing the amount of pixels/degrees to move or turn. The first line of each command `csv` file is a coordinate pair in the form `(x,y)` which tells the Python script how to initially position the drawing cursor, so that the shapes are always centered.

## Instructions

#### Compilation

For each of the 3 C++ shape files, the files are all seperately compiled by invoking the g++ compiler. Simply enter `g++ -std=c++11 [SHAPE].cpp -o [SHAPE]` into the terminal, where `[SHAPE]` is either `triangle`, `snowflake`, or `curve`. No compilation is requred for the Python Script.

#### Runtime

To run each C++ program, the following 4 command line arguments are needed: `Executable Name, Length, Depth, Output File`. `Executable Name` is the executable associated with each of the 3 compiled shape generating programs, `Length` is the desired size of the outermost layer of depth for the shape, `Depth` is the desired amount of depth for the shape generating program to recurse through, and `Output File` is the name of the file to save the generated commands to, *always in `.csv` format*. For simplicity, `Output File` is typically named in the format `shape_length_depth.csv`. This will generate a `.csv` file, which can then be used with a Python script to draw the shapes. To run the python script, simply type `python3 draw_shape.py` into the terminal. The script will ask for an input file to read from, which is entered on the same line. It is important to note that input file should ideally be in the same directory as the Python script itself, otherwise additional text must be entered to direct the script to the file. The script will also handle error cases where an invalid or non-existent file name is input. Once a file has been entered, the script will ask if the user desires the colors of the shape to be randomized or not, prompting for either a `yes` or a `no` (not case-sensitive). Should an invalid word be entered, the script will ask for a valid choice. Once a color choice has been made, Python's `Turtle` module will draw the end result shape based on the commands generated by the C++ program for that `.csv` file. Once the shape has been drawn, simply click anywhere within the Python Turtle window to close the window and exit the script.
