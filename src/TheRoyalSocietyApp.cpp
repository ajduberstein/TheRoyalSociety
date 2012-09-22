/*CSE 274 students, I draw a textbox under the render() method.*/
#include "LinkedList.h"
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
#include <vector>
//#include "TheRoyalSocietyApp.h"
#include <math.h>
#define PI 3.14159265

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
	 int color_changer_;
	 gl::Texture master_texture_font_;
	 bool display_help;
	 int param_;
	 LinkedList l;
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
		l.bumpForward();
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
		render();
		display_help = true;
		color_changer_=0;
		param_=0;
		//Fill the list
		l.addNode(1);
		l.addNode(5);
		l.addNode(2);
		l.addNode(4);
		l.addNode(3);
		//Quality assurance--is what we're thinking is in the list actually in the list?
		console() << "LENGTH: " << l.length() << std::endl;
		for (int i = 0; i < l.length(); i++){
			console()<< "AT NODE " << i << " IS " << l.at(i)->data << std::endl;
		}
		console() << "BUMP TEST" << std::endl;
		l.bumpForward();
		for (int i = 0; i < l.length(); i++){
			console()<< "AT NODE " << i << " IS " << l.at(i)->data << std::endl;
		}
}

void TheRoyalSocietyApp::render(){
	string txt = "Welcome to the window manager!\n\n Keybindings: \n j      Moves shapes down \n k      Moves shapes up \n ~     Reverses shape order \n y     Selects foremost shape \n p     Pastes shape(s)";
	TextBox tbox = TextBox().alignment( TextBox::CENTER ).font(master_font_).size( Vec2i( 512, 511) ).text( txt );
	tbox.setColor( Color( 1.0f, 0.65f, 0.35f ) );
	tbox.setBackgroundColor( ColorA( 0.5, 0, 0, 1 ) );
	master_texture_font_ = gl::Texture( tbox.render() );
}

void TheRoyalSocietyApp::mouseDown( MouseEvent event )
{
}

void TheRoyalSocietyApp::update()
{
	param_++;
	color_changer_ = sin(param_*PI/1800)*100;
	if (param_>200)
		param_ = 0;
}

void TheRoyalSocietyApp::draw(){
	// clears out the window with black
	gl::clear( Color( 260, 260, 260 ) );
	int shape_id;
	for (int i = 0; i <= 5; i++){
		shape_id = l.at(i)->data;
		if (shape_id == 1){
			gl::color(Color8u(50,0,0));
			gl::drawSolidCircle(Vec2f(310-color_changer_,310+color_changer_),200,100);
			gl::color(Color8u(410,0,0));
			gl::drawSolidCircle(Vec2f(300-color_changer_,300+color_changer_),200,100);
		}
		else if (shape_id == 2){
			gl::color(Color8u(0,0,50));
			gl::drawSolidCircle(Vec2f(410+color_changer_/2,410),200,10);
			gl::color(Color8u(0,0,410));
			gl::drawSolidCircle(Vec2f(400+color_changer_/2,400),200,10);
		}
		else if (shape_id == 3){
			gl::color(Color8u(0,50,0));
			gl::drawSolidCircle(Vec2f(510,310+color_changer_/5),200/(1+abs(tan((double) param_)),4));
			gl::color(Color8u(0,410,0));
			gl::drawSolidCircle(Vec2f(500,300+color_changer_/5),200/(1+abs(tan((double) param_))),4);
		}
		else if (shape_id == 4){
			gl::color(Color8u(0,100,100));
			gl::drawSolidCircle(Vec2f(310,110),color_changer_*2.5,3);
			gl::color(Color8u(0,300,300));
			gl::drawSolidCircle(Vec2f(300,100),color_changer_*2.6,3*rand()%2);
		}
		else if (shape_id > 4 && shape_id < 10){
			gl::color(Color8u(100+rand()%100,rand()%100,rand()%100));
			gl::drawSolidCircle(Vec2f(200+rand()%100,rand()%100+200),color_changer_*2.5,3);
			gl::color(Color8u(100+rand()%100,rand()%100,rand()%100));
			gl::drawSolidCircle(Vec2f(200+rand()%100,rand()%100+200),color_changer_*2.6,3*rand()%2);
		}
		else{
			break;
		}
	}
	gl::color(Color8u(200,200,200));
	if (master_texture_font_ && display_help)
		gl::draw(master_texture_font_);
}

CINDER_APP_BASIC( TheRoyalSocietyApp, RendererGl )
