/// MBot Utility V1.0
/// By DarkGloves
/// https://www.github.com/DarkGloves

#include <MeMCore.h>

MeDCMotor motor_9(9);             // Call the motors that move the wheels on ports 9 and 10
MeDCMotor motor_10(10);
MeBuzzer buzzer;                  // Call MeBuzzer (frecuency generator) as just buzzer
MeRGBLed rgbled(7);               // Call MeRGBLed as rgbled, connected on pin 7
MeIR ir;                          // Call inflared as ir
MeLineFollower linefollower(2);   // Call line follower on port 2
MeUltrasonicSensor ultrasonic(3); // Call ultrasonic sensor on port 3

/////GLOBAL VARS/////
int mode;
int song;

/////VOIDS/////

// Movement
void move(int direction, int speed)
{
  int leftSpeed = 0;
  int rightSpeed = 0;
  if (direction == 1)
  {
    leftSpeed = speed;
    rightSpeed = speed;
  }
  else if (direction == 2)
  {
    leftSpeed = -speed;
    rightSpeed = -speed;
  }
  else if (direction == 3)
  {
    leftSpeed = -speed;
    rightSpeed = speed;
  }
  else if (direction == 4)
  {
    leftSpeed = speed;
    rightSpeed = -speed;
  }

  motor_9.run((9) == M1 ? -(leftSpeed) : (leftSpeed));
  motor_10.run((10) == M1 ? -(rightSpeed) : (rightSpeed));
}

void stop() // Move the motora at 0 speed
{
  move(1, 0);
}

// Sounds
class ModeSounds // Sounds played on eah mode
{
public:
  void menu()
  {
    buzzer.tone(440, 100); // buzzer.tone(hz, duration)
    buzzer.tone(523.25, 100);
    buzzer.tone(659.25, 100);
    buzzer.tone(880, 100);
  }
  void mode()
  {
    buzzer.tone(523.3, 100);
    buzzer.tone(174.6, 100);
  }
};
ModeSounds ms;

void iBeat(int hz, int length, int delay_time) // Interrumptible Beat
{
  if (ir.keyPressed(21)) // If the settings button is pressed, don't play the beat
  {
    song = 0;
    return;
  }
  else // Otherwise just play the beat and wait the specified time
  {
    buzzer.tone(hz, length);
    delay(delay_time);
  }
}

