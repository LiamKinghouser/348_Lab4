#include <stdio.h>
#include <string.h>  // For strcmp

// Converts celsius to fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (9.0 / 5.0) * celsius + 32;
}

// Converts fahrenheit to celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32);
}

// Converts celsius to kelvin
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

// Converts kelvin to celsius
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

// Converts fahrenheit to kelvin
float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

// Converts kelvin to fahrenheit
float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

// Categorizes temperature and provides advisory
void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Advisory: Extremely cold. Stay indoors if possible and bundle up!\n");
    } else if (celsius >= 0 && celsius <= 10) {
        printf("Temperature category: Cold\n");
        printf("Advisory: Wear warm clothing and limit exposure to cold.\n");
    } else if (celsius > 10 && celsius <= 25) {
        printf("Temperature category: Comfortable\n");
        printf("Advisory: The temperature is comfortable. Enjoy your day!\n");
    } else if (celsius > 25 && celsius <= 35) {
        printf("Temperature category: Hot\n");
        printf("Advisory: It's hot. Stay hydrated and avoid strenuous activity.\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Advisory: Extremely hot. Stay indoors, drink plenty of water.\n");
    }
}

int main() {
    char tempType, tempTypeTarget;
    float temp;

    // Input temperature type (F, C, K)
    do {
        printf("Enter the temperature type (F, C, K): ");
        scanf(" %c", &tempType);
    } while (tempType != 'F' && tempType != 'C' && tempType != 'K');

    // Input temperature value
    do {
        printf("Enter the temperature: ");
        scanf("%f", &temp);
        if (tempType == 'K' && temp < 0) {
            printf("Error: Kelvin temperature cannot be below 0.\n");
        }
    } while (tempType == 'K' && temp < 0);

    // Input target conversion type (F, C, K)
    do {
        printf("Convert to (F, C, K): ");
        scanf(" %c", &tempTypeTarget);
        if (tempTypeTarget == tempType) {
            printf("Error: Cannot convert between the same temperature type.\n");
        }
    } while ((tempTypeTarget != 'F' && tempTypeTarget != 'C' && tempTypeTarget != 'K') || tempTypeTarget == tempType);

    float convertedTemp;
    float tempCelsius;

    // Conversion logic
    if (tempType == 'F') {
        if (tempTypeTarget == 'C') {
            convertedTemp = fahrenheit_to_celsius(temp);
            printf("Temperature in Celsius: %.2f\n", convertedTemp);
            tempCelsius = convertedTemp;
        } else if (tempTypeTarget == 'K') {
            convertedTemp = fahrenheit_to_kelvin(temp);
            printf("Temperature in Kelvin: %.2f\n", convertedTemp);
            tempCelsius = fahrenheit_to_celsius(temp);  // For categorization
        }
    } else if (tempType == 'C') {
        if (tempTypeTarget == 'F') {
            convertedTemp = celsius_to_fahrenheit(temp);
            printf("Temperature in Fahrenheit: %.2f\n", convertedTemp);
        } else if (tempTypeTarget == 'K') {
            convertedTemp = celsius_to_kelvin(temp);
            printf("Temperature in Kelvin: %.2f\n", convertedTemp);
        }
        tempCelsius = temp;  // Already in Celsius
    } else if (tempType == 'K') {
        if (tempTypeTarget == 'F') {
            convertedTemp = kelvin_to_fahrenheit(temp);
            printf("Temperature in Fahrenheit: %.2f\n", convertedTemp);
            tempCelsius = kelvin_to_celsius(temp);  // For categorization
        } else if (tempTypeTarget == 'C') {
            convertedTemp = kelvin_to_celsius(temp);
            printf("Temperature in Celsius: %.2f\n", convertedTemp);
            tempCelsius = convertedTemp;
        }
    }

    // Categorize temperature
    categorize_temperature(tempCelsius);

    return 0;
}
