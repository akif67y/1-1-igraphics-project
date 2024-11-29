#include "iGraphics.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
// boulder gular x change na kore asteriod gular koro

int x = 0, y = 0, r = 20;
void drawhomepage();
void drawStartpage();
void drawAboutpage();
void drawScorepage();
void drawMusicpage();
void bulletchange();
void collisionCheck2();
void collisionresult();
void collisionCheck1();
// void boroboulderdraw();

int bouldernumber = 0;
int gamestate = 1;
int createBullet = 0;
typedef struct play{
	int x;
	int y;
	int health;
}player;

player hero;
typedef struct borobol{
	char image[250];
	int x;
	int y;
	int health;
}borobol;
// typedef struct boulder{
// 	char image[250];
// 	int x;
// 	int y;
// 	int health;
// }boulder;

borobol now[4];
// boulder drim[3];


// char boroboulder[4][250] = {"bmp_outputs//tile001.bmp",  "bmp_outputs//tile003.bmp", "bmp_outputs//tile004.bmp", "bmp_outputs//tile005.bmp"};
//char boulder[9][250] = {"bmp_outputs//asteroid.bmp", "bmp_outputs//asteroid.bmp", "bmp_outputs//asteroid.bmp", "bmp_outputs//asteroid.bmp", "bmp_outputs//asteroid.bmp", "bmp_outputs//asteroid.bmp", "bmp_outputs//asteroid.bmp", "bmp_outputs//asteroid.bmp", "bmp_outputs//asteroid.bmp"};
char boulder[3][250] = {"bmp_outputs//asteroid.bmp", "bmp_outputs//asteroid.bmp", "bmp_outputs//asteroid.bmp" };
int bulletcheck[60] = {0};
int bouldercheck[3] ={0};
player boulderCoordinate[3];


/*
	function iDraw() is called again and again by the system.

	*/
char point[10000];

void healthchecker(){
	iSetColor(129,128,128);
	iFilledRectangle(700, 500, 100, 40);

    sprintf(point,"Health : %d", hero.health);
	iSetColor(255,0,0);
	iText(710, 520, point, GLUT_BITMAP_HELVETICA_10);

}

