
typedef struct
{
  int name;
  int number;
} data;

data person[2] = {{5, 6}, {7, 8}};




void setup() {
  Serial.begin(9600);
  Serial.print(person[1].number);

}

void loop() {
  // put your main code here, to run repeatedly:

}
