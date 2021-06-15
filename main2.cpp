#include "header.cpp"
#include "menu_other_screen.cpp"
#include "loadMedia.cpp"

#define min(x, y) (x < y) ? x : y;
int g = 1;
int scroll = 0;
int water_zone = 250;
bool obs_water = 1;
int obsx, obsy;
int obstacle = 1;

void background(){

	//SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
	//SDL_RenderClear(gRenderer);
	obs[obstacle].render(obsx, obsy);
	obs[obstacle].render(obsx + scroll + SCREEN_WIDTH, obsy);

	forest.render(scroll, 0);
	forest.render(scroll + forest.mWidth, 0);
	mashroom.render(340 + scroll, 570 - mashroom.mWidth);
	mashroom.render(340 + scroll + SCREEN_WIDTH + obs_water*water_zone, SCREEN_HEIGHT - mashroom.mWidth);
	mashroom.render(1010 + scroll, 570 - mashroom.mWidth);
	mashroom.render(1010 + scroll + mashroom.mWidth + obs_water*water_zone, SCREEN_HEIGHT - mashroom.mWidth);

	bush1.render(120 + scroll, 570 - bush1.mHeight);
	bush1.render(120 + scroll + SCREEN_WIDTH + obs_water*water_zone, 570 - bush1.mHeight);
	bush2.render(100 + scroll, 570 - bush2.mHeight);
	bush2.render(100 + scroll + SCREEN_WIDTH  + obs_water*water_zone, 570 - bush2.mHeight);
	bush3.render(300 + scroll, 570 - bush3.mHeight);
	bush3.render(300 + scroll + SCREEN_WIDTH + obs_water*water_zone, 570 - bush3.mHeight);
	tree1.render(100 + scroll, 570 - tree1.mHeight);
	tree1.render(100 + scroll + SCREEN_WIDTH + obs_water*water_zone, 570 - tree1.mHeight);
	tree2.render(1100 + scroll, 570 - tree2.mHeight);
	tree2.render(1200 + scroll + SCREEN_WIDTH + obs_water*water_zone, 570 - tree2.mHeight);
	path1.render(scroll, SCREEN_HEIGHT - 150);
	path1.render(scroll + SCREEN_WIDTH + obs_water*water_zone, SCREEN_HEIGHT - 150);
	water2.render(scroll + path1.mWidth*obs_water, SCREEN_HEIGHT - 150);
	//water2.render(scroll + 500 + water2.mWidth, SCREEN_HEIGHT - 150);
	water1.render(scroll, SCREEN_HEIGHT - 80);
	water1.render(scroll + water1.mWidth, SCREEN_HEIGHT - 80);

	//SDL_RenderPresent(gRenderer);
}

int main()
{
	if(!init()) return 0;
	if(!loadMedia()) return 0;

	SDL_Event e;
	bool quit = false;
	int screen = 0;
	int run = 1, fly = 0;

	live = 3;
	int jump = 0;
		pinkmany = SCREEN_HEIGHT - 150;
	int p = 1;
	while(!on_quit)
	{
		while( SDL_PollEvent( &e ) != 0 )
		{
			if( e.type == SDL_QUIT )
			{
				on_quit = true;
				break;
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

				obsx = 400 + scroll;
				obsy = 570 - obs[obstacle].mHeight;

				//background
				background();

				for(int i = 0; i < live; i++){
					life.render(i*30, 0);
				}
				
				scroll -= 2;
				if(scroll < -SCREEN_WIDTH) {
					scroll = 0;
					//obs_water ^= 1;
					obstacle++;
					if(obstacle == 4){
						obstacle = 1;
					}
				}

				const Uint8* keystates = SDL_GetKeyboardState(NULL);
				if(keystates[SDL_SCANCODE_KP_0]) pinkmanx = 0;

				//checking jump
				if(keystates[SDL_SCANCODE_RETURN] || keystates[SDL_SCANCODE_J]) {
					//give a jump
					int x = pinkmanx;
					int y[9] = {257, 287, 317, 337, 337, 300, 287, 257, 257};
					for(int i = 0; i < 9; i++){
						SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
						SDL_RenderClear(gRenderer);

						//background
						background();

						pJump[i].render(x, SCREEN_HEIGHT - y[i]);

						SDL_Rect a = {x, SCREEN_HEIGHT - pJump[i].mHeight - y[i], pJump[i].mWidth, pJump[i].mHeight};
						SDL_Rect b = {scroll + path1.mWidth*obs_water, SCREEN_HEIGHT - 150, water2.mWidth - pJump[i].mWidth, water2.mHeight};
						SDL_Rect c = {obsx, obsy, obs[obstacle].mWidth, obs[obstacle].mHeight};
						if(checkCollision(a, b)){
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
						SDL_RenderPresent(gRenderer);
						SDL_Delay(200);
						//printf("%d\n", y[i]);

						x += 60 - (i >= 7)*60;
					}
					pinkmanx = x;
					jump++;
				}
				else
				{
					if(pinkmanx >= scroll + path1.mWidth*obs_water && pinkmanx <= scroll + path1.mWidth*obs_water + water2.mWidth - pRun[state].mWidth){
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
					SDL_Rect b = {scroll + path1.mWidth*obs_water, SCREEN_HEIGHT - 150 + 50, water2.mWidth, water2.mHeight};
					SDL_Rect c = {obsx, obsy, obs[obstacle].mWidth, obs[obstacle].mHeight};
					if(checkCollision(a, b)){
						for(int i = 0; i < 6; i++){
							SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
							SDL_RenderClear(gRenderer);
							background();
							if(i%2 == 0)broken_heart.render(SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT/2 - 100);
							SDL_RenderPresent(gRenderer);
							SDL_Delay(300);
						}
						--live;
						pinkmanx = scroll + path1.mWidth*obs_water + water2.mWidth;
						if(live == 0)
						{
							on_gameover = 1;
							on_play = 0;
							continue;
						}
					}				
				}
				if(4*pinkmanx >= 3*SCREEN_WIDTH) {
					scroll -= 600*p;
					pinkmanx -= 600*p;
					SDL_Delay(200);
					//p++;
				}
				else p = 1;

				screen++;
				if(screen > 71) screen = 0;
			}

			SDL_RenderPresent(gRenderer);
		}

		//printf("%d %d\n", pbravoos, pwestors);

	}

	Mix_PlayChannel(-1, gClick, 0);
	SDL_Delay(50);
	close();
}