#include "header.h"
#include "menu_other_screen.cpp"
#include "loadMedia.cpp"

#define MIN(x, y) (x < y) ? x : y
#define MAX(x, y) (x > y) ? x : y

int g = 1; // gravity
int ground = 570;
int current_w_obstacle = 1;
int reel = 0;
int p = 0;
int obsx = 1800;
int obsy;
int stonex = 200;
int stones = 1;
ll wtotal_dist = 0;
int love_show = 0;
int diamond_show = 0;
int coin_show = 0;
int lovex, lovey, loved, coinx, coiny, coined, diamondx, diamondy, diamonded;
int coinscroll = 0, diamondscroll = 0, lovescroll = 0, fobsscroll = 0;
int coin_score = 0, diamond_score = 0;
int wspeed = 2;
int fobsx, fobsy, fobs_show = 1;
int x, y;
double rotate_angle = 0.00;

//


void wbackground(SDL_Event &e)
{

	//SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
	//SDL_RenderClear(gRenderer);
	
	forest.render(scroll, 0);
	//forest.render(scroll + forest.mWidth, 0);
	forest.render(scroll + forest.mWidth, 0);
	forest.render(scroll + 2*forest.mWidth, 0);
	if(reel == 0) mashroom.render(scroll + 300, 570 - mashroom.mWidth);
	mashroom.render(scroll + 2*SCREEN_WIDTH - 300, 570 - mashroom.mWidth);
	
	if(reel == 0) bush3.render(300 + scroll,  570 - bush3.mHeight);
	bush3.render(-300 + scroll + 2*SCREEN_WIDTH, 570 - bush3.mHeight);

	if(reel == 0) tree1.render(100 + scroll, 570 - tree1.mHeight);
	tree1.render(-100 + scroll + 2*SCREEN_WIDTH, 570 - tree1.mHeight);
	tree1.render(-1800 + scroll + 2*SCREEN_WIDTH, 570 - tree1.mHeight);

	if(reel == 0) tree2.render(1100 + scroll, 570 - tree2.mHeight);
	tree2.render(-1100 + scroll + 2*SCREEN_WIDTH, 570 - tree2.mHeight);

	if(reel == 0) mashroom.render(1010 + scroll, 570 - mashroom.mWidth);
	mashroom.render(-1010 + scroll + 2*SCREEN_WIDTH, 570 - mashroom.mWidth);

	if(reel == 0) bush1.render(120 + scroll, 570 - bush1.mHeight);
	bush1.render(-120 + scroll + 2*SCREEN_WIDTH, 570 - bush1.mHeight);

	if(reel == 0) bush2.render(100 + scroll, 570 - bush2.mHeight);
	bush2.render(-100 + scroll + 2*SCREEN_WIDTH, 570 - bush2.mHeight);
	bush2.render(-1800 + scroll + 2*SCREEN_WIDTH, 570 - bush2.mHeight);



	path1.render(scroll, SCREEN_HEIGHT - 150);
	path1.render(scroll + 2*SCREEN_WIDTH, SCREEN_HEIGHT - 150);

	path5.render(scroll + SCREEN_WIDTH, SCREEN_HEIGHT - 150);
	path5.render(scroll + SCREEN_WIDTH + 2*SCREEN_WIDTH, SCREEN_HEIGHT - 150);
	path5.render(scroll + SCREEN_WIDTH + 765, SCREEN_HEIGHT - 150);
	path5.render(scroll + SCREEN_WIDTH + 2*SCREEN_WIDTH + 765, SCREEN_HEIGHT - 150);
	water2.render(scroll + SCREEN_WIDTH + 515, SCREEN_HEIGHT - 150);
	water1.render(scroll, SCREEN_HEIGHT - 80);
	water1.render(scroll + 2*SCREEN_WIDTH, SCREEN_HEIGHT - 80);

	obs[current_w_obstacle].render(-obsx + scroll + 2*SCREEN_WIDTH, obsy);
	stone[stones].render(-stonex + scroll + 2*SCREEN_WIDTH, 570 - stone[stones].mHeight);

	for(int i = 0; i < live; i++){
		life.render(i*30, 0);
	}


	if(love_show > 0) {
		if(!loved) love.render(lovex + scroll, lovey);
		else love1.render(lovex + scroll, lovey);
	}
	if(coin_show > 0) {
		if(!coined) coin.render(coinx + scroll, coiny);
		else coin1.render(coinx + scroll, coiny);
	}
	if(diamond_show > 0){
		if(!diamonded) diamond.render(diamondx + scroll, diamondy);
		else diamond1.render(diamondx + scroll, diamondy);
	}

	std::string temp = to_string(coin_score);
	coinscoretexture1.loadFromRenderedText(temp.c_str(), textColor);
	coinscoretexture.render(880, 5);
	coinscoretexture1.render(930, 0);
	temp = to_string(diamond_score);
	diamondscoretexture1.loadFromRenderedText(temp.c_str(), textColor);
	diamondscoretexture.render(980, 5);
	diamondscoretexture1.render(1030, 0);

	temp = to_string(wCurrentScore);
	scoretexture.loadFromRenderedText(temp, textColor);
	scoretexture.render(600, 0);


	if(fobs_show)
		fobs.render(fobsx + scroll, fobsy, NULL, NULL, NULL, SDL_FLIP_VERTICAL);

	SDL_GetMouseState(&x, &y);
	
	if(over_button(x, y, SCREEN_WIDTH - 210, 5, 200, 50)){
		SDL_Delay(25);
		pause_shadow = 1;
		if(e.type == SDL_MOUSEBUTTONDOWN){
			pause = 1;
			on_menu = 1;
			on_play = 0;
		}
	}
	else pause_shadow = 0;

	if(!pause_shadow) pause_button.render(SCREEN_WIDTH - 210, 5);
	else pause_button_sh.render(SCREEN_WIDTH - 210, 5);

	//SDL_RenderPresent(gRenderer);
}
//bravoos background
void bbackground(SDL_Event &e)
{
	bg2.render(bscroll, 0);
	bg2.render(bscroll + SCREEN_WIDTH, 0);

	for(int i = 0; i < blive; i++){
		life.render(i*30, 0);
	}

	std::string temp = to_string(bcoin_score);
	coinscoretexture1.loadFromRenderedText(temp.c_str(), textColor);
	coinscoretexture.render(880, 5);
	coinscoretexture1.render(930, 0);
	temp = to_string(bdiamond_score);
	diamondscoretexture1.loadFromRenderedText(temp.c_str(), textColor);
	diamondscoretexture.render(980, 5);
	diamondscoretexture1.render(1030, 0);

	temp = to_string(bCurrentScore);
	scoretexture.loadFromRenderedText(temp, textColor);
	scoretexture.render(600, 0);

	SDL_GetMouseState(&x, &y);
	if(over_button(x, y, SCREEN_WIDTH - 210, 5, 200, 50)){
		SDL_Delay(25);
		pause_shadow = 1;
		if(e.type == SDL_MOUSEBUTTONDOWN){
			pause = 1;
			on_menu = 1;
			on_play = 0;
		}
	}
	else pause_shadow = 0;

	if(blove_show > 0) {
		if(!bloved) love.render(blovex + bscroll, blovey);
		else love1.render(blovex + bscroll, blovey);
	}
	if(bcoin_show > 0) {
		if(!bcoined) coin.render(bcoinx + bscroll, bcoiny);
		else coin1.render(bcoinx + bscroll, bcoiny);
	}
	if(bdiamond_show > 0){
		if(!bdiamonded) diamond.render(bdiamondx + bscroll, bdiamondy);
		else diamond1.render(bdiamondx + bscroll, bdiamondy);
	}

	if(!pause_shadow) pause_button.render(SCREEN_WIDTH - 210, 5);
	else pause_button_sh.render(SCREEN_WIDTH - 210, 5);

	
	for(int i = 0; i < 7; i++) 
		if(bz) 
			rotating[id[i]].render(bzscroll + rx[i], ry[i], NULL, rotate_angle, NULL, SDL_FLIP_NONE);

	if(!bz) {
		for(int i = 0; i < 7; i++) upper[i].render(chainscroll + i*180 + SCREEN_WIDTH, -5);
		for(int i = 0; i < 7; i++) lower[i].render(chainscroll + i*180 + SCREEN_WIDTH, SCREEN_HEIGHT - lower[i].mHeight);
		middle[middle_state].render(chainscroll + middle1x + SCREEN_WIDTH, middle1y);
		middle[(middle_state+1)%7].render(chainscroll + middle2x + SCREEN_WIDTH, middle2y);
	}

}

