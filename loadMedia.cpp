bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load dot texture

	//success = success &	gFont = TTF_OpenFont("assets/fonts.ttf", 30);

	//map
	success = success & westors_button.loadFromFile("assets/westors.png");
	success = success & westors_button_sh.loadFromFile("assets/westors1.png");
	success = success & bravoos_button.loadFromFile("assets/bravoos.png");
	success = success & bravoos_button_sh.loadFromFile("assets/bravoos1.png");
	//menu meadia loading
	success = success & play_button.loadFromFile("assets/button_play.png");
	success = success & play_button_sh.loadFromFile("assets/button_play(2).png");
	success = success & setting_button.loadFromFile("assets/button_settings.png");
	success = success & setting_button_sh.loadFromFile("assets/button_settings(2).png");
	success = success &	help_button.loadFromFile("assets/button_help.png");
	success = success &	help_button_sh.loadFromFile("assets/button_help(2).png");
	success = success &	score_button.loadFromFile("assets/button_score.png");
	success = success &	score_button_sh.loadFromFile("assets/button_score(2).png");
	success = success &	quit_button.loadFromFile("assets/button_quit.png");
	success = success & quit_button_sh.loadFromFile("assets/button_quit(2).png");
	success = success & sound_button.loadFromFile("assets/button_sound.png");
	success = success & on_button.loadFromFile("assets/button_on.png");
	success = success & on_button_sh.loadFromFile("assets/button_on(2).png");
	success = success & on_button_on.loadFromFile("assets/button_on(3).png");
	success = success & off_button.loadFromFile("assets/button_off.png");
	success = success & off_button_sh.loadFromFile("assets/button_off(2).png");
	success = success & off_button_on.loadFromFile("assets/button_off(3).png");
	success = success & back_button.loadFromFile("assets/button_back.png");
	success = success & back_button_sh.loadFromFile("assets/button_back(1).png");
	success = success & pause_button.loadFromFile("assets/button_pause.png");
	success = success & pause_button_sh.loadFromFile("assets/button_pause(1).png");
	success = success & resume_button.loadFromFile("assets/button_resume.png");
	success = success & resume_button_sh.loadFromFile("assets/button_resume(1).png");

	//music
	
	success = success & ((gHelp = Mix_LoadMUS("assets/help.mp3")) != NULL);
	success = success & ((gClick = Mix_LoadWAV("assets/click.wav")) != NULL);


	//character
	//fly
	success = success & pFly[0].loadFromFile("assets/fly1.png");
	success = success & pFly[1].loadFromFile("assets/fly2.png");
	success = success & pFly[2].loadFromFile("assets/fly3.png");
	success = success & pFly[3].loadFromFile("assets/fly4.png");


	//run
	success = success & pRun[0].loadFromFile("assets/run/1.png");
	success = success & pRun[1].loadFromFile("assets/run/2.png");
	success = success & pRun[2].loadFromFile("assets/run/3.png");
	success = success & pRun[3].loadFromFile("assets/run/4.png");
	success = success & pRun[4].loadFromFile("assets/run/5.png");
	success = success & pRun[5].loadFromFile("assets/run/6.png");
	success = success & pRun[6].loadFromFile("assets/run/7.png");
	success = success & pRun[7].loadFromFile("assets/run/8.png");
	success = success & pRun[8].loadFromFile("assets/run/9.png");

	//jump

	success = success & pJump[0].loadFromFile("assets/jump/1.png");
	success = success & pJump[1].loadFromFile("assets/jump/2.png");
	success = success & pJump[2].loadFromFile("assets/jump/3.png");
	success = success & pJump[3].loadFromFile("assets/jump/4.png");
	success = success & pJump[4].loadFromFile("assets/jump/5.png");
	success = success & pJump[5].loadFromFile("assets/jump/6.png");
	success = success & pJump[6].loadFromFile("assets/jump/7.png");
	success = success & pJump[7].loadFromFile("assets/jump/8.png");
	success = success & pJump[8].loadFromFile("assets/jump/9.png");

	//backgrond
	success = success & forest.loadFromFile("assets/bg/bg1.png");
	success = success & tree1.loadFromFile("assets/bg/tree1.png");
	success = success & tree2.loadFromFile("assets/bg/tree2.png");
	success = success & mashroom.loadFromFile("assets/bg/mashroom.png");
	success = success & bush1.loadFromFile("assets/bg/bush1.png");
	//bush1.mHeight = 80;
	success = success & bush2.loadFromFile("assets/bg/bush2.png");
	bush2.mHeight = 80;
	success = success & bush3.loadFromFile("assets/bg/bush3.png");
	//bush3.mHeight = 80;
	success = success & water1.loadFromFile("assets/bg/water1.png");
	water1.mWidth = SCREEN_WIDTH;
	success = success & water2.loadFromFile("assets/bg/water2.png");
	water2.mWidth = 250;
	success = success & path1.loadFromFile("assets/bg/path1.png");
	path1.mWidth = SCREEN_WIDTH;


	//life
	success = success & life.loadFromFile("assets/life.png");
	success = success & broken_heart.loadFromFile("assets/broken_heart.png");
	life.mWidth = 20;
	life.mHeight = 20;
	broken_heart.mWidth = 200;
	broken_heart.mHeight = 200;


	success = success & try_button.loadFromFile("assets/button_try.png");
	success = success & try_button_sh.loadFromFile("assets/button_try(1).png");
	success = success & mainmenu_button.loadFromFile("assets/button_mainmenu.png");
	success = success &	mainmenu_button_sh.loadFromFile("assets/button_mainmenu(1).png");
	success = success & gameover.loadFromFile("assets/gameover.png");
	gameover.mWidth = 300;
	gameover.mHeight = 250;


	//obstacle
	success = success & obs[1].loadFromFile("assets/obs/obs1.png");
	success = success & obs[2].loadFromFile("assets/obs/obs2.png");
	success = success & obs[3].loadFromFile("assets/obs/obs3.png");

	//Scaling
	for(int state = 0; state < 9; state++) {
		pRun[state].mHeight *= 2.5;
		pRun[state].mWidth += 30;
	}
	for(int state = 0; state < 4; state++) {
		pFly[state].mHeight *= 2.5;
		pFly[state].mWidth += 30;
	}
	for(int state = 0; state < 9; state++) {
		pJump[state].mHeight *= 2.5;
		pJump[state].mWidth += 30;
	}


	return success;
}
