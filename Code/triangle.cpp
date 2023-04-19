#include <string>
#include <fstream>

void draw_triangle(int length, int depth, std::string &out){
    if (depth==0){
        for (int i = 0; i < 3; i++){
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

    int length = std::stoi(argv[1]);
    int depth = std::stoi(argv[2]);
    std::ofstream out_file(argv[3]);

    std::string out_string;
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
