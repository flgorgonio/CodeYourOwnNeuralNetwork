//
//  Code Your Own Neural Network
//  Adapted from Steven C. Shaffer
//  Code Your Own Neural Network, 2015
//

#include <stdio.h>
#include <stdlib.h>
#include <cmath>

const int NUM_INPUT_NODES = 2;
const int NUM_HIDDEN_NODES = 2;
const int NUM_OUTPUT_NODES = 1;

const int NUM_NODES = NUM_INPUT_NODES + NUM_HIDDEN_NODES + NUM_OUTPUT_NODES;
const int ARRAY_SIZE = NUM_NODES + 1;

const int MAX_INTERATIONS = 131072;
const double E = 2.71828;
const double LEARNING_RATE = 0.2;

void initialize(double [][ARRAY_SIZE], double [], double [], double []);
void connect_nodes(double [][ARRAY_SIZE], double []);
void training_example(double [], double []);
double update_weights(double [][ARRAY_SIZE], double [], double [], double []);
void display_network(double [], double);
void active_network(double [][ARRAY_SIZE], double [], double []);

int main(void){
    double weights[ARRAY_SIZE][ARRAY_SIZE];
    double values[ARRAY_SIZE];
    double expected_values[ARRAY_SIZE];
    double thresholds[ARRAY_SIZE];
    double sum_of_squared_errors;

    printf("Neural Network Program\n");

    initialize(weights, values, expected_values, thresholds);
    connect_nodes(weights, thresholds);

    int counter = 0;
    while (counter < MAX_INTERATIONS) {
        training_example(values, expected_values);
        active_network(weights, values, thresholds);
        sum_of_squared_errors = update_weights(weights, values, expected_values, thresholds);
        display_network(values, sum_of_squared_errors);
        counter++;
    }

    return 0;
}



void initialize(double weights[][ARRAY_SIZE], double values[], double expected_values[], double thresholds[]){
    for (int i = 0; i <= NUM_NODES; i++){
        values[i] = 0.0;
        expected_values[i] = 0.0;
        thresholds[i] = 0.0;
        for (int j = 0; j <= NUM_NODES; j++){
            weights[i][j] = 0.0;
        }
    }
}



void connect_nodes(double weigths[][ARRAY_SIZE], double threshold[]){
    for (int i = 1; i <= NUM_NODES; i++){
        for (int j = 1; j <= NUM_NODES; j++){
            weigths[i][j] = (rand() % 200) / 100.0;
        }
    }

    threshold[3] = rand() / (double) rand();
    threshold[4] = rand() / (double) rand();
    threshold[5] = rand() / (double) rand();
    
    printf("%f\t%f\n", weigths[1][3], weigths[1][4]);
    printf("%f\t%f\n", weigths[2][3], weigths[2][4]);
    printf("%f\t%f\n", weigths[3][5], weigths[4][5]);
    printf("%f\t%f\t%f\n", threshold[3], threshold[4], threshold[5]);
}