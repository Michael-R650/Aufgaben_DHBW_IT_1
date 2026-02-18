//Logig ist gleich wie bei section3, jedoch hat gemini diesen Code in klar strukturierten Methoden untergeordnet
#include <stdio.h>

#define MAX_DATA 3000

struct SensorData {
    float time;
    double probability;
};

struct Sensor {
    int id;
    double threshold;
    struct SensorData data[MAX_DATA];
};


/* ------------------------- METHODEN ------------------------- */

// Liest Sensordaten aus einer Datei ein
int read_sensor_data(struct Sensor *sensor, FILE *file) {
    int count = 0;
    while (count < MAX_DATA &&
           fscanf(file, "%f %lf",
                  &sensor->data[count].time,
                  &sensor->data[count].probability) == 2)
    {
        count++;
    }
    return count;
}

// Gibt alle Detektionsintervalle eines Sensors aus
void print_single_sensor_detections(struct Sensor *sensor, int size) {
    int active = 0;
    float start = 0, end = 0;

    for (int i = 0; i < size; i++) {
        if (!active && sensor->data[i].probability >= sensor->threshold) {
            active = 1;
            start = sensor->data[i].time;
        }
        if (active && sensor->data[i].probability < sensor->threshold) {
            active = 0;
            end = sensor->data[i - 1].time;
            printf("Start: %.2f s  End: %.2f s\n", start, end);
        }
    }

    if (active) {
        end = sensor->data[size - 1].time;
        printf("Start: %.2f s  End: %.2f s\n", start, end);
    }
}

// Gibt Detektionen aus, bei denen beide Sensoren gleichzeitig auslösen
void print_combined_detections(struct Sensor *s1, struct Sensor *s2, int size) {
    int active = 0;
    float start = 0, end = 0;

    for (int i = 0; i < size; i++) {
        int cond1 = s1->data[i].probability >= s1->threshold;
        int cond2 = s2->data[i].probability >= s2->threshold;

        if (!active && cond1 && cond2) {
            active = 1;
            start = s1->data[i].time;
        }
        if (active && (!cond1 || !cond2)) {
            active = 0;
            end = s1->data[i - 1].time;
            printf("Start: %.2f s  End: %.2f s\n", start, end);
        }
    }

    if (active) {
        end = s1->data[size - 1].time;
        printf("Start: %.2f s  End: %.2f s\n", start, end);
    }
}


/* ------------------------- MAIN ------------------------- */

int main() {
    FILE *sensdaten1 = fopen("sensor1.txt", "r");
    FILE *sensdaten2 = fopen("sensor2.txt", "r");

    if (!sensdaten1 || !sensdaten2) {
        printf("Fehler beim Öffnen der Dateien.\n");
        return 1;
    }

    struct Sensor sensor1 = { .id = 0x01, .threshold = 0.8 };
    struct Sensor sensor2 = { .id = 0x02, .threshold = 0.7 };


    int size1 = read_sensor_data(&sensor1, sensdaten1);
    int size2 = read_sensor_data(&sensor2, sensdaten2);

    int size = (size1 < size2) ? size1 : size2;

    printf("Sensor 1 detections:\n");
    print_single_sensor_detections(&sensor1, size1);

    printf("\nSensor 2 detections:\n");
    print_single_sensor_detections(&sensor2, size2);

    printf("\nSensor 1 AND Sensor 2 detections:\n");
    print_combined_detections(&sensor1, &sensor2, size);

    fclose(sensdaten1);
    fclose(sensdaten2);

    return 0;
}