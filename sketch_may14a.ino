
int led_G = 2;
int led_R = 4;
int led_Y =3;
int buzzer=5;
int secmePini_G = 13;
int secmePini_R = 12;
int secmePini_Y = 11;
int secmebutonu_G=0;
int secmebutonu_R=0;
int secmebutonu_Y=0;

int sevenSeg_4 = 10;
int sevenSeg_3 = 9;
int sevenSeg_6 = 8;
int sevenSeg_5 = 7;
int sevenSeg_2 = 6;
int sevenSeg_1 = A0;
int sevenSeg_7 = A1;
int sevenSeg_8 = A2;

int randomGen = A3;

int comArr[20];
int level=0;

int startGame_1=0;
int startGame_2=0;
int startGame_3=0;

int gameStart=0;
int inGame=0;

int totalDelay=1000;
int totalLed=0;

int buttonCounter=0;

void setup() {
  // put your setup code here, to run once:

  pinMode(led_G, OUTPUT);
  pinMode(led_R, OUTPUT);
  pinMode(led_Y, OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(secmePini_G,INPUT);
  pinMode(secmePini_R,INPUT);
  pinMode(secmePini_Y,INPUT);
  pinMode(sevenSeg_1, OUTPUT);
  pinMode(sevenSeg_2, OUTPUT);
  pinMode(sevenSeg_3, OUTPUT);
  pinMode(sevenSeg_4, OUTPUT);
  pinMode(sevenSeg_5, OUTPUT);
  pinMode(sevenSeg_6, OUTPUT);
  pinMode(sevenSeg_7, OUTPUT);
  pinMode(sevenSeg_8, OUTPUT);
  
  pinMode(randomGen,INPUT);
  
  randomSeed(analogRead(randomGen));
  
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

   if(digitalRead(secmePini_G)==HIGH){
   delay(50);
   if(digitalRead(secmePini_G)==HIGH){secmebutonu_G=1;}
    }
    else{secmebutonu_G=0;}
    
    if(digitalRead(secmePini_R)==HIGH){
   delay(50);
   if(digitalRead(secmePini_R)==HIGH){secmebutonu_R=1;}
    }
    else{secmebutonu_R=0;}
    
    if(digitalRead(secmePini_Y)==HIGH){
   delay(50);
   if(digitalRead(secmePini_Y)==HIGH){secmebutonu_Y=1;}
    }
    else{secmebutonu_Y=0;}
    
    
    if(secmebutonu_G == 1&&gameStart == 0){startGame_1=1;secmebutonu_G=0;}
    if(secmebutonu_R == 1&&gameStart == 0){startGame_2=1;secmebutonu_R=0;}
    if(secmebutonu_Y == 1&&gameStart == 0){startGame_3=1;secmebutonu_Y=0;}
    
    
    if(startGame_1 == 1 && startGame_2 == 1 && startGame_3 == 1){
    
      gameStart=1;
      startGame_1=0;
      startGame_2=0;
      startGame_3=0;
      
    }
    
    if(gameStart==1 && inGame == 0){
      
      if(level <= 9){
    
      digitalWrite(buzzer, HIGH);
      delay(totalDelay);
      digitalWrite(buzzer, LOW);
      delay(totalDelay);
      digitalWrite(buzzer, HIGH);
      delay(totalDelay);
      digitalWrite(buzzer, LOW);
      delay(totalDelay);
      lightSpecSegment(level);
      setLevelParam();
      setRandLed();
      
      for(int i=0;i<totalLed;i++){
      
        lightLed(comArr[i]);
        
      }
      
      inGame=1;
      
      }else{
      totalDelay=200;
        for(int i = 0;i<10;i++){
        
      digitalWrite(buzzer, HIGH);
      delay(totalDelay);
      digitalWrite(buzzer, LOW);
      delay(totalDelay);
      
      lightLed(i%3);
      lightSpecSegment(i);
      delay(totalDelay);
      closeAllSegment();
      delay(totalDelay);
      
        }
      lightSpecSegment(9);
      delay(totalDelay);
      closeAllSegment();
      delay(totalDelay);
     lightSpecSegment(9);
      delay(totalDelay);
      closeAllSegment();
      delay(totalDelay);
      
        restartGame();
        
      }

    }
  
    
    if(inGame==1){
      
      if(buttonCounter == totalLed){
      
        inGame=0;
        level++;
        buttonCounter=0;
        
      }else
        if(secmebutonu_G==1){
      
        if(comArr[buttonCounter] == 0){
          
          lightSpecSegment(10);
          delay(300);
          lightSpecSegment(level);
          delay(300);
        
          
        buttonCounter++;
        }else{
        
          openAllSegment();
          delay(totalDelay);
          
      digitalWrite(buzzer, HIGH);
      delay(totalDelay);
          closeAllSegment();
          delay(totalDelay);
          digitalWrite(buzzer, LOW);
      delay(totalDelay);
          restartGame();
        }
        secmebutonu_G=0;
        
      }else if(secmebutonu_Y==1){
      
        if(comArr[buttonCounter] == 2){
        
           lightSpecSegment(10);
          delay(300);
          lightSpecSegment(level);
          delay(300);
          
          buttonCounter++;
        }else{
        
         openAllSegment();
          delay(totalDelay);
          
      digitalWrite(buzzer, HIGH);
      delay(totalDelay);
          closeAllSegment();
          delay(totalDelay);
          digitalWrite(buzzer, LOW);
      delay(totalDelay);
          restartGame();
        }
        
        
        secmebutonu_Y=0;
        
      }else if(secmebutonu_R==1){
      
        if(comArr[buttonCounter] == 1){
          
           lightSpecSegment(10);
          delay(300);
          lightSpecSegment(level);
          delay(300);
        
           buttonCounter++;
        }else{
        
         openAllSegment();
          delay(totalDelay);
          
      digitalWrite(buzzer, HIGH);
      delay(totalDelay);
          closeAllSegment();
          delay(totalDelay);
          digitalWrite(buzzer, LOW);
      delay(totalDelay);
          restartGame();
          
        }
        
       
        secmebutonu_R=0;
        
      }
      
    }
    
    
    
    if(gameStart==0){
    closeAllSegment();
    }


}

void closeAllSegment(){

  digitalWrite(sevenSeg_1, HIGH);
  digitalWrite(sevenSeg_2, HIGH);
  digitalWrite(sevenSeg_3, HIGH);
  digitalWrite(sevenSeg_4, HIGH);
  digitalWrite(sevenSeg_5, HIGH);
  digitalWrite(sevenSeg_6, HIGH);
  digitalWrite(sevenSeg_7, HIGH);
  digitalWrite(sevenSeg_8, HIGH);
  
}

void openAllSegment(){

  digitalWrite(sevenSeg_1, LOW);
  digitalWrite(sevenSeg_2, LOW);
  digitalWrite(sevenSeg_3, LOW);
  digitalWrite(sevenSeg_4, LOW);
  digitalWrite(sevenSeg_5, LOW);
  digitalWrite(sevenSeg_6, LOW);
  digitalWrite(sevenSeg_7, LOW);
  digitalWrite(sevenSeg_8, LOW);
  
}

void setRandLed(){
  
    for(int i=0;i<totalLed;i++){
       comArr[i] = random(0,3);
    }
  
}

void setLevelParam(){

  if(level==0){
  
    totalLed=5;
    totalDelay=1000;
    
  }else if(level==1){
  
    totalLed=6;
    totalDelay=1000;
    
  }else if(level==2){
  
    totalLed=7;
    totalDelay=1000;
    
  }else if(level==3){
  
    totalLed=8;
    totalDelay=1000;
    
  }else if(level==4){
  
    totalLed=9;
    totalDelay=1000;
    
  }else if(level==5){
  
    totalLed=10;
    totalDelay=1000;
    
  }else if(level==6){
  
    totalLed=10;
    totalDelay=900;
    
  }else if(level==7){
  
    totalLed=11;
    totalDelay=900;
    
  }else if(level==8){
  
    totalLed=11;
    totalDelay=800;
    
  }else if(level==9){
  
    totalLed=12;
    totalDelay=700;
    
  }
  
}

void restartGame(){

  gameStart = 0;
  inGame = 0;
  level = 0;
  buttonCounter =0;
  
}

void lightLed(int x){

  if(x == 0){
  
    digitalWrite(led_G,HIGH);
    delay(totalDelay);
    digitalWrite(led_G,LOW);
    delay(totalDelay);
    
  }else if(x == 1){
  
    digitalWrite(led_R, HIGH);
      delay(totalDelay);
      digitalWrite(led_R, LOW);
      delay(totalDelay);
    
  }else if(x == 2){
  
    digitalWrite(led_Y, HIGH);
      delay(totalDelay);
      digitalWrite(led_Y, LOW);
      delay(totalDelay);
    
  }
  
}

void lightSpecSegment(int x){

  if(x==0){
  
  digitalWrite(sevenSeg_1, LOW);
  digitalWrite(sevenSeg_2, LOW);
  digitalWrite(sevenSeg_3, LOW);
  digitalWrite(sevenSeg_4, HIGH);
  digitalWrite(sevenSeg_5, LOW);
  digitalWrite(sevenSeg_6, LOW);
  digitalWrite(sevenSeg_7, LOW);
  digitalWrite(sevenSeg_8, HIGH);
    
  }else if(x==1){
  
     digitalWrite(sevenSeg_1, HIGH);
  digitalWrite(sevenSeg_2, HIGH);
  digitalWrite(sevenSeg_3, HIGH);
  digitalWrite(sevenSeg_4, HIGH);
  digitalWrite(sevenSeg_5, LOW);
  digitalWrite(sevenSeg_6, HIGH);
  digitalWrite(sevenSeg_7, LOW);
  digitalWrite(sevenSeg_8, HIGH);
    
  }else if(x==2){
  
  digitalWrite(sevenSeg_1, LOW);
  digitalWrite(sevenSeg_2, LOW);
  digitalWrite(sevenSeg_3, HIGH);
  digitalWrite(sevenSeg_4, LOW);
  digitalWrite(sevenSeg_5, LOW);
  digitalWrite(sevenSeg_6, LOW);
  digitalWrite(sevenSeg_7, HIGH);
  digitalWrite(sevenSeg_8, HIGH);
    
  }else if(x==3){
  
   digitalWrite(sevenSeg_1, LOW);
  digitalWrite(sevenSeg_2, HIGH);
  digitalWrite(sevenSeg_3, HIGH);
  digitalWrite(sevenSeg_4, LOW);
  digitalWrite(sevenSeg_5, LOW);
  digitalWrite(sevenSeg_6, LOW);
  digitalWrite(sevenSeg_7, LOW);
  digitalWrite(sevenSeg_8, HIGH);
    
  }else if(x==4){
  
   digitalWrite(sevenSeg_1, HIGH);
  digitalWrite(sevenSeg_2, HIGH);
  digitalWrite(sevenSeg_3, LOW);
  digitalWrite(sevenSeg_4, LOW);
  digitalWrite(sevenSeg_5, LOW);
  digitalWrite(sevenSeg_6, HIGH);
  digitalWrite(sevenSeg_7, LOW);
  digitalWrite(sevenSeg_8, HIGH);
    
  }else if(x==5){
  
  digitalWrite(sevenSeg_1, LOW);
  digitalWrite(sevenSeg_2, HIGH);
  digitalWrite(sevenSeg_3, LOW);
  digitalWrite(sevenSeg_4, LOW);
  digitalWrite(sevenSeg_5, HIGH);
  digitalWrite(sevenSeg_6, LOW);
  digitalWrite(sevenSeg_7, LOW);
  digitalWrite(sevenSeg_8, HIGH);
    
  }else if(x==6){
  
     digitalWrite(sevenSeg_1, LOW);
  digitalWrite(sevenSeg_2, LOW);
  digitalWrite(sevenSeg_3, LOW);
  digitalWrite(sevenSeg_4, LOW);
  digitalWrite(sevenSeg_5, HIGH);
  digitalWrite(sevenSeg_6, LOW);
  digitalWrite(sevenSeg_7, LOW);
  digitalWrite(sevenSeg_8, HIGH);
    
  }else if(x==7){
  
     digitalWrite(sevenSeg_1, HIGH);
  digitalWrite(sevenSeg_2, HIGH);
  digitalWrite(sevenSeg_3, HIGH);
  digitalWrite(sevenSeg_4, HIGH);
  digitalWrite(sevenSeg_5, LOW);
  digitalWrite(sevenSeg_6, LOW);
  digitalWrite(sevenSeg_7, LOW);
  digitalWrite(sevenSeg_8, HIGH);
    
  }else if(x==8){
  
     digitalWrite(sevenSeg_1, LOW);
  digitalWrite(sevenSeg_2, LOW);
  digitalWrite(sevenSeg_3, LOW);
  digitalWrite(sevenSeg_4, LOW);
  digitalWrite(sevenSeg_5, LOW);
  digitalWrite(sevenSeg_6, LOW);
  digitalWrite(sevenSeg_7, LOW);
  digitalWrite(sevenSeg_8, HIGH);
    
  }else if(x==9){
  
     digitalWrite(sevenSeg_1, LOW);
  digitalWrite(sevenSeg_2, HIGH);
  digitalWrite(sevenSeg_3, LOW);
  digitalWrite(sevenSeg_4, LOW);
  digitalWrite(sevenSeg_5, LOW);
  digitalWrite(sevenSeg_6, LOW);
  digitalWrite(sevenSeg_7, LOW);
  digitalWrite(sevenSeg_8, HIGH);
    
  }else if(x==10){
  
    digitalWrite(sevenSeg_1, HIGH);
  digitalWrite(sevenSeg_2, HIGH);
  digitalWrite(sevenSeg_3, HIGH);
  digitalWrite(sevenSeg_4, HIGH);
  digitalWrite(sevenSeg_5, HIGH);
  digitalWrite(sevenSeg_6, HIGH);
  digitalWrite(sevenSeg_7, HIGH);
  digitalWrite(sevenSeg_8, LOW);
    
  }
  
}
