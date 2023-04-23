#include <string>
#include <fstream>
#include <cmath>

// Function to recursively write commands for the turtle to the outfile
void draw_triangle(float length, float depth, std::ofstream &out){
    
    // Base case to end recursion if depth is 1
    if (depth == 1){
        // Loop to write the commands to draw a single equilateral triangle
        for (int i = 0 ; i < 3 ; i++){
            out << " F," + std::to_string(length) << std::endl;
            out << " L,120\n";
        }
    }
    // Writes out the rest of the commands for drawing the other triangles
    else {
        // Contains recursive calls that halves the length and decreases the depth by 1
        // Shows that the inner triangles will get smaller and smaller for higher depths
        // Each command is written on a seperate line for the python draw_shape funtion to read
        // F = Forward, B = Pick up pen and move backwards, L = Turn left, R = Turn right
        // F and B are accompanied by the length they must move 
        // L and R are acommpanied by the degree of the angle of their turn which is 60 for an equilateral triangle
        draw_triangle(length / 2, depth - 1, out);
        out << " F," + std::to_string(length/2) << std::endl;
        draw_triangle(length / 2, depth - 1, out);
        out << " B," + std::to_string(length/2) << std::endl;
        out << " L,60\n";
        out << " F," + std::to_string(length/2) << std::endl;
        out << " R,60\n";
        draw_triangle(length / 2, depth - 1, out);
        out << " L,60\n";
        out << " B," + std::to_string(length/2) << std::endl;
        out << " R,60\n";
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
    out_file << std::to_string(-1*length/2) + "," + std::to_string(-1*length/4*sqrt(3)) << std::endl;

    // Calls the function to write out the turtle commands
    draw_triangle(length, depth, out_file);

}
