#include "header.h"
#include "menu_other_screen.cpp"
#include "loadMedia.cpp"

#define min(x, y) (x < y) ? x : y;
int g = 1;
int ground = 570;
int water_zone = 250;
bool obs_water = 0;
int obstacle = 1;
int reel = 0;
int p = 0;
int obsx = 1800;
int obsy;
int stonex = 200;
int stones = 1;
ll wtotal_dist = 0;
ll btotal_dist = 0;
int love_show = 0;
int diamond_show = 0;
int coin_show = 0;
int lovex, lovey, loved, coinx, coiny, coined, diamondx, diamondy, diamonded;
int coin_score = 0, diamond_score = 0;
int wspeed = 2;
int bspeed = 2;

void background()
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

	obs[obstacle].render(-obsx + scroll + 2*SCREEN_WIDTH, obsy);
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

	//SDL_RenderPresent(gRenderer);
}

int main()
{
	if(!init()) return 0;
	if(!loadMedia()) return 0;
	//printf("%d %d", obs[1].mHeight, obs[1].mWidth);
	SDL_Event e;
	bool quit = false;
	int screen = 0;
	int run = 1, fly = 0;

	live = 3;
	pinkmany = SCREEN_HEIGHT - 150;
	obstacle = 1;
	obsy = 570 - obs[obstacle].mHeight;
	int p = 1;
	obsy = 570 - obs[obstacle].mHeight;

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

			if(pbravoos){

				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear(gRenderer);
				pinkman_move();
				state = floor(screen/24);
				if(mVelX < 0)
					state = 3;

				pFly[state].render(pinkmanx, pinkmany);
			}
			else if(pwestors){
				//map_2


				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear(gRenderer);

				
				//background
				background();				
				scroll -= wspeed;
				if(scroll < -2*SCREEN_WIDTH) {
					scroll = 0;
					obstacle++;
					stones++;
					if(obstacle == 4){
						obstacle = 1;
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
					int y[9] = {257, 287, 317, 337, 337, 300, 287, 257, 257};
					for(int i = 0; i < 9; i++){
						SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
						SDL_RenderClear(gRenderer);

						//background
						background();

						pJump[i].render(pinkmanx, SCREEN_HEIGHT - y[i]);

						SDL_Rect a = {pinkmanx, SCREEN_HEIGHT - pJump[i].mHeight - y[i], pJump[i].mWidth, pJump[i].mHeight};
						SDL_Rect b = {scroll + SCREEN_WIDTH + 515, SCREEN_HEIGHT - 150 + 50, water2.mWidth, water2.mHeight};
						SDL_Rect c = {obsx, obsy, obs[obstacle].mWidth, obs[obstacle].mHeight};

						if(checkCollision(a, b) || checkCollision(a, c)){
							for(int i = 0; i < 6; i++){
							SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
							SDL_RenderClear(gRenderer);
							background();
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
					pinkman_move();

					state = screen/8;
					SDL_RendererFlip flip;
					if(mVelX < 0) flip = SDL_FLIP_HORIZONTAL;
					else flip = SDL_FLIP_NONE;
					
					pRun[state].render(pinkmanx, pinkmany, NULL, NULL, NULL, flip);

					
					SDL_Rect a = {pinkmanx, pinkmany, pRun[state].mWidth, pRun[state].mHeight};
					SDL_Rect b = {scroll + SCREEN_WIDTH + 515, SCREEN_HEIGHT - 150 + 50, water2.mWidth, water2.mHeight};
					SDL_Rect c = {-obsx + scroll + 2*SCREEN_WIDTH, obsy, obs[obstacle].mWidth, obs[obstacle].mHeight};
					SDL_Rect d = {-stonex + scroll + 2*SCREEN_WIDTH, 570 - stone[stones].mHeight, stone[stones].mWidth, stone[stones].mHeight};
					if(checkCollision(a, b) || checkCollision(a, c) || checkCollision(a, d)){
						for(int i = 0; i < 6; i++){
							SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
							SDL_RenderClear(gRenderer);
							background();
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
					obstacle++;
					stones++;
					if(obstacle == 4){
						obstacle = 1;
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
				
				if(wtotal_dist%2000 == 0 && love_show <= 0){
					srand(time(0));
					love_show = SCREEN_WIDTH;
					lovex = SCREEN_WIDTH - scroll - rand()%200;
					lovey = ground - rand()%150 - 50;
					loved = 0;
				}
				if(wtotal_dist%50 == 0 && wtotal_dist%300 != 0 && coin_show <= 0 && love_show <= 0 && diamond_show <= 0){
					srand(time(0));
					coin_show = SCREEN_WIDTH;
					coinx = SCREEN_WIDTH - scroll - rand()%500;
					coiny = ground - rand()%50 - 50;
					coined = 0;
				}
				if(wtotal_dist%300 == 0 && love_show <= 0 && diamond_show <= 0){
					srand(time(0));
					diamond_show = SCREEN_WIDTH;;
					diamondx = SCREEN_WIDTH - scroll - rand()%2500;
					diamondy = ground - rand()%100 - 50;
					diamonded = 0;
				}
				//printf("%d %d\n", pinkmanx, pinkmany);

				if(wtotal_dist%(2*SCREEN_WIDTH) == 0){
					wspeed = min(wspeed + 1, 10);
				}
				//printf("%d\n", wspeed);
			}

			if(wtotal_dist%20 == 0) wCurrentScore++;

			SDL_RenderPresent(gRenderer);
		}

		//printf("%d %d\n", pbravoos, pwestors);

	}

	Mix_PlayChannel(-1, gClick, 0);
	SDL_Delay(50);
	close();
}