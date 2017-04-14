// Constants
const int left = 10;
const int right = 9;
const long interval = 5000;
const unsigned long MAX_LONG = 2147483647;

char instruction;
long previousMillis = 0;

void setup()
{
	Serial.begin(9600); //set baud rate
	pinMode(left, OUTPUT);
	pinMode(right, OUTPUT);
}

void loop()
{
	unsigned long currentMillis = millis();
	if (Serial.available())
		instruction = char(Serial.read());
	
	if (instruction == 'L')
		SignalLeft();
	else if (instruction == 'R')
		SignalRight();
	else if (instruction == 'U')
		SignalUTurn();

	if (currentMillis - previousMillis > interval)
	{
		previousMillis = MAX_LONG;

		digitalWrite(right, LOW);
		digitalWrite(left, LOW);
	}
}

void SignalLeft()
{
	previousMillis = millis();
	digitalWrite(left, HIGH);
	digitalWrite(right, LOW);
	instruction = ' ';
}

void SignalRight()
{
	previousMillis = millis();
	digitalWrite(right, HIGH);
	digitalWrite(left, LOW);
	instruction = ' ';
}

void SignalUTurn()
{
	previousMillis = millis();
	digitalWrite(right, HIGH);
	digitalWrite(left, HIGH);
	instruction = ' ';
}