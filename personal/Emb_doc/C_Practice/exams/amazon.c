#include <stdint.h>
#include <string.h>

typedef enum {
    STATUS_SUCCESS,
    STATUS_NO_SENSOR_DATA,
} FuncStatus_t;

FuncStatus_t TransformData(const size_t inputDataLength, const uint8_t inputDataValues[], const size_t outputDataLength, uint8_t outputDataValues[]) {
    if (inputDataLength < 9 || outputDataLength < 33) {
        return STATUS_NO_SENSOR_DATA; // Assuming there is a status for incorrect length
    }

    // First, clear the output data array
    memset(outputDataValues, 0, outputDataLength);

    // Get the sensor valid bitmask
    uint8_t validBitMask = inputDataValues[0];
    uint8_t validSensorCount = 0;

    // Iterate through each sensor value
    for (int i = 0; i < 8; ++i) {
        if (validBitMask & (1 << i)) {
            ++validSensorCount;

            // Little-endian sensor value calculation
            uint32_t sensorValue = (uint32_t)inputDataValues[i + 1] * (1 << i);
            // Store the sensor value in little-endian format
            outputDataValues[1 + (i * 4)] = sensorValue & 0xFF;
            outputDataValues[2 + (i * 4)] = (sensorValue >> 8) & 0xFF;
            outputDataValues[3 + (i * 4)] = (sensorValue >> 16) & 0xFF;
            outputDataValues[4 + (i * 4)] = (sensorValue >> 24) & 0xFF;
        }
    }

    // Check if there are no valid sensors
    if (validSensorCount == 0) {
        return STATUS_NO_SENSOR_DATA;
    }

    // Set the number of valid sensors at the start of the output array
    outputDataValues[0] = validSensorCount;

    return STATUS_SUCCESS;
}