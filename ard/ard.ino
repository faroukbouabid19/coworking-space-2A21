#include <Keypad.h> 
#include <Servo.h>
Servo monServomoteur;
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27,16,2);

const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] =
{
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};
byte rowPins[ROWS] =  {5,4,3,2}; 
byte colPins[COLS] = {8,7,6,10}; 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


String ID = "999999";
String id="";
int redled = 11;
int greenled=1;

void setup()
{
    Serial.begin(9600);

    monServomoteur.attach(13);

    lcd.begin(16, 2);
    //afficheur
//LCD

    lcd.init(); //initialisation de l'écran LCD
    lcd.backlight();
    lcd.setCursor (0,0);
    lcd.print("    projet  ");
    lcd.setCursor (0,1);
    lcd.print(" smart cowork parking");
    delay (5000);
    lcd.clear();
    /*pinMode(redled, OUTPUT);
    pinMode(greenled, OUTPUT);
    digitalWrite(redled, LOW);
    digitalWrite(greenled, LOW);*/

    Serial.println("enter ID");

    lcd.setCursor (0,0);
    lcd.print(" entrer votre ID  ");

    delay (200);
}

void loop()
{

    keypadfunction();


}

void keypadfunction()
{

   if (Serial.available() ) {
    // read the incoming byte:

 lcd.clear();
                lcd.init(); 
                lcd.backlight();
                lcd.setCursor (0,0);
    // say what you got:
    Serial.print("I received: ");
     lcd.print(Serial.readString() ); }


    else
    {
        char key = keypad.getKey();

        if (key)
        {
            Serial.println(key);
            lcd.print("*");
        }
        if (key == '1')
        {

            id = id + 1;
        }

        if (key == '2')
        {

            id = id + 2;
        }

        if (key == '3')
        {

            id = id + 3;
        }

        if (key == '4')
        {

            id = id + 4;
        }

        if (key == '5')
        {
            id = id + 5;
        }

        if (key == '6')
        {

            id = id + 6;
        }

        if (key == '7')
        {

            id = id + 7;
        }

        if (key == '8')
        {

            id = id + 8;
        }

        if (key == '9')
        {

            id = id + 9;
        }

        if (key == '0')
        {

            id = id + 0;
        }


        if (key == '#')
        {
            Serial.println(id);

            if ( ID == id )
            {
                lcd.clear();
                lcd.init(); //initialisation de l'écran LCD
                lcd.backlight();
                lcd.setCursor (0,0);
                lcd.println("yayyyyyy");
                delay (500);
                lcd.setCursor (0,1);
                lcd.print(" welcome ");
                delay (200);
                monServomoteur.write(180);
                delay(500);
                /*digitalWrite(greenled, LOW);
                delay(1000);
                digitalWrite(redled, HIGH);
                delay(1000);*/
                id = "";
                lcd.clear();

            }
            else
            {
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print("invailid ID");
                /*digitalWrite(redled, HIGH);
                delay(1000);
                digitalWrite(greenled, LOW);
                delay(1000);*/

            }
            id = "";

            delay(1000);
            monServomoteur.write(90);
            delay(100);
            lcd.clear();
            lcd.println("Enter ID");
            lcd.setCursor(0,1);
        }
    }
}