class Beats
{
public:
  void solfeggietto(int tempo, int delayTime)
  {
    iBeat(155.56, tempo, delayTime);  // E flat 3
    iBeat(130.81, tempo, delayTime);  // C3
    iBeat(155.56, tempo, delayTime);  // E flat 3
    iBeat(196.00, tempo, delayTime);  // G3
    iBeat(261.63, tempo, delayTime);  // C4
    iBeat(311.13, tempo, delayTime);  // E flat 4
    iBeat(293.66, tempo, delayTime);  // D4
    iBeat(261.63, tempo, delayTime);  // C4
    iBeat(246.94, tempo, delayTime);  // B3
    iBeat(196.00, tempo, delayTime);  // G3
    iBeat(246.94, tempo, delayTime);  // B3
    iBeat(293.66, tempo, delayTime);  // D4
    iBeat(392.00, tempo, delayTime);  // G4
    iBeat(349.23, tempo, delayTime);  // F4
    iBeat(311.13, tempo, delayTime);  // E flat 4
    iBeat(293.66, tempo, delayTime);  // D4
    iBeat(311.13, tempo, delayTime);  // E flat 4
    iBeat(261.63, tempo, delayTime);  // C4
    iBeat(311.13, tempo, delayTime);  // E flat 4
    iBeat(392.00, tempo, delayTime);  // G4
    iBeat(523.25, tempo, delayTime);  // C5
    iBeat(622.25, tempo, delayTime);  // E flat 5
    iBeat(587.33, tempo, delayTime);  // D5
    iBeat(523.25, tempo, delayTime);  // C5
    iBeat(587.33, tempo, delayTime);  // D5
    iBeat(523.25, tempo, delayTime);  // C5
    iBeat(493.88, tempo, delayTime);  // B4
    iBeat(440.00, tempo, delayTime);  // A4
    iBeat(392.00, tempo, delayTime);  // G4
    iBeat(349.23, tempo, delayTime);  // F4
    iBeat(311.13, tempo, delayTime);  // E flat 4
    iBeat(293.66, tempo, delayTime);  // D4
    iBeat(311.13, tempo, delayTime);  // E flat 4
    iBeat(261.63, tempo, delayTime);  // C4
    iBeat(311.13, tempo, delayTime);  // E flat 4
    iBeat(392.00, tempo, delayTime);  // G4
    iBeat(523.25, tempo, delayTime);  // C5
    iBeat(622.25, tempo, delayTime);  // E flat 5
    iBeat(587.33, tempo, delayTime);  // D5
    iBeat(523.25, tempo, delayTime);  // C5
    iBeat(493.88, tempo, delayTime);  // B4
    iBeat(392.00, tempo, delayTime);  // G4
    iBeat(493.88, tempo, delayTime);  // B4
    iBeat(587.33, tempo, delayTime);  // D5
    iBeat(783.99, tempo, delayTime);  // G5
    iBeat(698.46, tempo, delayTime);  // F5
    iBeat(622.25, tempo, delayTime);  // E flat 5
    iBeat(587.33, tempo, delayTime);  // D5
    iBeat(622.25, tempo, delayTime);  // E flat 5
    iBeat(523.25, tempo, delayTime);  // C5
    iBeat(622.25, tempo, delayTime);  // E flat 5
    iBeat(783.99, tempo, delayTime);  // G5
    iBeat(1046.50, tempo, delayTime); // C6
    iBeat(1244.51, tempo, delayTime); // E flat 6
    iBeat(1174.66, tempo, delayTime); // D6
    iBeat(1046.50, tempo, delayTime); // C6
    iBeat(1174.66, tempo, delayTime); // D6
    iBeat(1046.50, tempo, delayTime); // C6
    iBeat(987.77, tempo, delayTime);  // B5
    iBeat(880.00, tempo, delayTime);  // A5
    iBeat(783.99, tempo, delayTime);  // G5
    iBeat(698.46, tempo, delayTime);  // F5
    iBeat(622.25, tempo, delayTime);  // E flat 5
    iBeat(587.33, tempo, delayTime);  // D5
    iBeat(622.25, tempo, delayTime);  // Eb5
    iBeat(523.25, tempo, delayTime);  // C5
    iBeat(392.0, tempo, delayTime);   // G4
    iBeat(311.13, tempo, delayTime);  // Eb4
    iBeat(261.63, tempo, delayTime);  // C4
    iBeat(1046.5, tempo, delayTime);  // C6
    iBeat(783.99, tempo, delayTime);  // G5
    iBeat(622.25, tempo, delayTime);  // Eb5
    iBeat(830.61, tempo, delayTime);  // Ab5
    iBeat(174.61, tempo, delayTime);  // F3
    iBeat(207.65, tempo, delayTime);  // Ab3
    iBeat(261.63, tempo, delayTime);  // C4
    iBeat(349.23, tempo, delayTime);  // F4
    iBeat(415.3, tempo, delayTime);   // Ab4
    iBeat(523.25, tempo, delayTime);  // C5
    iBeat(622.25, tempo, delayTime);  // Eb5
    iBeat(587.33, tempo, delayTime);  // D5
    iBeat(466.16, tempo, delayTime);  // Bb4
    iBeat(349.23, tempo, delayTime);  // F4
    iBeat(293.66, tempo, delayTime);  // D4
    iBeat(233.08, tempo, delayTime);  // Bb3
    iBeat(932.33, tempo, delayTime);  // Bb5
    iBeat(698.46, tempo, delayTime);  // F5
    iBeat(587.33, tempo, delayTime);  // D5
    iBeat(783.99, tempo, delayTime);  // G5
    iBeat(155.56, tempo, delayTime);  // Eb3
    iBeat(196.0, tempo, delayTime);   // G3
    iBeat(233.08, tempo, delayTime);  // Bb3
    iBeat(311.13, tempo, delayTime);  // Eb4
    iBeat(392.0, tempo, delayTime);   // G4
    iBeat(466.16, tempo, delayTime);  // Bb4
    iBeat(587.33, tempo, delayTime);  // D5
  }
  void alla_turca(int tempo, int delayTime)
  {
    for (int i = 0; i < 2; i++) // Repeat twice
    {
      iBeat(493.88, tempo, delayTime);         // B4
      iBeat(440.0, tempo, delayTime);          // A4
      iBeat(415.3, tempo, delayTime);          // G#4
      iBeat(440.0, tempo, delayTime);          // A4
      iBeat(523.25, tempo * 2, delayTime * 2); // C5
      delay(tempo * 2 + delayTime * 2);        // Silence
      iBeat(587.33, tempo, delayTime);         // D5
      iBeat(523.25, tempo, delayTime);         // C5
      iBeat(493.88, tempo, delayTime);         // B4
      iBeat(523.25, tempo, delayTime);         // C5
      iBeat(659.26, tempo * 2, delayTime * 2); // E5
      delay(tempo * 2 + delayTime * 2);        // Silence
      iBeat(698.46, tempo, delayTime);         // F5
      iBeat(659.26, tempo, delayTime);         // E5
      iBeat(622.25, tempo, delayTime);         // D#5
      iBeat(659.26, tempo, delayTime);         // E5
      iBeat(987.77, tempo, delayTime);         // B5
      iBeat(880.0, tempo, delayTime);          // A5
      iBeat(830.61, tempo, delayTime);         // G#5
      iBeat(880.0, tempo, delayTime);          // A5
      iBeat(987.77, tempo, delayTime);         // B5
      iBeat(880.0, tempo, delayTime);          // A5
      iBeat(830.61, tempo, delayTime);         // G#5
      iBeat(880.0, tempo, delayTime);          // A5
      iBeat(1046.5, tempo * 4, delayTime * 4); // C6
      iBeat(880.0, tempo * 2, delayTime * 2);  // A5
      iBeat(1046.5, tempo * 2, delayTime * 2); // C6
      iBeat(783.99, tempo / 4, delayTime / 4); // G5
      iBeat(880.0, tempo / 4, delayTime / 4);  // A5
      iBeat(987.77, tempo * 2, delayTime * 2); // B5
      iBeat(880.0, tempo * 2, delayTime * 2);  // A5
      iBeat(783.99, tempo * 2, delayTime * 2); // G5
      iBeat(880.0, tempo * 2, delayTime * 2);  // A5
      iBeat(783.99, tempo / 4, delayTime / 4); // G5
      iBeat(880.0, tempo / 4, delayTime / 4);  // A5
      iBeat(987.77, tempo * 2, delayTime * 2); // B5
      iBeat(880.0, tempo * 2, delayTime * 2);  // A5
      iBeat(783.99, tempo * 2, delayTime * 2); // G5
      iBeat(880.0, tempo * 2, delayTime * 2);  // A5
      iBeat(783.99, tempo / 4, delayTime / 4); // G5
      iBeat(880.0, tempo / 4, delayTime / 4);  // A5
      iBeat(987.77, tempo * 2, delayTime * 2); // B5
      iBeat(880.0, tempo * 2, delayTime * 2);  // A5
      iBeat(783.99, tempo * 2, delayTime * 2); // G5
      iBeat(739.99, tempo * 2, delayTime * 2); // F#5
      iBeat(659.26, tempo * 4, delayTime * 4); // E5
    }
  }
};
Beats beats;

