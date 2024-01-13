#include "anomalydetector.h"

void detectAnomalies(double temperature, double windSpeed, FILE *outputFile) {
    // Assume anomaly if temperature is below a certain threshold (adjust as needed)
    if (temperature < 250.0) {
        fprintf(outputFile, "Low Temperature Anomaly Detected: %.2f°C, City Name: %s\n", temperature, "Africa");
    }

    // Assume anomaly if wind speed is below a certain threshold (adjust as needed)
    if (windSpeed < 1.50) {
        fprintf(outputFile, "Low Wind Speed Anomaly Detected: %.2f m/s, City Name: %s\n", windSpeed, "Africa");
    }

    // Add more conditions based on your requirements
    // ...
    if (temperature > 310.0) {
        fprintf(outputFile, " High Temperature Anomaly Detected: %.2f°C, City Name: %s\n", temperature, "Africa");
    }

    // Assume anomaly if wind speed is above a certain threshold (adjust as needed)
    if (windSpeed > 2.50) {
        fprintf(outputFile, "High Wind Speed Anomaly Detected: %.2f m/s, City Name: %s\n", windSpeed, "Africa");
    }
}


int main(void) {
    FILE *file = fopen("processoutput.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file for reading\n");
        return 1;
    }

    // Variables to store temperature and wind speed
    double temperature = 0.0;  
    double windSpeed = 0.0;    

    // Loop through each line in the file
    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        // Check if the line contains Temperature and Wind Speed information
        if (sscanf(line, "Temperature: %lf°C", &temperature) == 1) {
            // Temperature information found
        } else if (sscanf(line, "Wind Speed: %lf m/s", &windSpeed) == 1) {
            // Wind Speed information found
        }
    }

    // Close the file
    fclose(file);

    // Open a file for writing anomalies
    FILE *outputFile = fopen("anomalies.txt", "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Failed to open file for writing\n");
        return EXIT_FAILURE;
    }

    // Check for anomalies and save to the output file
    detectAnomalies(temperature, windSpeed, outputFile);

    // Close the output file
    fclose(outputFile);

    return EXIT_SUCCESS;
}
