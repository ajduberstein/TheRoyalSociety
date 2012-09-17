#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/Color.h"
#include "cinder/gl/gl.h"
#include "Resources.h"
#include "cinder/gl/Texture.h"
#include "cinder/Text.h"
#include "cinder/Surface.h"
#include "cinder/Cinder.h"
#include "cinder/Font.h"
#include "cinder/ImageIo.h"

//#include "TheRoyalSocietyApp.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class TheRoyalSocietyApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	void displayHelp();
	void prepareSettings(Settings *settings);
	void keyDown(KeyEvent event);
	void render();
  private:
	 Font master_font_;
	 gl::Texture master_texture_font_;
	 bool display_help;
	 Vec2f master_size;
	  //LinkedList shapes_;
};

void TheRoyalSocietyApp::prepareSettings(Settings *settings){
	settings->setWindowSize(800, 600);
	settings->setFrameRate(60.0f);
	settings->setResizable(false);
	settings->setFullScreen(false);
}

//TODO implement;
void TheRoyalSocietyApp::keyDown( KeyEvent event ) {
    if( event.getChar() == 'j' ){
    } 
	else if (event.getChar() == '?'){
		display_help = !(display_help);
	}
	else if( event.getChar() == 'k' ){
    }
	else if( event.getChar() == '~' ){
    }
	else if( event.getChar() == '?' ){
    }
	else if( event.getChar() == 'y' ){
    }
	else if( event.getChar() == 'p' ){
    }
	else{
	}
}

void TheRoyalSocietyApp::setup(){
		master_font_ = Font("Helvetica",32);
		master_size = Vec2f( 100, 100 );
		render();
		display_help = true;
}

void TheRoyalSocietyApp::render()
{
	string txt = "Welcome to the window manager!\n Keybindings: \n j      Moves shapes down \n k      Moves shapes up \n ~     Reverses shape order \n y     Selects foremost shape \n p     Pastes shapes(s)";
	TextBox tbox = TextBox().alignment( TextBox::CENTER ).font(master_font_).size( Vec2i( 512, 511) ).text( txt );
	tbox.setColor( Color( 1.0f, 0.65f, 0.35f ) );
	tbox.setBackgroundColor( ColorA( 0.5, 0, 0, 1 ) );
	Vec2i sz = tbox.measure();
	console() << "Height: " << sz.y << endl;
	master_texture_font_ = gl::Texture( tbox.render() );
}

void TheRoyalSocietyApp::mouseDown( MouseEvent event )
{
}

void TheRoyalSocietyApp::update()
{

}


void TheRoyalSocietyApp::draw()
{
	// clears out the window with black
	gl::clear( Color( 0, 0, 0 ) );
	gl::color(Color8u(0,255,0));
	gl::drawSolidCircle(Vec2f(65.0f,65.0f),50.0f,5);
	gl::color(Color8u(240,255,0));
	gl::drawSolidCircle(Vec2f(55.0f,55.0f),50.0f,5);
	gl::color(Color8u(255,255,0));
	gl::drawSolidCircle(Vec2f(255.0f,255.0f),50.0f,4);
	if (master_texture_font_ && display_help)
		gl::draw(master_texture_font_);
}

CINDER_APP_BASIC( TheRoyalSocietyApp, RendererGl )
