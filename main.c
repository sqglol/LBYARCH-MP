#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10 // EDIT FOR SIZE Y
#define COLS 3

extern void compute_accelerations(float *car_info, int y, int* acceleration_list);

float random_float(float max) {
    int max_range = (int)(max * 10.0f);

    int rand_scaled_int = rand() % max_range;

    return (float)rand_scaled_int / 10.0f;
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    int y = ROWS;

    /*float car_info[ROWS][COLS] = {
        {0.0, 62.5, 10.1},
        {60.0, 122.3, 5.5},
        {30.0, 160.7, 7.8}
    };*/

    float car_info[ROWS][COLS];

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 2)
                car_info[i][j] = random_float(10.0f);
            else
                car_info[i][j] = random_float(100.0f);        
        }

    }
    int *acceleration_list = malloc(y * sizeof(int));

    compute_accelerations(&car_info[0][0], y, acceleration_list);

    for (int i = 0; i < y; i++) 
        printf("Car %d | Vi = %.1f | Vf = %.1f | T = %.1f | \n", i+1, car_info[i][0], car_info[i][1], car_info[i][2]);
    printf("\n\n\n");

    for (int i = 0; i < y; i++)
        printf("Car %d's Acceleration: %d m/s^2\n", i + 1, acceleration_list[i]);
	
	return 0;
}
