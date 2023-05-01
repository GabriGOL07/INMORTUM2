//Add the SdFat Libraries
#include <SdFat.h>
#include <SdFatUtil.h>

//and the MP3 Shield Library
#include <SFEMP3Shield.h>


// Variables
int buttons[4] = {A0, A1, A2, A3};

char tracks[3][13] = {"track001.mp3", "track002.mp3", "track003.mp3"};

enum State {Waiting_for_Button, Track_001, Track_002, Track_003, Stop_music};

State state = Waiting_for_Button;

//static int prev_Button_State[4] = {HIGH, HIGH, HIGH, HIGH};
//static unsigned long debounce_Time[4] = {0, 0, 0, 0};
//unsigned long current_Millis = millis();

int buttonPressed = -1;

SFEMP3Shield MP3player;

SdFat sd;

void setup() {
    uint8_t result; //result code from some function as to be tested at later time.

    //Serial.begin(115200);
    //Initialize the SdCard.
    if(!sd.begin(SD_SEL, SPI_FULL_SPEED)) sd.initErrorHalt();
    // depending upon your SdCard environment, SPI_HAVE_SPEED may work better.
    if(!sd.chdir("/")) sd.errorHalt("sd.chdir");

    //Initialize the MP3 Player Shield
    result = MP3player.begin();

    for (int i= 0; i<4; i++){
    pinMode(buttons[0], INPUT_PULLUP);
    }
}


int check_buttons(int buttons[4]){
    for (int i = 0; i<4; i++){
        int button_State = digitalRead(buttons[i]);
        if(button_State == LOW){
            buttonPressed = i;
        }
    }
    return buttonPressed;

}


void loop(){
    uint8_t result;
    uint32_t offset = 0;
    switch (state)
    {
    case Waiting_for_Button:
        buttonPressed = check_buttons(buttons);
        if(buttonPressed>=0){
            if(buttonPressed == 0){
                state = Track_001;
            }else if(buttonPressed == 1){
                state = Track_002;
            }else if(buttonPressed == 2){
                state = Track_003;
            }else{
                state = Stop_music;
            }
        }else{
            state = Waiting_for_Button;
            break;
        }
        break;
    case Track_001:
        result = MP3player.playMP3(tracks[0], offset);
        buttonPressed = -1;
        state = Waiting_for_Button;
        break;

    case Track_002:
        result = MP3player.playMP3(tracks[1], offset);
        buttonPressed = -1;
        state = Waiting_for_Button;
        break;
    
    case Track_003:
        result = MP3player.playMP3(tracks[2], offset);
        buttonPressed = -1;
        state = Waiting_for_Button;
        break;

    case Stop_music:
        MP3player.stopTrack();
        buttonPressed = -1;
        state = Waiting_for_Button;
        break;
    }
    
    



}