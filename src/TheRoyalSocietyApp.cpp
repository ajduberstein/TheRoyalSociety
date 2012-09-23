/*CSE 274 students, I draw a textbox under the render() method.*/
#include "LinkedList.h"
#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/Color.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/gl.h"
#include "Resources.h"
#include "cinder/gl/Texture.h"
#include "cinder/Text.h"
#include "cinder/Surface.h"
#include "cinder/Cinder.h"
#include "cinder/Font.h"
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
	 Surface* mySurface_; 
	 Font master_font_;
	 int color_changer_;
	 gl::Texture master_texture_font_;
	 bool display_help;
	 double param_;
	 LinkedList l;
	 int filler_; 
};

void TheRoyalSocietyApp::prepareSettings(Settings *settings){
	settings->setWindowSize(800, 600);
	settings->setFrameRate(60.0f);
	settings->setResizable(false);
	settings->setFullScreen(false);
}

void TheRoyalSocietyApp::keyDown( KeyEvent event ) {
    if( event.getChar() == 'j' ){
		l.bump();
    } 
	else if (event.getChar() == '?'){
		display_help = !(display_help);
		filler_ = 0;
	}
	else if( event.getChar() == '~' ){
		l.reverse();
    }
	else{
	}
}

void TheRoyalSocietyApp::setup(){
		mySurface_ = new Surface(800,600,false);
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
		l.bump();
		for (int i = 0; i < l.length(); i++){
			console()<< "AT NODE " << i << " IS " << l.at(i)->data << std::endl;
		}
		console() << "REVERSE TEST" << std::endl;
		l.reverse();
		for (int i = 0; i < l.length(); i++){
			console()<< "AT NODE " << i << " IS " << l.at(i)->data << std::endl;
		}
}

void TheRoyalSocietyApp::render(){
	string txt = "Welcome to the Royal Society for Stacking Things Upon Other Things!\n\n Keybindings: \n j      Moves shapes up \n ~     Reverses shape order \n";
	TextBox tbox = TextBox().alignment( TextBox::CENTER ).font(master_font_).size( Vec2i( 512, 511) ).text( txt );
	tbox.setColor( Color( 1.0f, 0.65f, 0.35f ) );
	tbox.setBackgroundColor( ColorA( 0.5, 0, 0, 1 ) );
	master_texture_font_ = gl::Texture( tbox.render() );
}

void TheRoyalSocietyApp::mouseDown( MouseEvent event )
{
}

void TheRoyalSocietyApp::update(){
	filler_ = getElapsedSeconds()*50;
	if (!display_help){
		filler_ = 0;
		param_++;
		color_changer_ = sin((param_)*PI/1800)*100;
	}
		if (param_>200)
			param_ = 0;
}

void TheRoyalSocietyApp::draw(){
	gl::clear( Color( 0, 0, 0 ) );
	mySurface_->setPremultiplied(true);
	gl::draw(*mySurface_);
	int shape_id;
	for (int i = 0; i <= 5; i++){
		shape_id = l.at(i)->data;
		if (shape_id == 1){
			gl::enableAlphaBlending();
			gl::color(ColorA8u(15,77,146,150)); //Yale blue. http://en.wikipedia.org/wiki/Yale_Blue
			gl::drawSolidCircle(Vec2f(310-color_changer_,310+color_changer_),200,100);
			gl::color(ColorA8u(5,7,46,150));
			gl::disableAlphaBlending();
			gl::drawSolidCircle(Vec2f(300-color_changer_,300+color_changer_),200,100);
		}
		else if (shape_id == 2){
			gl::enableAlphaBlending();
			gl::color(ColorA8u(55,28,48,150));
			gl::drawSolidCircle(Vec2f(410+color_changer_/2,410),200,10);
			gl::color(Color8u(165,28,48)); //Harvard crimson. http://en.wikipedia.org/wiki/Harvard_Crimson_(color)#Harvard_crimson
			gl::drawSolidCircle(Vec2f(400+color_changer_/2,400),200,10);
		}
		else if (shape_id == 3){
			gl::color(Color8u(0,50,0));
			gl::drawSolidCircle(Vec2f(510,310+color_changer_/5),200/(1+abs(tan((double) param_)),4));
			gl::color(Color8u(0,112,60)); //Dartmouth green. http://en.wikipedia.org/wiki/Dartmouth_Green#Dartmouth_green 
			gl::drawStrokedCircle(Vec2f(500,300+color_changer_/5),200/(1+abs(tan((double) param_))),4);
		}
		else if (shape_id == 4){
			gl::color(Color8u(255,127,0)); //Princeton's colors. http://en.wikipedia.org/wiki/Princeton_University
			gl::drawStrokedCircle(Vec2f(310,110),color_changer_*2.5,3);
			gl::color(Color8u(0,0,0)); 
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
	if (master_texture_font_ && display_help){
		gl::enableAlphaBlending();
		if (filler_ > 250)
			gl::color(ColorA8u(150,150,0,250));
		else	
			gl::color(ColorA8u(150,150,0,filler_));
		gl::draw( master_texture_font_);
	}
	gl::disableAlphaBlending();
}

CINDER_APP_BASIC( TheRoyalSocietyApp, RendererGl )
