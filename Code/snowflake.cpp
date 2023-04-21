#include <string>
#include <fstream>
#include <cmath>

void draw_curve(float len, float depth, std::string &out_s) {
    if (depth == 1) {
        out_s += " F," + std::to_string(len);
        return;
    }
    else {
        draw_curve(len/3,depth-1,out_s);
        out_s += " L,60";
        draw_curve(len/3,depth-1,out_s);
        out_s += " R,120";
        draw_curve(len/3,depth-1,out_s);
        out_s += " L,60";
        draw_curve(len/3,depth-1,out_s);
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
    out_string += " " + std::to_string(-1*length/2) + "," + std::to_string(length*1/6*sqrt(3));

    // To draw the entire snowflake, we have to draw 3 different curves at 120 degree angles
    for (int i = 0 ; i < 3 ; i++) {
        draw_curve(length, depth, out_string);
        out_string += " R,120" ;
    }
    
    for (int i = 1 ; i < out_string.size() ; i++) {
        if (out_string[i] == ' '){
            out_file << "\n";
        }
        else{
            out_file << out_string[i];
        }

    }
}