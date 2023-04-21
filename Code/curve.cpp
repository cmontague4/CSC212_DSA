#include <string>
#include <fstream>
#include <cmath>

void hilbert(float depth, float length, float angle, std::string &out_s) {
    if (depth == 0) {
        return;
    }
    out_s += " R," + std::to_string(angle);
    hilbert(depth - 1, length, -1*angle, out_s);
    out_s += " F," + std::to_string(length);
    out_s += " L," + std::to_string(angle);
    hilbert(depth - 1, length, angle, out_s);
    out_s += " F," + std::to_string(length);
    hilbert(depth - 1, length, angle, out_s);
    out_s += " L," + std::to_string(angle);
    out_s += " F," + std::to_string(length);
    hilbert(depth - 1, length, -1*angle, out_s);
    out_s += " R," + std::to_string(angle);

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
    float pos = length/pow(2,(depth-1))*(pow(2,(depth-1))-0.5);
    out_string += " " + std::to_string(-1*pos) + "," + std::to_string(pos);
    hilbert(depth, length/pow(2,(depth-1)), 90, out_string);

    for (int i = 1 ; i < out_string.size() ; i++) {
        if (out_string[i] == ' '){
            out_file << "\n";
        }
        else{
            out_file << out_string[i];
        }

    }

}