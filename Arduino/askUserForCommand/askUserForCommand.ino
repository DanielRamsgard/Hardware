void setup() {
  Serial.begin(9600);
  while (!Serial) {
    // wait for serial port to connect.
  }
}

void loop() {
  char answer[20];
  Serial.print("What is your name: ");
  while(!Serial.available()){
    // wait for user input
  }
  int count = Serial.readBytesUntil('\n', answer, 20);
  answer[count] = '\0'; // add null terminator
  Serial.println();
  Serial.print("Hello, ");
  Serial.println(answer);
}