// Lights
class Lights // Lights displayed depending on the mode
{
public:
  void mMenu()
  {
    rgbled.setColor(0, 0, 15, 7);
    rgbled.show();
  }
  void a()
  {
    rgbled.setColor(0, 15, 0, 0);
    rgbled.show();
  }
  void b()
  {
    rgbled.setColor(0, 15, 15, 0);
    rgbled.show();
  }
  void c()
  {
    rgbled.setColor(0, 0, 15, 0);
    rgbled.show();
  }
  void d()
  {
    rgbled.setColor(0, 0, 15, 15);
    rgbled.show();
  }
  void e()
  {
    rgbled.setColor(0, 0, 0, 15);
    rgbled.show();
  }
  void f()
  {
    rgbled.setColor(0, 15, 0, 15);
    rgbled.show();
  }
};
Lights lights;

///// MODES /////
void mode_a() // RC mode
{
  int modea = 1;
  int speed = 100;
  while (modea == 1)
  {
    if (ir.keyPressed(64))
    {
      while (ir.keyPressed(64))
      {
        move(1, speed);
      }
      stop();
    }
    if (ir.keyPressed(25))
    {
      while (ir.keyPressed(25))
      {
        move(2, speed);
      }
      stop();
    }
    if (ir.keyPressed(7))
    {
      while (ir.keyPressed(7))
      {
        move(3, speed);
      }
      stop();
    }
    if (ir.keyPressed(9))
    {
      while (ir.keyPressed(9))
      {
        move(4, speed);
      }
      stop();
    }

    if (ir.keyPressed(12))
    {
      while (ir.keyPressed(12))
        _loop;
      buzzer.tone(440, 100);
      speed = 90;
    }
    if (ir.keyPressed(24))
    {
      while (ir.keyPressed(24))
        _loop;
      buzzer.tone(440, 100);
      speed = 110;
    }
    if (ir.keyPressed(94))
    {
      while (ir.keyPressed(94))
        _loop;
      buzzer.tone(440, 100);
      speed = 130;
    }
    if (ir.keyPressed(8))
    {
      while (ir.keyPressed(8))
        _loop;
      buzzer.tone(440, 100);
      speed = 150;
    }
    if (ir.keyPressed(28))
    {
      while (ir.keyPressed(28))
        _loop;
      buzzer.tone(440, 100);
      speed = 170;
    }
    if (ir.keyPressed(90))
    {
      while (ir.keyPressed(90))
        _loop;
      buzzer.tone(440, 100);
      speed = 190;
    }
    if (ir.keyPressed(66))
    {
      while (ir.keyPressed(66))
        _loop;
      buzzer.tone(440, 100);
      speed = 210;
    }
    if (ir.keyPressed(82))
    {
      while (ir.keyPressed(82))
        _loop;
      buzzer.tone(440, 100);
      speed = 230;
    }
    if (ir.keyPressed(74))
    {
      while (ir.keyPressed(74))
        _loop;
      buzzer.tone(440, 100);
      speed = 255;
    }
    if (ir.keyPressed(69))
    {
      while (ir.keyPressed(69))
        _loop;
      modea = 0;
      mainMenu();
    }
  }
}

