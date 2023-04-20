#include <string>
#include <fstream>

void draw_curve(int len, int depth, std::string &out_s) {
    if (depth == 0) {
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

    int length = std::stoi(argv[1]);
    int depth = std::stoi(argv[2]);
    std::ofstream out_file(argv[3]);

    std::string out_string;

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
