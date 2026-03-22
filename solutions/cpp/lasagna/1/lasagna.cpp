// ovenTime returns the amount in minutes that the lasagna should stay in the oven.
int ovenTime() {
    // The cookbook says 40 minutes
    return 40;
}

/* remainingOvenTime returns the remaining
   minutes based on the actual minutes already in the oven.
*/
int remainingOvenTime(int actualMinutesInOven) {
    // Subtract the time already spent from the total oven time
    return ovenTime() - actualMinutesInOven;
}

/* preparationTime returns an estimate of the preparation time based on the
   number of layers and the necessary time per layer.
*/
int preparationTime(int numberOfLayers) {
    // Assuming 2 minutes of prep work per layer
    return numberOfLayers * 2;
}

// elapsedTime calculates the total time spent to create and bake the lasagna so far.
int elapsedTime(int numberOfLayers, int actualMinutesInOven) {
    // Total time is prep time + time currently spent in the oven
    return preparationTime(numberOfLayers) + actualMinutesInOven;
} 