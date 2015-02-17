#define LED D7

#include "plotly_spark.h"
#include "math.h"

#define NUM_TRACES 2

char *streaming_tokens[NUM_TRACES] = {"aaaaaaaaaa","bbbbbbbbbb"};
plotly graph = plotly("xxxxxxxxx", "yyyyyyyyyy", streaming_tokens, "Temperature", NUM_TRACES);

void setup() {
    // Prepare LED
    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);

    // Prepare Serial for debugging
    Serial.begin(9600);
    Serial.println("Setup");
    delay(6000);

    // Prepare plot.ly interface
    graph.init();
    graph.openStream(); 
}

void loop() {
    // Two wave forms for diplay in plot.ly, sine and cosine
    float t1 = 20 + 10 * sin(millis() / 60000.0);
    float t2 = 20 + 10 * cos(millis() / 60000.0);

    // Stream data to plot.ly
    graph.plot(millis(), t1, streaming_tokens[0]);
    graph.plot(millis(), t2, streaming_tokens[1]);

    // every two seconds
    delay(2000);
    
    // LED pulse to verify main loop and data transmitting
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200); 
}