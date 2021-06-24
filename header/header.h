#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL_mixer.h>
#include<bits/stdc++.h>
#include<string>
#include<sstream>
using namespace std;


#define keypressed e.key.keysym.sym
#define ll long long
#define ff first
#define ss second
#define PLLS pair<ll, string>


//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int g = 1; // gravity
int ground = 570;
int current_w_obstacle = 1;
int reel = 0;
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
int wspeed = 5;
int fobsx, fobsy, fobs_show = 1;
int x, y;
double rotate_angle = 0.00;

int sound = 1;
int music = 1;
int pause = 0;
int pinkmanx = 0;
int pinkmany = 0;
int vel = 10;
int mVelX= 0;
int mVelY = 0;
int state = 0;

double width_ratio, heigt_ratio;

int scrollingOffset = 0;

int live;
int score;
int scroll = 0;

//bravoos map variable
int bscreen = 0;
ll btotal_dist = 0;
ll bCurrentScore = 0;
ll pScore[5];
ll bscore = 0;
int bspeed = 4;
int fx = 200, fy = 360;
int bstate = 0;
int bscroll = 0;
int blove_show = 0;
int bcoin_show = 0;
int bdiamond_show = 0;
int blovex, blovey, bloved;
int bcoinx, bcoiny, bcoined;
int bdiamondx, bdiamondy, bdiamonded;
int bcoinscroll = 0, bdiamondscroll = 0, blovescroll = 0;
int bcoin_score = 0, bdiamond_score = 0;
int blive;
int id[7], ry[7], rx[7];
bool bz = 0;
int bzscroll = 0;
int st = 0;
int chainx[5], chainy[5];
int ryr[7];
int screen_speed = bspeed;
int second = 0;
int chainscroll = 0;
int middle1x = 300, middle1y = 300, middle_state = 0;
int middle2x = 600, middle2y = 300;

ll wCurrentScore = 0;
ll wScore[5];
vector<PLLS> wName, pName;
string inputtext = "";

//Some colors to render text
SDL_Color textColor1 = {153, 255, 255, 0xFF};
SDL_Color textColor2 = {244, 244, 244, 0xFF};
SDL_Color textColor3 = {255, 0, 255, 0xFF};
SDL_Color textColor4 = {47, 136, 255, 0xFF};


//A class to render an object
class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile( std::string path );
		
		//Creates image from font string
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor );

		//Deallocates texture
		void free();

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );
		
		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

		//Gets image dimensions
		int getWidth();
		int getHeight();

		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;
};

//Starts up SDL and creates window
bool init();
//Loads media
bool loadMedia();
//Frees media and shuts down SDL
void close();
//chek collision between two rectangle
bool checkCollision( SDL_Rect a, SDL_Rect b );

void reset();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Sounds file variables
Mix_Music *gHelp = NULL;
Mix_Chunk *gClick = NULL;
Mix_Chunk *gCoin = NULL;
Mix_Chunk *gDiamond = NULL;
Mix_Chunk *gLove = NULL;
Mix_Chunk *gGameOver = NULL;
Mix_Chunk *gWater = NULL;
Mix_Chunk *gObs = NULL;
Mix_Chunk *gSpike = NULL;
Mix_Chunk *gWall = NULL;
Mix_Chunk *gCollchain = NULL;
Mix_Chunk *gJump = NULL;
Mix_Chunk *gStone = NULL;
Mix_Chunk *gLive = NULL;
Mix_Music *gMenu = NULL;
Mix_Music *gPlayw = NULL;
Mix_Music *gPlayb = NULL;

//Scene textures
LTexture gDotTexture;
LTexture gBGTexture;
LTexture gOverTexture;
LTexture gScoreTexture;
LTexture gPointTexture;
LTexture gFirstScreenTexture;
LTexture gPuasedTexture;
LTexture gPinkManTexture;
LTexture pFly[10];
LTexture pRun[10];
LTexture pJump[10];
//background texture
LTexture forest, road, tree1, tree2, mashroom, bush1, bush2, bush3, water1, water2, path1, path2, path3, path4, path5;
LTexture bg2;

//menu and button variable
LTexture play_button, play_button_sh, setting_button, setting_button_sh, score_button, score_button_sh, help_button, help_button_sh, quit_button, quit_button_sh;
LTexture pause_button, pause_button_sh, resume_button, resume_button_sh;
LTexture sound_button, on_button, on_button_sh, on_button_on, off_button, off_button_sh, off_button_on, back_button, back_button_sh;
LTexture life, broken_heart, bravoos_button, bravoos_button_sh, westors_button, westors_button_sh;
LTexture try_button, try_button_sh, mainmenu_button, mainmenu_button_sh, gameover, input_name0, input_name, reset_button, reset_button_sh, music_button, music_button_sh;
LTexture logo, logo_char;
LTexture pScoreCard, wScoreCard;
LTexture wHelp, bHelp;

//bonus texture variables
LTexture coin, diamond, love, coin1, diamond1, love1;
LTexture coinscoretexture1, diamondscoretexture1;
LTexture coinscoretexture, diamondscoretexture;
//obstacles
LTexture fobs;
LTexture obs[10];
LTexture stone[5];
LTexture wood1, wood2, wood3;

