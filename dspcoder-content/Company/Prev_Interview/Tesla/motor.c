#include <stdio.h>
#include <math.h>


float motor_model(double dt, double vol) {
    static double t = 0; 
    t += dt; 

    float speed = vol * 64 * (0.0274725 - 0.0274725 * exp(-36.4 * t));

    return speed; 
}

int main() {
    double simulation_time = 10;  // Simulation time in seconds
    double dt = 0.1;            // Time step for simulation
    float speed = 0.0; 

    for (double t = 0; t < simulation_time; t += dt) {
        if (t < 4){
            speed = motor_model(dt, 0.1f);
        }
        else if(t >= 4 && t < 6 ){
            speed = motor_model(dt, 0.2f);
        }
        else{
            speed = motor_model(dt, -0.3f);
        }
        
        printf("Time: %.3f seconds, Speed: %.3f rad/s\n", t, speed);
    }

    return 0;
}


/**
 * 
 * A *  64 (0.0274725 - 0.0274725 e^(-36.4 t))
*/