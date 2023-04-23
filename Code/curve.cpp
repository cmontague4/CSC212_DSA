#include <string>
#include <fstream>
#include <cmath>

// Function to recursively write commands for the turtle to the outfile
void hilbert(float depth, float length, float angle, std::ofstream &out) {
    
    // Base case to end recursion if depth is 0
    if (depth == 0) {
        return;
    }
    
    // Contains recursive calls that keep the length, decrease the depth by 1, and flip the sign of the angle
    // Each command is written on a seperate line for the python draw_shape funtion to read
    
    // Turn the turtle by the current angle
    out << "R," + std::to_string(angle) << std::endl;
    
    // Decrease the depth and flip the angle for the sub hilbert curve
    hilbert(depth - 1, length, -1*angle, out);
    
    // Draw the first section of the most basic hilbert curve and turn left
    out << "F," + std::to_string(length) << std::endl;
    out << "L," + std::to_string(angle) << std::endl;
    
    // Decrease the depth but keep the angle of turn the same for the sub hilbert curve
    hilbert(depth - 1, length, angle, out);
    
    // Draw the second section of the most basic hilbert curve
    out << "F," + std::to_string(length) << std::endl;
    
    // Decrease the depth but keeo the angle of turn the same for the sub hilbert curve
    hilbert(depth - 1, length, angle, out);
    
    // Turn left and draw the third and final section of the most basic hilbert curve
    out << "L," + std::to_string(angle) << std::endl;
    out << "F," + std::to_string(length) << std::endl;
    
    // Decrease the depth and flip the angle of turn for the sub hilbert curve
    hilbert(depth - 1, length, -1*angle, out);
    
    // Turn right to adjust the turtle's position after it finishes drawing the most basic hilbert curve
    out << "R," + std::to_string(angle) << std::endl;

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

    // Math to find the side length of the total shape to center the drawing
    float pos = length/pow(2,(depth-1))*(pow(2,(depth-1))-0.5);
    
    // Writes the turtle's starting coordinates to the first line of the outfile to center the drawing
    out_file << " " + std::to_string(-1*pos) + "," + std::to_string(pos) << std::endl;

    // Calls the function to write out the turtle commands
    hilbert(depth, length/pow(2,(depth-1)), 90, out_file);
}
