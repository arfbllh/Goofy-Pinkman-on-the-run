//#include "header.h"

bool on_menu = 1;
bool on_play = 0;
bool on_setting = 0;
bool on_help = 0;
bool on_score = 0;
bool on_quit = 0;
bool on_select_map = 0;
bool on_gameover = 0;

int button_animation = 7;
int button_interval = 70;
int button_width = 323;
int button_height = 80;
int buttonx = 478;
int play_buttony = 370;
int buttony = 300;
int setting_buttony = play_buttony + button_interval;
int score_buttony = play_buttony + button_interval*2;
int help_buttony = play_buttony + button_interval*3;
int quit_buttony = play_buttony + button_interval*4;
int pause_buttony = play_buttony - button_interval;

int play_shadow = 0;
int setting_shadow = 0;
int help_shadow = 0;
int score_shadow = 0;
int quit_shadow = 0;
int on_shadow = 0;
int on_on = 1;
int off_shodow = 0;
int off_on = 1;
int back_shadow = 0;
int bravoos_shadow = 0;
int west_shadow = 0;
int try_shadow = 0;
int mainmenu_shadow = 0;
int reset_shadow = 0;
int music_shadow = 1;

bool is_menu_medialoaded = 0;

bool pbravoos = 0;
bool pwestors = 0;
bool pause_shadow = 0;
bool start = 0;
int menu_music = 1;
int gameover_music = 1;
int off_shodow1 = 1;
int on_shadow1 = 0;
int off_on1 = 0;
int on_on1 = 1;

bool over_button(int mouse_x,int mouse_y, int button_x, int button_y, int button_width, int button_height)
{
	if(mouse_x >= button_x && mouse_y >= button_y && mouse_x <= button_x + button_width && mouse_y <= button_y + button_height) return 1;
	return 0;
}