void mode_b() // Object avoidance mode
{
  int modeb = 1;
  int speed = 100;
  while (modeb == 1)
  {
    move(1, speed);
    if (ultrasonic.distanceCm() < 15) // For making the mode more precise, the ultrasonic already detects de objects from a long distance, and then wait until they get closer for turning
    {
      delay(500);
      while (ultrasonic.distanceCm() < 15)
      {
        move(3, 100);
        delay(1000);
      }
      move(1, speed);
    }
    if (ir.keyPressed(12))
    {
      while (ir.keyPressed(12))
        _loop;
      buzzer.tone(440, 100);
      speed = 90;
    }
    if (ir.keyPressed(24))
    {
      while (ir.keyPressed(24))
        _loop;
      buzzer.tone(440, 100);
      speed = 110;
    }
    if (ir.keyPressed(94))
    {
      while (ir.keyPressed(94))
        _loop;
      buzzer.tone(440, 100);
      speed = 130;
    }
    if (ir.keyPressed(8))
    {
      while (ir.keyPressed(8))
        _loop;
      buzzer.tone(440, 100);
      speed = 150;
    }
    if (ir.keyPressed(28))
    {
      while (ir.keyPressed(28))
        _loop;
      buzzer.tone(440, 100);
      speed = 170;
    }
    if (ir.keyPressed(90))
    {
      while (ir.keyPressed(90))
        _loop;
      buzzer.tone(440, 100);
      speed = 190;
    }
    if (ir.keyPressed(66))
    {
      while (ir.keyPressed(66))
        _loop;
      buzzer.tone(440, 100);
      speed = 210;
    }
    if (ir.keyPressed(82))
    {
      while (ir.keyPressed(82))
        _loop;
      buzzer.tone(440, 100);
      speed = 230;
    }
    if (ir.keyPressed(74))
    {
      while (ir.keyPressed(74))
        _loop;
      buzzer.tone(440, 100);
      speed = 255;
    }
    if (ir.keyPressed(69))
    {
      while (ir.keyPressed(69))
        _loop;
      stop();
      modeb = 0;
      mainMenu();
    }
  }
}

