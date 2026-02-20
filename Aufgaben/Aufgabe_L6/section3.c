#include <stdio.h>
struct SensorData
{
    float time;
    double probability;
};
struct Sensor
{
    int id;
    double threshold;
    struct SensorData data[3000];
    int object_detection[];
};
/**
 * @brief Reads all sensor values from the given file and stores them in the sensor structure.
 *
 * This function reads up to @p arraysize entries from the file and writes the
 * time and probability values into the corresponding fields of the sensor's data array.
 *
 * @param[in,out] sensor   Pointer to the sensor structure where the values will be stored.
 * @param[in]     file     File handle from which the sensor values are read.
 * @param[in]     arraysize Number of values to read (maximum size of the data array).
 */
void read(struct Sensor *sensor, FILE *file, int arraysize)
{
    for (int i = 0; i < arraysize; i++)
    {
        float buf_time;
        double buf_prob;

        if (fscanf(file, "%f %lf", &buf_time, &buf_prob) == 2)
        {
            sensor->data[i].time = buf_time;
            sensor->data[i].probability = buf_prob;
        }
        else
        {
            break;
        }
    }
}
/**
 * @brief Prints all time intervals during which the sensor's probability exceeds its threshold.
 *
 * The function scans the sensor's data array and identifies continuous intervals
 * where the measured probability is greater than or equal to the sensor's threshold.
 * For each detected interval, the start and end timestamps are printed.
 *
 * @param[in] sensor     Pointer to the sensor structure containing the measurement data.
 * @param[in] arraysize  Number of entries in the sensor's data array.
 */
void output(struct Sensor *sensor, int arraysize)
{
    int output = 0;
    float start = 0;
    float end = 0;
    printf("Sensor %i detections:\n", sensor->id);
    for (int i = 0; i < arraysize; i++)
    {
        if (sensor->data[i].probability >= sensor->threshold && output == 0)
        {
            output = 1;
            start = sensor->data[i].time;
        }
        if (sensor->data[i].probability < sensor->threshold && output == 1)
        {
            output = 0;
            end = sensor->data[i - 1].time;
            printf("Start: %.2f s End: %.2f s\n", start, end);
        }
    }
    if (output == 1)
    {
        end = sensor->data[2999].time;
        printf("Start: %.2f s End: %.2f s\n", start, end);
    }
}
/**
 * @brief Prints time intervals where both sensors simultaneously exceed their thresholds.
 *
 * This function compares the probability values of two sensors at each timestamp.
 * Whenever both sensors exceed their respective thresholds at the same time,
 * the function records and prints the corresponding time interval.
 *
 * @param[in] sensor      Pointer to the first sensor structure.
 * @param[in] sensor2     Pointer to the second sensor structure.
 * @param[in] arraysize   Number of entries in the data arrays of both sensors.
 */
void output_both(struct Sensor *sensor, struct Sensor *sensor2, int arraysize)
{
    int output = 0;
    float start = 0;
    float end = 0;
    printf("Sensor %i detections:\n", sensor->id);
    for (int i = 0; i < arraysize; i++)
    {
        if ((sensor->data[i].probability >= sensor->threshold && output == 0) && (sensor2->data[i].probability >= sensor2->threshold && output == 0))
        {
            output = 1;
            start = sensor->data[i].time;
        }
        if ((sensor->data[i].probability < sensor->threshold && output == 1) || (sensor2->data[i].probability < sensor2->threshold && output == 1))
        {
            output = 0;
            end = sensor->data[i - 1].time;
            printf("Start: %.2f s End: %.2f s\n", start, end);
        }
    }
    if (output == 1)
    {
        end = sensor->data[3000].time;
        printf("Start: %.2f s End: %.2f s\n", start, end);
    }
}
int main()
{
    // open sensor data files
    FILE *sensdaten1 = fopen("sensor1.txt", "r");
    FILE *sensdaten2 = fopen("sensor2.txt", "r");
    //initializes both sensor structures
    struct Sensor sensor1;
    sensor1.id = 0x01;
    sensor1.threshold = 0.8;

    struct Sensor sensor2;
    sensor2.id = 0x02;
    sensor2.threshold = 0.7;
    // length of each sensor's data array
    int arraysize = sizeof sensor1.data / sizeof sensor1.data[0];
    //method calls
    read(&sensor1, sensdaten1, arraysize);
    read(&sensor2, sensdaten2, arraysize);

    output(&sensor1, arraysize);
    output(&sensor2, arraysize);

    output_both(&sensor1, &sensor2, arraysize);
    fclose(sensdaten1);
    fclose(sensdaten2);
}