void average(){
 // subtract the last reading:
  totalA = totalA - readingsA[readIndex];
 
  // read from the sensor:
  readingsA[readIndex] = hx711.read();
  
  // add the reading to the total:
  totalA = totalA + readingsA[readIndex];
 
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }
ValA=totalA/numReadings;

}