void mode_c() // Line follower, better than the default program's line follower
{
  int modec = 1;
  int speed = 100;
  int lastmove = 3; // lastmove is used to continue rotating the same way when the robot gets out of the track, it works pretty well
  while (modec == 1)
  {
    if (linefollower.readSensors() == 0)
    {
      move(1, speed);
      lastmove = 1;
    }
    if (linefollower.readSensors() == 1)
    {
      move(3, speed);
      lastmove = 3;
    }
    if (linefollower.readSensors() == 2)
    {
      move(4, speed);
      lastmove = 4;
    }
    if (linefollower.readSensors() == 3)
    {
      move(lastmove, speed);
    }

    if (ir.keyPressed(12))
    {
      while (ir.keyPressed(12))
        _loop;
      buzzer.tone(440, 100);
      speed = 90;
    }
    if (ir.keyPressed(24))
    {
      while (ir.keyPressed(24))
        _loop;
      buzzer.tone(440, 100);
      speed = 110;
    }
    if (ir.keyPressed(94))
    {
      while (ir.keyPressed(94))
        _loop;
      buzzer.tone(440, 100);
      speed = 130;
    }
    if (ir.keyPressed(8))
    {
      while (ir.keyPressed(8))
        _loop;
      buzzer.tone(440, 100);
      speed = 150;
    }
    if (ir.keyPressed(28))
    {
      while (ir.keyPressed(28))
        _loop;
      buzzer.tone(440, 100);
      speed = 170;
    }
    if (ir.keyPressed(90))
    {
      while (ir.keyPressed(90))
        _loop;
      buzzer.tone(440, 100);
      speed = 190;
    }
    if (ir.keyPressed(66))
    {
      while (ir.keyPressed(66))
        _loop;
      buzzer.tone(440, 100);
      speed = 210;
    }
    if (ir.keyPressed(82))
    {
      while (ir.keyPressed(82))
        _loop;
      buzzer.tone(440, 100);
      speed = 230;
    }
    if (ir.keyPressed(74))
    {
      while (ir.keyPressed(74))
        _loop;
      buzzer.tone(440, 100);
      speed = 255;
    }

    if (ir.keyPressed(69))
    {
      while (ir.keyPressed(69))
        _loop;
      modec = 0;
      stop();
      mainMenu();
    }
  }
}