void iDraw() {
        iClear();
		
		switch(gamestate){
			case 1:
			drawhomepage();
			break;
			case 2:
			drawStartpage();
			break;
			case 3:
			drawScorepage();
			break;
			case 4 :
			drawMusicpage();
			break;
			case 5 :
			drawAboutpage();
			break;
		}
        // iSetColor(0, 256, 0);
        // iRectangle(x+ 200,y + 400 , 700, 400);
        // iFilledRectangle(x+ 200,y + 400 , 700, 400);


        // iSetColor(256, 0, 0);
        // iCircle(x+550, y+600, 120);
        // iFilledCircle(x+550, y+600, 120);

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	printf("x = %d, y= %d\n",mx,my);
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		if(gamestate == 1){   // player is in home menu
			if(mx >= 770 && mx <= 970){
				
				if(my >= 10 && my <= 140){   // goes to different menu based on clicks
					gamestate = 5;
				}
				else if(my >= 160 && my <= 290){
					gamestate = 4;
				}
				else if(my >= 310 && my <= 440){
					gamestate = 3;
				}
				else if(my >= 460 && my <= 590){
					gamestate = 2;
				}
			}
		}
		if(gamestate == 2){
			createBullet = 1;
		}
		
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		printf("x = %d, y= %d\n",mx,my);
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	if (key == 'k') {
		createBullet = 1;
	}
	else if( key == 'd'){
		int t = hero.x + 10;
		if(t > 900){
			hero.x = 900;
		}
		else {
			hero.x = t;
		}
	}
	else if(key == 'a'){
		int t = hero.x - 10;
		if(t < 0){
			hero.x =0;
		}
		else {
			hero.x = t;
		}
	}
		
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	//place your codes for other keys here
}
void drawhomepage(){
    iSetColor(128, 128, 128);
	iFilledRectangle(0,0,1000,600);
	iShowBMP2(0,0,"bmp_outputs//home.bmp", 0);

	iShowBMP2(770, 10, "bmp_outputs//buttoncdi.bmp", 0);
	iShowBMP2(770, 160, "bmp_outputs//buttoncdi.bmp", 0);
	iShowBMP2(770, 310, "bmp_outputs//buttoncdi.bmp", 0);
	iShowBMP2(770, 460, "bmp_outputs//buttoncdi.bmp", 0);

	iSetColor(225,225,225);
	iText(800, 69, "ABOUT", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(800, 218, "MUSIC", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(800, 365, "SCORE", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(800, 518, "PLAY", GLUT_BITMAP_TIMES_ROMAN_24);

}
void drawStartpage(){
	srand(time(NULL));
	iSetColor(128,128,128);
	iFilledRectangle(0,0,1000,600);
	iShowBMP2(0,0, "bmp_outputs//background3.bmp", 0);
	iShowBMP2(hero.x, hero.y, "bmp_outputs//spike2.bmp", 0);
	bulletchange();
	for(int i = 0; i < 3; i++){
		if(bouldercheck[i] == 1){  // it will work on bouldercheck status
		// if(boulderCoordinate[i].health == 0){
		// 	iShowBMP2(boulderCoordinate[i].x, boulderCoordinate[i].y, "bmp_outputs//collision.bmp",0);
		// } 
		// else{
		// 	iShowBMP2(boulderCoordinate[i].x, boulderCoordinate[i].y, boulder[i],0);
		// }
		iShowBMP2(boulderCoordinate[i].x, boulderCoordinate[i].y, boulder[i],0);
	}
	}
	collisionCheck1();
	collisionresult();
	
	for(int i = 0; i < 4; i++){   

		// check how health is;
		// if(now[i].health == 0 ){
		// iShowBMP2(now[i].x,now[i].y, "bmp_outputs//collision.bmp",0);
		// }
		// else{
		// 	iShowBMP2(now[i].x, now[i].y, now[i].image, 0);
		// }
		iShowBMP2(now[i].x, now[i].y, now[i].image, 0);
	
	}
	collisionCheck2();
	collisionresult();
	healthchecker();
	// boroboulderdraw();

	
}
void bulletchange(){
	if(createBullet == 1){ 
		bulletcheck[8] = hero.x + 45;
		createBullet = 0;
	}

	for(int i = 8; i < 60; i++){
		if(bulletcheck[i] != 0 && bulletcheck[i] != -1){
			
			iShowBMP2(bulletcheck[i], i * 10, "bmp_outputs//sbullet.bmp", 0);
			// printf("%d", i);  // the value of bullet[i] is the x coordinate of the existing bullet in i *10 bhuj
			// if it is not here then it is made to be zero as no bullet can be in zero
		}
	}
	for(int i = 59; i >=8; i--){
			bulletcheck[i + 1] = bulletcheck[i] ;
			bulletcheck[i] = 0;
		
	}

}
void asteriodgenerate(){


int t = rand() % 2;
	int p = rand() % 4;
	if(t == 1){
		for(int j = 0, k = 0; j < 3; j++){  // generating boulder at the start
			if(k == p) break;
			if(bouldercheck[j] == 0){

			bouldercheck[j] = 1;
			boulderCoordinate[j].x = 0 + rand() % 600;
			boulderCoordinate[j].y = 575;
			k++;
			
			}
		}
		
	}
		for(int i = 0; i < 3 ; i++){
		int s = rand() % 2;   //changing existing boulder coordinate
		
		if(s == 0){
			boulderCoordinate[i].x = boulderCoordinate[i].x + 50  ;
		}
		else {
			boulderCoordinate[i].x = boulderCoordinate[i].x - 50  ;
		}
		
		if(boulderCoordinate[i].x >= 990) boulderCoordinate[i].x = 990;
		if(boulderCoordinate[i].x < 10) boulderCoordinate[i]. x = 0;
		boulderCoordinate[i].y = boulderCoordinate[i].y - 50;
		if(boulderCoordinate[i].y < 5){
			bouldercheck[i] = 0;  //removing it when reaches the end of the screen;
		}
		}

		for(int i = 0; i < 4; i++){
			now[i].y = now[i].y - 70;
			// noshto hoye geleo etai korbo(health 0 hoile)
			if(now[i]. y < 5) now[i].y = 598;
		
		}

	}

	// void boroboulderdraw(){
		
	// 	for(int i = 0; i < 4; i++){
	// 		iShowBMP2(now[i].x, now[i].y, now[i].image, 0);
	// 		now[i].y = now[i].y - 70;
	// 		if(now[i]. y < 5) now[i].y = 598;
	// 	}
	// }
	


// }

void drawMusicpage(){
	iSetColor(128,128,128);
	iFilledRectangle(0,0,1000,600);
   
}
void drawAboutpage(){

}
void drawScorepage(){

}
void first(){
		srand(time(NULL));
	hero.x = 500;
	hero.y = 0;
	hero.health = 100;
	for(int i = 0; i < 4; i++){
		strcpy(now[i].image, "bmp_outputs//tile001.bmp");
		// now[i].y = 598 - (rand() % 100);
		now[i].health = 20;
	}
	now[1].y = 50 + (rand()% 100); 
	now[2].y = 150 + (rand() % 100);
	now[3].y = 250 + (rand() % 100);
	now[4].y = 350 + (rand() % 100);

	now[1].x = 350 + (rand()% 100);
	now[2].x = 450 + (rand() % 100);
	now[3].x = 650 + (rand() % 100);
	now[4].x = 850 + (rand() % 100);

	for(int i = 0; i < 3; i++){
		boulderCoordinate[i].health = 10;
	}

}
void collisionCheck1(){
	// if  bullet hit any boulder
	// asteriod
	
for(int i = 0; i < 60; i++){
		if(bulletcheck[i] != 0 && bulletcheck[i] != -1){
			// boulder
			// for(int j = 0; j < 4; j++){
			// 	if((bulletcheck[i] >= now[j].x && bulletcheck[i] <= now[j].x + 60) &&( (i * 10 >= now[j].y && i * 10 <= now[j].y + 60) )){
			// 		now[j].health = now[j].health - 10;
			// 	}
			// }

			// asteroid
			for(int k = 0; k < 3; k++){
				if(bouldercheck[k] == 1){
					if((bulletcheck[i] >= boulderCoordinate[k].x && bulletcheck[i] <= boulderCoordinate[k].x + 60) &&( (i * 10 >= boulderCoordinate[k].y && i * 10 <= boulderCoordinate[k].y + 60) )){
						boulderCoordinate[k].health -= 10;
						bulletcheck[i] = -1;
						
					}
				}
			}
		}
	}
// if any boulder or asteroid hit plane

		// for(int j = 0; j < 4; j++){
		// 		if(( now[j].x + 60 >= hero.x && now[j].x <= hero.x + 105) &&(  now[j].y <= hero.y + 80 )){
		// 			hero.health -= 10;
		// 			now[j].health = 0;
		// 		}
		// 	}

		for(int j = 0; j < 3;j++){
			if(bouldercheck[j] == 1){
				if(( boulderCoordinate[j].x + 60 >= hero.x && boulderCoordinate[j].x <= hero.x + 105) &&( boulderCoordinate[j].y <= hero.y + 80 )){
					hero.health -= 5;
					iShowBMP2(boulderCoordinate[j].x, boulderCoordinate[j].y, "bmp_outputs//collision.bmp",0);
					boulderCoordinate[j].health = 0;
				}
			}
			
		}

	// 	for(int j = 0; j< 3; j++){
	// 	if(boulderCoordinate[j].health == 0){
	// 		iShowBMP2(boulderCoordinate[j].x, boulderCoordinate[j].y, "bmp_outputs//collision.bmp",0);
	// 		bouldercheck[j] = 1;
	// 		boulderCoordinate[j].x = 0 + rand() % 600;
	// 		boulderCoordinate[j].y = 575;
	// 		boulderCoordinate[j].health = 10;
	// 	}
	// }
	// for(int j = 0; j<4; j++){
	// 	if(now[j].health == 0){
	// 		iShowBMP2(now[j].x,now[j].y, "bmp_outputs//collision.bmp",0);
	// 		now[j].y = 598;
	// 		now[j].health = 20;
			
	// 	}
	// }
	// if(hero.health <= 0){
	// 	exit(0);
	// }

}
void collisionresult(){
		for(int j = 0; j< 3; j++){
		if(boulderCoordinate[j].health == 0){
			iShowBMP2(boulderCoordinate[j].x, boulderCoordinate[j].y, "bmp_outputs//collision.bmp",0);
			bouldercheck[j] = 1;
			boulderCoordinate[j].x = 0 + rand() % 600;
			boulderCoordinate[j].y = 575;
			boulderCoordinate[j].health = 10;
		}
	}
	for(int j = 0; j<4; j++){
		if(now[j].health == 0){
			iShowBMP2(now[j].x,now[j].y, "bmp_outputs//collision.bmp",0);
			now[j].y = 598;
			now[j].health = 20;
			
		}
	}
	if(hero.health <= 0){
		exit(0);
	}
}
void collisionCheck2(){
	for(int i = 0; i < 60; i++){
		if(bulletcheck[i] != 0 && bulletcheck[i] != -1){
			// boulder
			for(int j = 0; j < 4; j++){
				if((bulletcheck[i] >= now[j].x && bulletcheck[i] <= now[j].x + 60) &&( (i * 10 >= now[j].y && i * 10 <= now[j].y + 60) )){
					now[j].health = now[j].health - 10;
					bulletcheck[i] = -1;
				}
			}
		}
		
		}
		for(int j = 0; j < 4; j++){
				if(( now[j].x + 60 >= hero.x && now[j].x <= hero.x + 105) &&(  now[j].y <= hero.y + 80 )){
					hero.health -= 10;
					iShowBMP2(now[j].x,now[j].y, "bmp_outputs//collision.bmp",0);
					now[j].health = 0;
				}
			}

}




int main() {
	first();
	// iSetTimer(100, healthchecker);
	iSetTimer(250, asteriodgenerate);
	//place your own initialization codes here.
	iInitialize(1000, 600, "learningIgraphics");
	return 0;
}
