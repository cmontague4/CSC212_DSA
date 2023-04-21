#include <string>
#include <fstream>
#include <cmath>

void draw_triangle(float length, float depth, std::string &out){
    if (depth == 1){
        for (int i = 0 ; i < 3 ; i++){
            out += " F," + std::to_string(length);
            out += " L,120";
        }
    }
    else {
        draw_triangle(length / 2, depth - 1, out);
        out += " F," + std::to_string(length/2);
        draw_triangle(length / 2, depth - 1, out);
        out += " B," + std::to_string(length/2);
        out += " L,60";
        out += " F," + std::to_string(length/2);
        out += " R,60";
        draw_triangle(length / 2, depth - 1, out);
        out += " L,60";
        out += " B," + std::to_string(length/2);
        out += " R,60";
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

    std::string out_string;
    out_string += " " + std::to_string(-1*length/2) + "," + std::to_string(-1*length/4*sqrt(3));

    draw_triangle(length, depth, out_string);
    
    for (int i = 1 ; i < out_string.size() ; i++) {
        if (out_string[i] == ' '){
            out_file << "\n";
        }
        else{
            out_file << out_string[i];
        }

    }
}