#include "iGraphics.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
// boulder gular x change na kore asteriod gular koro

int x = 0, y = 0, r = 20, k = 0; // k = count of enemy
void drawhomepage();
void drawStartpage();
void drawAboutpage();
void drawScorepage();
void drawMusicpage();
void bulletchange();
void collisionCheck2();
void collisionresult();
void collisionCheck1();
void drawArenapage();
// void rocketbullet();
void drawarena2();
void spaceshipgenerate();
// void boroboulderdraw();

typedef struct{
	int x;
	int y;
	int health;
	int move;
	int bulletcheck[60];
}spaceship;

typedef struct{
	int place;
	int check;
}arena;
typedef struct {
	int shiptype;
	int check;

}ship;
arena are ;
ship shi;
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


borobol now[4];
spaceship rocket[2];


char boulder[3][250] = {"bmp_outputs//asteroid.bmp", "bmp_outputs//asteroid.bmp", "bmp_outputs//asteroid.bmp" };
int bulletcheck[60] = {0};
int bouldercheck[3] ={0};
player boulderCoordinate[3];



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
			drawArenapage();  // gamestate is 2 for drawarena page
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
			case 6:
			drawStartpage(); 
			break;
			case 7:
			drawarena2();
			break; // drawstartpage is drawarena1 page

		}
       

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	printf("x = %d, y= %d\n",mx,my);
	
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		
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


		
		else if(gamestate == 2){
			if((mx > 10 && mx < 410) && (my > 275 && my < 550)){
				are.place = 1;
				are.check = 1;
			}
			if((mx > 430 && mx < 830) && (my > 275 && my < 550)){
				are.place = 2;
				are.check = 1;
			}
			if((mx > 10 && mx < 278) && (my > 5 && my < 270)){
				shi.shiptype = 1;
				shi.check = 1;
			}
			if((mx > 285 && mx < 553) && (my > 5 && my < 270)){
				shi.shiptype = 2;
				shi.check = 1;
			}

			if(shi.check == 1 && are.check == 1){
				if( are.place == 1){
					gamestate = 6;    // arena 1 e asteroid er khela hobe
				}
				else if(are.place == 2){
					gamestate = 7;    // arena 2 e spaceship er khela hobe
				}
			}
		}

		else if(gamestate == 6 || gamestate == 7){  // have to change this gamestate
			createBullet = 1;
		}

		
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		
		printf("x = %d, y= %d\n",mx,my);
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	// if (key == 'k') {
	// 	createBullet = 1;
	// }

	if( key == 'd'){
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
	
}
void drawArenapage(){
	iSetColor(128,128,128);
	iFilledRectangle(0,0,1000,600);
	iShowBMP2(0,0,"bmp_outputs//home.bmp",0);
	iShowBMP2(10, 275,"bmp_outputs//arena1formenu.bmp",0);
	iShowBMP2(430, 275, "bmp_outputs//arena2formenu.bmp", 0);
	iShowBMP2(10, 5, "bmp_outputs//ship1.bmp", 0);
	iShowBMP2(285, 5, "bmp_outputs//ship2.bmp", 0);

	iSetColor(225,225,225);
	iText(10, 560, "ARENA", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(10, 260, "SHIP", GLUT_BITMAP_TIMES_ROMAN_24);

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
void spaceshipgenerate(){  //
	// srand(time(NULL));
	if(gamestate == 7){
		// srand(time)
	
		for(int j = 0; j < 2 ; j++){  // generating boulder at the start
			// if(k == p) break;
			if(rocket[j].health <= 0){

			rocket[j].health = 100;
			if(j == 0){
				rocket[j].x = 225;
				rocket[j].y = 390;

			}
			else if( j == 1){
				rocket[j].x = 725;
				rocket[j].y = 390;

			}
			// printf("%d", j);
			// k++;
			}
		
		}
	
	//changing exosting rocket x coordinate
	
	for(int i = 0; i < 2 ; i++){  // i can make it one loop

		if(rocket[i].health > 0){

		   //changing existing boulder coordinate
		
		if(rocket[i].move == 1){
			rocket[i].x = rocket[i].x + 50  ;  // egla thikmoto kaj korteche nah
		}
		else if(rocket[i].move == -1) {
			rocket[i].x = rocket[i].x - 50  ;
		}
		if(i == 0){
		if(rocket[i].x < 10){
			rocket[i].x = 10 ;
			rocket[i].move = 1;
		}
		else if(rocket[i].x > 445 ) {
			rocket[i].x = 445;
			rocket[i].move = -1;
		}

		}
		else if( i == 1){
			if(rocket[i].x < 555){
			rocket[i].x = 555 ;
			rocket[i].move = 1;
		}
		else if(rocket[i].x > 900 ) {
			rocket[i].x = 900;
			rocket[i].move = -1;
		}

		}
	

	rocket[i].bulletcheck[39] = rocket[i].x + 45;
	for(int l = 0; l < 59; l++){
		rocket[i].bulletcheck[l] = rocket[i].bulletcheck[l+1];
		rocket[i].bulletcheck[l+1] = 0;
	}
	rocket[i].bulletcheck[59] = 0;
		
			
	}
	

	}
	
	}
		
	


}

// void rocketbullet()
// {
// 	for(int i = 0; i < 10; i++){
// 		rocket[i].bulletcheck[(rocket[i].y)/10] = rocket[i].x + 45;  //generating at the y coordinate of the ship
// 	for(int j = 0 ; j < 60; j++){
// 		if(rocket[i].bulletcheck[j] != 0 && rocket[i].bulletcheck[j] != -1){  // 0 for out of screen and -1 for hitting the plane
			
// 			iShowBMP2(rocket[i].bulletcheck[j], j * 10, "bmp_outputs//sbullet.bmp", 0);  //showing the bullets where they are for every rocket
			
// 		}
// 	}
// 	for(int j = 0 ; j < 60; j++){
// 			rocket[i].bulletcheck[j] = rocket[i].bulletcheck[j + 1] ; // passing bullet information to the next coordinate
// 			rocket[i].bulletcheck[j + 1] = 0;
		
// 	}
		
// 	}

// 	}


		



void drawarena2(){

	iSetColor(128,128,128);
	iFilledRectangle(0,0,1000,600);
	iShowBMP2(0,0, "bmp_outputs//arena2.bmp", 0);
	if(shi.shiptype == 1){
		iShowBMP2(hero.x, hero.y, "bmp_outputs//spike2.bmp", 0);
	}
	else if(shi.shiptype == 2){
		iShowBMP2(hero.x, hero.y, "bmp_outputs//starwars.bmp", 0);
	}
	bulletchange();
	for(int i = 0; i < 2; i++){
		if(rocket[i].health > 0){  // it will work on bouldercheck status
		
		iShowBMP2(rocket[i].x, rocket[i].y,"bmp_outputs//enemy.bmp",0);
	}
	for(int j = 0 ; j < 40; j++){

		if(rocket[i].bulletcheck[j] != 0 && rocket[i].bulletcheck[j] != -1){  // 0 for out of screen and -1 for hitting the plane
			
			iShowBMP2(rocket[i].bulletcheck[j], j * 10, "bmp_outputs//sbullet.bmp", 0);  //showing the bullets where they are for every rocket
			
		}
		
	}
	
	// rocketbullet();

	// rocket er bullet taki alada kore function e  kora uchit??

	//collisioncheck and healthcheck
	}}

	
void drawStartpage(){
	// srand(time(NULL));
	iSetColor(128,128,128);
	iFilledRectangle(0,0,1000,600);
	iShowBMP2(0,0, "bmp_outputs//arena1.bmp", 0);
	if(shi.shiptype == 1){
		iShowBMP2(hero.x, hero.y, "bmp_outputs//spike2.bmp", 0);
	}
	else if(shi.shiptype == 2){
		iShowBMP2(hero.x, hero.y, "bmp_outputs//starwars.bmp", 0);
	}
	
	bulletchange();
	for(int i = 0; i < 1; i++){
		if(bouldercheck[i] == 1){  // it will work on bouldercheck status
		
		iShowBMP2(boulderCoordinate[i].x, boulderCoordinate[i].y, boulder[i],0);
	}
	}
	collisionCheck1();
	collisionresult();
	
	for(int i = 0; i < 4; i++){   

		
		iShowBMP2(now[i].x, now[i].y, now[i].image, 0);
	
	}
	collisionCheck2();
	collisionresult();
	healthchecker();
	

	
}
void bulletchange(){
	if(createBullet == 1){ 
		bulletcheck[8] = hero.x + 45;
		createBullet = 0;
	}

	for(int i = 8; i < 60; i++){
		if(bulletcheck[i] != 0 && bulletcheck[i] != -1){
			
			iShowBMP2(bulletcheck[i], i * 10, "bmp_outputs//sbullet.bmp", 0);
			
		}
	}
	for(int i = 59; i >=8; i--){
			bulletcheck[i + 1] = bulletcheck[i] ;
			bulletcheck[i] = 0;
		
	}

}
void asteriodgenerate(){
// eita execute howar jonno condition deya lagbe(differenent arena te gele eita execute hobena)
if(gamestate == 6){
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
		
		if(boulderCoordinate[i].x >= 990) boulderCoordinate[i].x = 990;  //ekta arektake hit korleo direction change kora uchit
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

	}}






void drawMusicpage(){
	iSetColor(128,128,128);
	iFilledRectangle(0,0,1000,600);
   
}
void drawAboutpage(){

}
void drawScorepage(){

}
void first(){
	// srand(time(NULL));
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

	are.place = 0; 
	are.check = 0;
	shi.shiptype = 0;
	shi.check = 0;

	for(int i = 0; i < 2; i++){
		rocket[i]. x = -1;
		rocket[i].y = -1;
		rocket[i].health = 0;
		for(int j = 0; j < 60; j++) rocket[i].bulletcheck[j] = 0;
		// rocket[i].bulletcheck[60] = {0};
	}
	rocket[0].move = 1;
	rocket[1].move = -1;

}
void collisionCheck1(){
	// if  bullet hit any boulder
	// asteriod
	
for(int i = 0; i < 60; i++){
		if(bulletcheck[i] != 0 && bulletcheck[i] != -1){
			
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


		for(int j = 0; j < 3;j++){
			if(bouldercheck[j] == 1){
				if(( boulderCoordinate[j].x + 60 >= hero.x && boulderCoordinate[j].x <= hero.x + 105) &&( boulderCoordinate[j].y <= hero.y + 80 )){
					hero.health -= 5;
					iShowBMP2(boulderCoordinate[j].x, boulderCoordinate[j].y, "bmp_outputs//collision.bmp",0);
					boulderCoordinate[j].health = 0;
				}
			}
			
		}


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
	srand(time(NULL));
	first();
	iSetTimer(500, asteriodgenerate);
	iSetTimer(250, spaceshipgenerate);
	//place your own initialization codes here.
	iInitialize(1000, 600, "SPACE COWBOY");
	return 0;
}
// for(int j = 0 ; j < 60; j++){
			
// 			rocket[i].bulletcheck[j] = rocket[i].bulletcheck[j + 1] ; // passing bullet information to the next coordinate
// 			rocket[i].bulletcheck[j + 1] = 0;
			
		
// 		// }
// 		// rocket[i].bulletcheck[(rocket[i].y)/10] = rocket[i].x + 45;
// 		}