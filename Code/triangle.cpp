#include <string>
#include <fstream>
#include <cmath>

void draw_triangle(float length, float depth, std::ofstream &out){
    if (depth == 1){
        for (int i = 0 ; i < 3 ; i++){
            out << " F," + std::to_string(length) << std::endl;
            out << " L,120\n";
        }
    }
    else {
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

    out_file << std::to_string(-1*length/2) + "," + std::to_string(-1*length/4*sqrt(3)) << std::endl;

    draw_triangle(length, depth, out_file);

}