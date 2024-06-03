#include <stdio.h>

#define MAX_itr 1000
#define dt 0.01
#define BUF_SIZE 10
typedef float FLOAT32;
typedef int INT32;

typedef struct {
    FLOAT32 kp;
    FLOAT32 ki;
    FLOAT32 kd;

    FLOAT32 max_acc_error;
    FLOAT32 min_acc_error;
    FLOAT32 accumulated_error ;

    FLOAT32 prev_error; 
    
} PID_struct;

typedef enum{
    SATURATED , 
    NOT_SATURAATED

} BUFF_ENUM ; 

typedef struct 
{
    FLOAT32 buffer[BUF_SIZE] ;
    BUFF_ENUM status;
    INT32 index;

} filter_struct ;

FLOAT32 sum(FLOAT32 *array, int size ){
    FLOAT32 out = 0;
    for(int i = 0; i < size ; i++){
        out += array[i];
    }
    return out ; 
}

void init_PID(PID_struct *PID, FLOAT32 kp, FLOAT32 ki, FLOAT32 kd ){

    PID->kp = kp;
    PID->ki = ki;
    PID->kd = kd;
    PID->accumulated_error = 0;
    PID->prev_error = 0;
    PID->max_acc_error = 100; 
    PID->min_acc_error = -100; 

}

FLOAT32 update_PID(PID_struct PID, FLOAT32 setpoint , FLOAT32 curr_point){
    FLOAT32 error = setpoint - curr_point ; 

    PID.accumulated_error += error*dt ;
    if (PID.accumulated_error > PID.max_acc_error){
        PID.accumulated_error = PID.max_acc_error;
    }   
    else if (PID.accumulated_error < PID.min_acc_error){
        PID.accumulated_error = PID.min_acc_error;
    }

    FLOAT32 out = PID.kp * error + PID.ki * PID.accumulated_error + PID.kd * (error - PID.prev_error)/dt ;
    PID.prev_error = error;
    return out;

}

void init_filter(filter_struct *filter){
    memset(filter->buffer , 0, sizeof(filter->buffer));
    filter->status = SATURATED; 
    filter->index = 0;
}

FLOAT32 give_filtered(filter_struct *filter ,FLOAT32 val){

    if(filter->status != SATURATED){
        filter->buffer[filter->index] = val;
        filter->index += 1;
        return sum(filter, filter->index);
    }
    else{
        filter->index %= BUF_SIZE;
        filter->buffer[filter->index] = val;
        filter->index += 1;
        return sum(filter, BUF_SIZE);
    }

}


int main(){
    // Initialise PID structure
    PID_struct PID ;
    filter_struct filter;
    FLOAT32 setpoint = 10;
    FLOAT32 curr_point = 1;
    
    // Update PID struct with base values
    init_PID( &PID , 0.2 , 0.1, 0.01 );
    init_filter(&filter);

    // Run PID
    for(int i = 0; i < MAX_itr ; i++){
        FLOAT32 curr_point = give_filtered(&filter , curr_point);
        FLOAT32 duty = update_PID( PID, setpoint, curr_point );

    }

    FLOAT32 (*function_ptr)(FLOAT32 *array, int size)  = sum;
    
}

