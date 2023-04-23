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
    // Shows that the length of each line will be the same
    // Each command is written on a seperate line for the python draw_shape funtion to read
    // F = Forward, L = Turn left, R = Turn right
    // F is by the length the turtle must move 
    // L and R are acommpanied by the degree of the angle of their turn which is 90 or -90
    out << "R," + std::to_string(angle) << std::endl;
    hilbert(depth - 1, length, -1*angle, out);
    out << "F," + std::to_string(length) << std::endl;
    out << "L," + std::to_string(angle) << std::endl;
    hilbert(depth - 1, length, angle, out);
    out << "F," + std::to_string(length) << std::endl;
    hilbert(depth - 1, length, angle, out);
    out << "L," + std::to_string(angle) << std::endl;
    out << "F," + std::to_string(length) << std::endl;
    hilbert(depth - 1, length, -1*angle, out);
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

    // Math to find geometric center of hilbert curve
    float pos = length/pow(2,(depth-1))*(pow(2,(depth-1))-0.5);
    
    // Writes the turtle's starting coordinates to the first line of the outfile to center the drawing
    out_file << " " + std::to_string(-1*pos) + "," + std::to_string(pos) << std::endl;

    // Calls the function to write out the turtle commands
    hilbert(depth, length/pow(2,(depth-1)), 90, out_file);
}
