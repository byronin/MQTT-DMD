#include <RoninDMD.h>                    // Include lib & font 
#include <fonts/Arial_Black_16.h>
#define FONT Arial_Black_16

#define WIDTH 1                          // Set width & height
#define HEIGHT 1
RoninDMD P10(WIDTH, HEIGHT);

String Message = "Hi Im Ronin";

void setup() {
  Serial.begin(115200);

  P10.begin();              // Begin the display & font
  P10.setFont(FONT);

  P10.setBrightness(20);    // Set the brightness

  P10.drawText(0 , 0, " :) "); // P10.drawText(position x , position y, String type text);

}

void loop() {

  P10.loop();          // Run DMD loop

  if (Serial.available() > 0) {        // Save message from serial
    Message =  Serial.readString();
  }

  Scrolling_text(0 , 50 , Message ); // Call the function to write scrolling text on screen.
                                     // like -> Scrolling_text( position y , scroll speed, String type text);
                                     // or for not scroll -> P10.drawText(position x , position y, String type text);

  delay(100);

}

void Scrolling_text(int text_height , int scroll_speed , String scroll_text ) {
  static uint32_t pM ;
  pM = millis();
  static uint32_t x = 0;
  scroll_text = scroll_text + " ";

  bool  scrl_while = 1 ;
  int dsp_width = P10.width();
  int txt_width = P10.textWidth(scroll_text);

  while (scrl_while == 1) {

    P10.loop();
    delay(1);
    if (millis() - pM > scroll_speed) {
      P10.setFont(FONT);
      P10.drawText(dsp_width - x, text_height, scroll_text);


      x++;
      if (x >  txt_width + dsp_width) {

        x = 0 ;
        scrl_while = 0 ;

      }
      pM = millis();

    }


  }

}
