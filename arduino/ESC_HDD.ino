byte phase1 = 2;
byte phase2 = 3;
byte phase3 = 4;
byte led = 1;
byte Button = PB0;
boolean reading = 0;
 
unsigned int stepLength = 40000;
unsigned int minStepLength = 1400;
unsigned int steps = 5;
 
void setup()
{
    pinMode(led, OUTPUT);
    pinMode(phase1, OUTPUT);
    pinMode(phase2, OUTPUT);
    pinMode(phase3, OUTPUT);
    pinMode(Button, INPUT);
    digitalWrite(led, LOW);
}
 
void loop()
{
    if(digitalRead(Button) == 0)
        reading = 1;
 
    if (reading == 1)
    {
        switchStep(1);
        switchStep(2);
        switchStep(3);
 
        if(stepLength > minStepLength)
            stepLength = stepLength - steps;
        else
            stepLength = minStepLength;
 
        if (stepLength < 39950)
        {
            digitalWrite(led, HIGH);
            steps = 400;
        }
 
        if (stepLength < 20000)
        {
            digitalWrite(led, LOW);
            steps = 100;
        }
 
        if (stepLength < 4000)
            steps = 2;
        
        if (stepLength < 1600)
            digitalWrite(led, HIGH);
    }
}
 
 
void switchStep(byte stage)
{
    switch(stage)
    {
        case 1:
            digitalWrite(phase1, HIGH);
            digitalWrite(phase2, LOW);
            digitalWrite(phase3, LOW);
            myDelay(stepLength);
            break;
 
        case 2:
            digitalWrite(phase1, LOW);
            digitalWrite(phase2, HIGH);
            digitalWrite(phase3, LOW);
            myDelay(stepLength);
            break;
 
        default:
            digitalWrite(phase1, LOW);
            digitalWrite(phase2, LOW);
            digitalWrite(phase3, HIGH);
            myDelay(stepLength);
            break;
    }
}
 
void myDelay(unsigned int p)
{
    if (p > 16380)
        delay (p / 1000);
    else
        delayMicroseconds(p);
}
