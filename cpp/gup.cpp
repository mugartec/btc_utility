#include "gup.hpp"

using namespace std;

int main(int argc, char** argv){
    
    generate_gup_plot(0, 1);
    
    return 0;
}


void generate_gup_plot(double initial_i, double final_i){

    mpf_set_default_prec (PREC);
    double h_step = (double)(final_i - initial_i)/NUM_POINTS;
    double h;


    // Generate each point
    double xvals[NUM_POINTS];

    mpf_class Y[5][NUM_POINTS];
    
    for(int i = 0; i < NUM_POINTS; i++){
        h = initial_i + (i+1) * h_step;
        // Gnuplots' fault:
        if(i == NUM_POINTS-1){ h -= h_step;}

        xvals[i] = h;
        Y[0][i] = def(h);
        Y[1][i] = util(1, 2, h);
        Y[2][i] = util(1, 3, h);
        Y[3][i] = util(1, 4, h);
        Y[4][i] = util(1, 5, h);
        
        cout << i << endl;
    }

    string names[5] = {
        "Default.temp", 
        "g12.temp",
        "g13.temp",
        "g14.temp",
        "g15.temp"
    };
    
    generate_plot_mpf(5, xvals, Y, names);
}