//spikes
LTexture rotating[5];
LTexture upper[7];
LTexture lower[7];
LTexture middle[7];


TTF_Font *gFont = NULL;
LTexture inputtexttexture, nametexture, scoretexture;



//bravoos textur
SDL_Color textColor = {0, 0, 0, 0};


//Ltexture function starts
LTexture::LTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	//Deallocate
	free();
}

bool LTexture::loadFromFile( std::string path )
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

bool LTexture::loadFromRenderedText( std::string textureText, SDL_Color textColor )
{
	//Get rid of preexisting texture
	free();

	//Render text surface
	if(textureText.length() == 0){
		textureText = " ";
	}
	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
	if( textSurface != NULL )
	{
		//Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
		if( mTexture == NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface( textSurface );
	}
	else
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}

	
	//Return success
	return mTexture != NULL;
}

void LTexture::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	//Modulate texture rgb
	SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void LTexture::setBlendMode( SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode( mTexture, blending );
}
		
void LTexture::setAlpha( Uint8 alpha )
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod( mTexture, alpha );
}

void LTexture::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight};

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}

//Ltexture function ended

bool init()
{
	//Initialization flag
	bool success = true;

	srand(time(NULL));

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Goopy PinkMan: On The Run", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

				if(TTF_Init() == -1)
				{
					printf("SDL_TTF could not initialize.\n");
					printf("SDL_TTF Error: %s\n", TTF_GetError());
				}
				if(Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 < 0)
				{
					printf("SDL_Mixer Could not initialize!\n");
					printf("SDL_mixer Error: %s\n", Mix_GetError());
				}

			}
		}
	}

	return success;
}

//a function to check collision between to rectangle
bool checkCollision( SDL_Rect a, SDL_Rect b )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside Bclear
    return true;
}

//keyboard event for character moving
void pinkman_handleEvent( SDL_Event& e )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY -= vel; break;
            case SDLK_DOWN: mVelY += vel; break;
            case SDLK_LEFT: mVelX -= vel; break;
            case SDLK_RIGHT: mVelX += vel; break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY += vel; break;
            case SDLK_DOWN: mVelY -= vel; break;
            case SDLK_LEFT: mVelX += vel; break;
            case SDLK_RIGHT: mVelX -= vel; break;
        }
    }
}

//moving function
void pinkman_move(int &x, int &y)
{
    //Move the dot left or right
    x += mVelX;

    //if(x < 0) x = 0;

    //Move the dot up or down
    y += mVelY;

    //If the dot collided or went too far up or down
    if( ( y < 0 ) || ( y + pFly[state].getHeight() > SCREEN_HEIGHT) )
    {
        //Move back
        y -= mVelY;
    }
}

void close()
{
	//Free loaded images
	
	ofstream f1;
	f1.open("score_board1.txt");
	ofstream f2;
	f2.open("score_board2.txt");
	for(int i = 0; i < wName.size(); i++){
		f1<<wName[i].ss<<" "<<wName[i].ff<<endl;
		//cout<<wName[i].ss<<" "<<wName[i].ff<<endl;
		f1.flush();
	}
	for(int i = 0; i < pName.size(); i++){
		f2<<pName[i].ss<<" "<<pName[i].ff<<endl;
		f2.flush();
	}
	gBGTexture.free();
	gFirstScreenTexture.free();
	gScoreTexture.free();
	gPuasedTexture.free();


	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
	TTF_Quit();

}

bool fsort(PLLS a, PLLS b)
{
	return a.ff > b.ff;
}

void reset()
{
	ground = 570;
	current_w_obstacle = 1;
	reel = 0;
	obsx = 1800;
	obsy;
	stonex = 200;
	stones = 1;
	ll wtotal_dist = 0;
	love_show = 0;
	diamond_show = 0;
	coin_show = 0;
	coinscroll = 0, diamondscroll = 0, lovescroll = 0, fobsscroll = 0;
	coin_score = 0, diamond_score = 0;
	wspeed = 4;
	fobs_show = 1;
	rotate_angle = 0.00;

	pause = 0;
	pinkmanx = 0;
	pinkmany = 0;
	state = 0;

	live = 3;
	score = 0;
	scroll = 0;

	//bravoos map variable
	bscreen = 0;
	btotal_dist = 0;
	bCurrentScore = 0;
	bspeed = 4;
	fx = 200, fy = 360;
	bstate = 0;
	bscroll = 0;
	blove_show = 0;
	bcoin_show = 0;
	bdiamond_show = 0;
	bdiamonded = 0;
	bcoinscroll = 0, bdiamondscroll = 0, blovescroll = 0;
	bcoin_score = 0, bdiamond_score = 0;
	blive = 3;
	bz = 0;
	bzscroll = 0;
	st = 0;
	screen_speed = bspeed;
	second = 0;
	chainscroll = 0;
	middle1x = 300, middle1y = 300, middle_state = 0;
	middle2x = 600, middle2y = 300;

}