void show_menu_otherscreen(SDL_Event e)
{
	int x, y;
	if(music && menu_music) Mix_PlayMusic(gMenu, -1);
	menu_music = 0;
	if(on_menu)
	{
		if(pause && !pause_shadow) resume_button.render(buttonx, play_buttony);
		else if(pause) resume_button_sh.render(buttonx, play_buttony);

		if(!play_shadow) play_button.render(buttonx, play_buttony);
		else play_button_sh.render(buttonx, play_buttony);

		if(!setting_shadow) setting_button.render(buttonx, setting_buttony);
		else setting_button_sh.render(buttonx, setting_buttony);

		if(!help_shadow) help_button.render(buttonx, help_buttony);
		else help_button_sh.render(buttonx, help_buttony);

		if(!score_shadow) score_button.render(buttonx, score_buttony);
		else score_button_sh.render(buttonx, score_buttony);

		if(!quit_shadow) quit_button.render(buttonx, quit_buttony);
		else quit_button_sh.render(buttonx, quit_buttony);

		SDL_GetMouseState(&x, &y);
		if(pause && over_button(x, y, buttonx, pause_buttony, button_width, button_height)){
			SDL_Delay(25);
			pause_shadow = 1;
			play_shadow = 0;
			setting_shadow = 0;
			help_shadow = 0;
			score_shadow = 0;
			quit_shadow = 0;
			if(e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP){
				pause = 0;
				on_setting = 0;
				on_help = 0;
				on_score = 0;
				on_quit = 0;
				on_menu = 0;
				on_play = 1;
				e.type = SDL_MOUSEBUTTONUP;
				if(sound) Mix_PlayChannel(-1, gClick, 0);
			}
		}
		else if(over_button(x, y, buttonx, play_buttony, button_width, button_height))
		{
			SDL_Delay(25);
			play_shadow = 1;
			setting_shadow = 0;
			help_shadow = 0;
			score_shadow = 0;
			quit_shadow = 0;
			pause_shadow = 0;
			if(e.type == SDL_MOUSEBUTTONDOWN){
				on_select_map = 1;
				pause = 0;
				on_setting = 0;
				on_help = 0;
				on_score = 0;
				on_quit = 0;
				on_menu = 0;
				pause = 0;
				pbravoos = 0;
				pwestors = 0;
				e.type = SDL_MULTIGESTURE;
				e.key.repeat = 0;
				if(sound) Mix_PlayChannel(-1, gClick, 0);

			}

		}
		else if(over_button(x, y, buttonx, setting_buttony, button_width, button_height)){
			SDL_Delay(25);
			play_shadow = 0;
			setting_shadow = 1;
			help_shadow = 0;
			score_shadow = 0;
			quit_shadow = 0;
			pause_shadow = 0;

			if(e.type == SDL_MOUSEBUTTONDOWN){
				SDL_Delay(50);
				on_select_map = 0;
				on_setting = 1;
				on_help = 0;
				on_score = 0;
				on_quit = 0;
				on_menu = 0;
				if(sound) Mix_PlayChannel(-1, gClick, 0);
			}
		}
		else if(over_button(x, y, buttonx, help_buttony, button_width, button_height)){
			SDL_Delay(25);
			play_shadow = 0;
			setting_shadow = 0;
			help_shadow = 1;
			score_shadow = 0;
			quit_shadow = 0;
			pause_shadow = 0;
			if(e.type == SDL_MOUSEBUTTONDOWN){
				on_select_map = 0;
				on_setting = 0;
				on_help = 1;
				on_score = 0;
				on_quit = 0;
				on_menu = 0;
				if(sound) Mix_PlayChannel(-1, gClick, 0);
			}
		}
		else if(over_button(x, y, buttonx, score_buttony, button_width, button_height)){
			SDL_Delay(25);
			play_shadow = 0;
			setting_shadow = 0;
			help_shadow = 0;
			score_shadow = 1;
			quit_shadow = 0;
			pause_shadow = 0;

			if(e.type == SDL_MOUSEBUTTONDOWN){
				on_select_map = 0;
				on_setting = 0;
				on_help = 0;
				on_score = 1;
				on_quit = 0;
				on_menu = 0;
				pause_shadow = 0;
				if(sound) Mix_PlayChannel(-1, gClick, 0);
			}	
		}
		else if(over_button(x, y, buttonx, quit_buttony, button_width, button_height)){
			SDL_Delay(25);
			play_shadow = 0;
			setting_shadow = 0;
			help_shadow = 0;
			score_shadow = 0;
			quit_shadow = 1;
			pause_shadow = 0;

			if(e.type == SDL_MOUSEBUTTONDOWN){

				on_select_map = 0;
				on_setting = 0;
				on_help = 0;
				on_score = 0;
				on_menu = 0;
				on_quit = 1;
				if(sound) Mix_PlayChannel(-1, gClick, 0);
				SDL_Delay(50);
			}
		}
		else
		{
			pause_shadow = 0;
			play_shadow = 0;
			setting_shadow = 0;
			help_shadow = 0;
			score_shadow = 0;
			quit_shadow = 0;

		}

		SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderClear(gRenderer);

		if(pause && !pause_shadow) resume_button.render(buttonx, pause_buttony);
		else if(pause) resume_button_sh.render(buttonx, pause_buttony);

		if(!play_shadow) play_button.render(buttonx, play_buttony);
		else play_button_sh.render(buttonx, play_buttony);

		if(!setting_shadow) setting_button.render(buttonx, setting_buttony);
		else setting_button_sh.render(buttonx, setting_buttony);

		if(!help_shadow) help_button.render(buttonx, help_buttony);
		else help_button_sh.render(buttonx, help_buttony);

		if(!score_shadow) score_button.render(buttonx, score_buttony);
		else score_button_sh.render(buttonx, score_buttony);

		if(!quit_shadow) quit_button.render(buttonx, quit_buttony);
		else quit_button_sh.render(buttonx, quit_buttony);
		//printf("%d %d\n", x, y);


		SDL_RenderPresent(gRenderer);

	}
	else if(on_setting)
	{
		SDL_GetMouseState(&x, &y);
		SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderClear(gRenderer);

		sound_button.render(buttonx - 180, play_buttony - 100);
		music_button.render(buttonx + 18, play_buttony - 100);

		if(over_button(x, y, buttonx - 180, play_buttony, button_width, button_height)){
			SDL_Delay(25);
			on_shadow = 1;
			off_shodow = 0;
			back_shadow = 0;
			off_shodow1 = 0;
			on_shadow1 = 0;
			if(e.type == SDL_MOUSEBUTTONDOWN){

				if(sound) Mix_PlayChannel(-1, gClick, 0);
				sound = 1;
				on_on = 1;
				SDL_Delay(50);
			}
		}
		else if(over_button(x, y, buttonx - 180, play_buttony + 100, button_width, button_height)){
			SDL_Delay(25);
			on_shadow = 0;
			off_shodow = 1;
			back_shadow = 0;
			off_shodow1 = 0;
			on_shadow1 = 0;

			if(e.type == SDL_MOUSEBUTTONDOWN ){

				if(sound) Mix_PlayChannel(-1, gClick, 0);
				sound = 0;
				off_on = 1;
				SDL_Delay(50);
			}
		}
		else if(over_button(x, y, buttonx - 180, play_buttony + 250, button_width, button_height)){
			SDL_Delay(25);
			on_shadow = 0;
			off_shodow = 0;
			back_shadow = 1;
			off_shodow1 = 0;
			on_shadow1 = 0;

			if(e.type == SDL_MOUSEBUTTONDOWN){

				if(sound) Mix_PlayChannel(-1, gClick, 0);
				on_setting = 0;
				on_menu = 1;
				SDL_Delay(100);
			}
		}
		else if(over_button(x, y, buttonx + 180, play_buttony, button_width, button_height)){
			SDL_Delay(25);
			on_shadow = 0;
			off_shodow = 0;
			back_shadow = 0;
			off_shodow1 = 0;
			on_shadow1 = 1;

			if(e.type == SDL_MOUSEBUTTONDOWN){

				if(sound) Mix_PlayChannel(-1, gClick, 0);
				menu_music = 1;
				music = 1;
				on_on1 = 1;
				SDL_Delay(50);
			}
		}
		else if(over_button(x, y, buttonx + 180, play_buttony + 100, button_width, button_height)){
			SDL_Delay(25);
			on_shadow = 0;
			off_shodow = 0;
			back_shadow = 0;
			off_shodow1 = 1;
			on_shadow1 = 0;

			if(e.type == SDL_MOUSEBUTTONDOWN ){

				if(sound) Mix_PlayChannel(-1, gClick, 0);
				music = 0;
				off_on1 = 1;
				Mix_HaltMusic();
				SDL_Delay(50);
			}
		}
		else{
			on_shadow = 0;
			off_shodow = 0;
			back_shadow = 0;
			on_shadow1 = 0;
			off_shodow1 = 0;

		}

		//if(on_shadow) on_button_sh.render(buttonx, play_buttony + 100);
		 if(sound) on_button_on.render(buttonx - 180, play_buttony);
		else on_button.render(buttonx - 180, play_buttony);

		//if(off_shodow) off_button_sh.render(buttonx, play_buttony + 200);
		 if(sound) off_button.render(buttonx - 180, play_buttony + 100);
		else off_button_on.render(buttonx - 180, play_buttony + 100);

		//if(on_shadow) on_button_sh.render(buttonx, play_buttony + 100);
		 if(music) on_button_on.render(buttonx + 180, play_buttony);
		else on_button.render(buttonx + 180, play_buttony);

		//if(off_shodow) off_button_sh.render(buttonx, play_buttony + 200);
		 if(music) off_button.render(buttonx + 180, play_buttony + 100);
		else off_button_on.render(buttonx + 180, play_buttony + 100);

		if(!back_shadow) back_button.render(buttonx, play_buttony + 250);
		else  back_button_sh.render(buttonx, play_buttony + 250);
		SDL_RenderPresent(gRenderer);
	}
	else if(on_help)
	{
		SDL_GetMouseState(&x, &y);
		SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderClear(gRenderer);


		if(Mix_PlayingMusic() == 0) Mix_PlayMusic(gHelp, -1);

		if(over_button(x, y, buttonx, play_buttony + 350, button_width, button_height)){
			SDL_Delay(25);
			back_shadow = 1;
			if(e.type == SDL_MOUSEBUTTONDOWN)
			{
				on_help = 0;
				on_menu = 1;
				SDL_Delay(50);
				back_shadow = 0;
				if(sound) Mix_PlayChannel(-1, gClick, 0);
			}
		}
		else back_shadow = 0;

		if(!back_shadow) back_button.render(buttonx, play_buttony + 350);
		else back_button_sh.render(buttonx, play_buttony + 350);

		SDL_RenderPresent(gRenderer);

	}
	else if(on_select_map){
		SDL_GetMouseState(&x, &y);
		SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderClear(gRenderer);

		// if(!west_shadow) westors_button.render(buttonx, buttony);
		// else westors_button_sh.render(buttonx, buttony);

		// if(!bravoos_shadow) bravoos_button.render(buttonx, buttony + button_interval);
		// else bravoos_button_sh.render(buttonx, buttony + button_interval);

		// if(!back_shadow) back_button.render(buttonx, buttony + button_interval*2);
		// else back_button_sh.render(buttonx, buttony + button_interval*2);

		//SDL_RenderPresent(gRenderer);

		if(over_button(x, y, buttonx, buttony, button_width, button_height))
		{
			SDL_Delay(25);
			west_shadow = 1;
			bravoos_shadow = 0;
			back_shadow = 0;
			if(e.type == SDL_MOUSEBUTTONDOWN){
				if(sound)  Mix_HaltMusic();
				if(music) Mix_PlayMusic(gPlayw, -1);
				pwestors = 1;
				pause = 0;
				on_setting = 0;
				on_help = 0;
				on_score = 0;
				on_quit = 0;
				on_menu = 0;
				on_select_map = 0;
				on_play = 1;
				live = 3;
				wCurrentScore = 0;
				bCurrentScore = 0;
				coin_score = 0;
				diamond_score = 0;
				if(sound) Mix_PlayChannel(-1, gClick, 0);
			}

		}
		else if(over_button(x, y, buttonx, buttony + button_interval, button_width, button_height)){
			SDL_Delay(25);
			west_shadow = 0;
			bravoos_shadow = 1;
			back_shadow = 0;

			if(e.type == SDL_MOUSEBUTTONDOWN){
				if(sound)  Mix_HaltMusic();
				pwestors = 0;
				pbravoos = 1;
				pause = 0;
				on_setting = 0;
				on_help = 0;
				on_score = 0;
				on_quit = 0;
				on_menu = 0;
				on_select_map = 0;
				blive = 3;
				on_play = 1;
				wCurrentScore = 0;
				bCurrentScore = 0;
				coin_score = 0;
				diamond_score = 0;

				if(sound) Mix_PlayChannel(-1, gClick, 0);
			}
		}
		else if(over_button(x, y, buttonx, buttony + button_interval*2, button_width, button_height)){
			SDL_Delay(25);
			west_shadow = 0;
			bravoos_shadow = 0;
			back_shadow = 1;

			if(e.type == SDL_MOUSEBUTTONDOWN){
				pwestors = 0;
				pbravoos = 0;
				pause = 0;
				on_setting = 0;
				on_help = 0;
				on_score = 0;
				on_quit = 0;
				on_menu = 1;
				on_select_map = 0;
				if(sound) Mix_PlayChannel(-1, gClick, 0);
			}
		}
		else{
			west_shadow = 0;
			bravoos_shadow = 0;
			back_shadow = 0;
		}

		if(!west_shadow) westors_button.render(buttonx, buttony);
		else westors_button_sh.render(buttonx, buttony);

		if(!bravoos_shadow) bravoos_button.render(buttonx, buttony + button_interval);
		else bravoos_button_sh.render(buttonx, buttony + button_interval);

		if(!back_shadow) back_button.render(buttonx, buttony + button_interval*2);
		else back_button_sh.render(buttonx, buttony + button_interval*2);

		SDL_RenderPresent(gRenderer);
	}
	else if(on_gameover){
		SDL_GetMouseState(&x, &y);
		if(sound && gameover_music) Mix_PlayChannel(-1, gLive, 0);
		gameover_music = 0;
		SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderClear(gRenderer);

		gameover.render(buttonx, SCREEN_HEIGHT/2 - 300);

		input_name0.render(buttonx - 100, buttony);
		input_name.render(buttonx - 100, buttony + button_interval);

		// if(inputtext.length() == 0){
		//  	inputtext = "Player Name";
		// }

		inputtexttexture.loadFromRenderedText(inputtext.c_str(), textColor);


		if(e.type == SDL_KEYDOWN)
		{
			if(keypressed == SDLK_BACKSPACE && inputtext.length() > 0){
				inputtext.pop_back();
			}

		}
		else if(e.type == SDL_TEXTINPUT)
		{
			if( !( SDL_GetModState() & KMOD_CTRL && ( e.text.text[ 0 ] == 'c' || e.text.text[ 0 ] == 'C' || e.text.text[ 0 ] == 'v' || e.text.text[ 0 ] == 'V' ) ) )
			{
				inputtext += e.text.text;
			}

		}

		if(over_button(x, y, buttonx, buttony + button_interval*2, button_width, button_height))
		{
			SDL_Delay(25);
			try_shadow = 1;
			mainmenu_shadow = 0;
			if(e.type == SDL_MOUSEBUTTONDOWN){
				pause = 0;
				on_play = 1;
				on_gameover = 0;
				gameover_music = 0;
				reset();
				if(pwestors)
				{
					if(wName.size() == 5) wName.pop_back();
					wName.push_back(PLLS(wCurrentScore, inputtext));
					sort(wName.begin(), wName.end(), fsort);
				}
				else if(pbravoos){
					if(pName.size() == 5) pName.pop_back();
					pName.push_back(PLLS(bCurrentScore, inputtext));
					sort(pName.begin(), pName.end(), fsort);
				}
				inputtext.clear();
				if(sound) Mix_PlayChannel(-1, gClick, 0);
			}

		}
		else if(over_button(x, y, buttonx, buttony + button_interval*3, button_width, button_height)){
			SDL_Delay(25);
			try_shadow = 0;
			mainmenu_shadow = 1;

			if(e.type == SDL_MOUSEBUTTONDOWN){
				if(pwestors)
				{
					if(wName.size() == 5) wName.pop_back();
					wName.push_back(PLLS(wCurrentScore, inputtext));
					sort(wName.begin(), wName.end(), fsort);
				}
				else if(pbravoos){
					if(pName.size() == 5) pName.pop_back();
					pName.push_back(PLLS(bCurrentScore, inputtext));
					sort(pName.begin(), pName.end(), fsort);
					
				}
				pwestors = 0;
				pbravoos = 0;
				gameover_music = 0;
				//on_menu = 1;
				on_gameover = 0;
				inputtext.clear();
				reset();
				if(sound) Mix_PlayChannel(-1, gClick, 0);
				on_menu = 1;
			}
		}
		inputtexttexture.render(buttonx - 92, buttony + button_interval + 5);
		if(!try_shadow) try_button.render(buttonx, buttony + button_interval*2);
		else try_button_sh.render(buttonx, buttony + button_interval*2);

		if(!mainmenu_shadow) mainmenu_button.render(buttonx, buttony + button_interval*3);
		else mainmenu_button_sh.render(buttonx, buttony + button_interval*3);
		SDL_RenderPresent(gRenderer);

	}
	else if(on_score)
	{
		SDL_GetMouseState(&x,  &y);
		SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderClear(gRenderer);


		wScoreCard.render(0, 0);
		pScoreCard.render(0, 350);
		int intervel = 45;
		int px = 155, py = 132;
		back_button.mWidth = back_button_sh.mWidth = 200;
		back_button.mHeight = back_button_sh.mHeight = 50;
		reset_button.mWidth = reset_button_sh.mWidth = 200;
		reset_button.mHeight = reset_button_sh.mHeight = 50;
		for(int i = 0; i < wName.size(); i++)
		{
			nametexture.loadFromRenderedText(wName[i].ss.c_str(), textColor);
			string temp = to_string(wName[i].ff);
			scoretexture.loadFromRenderedText(temp.c_str(), textColor);
			nametexture.render(px, py);
			scoretexture.render(950, py);
			py += intervel;
		}
		py = 480;
		for(int i = 0; i < pName.size(); i++)
		{
			nametexture.loadFromRenderedText(pName[i].ss.c_str(), textColor);
			string temp = to_string(pName[i].ff);
			scoretexture.loadFromRenderedText(temp.c_str(), textColor);
			nametexture.render(px, py);
			scoretexture.render(950, py);
			py += intervel;
		}

		if(over_button(x, y, 0, 5, 200, 50)){
			SDL_Delay(25);
			back_shadow = 1;
			reset_shadow = 0;

			if(e.type == SDL_MOUSEBUTTONDOWN){

				on_score = 0;
				on_menu = 1;
				if(sound) Mix_PlayChannel(-1, gClick, 0);
				SDL_Delay(100);
			}
		}
		else if(over_button(x, y, SCREEN_WIDTH - 210, 5, 200, 50)){
			SDL_Delay(25);
			reset_shadow = 1;
			back_shadow = 0;
			if(e.type == SDL_MOUSEBUTTONDOWN){
				wName.clear();
				pName.clear();
			}
		}
		else {
			back_shadow = 0;
			reset_shadow = 0;
		}
		if(!back_shadow) back_button.render(0, 5);
		else back_button_sh.render(0, 5);

		if(!reset_shadow) reset_button.render(SCREEN_WIDTH - 210, 5);
		else reset_button_sh.render(SCREEN_WIDTH -  210, 5);

		//printf("%d %d\n", x, y);
		SDL_RenderPresent(gRenderer);

		back_button.mWidth = back_button_sh.mWidth = button_width;
		back_button.mHeight = back_button_sh.mHeight = button_height;

	}
}
/*

int main()
{
	if(!init()) return 0;
	if(!loadMedia()) return 0;

	SDL_Event e;
	bool quit = false;
	while(!quit)
	{
		while( SDL_PollEvent( &e ) != 0 )
		{
			if( e.type == SDL_QUIT )
			{
				quit = true;
				break;
			}
		}

		if(on_menu) {
				show_menu_otherscreen(e);
				continue;
		}

		SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
		SDL_RenderClear(gRenderer);

		SDL_RenderPresent(gRenderer);

	}
}
*/