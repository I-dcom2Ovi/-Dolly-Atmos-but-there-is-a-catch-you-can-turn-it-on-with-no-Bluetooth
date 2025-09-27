// ovisurround.c
// OviSurround - Custom Surround Sound Engine (C version)
// Created: 2025 by Ovizikhungo
// License: Ovi License (see LICENSE file in repo)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define DURATION 3
#define FREQ 440

// Generate a simple sine wave tone
void generate_tone(float* buffer, int samples, float freq) {
    for (int i = 0; i < samples; i++) {
        buffer[i] = sinf(2.0f * M_PI * freq * i / SAMPLE_RATE);
    }
}

// Apply simple surround effect (fake 3D)
void ovisurround_process(float* left, float* right, int samples) {
    for (int i = 300; i < samples; i++) {
        right[i] += right[i - 300] * 0.4f; // delay + attenuation
        if (right[i] > 1.0f) right[i] = 1.0f;
        if (right[i] < -1.0f) right[i] = -1.0f;
    }
}

int main() {
    int samples = SAMPLE_RATE * DURATION;

    float* left = (float*)malloc(sizeof(float) * samples);
    float* right = (float*)malloc(sizeof(float) * samples);

    if (!left || !right) {
        printf("Error allocating memory.\n");
        return 1;
    }

    generate_tone(left, samples, FREQ);
    generate_tone(right, samples, FREQ);

    ovisurround_process(left, right, samples);

    printf("OviSurround C demo generated %d samples per channel.\n", samples);
    printf("This is a placeholder. Integrate with your audio output library to play sound.\n");

    free(left);
    free(right);

    return 0;
}