#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/Color.h"
#include "cinder/gl/gl.h"
#include "Resources.h"
#include "cinder/gl/TextureFont.h"
#include "cinder/gl/Texture.h"
#include "cinder/Text.h"
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
  private:
	  Font master_font_;
	  gl::TextureFontRef master_texture_font_;
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

/**
 *
 * Enthusiasts will note the keybindings are pulled from Vim
 * http://en.wikipedia.org/wiki/Editor_war
*/
void TheRoyalSocietyApp::displayHelp(){
	master_font_ = Font("Helvetica", 24);
	Color8u text_color = Color8u(Rand::randFloat(), 0.5f,0.9f);
	std::string str("Welcome to the window manager!\n Keybindings: \n j      Moves shapes down \n k      Moves shapes up \n ~     Reverses shape order \n y     Selects foremost shape--can be used on multiple shapes \n p     Pastes shapes(s)");
	Rectf boundsRect = Rectf(200,200,500,500);
	master_texture_font_->drawStringWrapped( str, boundsRect );
	//myTexture = gl::Texture(layout.render(true));
}

void TheRoyalSocietyApp::setup(){
	displayHelp();
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
}

CINDER_APP_BASIC( TheRoyalSocietyApp, RendererGl )
