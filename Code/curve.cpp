#include <string>
#include <fstream>
#include <cmath>

void hilbert(float depth, float length, float angle, std::ofstream &out) {
    if (depth == 0) {
        return;
    }
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

    float pos = length/pow(2,(depth-1))*(pow(2,(depth-1))-0.5);
    out_file << " " + std::to_string(-1*pos) + "," + std::to_string(pos) << std::endl;

    hilbert(depth, length/pow(2,(depth-1)), 90, out_file);


}
