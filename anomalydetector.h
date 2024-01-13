#ifndef ANOMALY_DETECTOR_H
#define ANOMALY_DETECTOR_H

#include <stdio.h>
#include <stdlib.h>

// Structure to represent temperature data
typedef struct {
    char timestamp[50];
    char city_name[50];
    double temperature;
    double wind_speed;
} TemperatureData;

// Function to detect anomalies in temperature
void detectAnomalies(double temperature, double windSpeed, FILE *outputFile);

#endif  // ANOMALY_DETECTOR_H
