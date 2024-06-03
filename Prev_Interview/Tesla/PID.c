#include <stdio.h>
#include <stdlib.h>  
#include <math.h>


typedef struct  
{
    float prev_error; 
    float reference; 
    float kp; 
    float ki; 
    float kd; 
    float dt; 
    float integral_val ; 
    float derivative; 
    float error; 
    float applied_vol ; 


} PID;

void initPID(PID *PID_config){
    PID_config->kp = 0.6f; 
    PID_config->kd = 0.0f; 
    PID_config->ki = 0.01f;

    PID_config->prev_error = 0.0f; 
    PID_config->reference = 1.0f; 
    PID_config->dt = 0.01; 
    PID_config->integral_val = 0.0f; 
    PID_config->applied_vol = 0.0f; 
    PID_config->derivative = 0.0f; 
    PID_config->error = 0.0f; 
}

float give_curr_speed(float t, PID *PID_config){
    
    float speed = PID_config->applied_vol * 64 * (0.0274725 - 0.0274725 * exp(-36.4 * t));
    
    // * 64 * (0.0274725 - 0.0274725 * exp(-36.4 * t));

    // 64 (0.0274725 t + 0.00075474 e^(-36.4 t) - 0.00075474)

    //  (0.01 /(25.0156 * exp(-2.0025* t) - 25.0156 * exp(-9.9975 * t))) ; 

    return speed; 
}; 

void PIDUpdate(float speed,  PID *PID_config){

    PID_config->error = PID_config->reference - speed; 
    PID_config->integral_val += PID_config->error * PID_config->dt; 
    PID_config->derivative = (PID_config->error - PID_config->prev_error)/PID_config->dt ; 


    float vol =   PID_config->kp * PID_config->error + \
                                PID_config->kd * PID_config->derivative + \
                                PID_config->ki * PID_config->integral_val ; 

    PID_config->applied_vol = fmax(-12, fmin(vol, 12)); 
    PID_config->prev_error = PID_config->error; 
    
}

void py_fun(){
    printf("called from c"); 
}


int main() {
    printf("PID control for DC Motor\n"); 
    float curr_speed = 0.0f; 
    float dutyCycle = 0.0f; 

    float simulation_time = 20; 
    
    PID *PID_config = (PID *)malloc(sizeof(PID)); 
    initPID(PID_config); 

    float t = 0; 
    printf("---------------"); 

    while(t < simulation_time){
        t += PID_config->dt; 

        // get current speed
        curr_speed = give_curr_speed(t, PID_config); 

        // Update PID block
        PIDUpdate(curr_speed, PID_config); 

        printf(" Current : %.3f \t| Reference : %.3f \t| Voltage : %.3f\n", curr_speed, PID_config->reference, PID_config->applied_vol); 

    }
    printf("---------------"); 

    return 0;
}
