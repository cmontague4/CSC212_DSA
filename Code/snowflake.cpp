#include <string>
#include <fstream>
#include <cmath>

// Function to recursively write commands for the turtle to the outfile to draw a curve of the snowflake
void draw_curve(float len, float depth, std::ofstream &out) {
    
    // Base case to end recursion if depth is 1
    // Writes the commands to draw an equilateral triangle when called 3 times by main
    if (depth == 1) {
        out << "F," + std::to_string(len) << std::endl;
        return;
    }
    else {
        
        // Contains recursive calls that divide the length by 3 and decrease the depth by 1
        // Each command is written on a seperate line for the python draw_shape funtion to read
        
        // Call to draw the first section of the current depth
        draw_curve(len/3,depth-1,out);
        
        // Turn left 60 degrees
        out << "L,60\n";
        
        // Draw the second section (first branching section) of the current depth
        draw_curve(len/3,depth-1,out);
        
        // Turn right 120 degrees
        out << "R,120\n";
        
        // Draw the third second (second branching section) of the current depth
        draw_curve(len/3,depth-1,out);
        
        // Turn left 60 degrees, draw the fourth and final section of the current depth
        out << "L,60\n";
        draw_curve(len/3,depth-1,out);
    }
}

// Main function that will take in command line arguments to set the depth and length of the drawing and create an outfile for the turtle commands
int main(int argc, char* argv[]) {

    // Gets both values and the outfile name from the command line
    float length = std::stof(argv[1]);
    float depth = std::stof(argv[2]);
    std::ofstream out_file(argv[3]);

    // Preventing invalid depths
    if (depth < 1) {
        depth = 1;
        // Minimum depth of 1
    }

    // Preventing invalid lengths (too big or small)
    if (length < 100) {
        length = 100;
        // Minimum length of 100
    }
    else if (length > 700) {
        length = 700;
        // Maximum length of 700
    }

    // Writes the turtle's starting coordinates to the first line of the outfile to center the drawing
    out_file << std::to_string(-1*length/2) + "," + std::to_string(length*1/6*sqrt(3)) << std::endl;

    // To draw the entire snowflake, we have to draw 3 different curves at 120 degree angles
    for (int i = 0 ; i < 3 ; i++) {
        draw_curve(length, depth, out_file);
        out_file << "R,120\n";
    }
}