int main()
{
	if(!init()) return 0;
	if(!loadMedia()) return 0;
	//printf("%d %d", obs[1].mHeight, obs[1].mWidth);
	SDL_Event e;
	bool quit = false;
	int screen = 0;

	live = 3;
	pinkmany = SCREEN_HEIGHT - 150;
	current_w_obstacle = 1;
	obsy = 570 - obs[current_w_obstacle].mHeight;
	int p = 1;
	obsy = 570 - obs[current_w_obstacle].mHeight;

	while(!on_quit)
	{
		while( SDL_PollEvent( &e ) != 0 )
		{
			if( e.type == SDL_QUIT )
			{
				on_quit = true;
				break;
			}
			if(on_gameover)
			{
				on_gameover;
			}
			pinkman_handleEvent(e);
		}

		if(!on_play) {
				show_menu_otherscreen(e);
				e.type = 0;
				continue;
		}
		else{

			//map2

			if(pbravoos){

				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear(gRenderer);
				if(fx < 0) fx = 0;
				pinkman_move(fx, fy);

				bscroll -= screen_speed;
				if(bscroll < -SCREEN_WIDTH){
					bscroll = 0;
				}
				bstate = floor(bscreen/16);
				if(mVelX < 0) bstate = 3;
				
				bscreen++;
				if(bscreen == 48) bscreen = 0;

				btotal_dist += bspeed;

				if(btotal_dist%20 == bspeed) bCurrentScore++;

				if(blovescroll >= 1500 && blove_show <= 0){
					blove_show = SCREEN_WIDTH;
					blovex = SCREEN_WIDTH - bscroll - rand()%200;
					blovey = ground - rand()%150 - 50;
					bloved = 0;
					blovescroll = 0;
				}
				if(bcoinscroll >= 600){
					bcoin_show = SCREEN_WIDTH;
					bcoinx = SCREEN_WIDTH - bscroll - rand()%500;
					bcoiny = ground - rand()%50 - 50;
					bcoined = 0;
					bcoinscroll = 0;
				}
				if(bdiamondscroll >= 1280){
					bdiamond_show = SCREEN_WIDTH;;
					bdiamondx = SCREEN_WIDTH - bscroll - rand()%500;
					bdiamondy = ground - rand()%100 - 50;
					bdiamonded = 0;
					bdiamondscroll = 0;
				}
			
				//printf("%d %d\n", pinkmanx, pinkmany);
				blovescroll += wspeed; 
				bcoinscroll += wspeed; 
				bdiamondscroll += wspeed;

				if(bz) for(int i = 0; i < 7; i++)
				{
					SDL_Rect a = {fx, fy, pFly[state].mWidth, pFly[state].mHeight};
					SDL_Rect b = {rx[i] + bzscroll, ry[i], rotating[id[i]].mWidth, rotating[id[i]].mHeight};

					if(checkCollision(a, b)){
						for(int i = 0; i < 6; i++){
							SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
							SDL_RenderClear(gRenderer);
							bbackground(e);
							if(i%2 == 0)broken_heart.render(SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT/2 - 100);
							SDL_RenderPresent(gRenderer);
							SDL_Delay(300);
						}
						blive--;
						fx = fx + 500;
						break;						
					}
				}
				if(blive == 0)
				{	
					on_gameover = 1;
					on_play = 0;
					continue;
				}
				if(!bz) for(int i = 0; i < 7; i++)
				{
					SDL_Rect a = {fx, fy, pFly[state].mWidth, pFly[state].mHeight};
					SDL_Rect b = {chainscroll + i*180 + SCREEN_WIDTH, -5, upper[i].mWidth, upper[i].mHeight};
					SDL_Rect c = {chainscroll + i*180 + SCREEN_WIDTH, SCREEN_HEIGHT - lower[i].mHeight, lower[i].mWidth, lower[i].mHeight};

					if(checkCollision(a, b) || checkCollision(a, c)){
						for(int i = 0; i < 6; i++){
							SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
							SDL_RenderClear(gRenderer);
							bbackground(e);
							if(i%2 == 0)broken_heart.render(SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT/2 - 100);
							SDL_RenderPresent(gRenderer);
							SDL_Delay(300);
						}
						blive--;
						fx = 200;
						fy = 200;
					}
				}
				if(blive == 0)
				{	
					on_gameover = 1;
					on_play = 0;
					continue;
				}

				SDL_Rect a = {fx, fy, pFly[state].mWidth, pFly[state].mHeight};
				SDL_Rect b = {chainscroll + middle1x + SCREEN_WIDTH, middle1y, middle[middle_state].mWidth, middle[middle_state].mHeight};
				SDL_Rect c = {chainscroll + middle2x + SCREEN_WIDTH, middle2y, middle[(middle_state + 1)%7].mWidth, middle[(middle_state + 1)%7].mHeight};

				if(checkCollision(a, b) || checkCollision(a, c)){
					for(int i = 0; i < 6; i++){
						SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
						SDL_RenderClear(gRenderer);
						bbackground(e);
						if(i%2 == 0)broken_heart.render(SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT/2 - 100);
						SDL_RenderPresent(gRenderer);
						SDL_Delay(300);
					}
					blive--;
					fx = 200;
					fy = 200;
					break;						
				}

				if(blive == 0)
				{	
					on_gameover = 1;
					on_play = 0;
					continue;
				}


				if(blove_show > 0 && !bloved){
					SDL_Rect a = {fx, fy, pFly[bstate].mWidth, pFly[bstate].mHeight};
					SDL_Rect loverect = {blovex + bscroll, blovey, love.mWidth, love.mHeight};
					if(checkCollision(a, loverect)){
						if(blive < 3) blive++;
						bloved = 1;
					}
					blove_show -= bspeed;
				}
				if(bcoin_show > 0 && !bcoined){
					SDL_Rect a = {fx, fy, pFly[bstate].mWidth, pFly[bstate].mHeight};
					SDL_Rect coinrect = {bcoinx + bscroll, bcoiny, coin.mWidth, coin.mHeight};
					if(checkCollision(a, coinrect)){
						bCurrentScore += 10;
						bcoin_score++;
						bcoined = 1;
					}
					bcoin_show -= bspeed;

				}
				if(bdiamond_show > 0 && !bdiamonded){
					SDL_Rect a = {fx, fy, pFly[bstate].mWidth, pFly[bstate].mHeight};
					SDL_Rect drect = {bdiamondx + bscroll, bdiamondy, diamond.mWidth, diamond.mHeight};
					if(checkCollision(a, drect)){
						bdiamonded = 1;
						bCurrentScore += 100;
						bdiamond_score++;
					}
					bdiamond_show -= bspeed;
				}

				if(!bz) 
				{

					chainscroll -= bspeed;

					if(chainscroll < -SCREEN_WIDTH - 1000){
						bzscroll = 0;
						bz = 1;
						st++;
						if(st == 7) st = 0;
						for(int i = 0; i < 7; i++) {
							id[i] = (st + i)%5;
							ryr[i] = !(i >= 3);
							rx[i] = SCREEN_WIDTH + rand()%500;
						}
						ry[0] = 0;
						ry[1] = 200;
						ry[2] = 300;
						ry[3] = 400;
						ry[4] = 600;
						ry[5] = 650;
						ry[6] = 720;
						screen_speed = 0;
					}
				}
				else
				{

					bzscroll -= bspeed;
					bool tmp = 0;
					for(int i = 0; i < 7; i++) if(bzscroll + rotating[id[i]].mWidth > -SCREEN_WIDTH) tmp |= 1;
					if(tmp == 0) bz = 0;

					if(bz)
					{

						for(int i = 0; i < 7; i++) if(id[i] != 4){
	
							if(ryr[i]){
								if((ry[i] - bspeed) >= 0) ry[i] -= bspeed;
								else {
									ry[i] += bspeed;
									ryr[i] = 0;
								}							
							}
							else {
								if((ry[i] + bspeed) <= SCREEN_HEIGHT) ry[i] += bspeed;
								else {
									ry[i] -= bspeed;
									ryr[i] = 1;
								}
							}
						}

						//printf("%d\n", bzscroll + rx);
					}
					else {

						chainscroll = 0;
						middle_state++;
						if(middle_state == 7) middle_state = 0;
						middle1x = 200 + rand()%50;
						middle1y = 200 + rand()%50;
						middle2x = middle1x + middle[middle_state].mWidth + 100 + rand()%100;
						middle2y = 200 + rand()%50;
					}
				}

				bbackground(e);

				pFly[bstate].render(fx, fy);

				rotate_angle += 10;
				if(rotate_angle == 360) rotate_angle = 0;
				SDL_RenderPresent(gRenderer);

			}
			else if(pwestors){
				//map_2


				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear(gRenderer);

				
				//wbackground
				wbackground(e);				
				scroll -= 4;
				if(scroll < -2*SCREEN_WIDTH) {
					scroll = 0;
					current_w_obstacle++;
					stones++;
					if(current_w_obstacle == 4){
						current_w_obstacle = 1;
						stones = 1;
					}
					// love_show = 0;
					// coin_show = 0;
					// diamond_show = 0;
					// diamonded = 0;
					// loved = 0;
					// coined = 0;

					//obsx += SCREEN_WIDTH;
				}

				if(scroll < -SCREEN_WIDTH){

					reel++;
				}

				const Uint8* keystates = SDL_GetKeyboardState(NULL);
				if(keystates[SDL_SCANCODE_KP_0]) pinkmanx = 0;

				//checking jump
				if(keystates[SDL_SCANCODE_RETURN] || keystates[SDL_SCANCODE_J]) {
					//give a jump
					int y[9] = {287, 317, 347, 377, 377, 330, 317, 287, 287};
					for(int i = 0; i < 9; i++){
						SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
						SDL_RenderClear(gRenderer);

						//wbackground
						wbackground(e);

						pJump[i].render(pinkmanx, SCREEN_HEIGHT - y[i]);

						SDL_Rect pink = {pinkmanx, SCREEN_HEIGHT - y[i], pJump[i].mWidth, pJump[i].mHeight};
						SDL_Rect b = {scroll + SCREEN_WIDTH + 515, SCREEN_HEIGHT - 150 + 50, water2.mWidth, water2.mHeight};
						SDL_Rect c = {obsx, obsy, obs[current_w_obstacle].mWidth, obs[current_w_obstacle].mHeight};
						SDL_Rect f = {-1, -1, 0, 0};
						if(fobs_show > 0) f = {fobsx + scroll, fobsy, fobs.mWidth, fobs.mHeight};

						if(checkCollision(pink, b) || checkCollision(pink, c) ||  checkCollision(pink, f)){
							for(int i = 0; i < 6; i++){
							SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
							SDL_RenderClear(gRenderer);
							wbackground(e);
							if(i%2 == 0)broken_heart.render(SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT/2 - 100);
							SDL_RenderPresent(gRenderer);
							SDL_Delay(300);
						}							
							pinkmanx = pinkmanx + 250;
							if(live == 0)
							{	
								on_gameover = 1;
								on_play = 0;
								continue;
							}
						}

						//coin, diamond and love collision during jump
						if(love_show > 0 && !loved){
							SDL_Rect a = {pinkmanx, pinkmany, pRun[state].mWidth, pRun[state].mHeight};
							SDL_Rect loverect = {lovex + scroll, lovey, love.mWidth, love.mHeight};
							if(checkCollision(a, loverect)){
								if(live < 3) live++;
								loved = 1;
							}
							love_show -= wspeed;
						}
						if(coin_show > 0 && !coined){
							SDL_Rect a = {pinkmanx, pinkmany, pRun[state].mWidth, pRun[state].mHeight};
							SDL_Rect coinrect = {coinx + scroll, coiny, coin.mWidth, coin.mHeight};
							if(checkCollision(a, coinrect)){
								score += 10;
								coin_score++;
								coined = 1;
							}
							coin_show -= wspeed;
						}
						if(diamond_show > 0 && !diamonded){
							SDL_Rect a = {pinkmanx, pinkmany, pRun[state].mWidth, pRun[state].mHeight};
							SDL_Rect drect = {diamondx + scroll, diamondy, diamond.mWidth, diamond.mHeight};
							if(checkCollision(a, drect)){
								diamonded = 1;
								score += 100;
								diamond_score++;
							}
							diamond_show -= wspeed;
						}


						SDL_RenderPresent(gRenderer);
						SDL_Delay(50);
						//printf("%d\n", y[i]);

						pinkmanx += 60 - (i >= 7)*60;
						//scroll -= 12;
					}

					SDL_Delay(20);
					//scroll -= 260;				
					wCurrentScore += 5;
					//jump++;
				}
				else
				{
					if(pinkmanx >= scroll + SCREEN_WIDTH + 515 && pinkmanx <= scroll + SCREEN_WIDTH + 765 - pRun[state].mWidth/2){
						mVelY = mVelY + g;
						//printf("here");
						//pinkmany += mVelY;
						pinkmany = min(pinkmany, SCREEN_HEIGHT - 200);
						//printf("%d", mVelY);
					}
					else {
						pinkmany = SCREEN_HEIGHT - 256;
						mVelY = 0;
					}
					pinkman_move(pinkmanx, pinkmany);

					state = screen/8;
					SDL_RendererFlip flip;
					if(mVelX < 0) flip = SDL_FLIP_HORIZONTAL;
					else flip = SDL_FLIP_NONE;
					
					pRun[state].render(pinkmanx, pinkmany, NULL, NULL, NULL, flip);

					
					SDL_Rect a = {pinkmanx, pinkmany, pRun[state].mWidth, pRun[state].mHeight};
					SDL_Rect b = {scroll + SCREEN_WIDTH + 515, SCREEN_HEIGHT - 150 + 50, water2.mWidth, water2.mHeight};
					SDL_Rect c = {-obsx + scroll + 2*SCREEN_WIDTH, obsy, obs[current_w_obstacle].mWidth, obs[current_w_obstacle].mHeight};
					SDL_Rect d = {-stonex + scroll + 2*SCREEN_WIDTH, 570 - stone[stones].mHeight, stone[stones].mWidth, stone[stones].mHeight};
					SDL_Rect f = {0, 0, 0, 0};
					if(fobs_show > 0) f = {fobsx + scroll, fobsy, fobs.mWidth, fobs.mHeight};
					if(checkCollision(a, b) || checkCollision(a, c) || checkCollision(a, d) || checkCollision(a, f)){
						for(int i = 0; i < 6; i++){
							SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
							SDL_RenderClear(gRenderer);
							wbackground(e);
							if(i%2 == 0)broken_heart.render(SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT/2 - 100);
							SDL_RenderPresent(gRenderer);
							SDL_Delay(300);
						}
						--live;
						pinkmanx = SCREEN_WIDTH + 770 + scroll;
						if(live == 0)
						{
							on_gameover = 1;
							on_play = 0;
							continue;
						}
					}				
				}
				//falling obstacl 
				if(fobs_show)
				{
					fobsy = MIN(ground - fobs.mHeight, fobsy + wspeed);
					fobs_show -= wspeed;
					if(fobs_show < 0) fobs_show = 0;

				}
				//coin, diamond and love render and collision
				if(love_show > 0 && !loved){
					SDL_Rect a = {pinkmanx, pinkmany, pRun[state].mWidth, pRun[state].mHeight};
					SDL_Rect loverect = {lovex + scroll, lovey, love.mWidth, love.mHeight};
					if(checkCollision(a, loverect)){
						if(live < 3) live++;
						loved = 1;
					}
					love_show -= wspeed;
				}
				if(coin_show > 0 && !coined){
					SDL_Rect a = {pinkmanx, pinkmany, pRun[state].mWidth, pRun[state].mHeight};
					SDL_Rect coinrect = {coinx + scroll, coiny, coin.mWidth, coin.mHeight};
					if(checkCollision(a, coinrect)){
						score += 10;
						coin_score++;
						coined = 1;
					}
					coin_show -= wspeed;
				}
				if(diamond_show > 0 && !diamonded){
					SDL_Rect a = {pinkmanx, pinkmany, pRun[state].mWidth, pRun[state].mHeight};
					SDL_Rect drect = {diamondx + scroll, diamondy, diamond.mWidth, diamond.mHeight};
					if(checkCollision(a, drect)){
						diamonded = 1;
						score += 100;
						diamond_score++;
					}
					diamond_show -= wspeed;
				}

				if(pinkmanx  + pRun[state].mWidth >= SCREEN_WIDTH) {
					pinkmanx = 0;
					scroll = 0;
					scroll = 0;
					current_w_obstacle++;
					stones++;
					if(current_w_obstacle == 4){
						current_w_obstacle = 1;
						stones = 1;
					}
					love_show = 0;
					coin_show = 0;
					diamond_show = 0;
					diamonded = 0;
					loved = 0;
					coined = 0;
					//p++;
				}

				screen++;
				if(screen > 71) screen = 0;
				wtotal_dist++;

				//coin, diamond, love controller
				
				if(lovescroll >= 1500 && love_show <= 0){
					love_show = SCREEN_WIDTH;
					lovex = SCREEN_WIDTH - scroll - rand()%200;
					lovey = ground - rand()%150 - 50;
					loved = 0;
					lovescroll = 0;
				}
				if(coinscroll >= 600){
					coin_show = SCREEN_WIDTH;
					coinx = SCREEN_WIDTH - scroll - rand()%500;
					coiny = ground - rand()%50 - 50;
					coined = 0;
					coinscroll = 0;
				}
				if(diamondscroll >= 1280){
					diamond_show = SCREEN_WIDTH;;
					diamondx = SCREEN_WIDTH - scroll - rand()%500;
					diamondy = ground - rand()%100 - 50;
					diamonded = 0;
					diamondscroll = 0;
				}
				if(fobsscroll >= 1500){
					fobs_show = SCREEN_WIDTH;
					fobsx = SCREEN_WIDTH - scroll - 200;
					fobsy = 0;
					fobsscroll = 0;
				}
				//printf("%d %d\n", pinkmanx, pinkmany);
				lovescroll += wspeed; 
				coinscroll += wspeed; 
				diamondscroll += wspeed; 
				fobsscroll += wspeed;

				if(wtotal_dist%(2*SCREEN_WIDTH) == 0){
					wspeed = min(wspeed + 1, 10);
				}
				//printf("%d\n", wspeed);
				if(wtotal_dist%20 == 0) wCurrentScore++;
				SDL_RenderPresent(gRenderer);
			}

		}

		//printf("%d\n", fobs_show);

		//printf("%d %d\n", pbravoos, pwestors);

	}

	Mix_PlayChannel(-1, gClick, 0);
	SDL_Delay(50);
	close();
}