void mode_d() // Limited mode
{
  int speed = 100;
  int moded = 1;
  move(1, speed);
  while (moded == 1)
  {
    if (linefollower.readSensors() != 3)
    {
      move(random(3, 4), speed);
      delay(random(96300, 285300) / speed);
      move(1, speed);
    }
    if (ir.keyPressed(12))
    {
      while (ir.keyPressed(12))
        _loop;
      buzzer.tone(440, 100);
      speed = 90;
    }
    if (ir.keyPressed(24))
    {
      while (ir.keyPressed(24))
        _loop;
      buzzer.tone(440, 100);
      speed = 110;
    }
    if (ir.keyPressed(94))
    {
      while (ir.keyPressed(94))
        _loop;
      buzzer.tone(440, 100);
      speed = 130;
    }
    if (ir.keyPressed(8))
    {
      while (ir.keyPressed(8))
        _loop;
      buzzer.tone(440, 100);
      speed = 150;
    }
    if (ir.keyPressed(28))
    {
      while (ir.keyPressed(28))
        _loop;
      buzzer.tone(440, 100);
      speed = 170;
    }
    if (ir.keyPressed(90))
    {
      while (ir.keyPressed(90))
        _loop;
      buzzer.tone(440, 100);
      speed = 190;
    }
    if (ir.keyPressed(66))
    {
      while (ir.keyPressed(66))
        _loop;
      buzzer.tone(440, 100);
      speed = 210;
    }
    if (ir.keyPressed(82))
    {
      while (ir.keyPressed(82))
        _loop;
      buzzer.tone(440, 100);
      speed = 230;
    }
    if (ir.keyPressed(74))
    {
      while (ir.keyPressed(74))
        _loop;
      buzzer.tone(440, 100);
      speed = 255;
    }

    if (ir.keyPressed(69))
    {
      while (ir.keyPressed(69))
        _loop;
      moded = 0;
      stop();
      mainMenu();
    }
  }
}

void mode_e() // Music
{
  song = 0;
  while (song == 0)
  {
    if (ir.keyPressed(12))
    {
      beats.solfeggietto(25, 50);
    }
    else if (ir.keyPressed(24))
    {
      beats.alla_turca(80, 10);
    }
    else if (ir.keyPressed(69))
    {
      song = 1;
      mainMenu();
    }
  }
}

//////MAIN SECTION///////
void setup()
{
  ir.begin(); // Start inflared sensor
  mainMenu(); // Start MainMenu when mBot starts up
}

void mainMenu()
{
  // Color
  lights.mMenu();
  rgbled.show();

  // Play mainscr sound
  ms.menu();

  // Define mode variable
  mode = 0;

  // Select a mode
  while (mode == 0)
  {
    if (ir.keyPressed(69))
    {
      while (ir.keyPressed(69))
        _loop;
      lights.a();
      ms.mode();
      mode = 1;
      mode_a();
    }
    if (ir.keyPressed(70))
    {
      while (ir.keyPressed(70))
        _loop;
      lights.b();
      ms.mode();
      mode = 1;
      mode_b();
    }
    if (ir.keyPressed(71))
    {
      while (ir.keyPressed(71))
        _loop;
      lights.c();
      ms.mode();
      mode = 1;
      mode_c();
    }
    if (ir.keyPressed(68))
    {
      while (ir.keyPressed(68))
        _loop;
      lights.d();
      ms.mode();
      mode = 1;
      mode_d();
    }
    if (ir.keyPressed(67))
    {
      while (ir.keyPressed(67))
        _loop;
      lights.e();
      ms.mode();
      mode = 1;
      mode_e();
    }
    if (ir.keyPressed(13))
    {
      while (ir.keyPressed(13))
        _loop;
      lights.f();
      ms.mode();
      mode = 1;
    }
    if (analogRead(A7) < 10)
    {
      loop();
    }
  }
};

void loop()
{
  if (analogRead(A7) < 10)
  {
    while (analogRead(A7) < 10)
      _loop;
    mainMenu();
  }
}

void _loop()
{
}