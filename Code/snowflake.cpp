#include <string>
#include <fstream>
#include <cmath>

void draw_curve(float len, float depth, std::ofstream &out) {
    if (depth == 1) {
        out << "F," + std::to_string(len) << std::endl;
        return;
    }
    else {
        draw_curve(len/3,depth-1,out);
        out << "L,60\n";
        draw_curve(len/3,depth-1,out);
        out << "R,120\n";
        draw_curve(len/3,depth-1,out);
        out << "L,60\n";
        draw_curve(len/3,depth-1,out);
    }
}

int main(int argc, char* argv[]) {

    float length = std::stof(argv[1]);
    float depth = std::stof(argv[2]);
    std::ofstream out_file(argv[3]);

    if (depth < 1) {
        depth = 1;
    }

    if (length < 100) {
        length = 100;
    }
    else if (length > 700) {
        length = 700;
    }

    out_file << std::to_string(-1*length/2) + "," + std::to_string(length*1/6*sqrt(3)) << std::endl;

    // To draw the entire snowflake, we have to draw 3 different curves at 120 degree angles
    for (int i = 0 ; i < 3 ; i++) {
        draw_curve(length, depth, out_file);
        out_file << "R,120\n";
    }
}