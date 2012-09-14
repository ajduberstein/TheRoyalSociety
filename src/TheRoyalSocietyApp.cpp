#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Resources.h"
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
};

void TheRoyalSocietyApp::setup()
{
}

void TheRoyalSocietyApp::mouseDown( MouseEvent event )
{
}

void TheRoyalSocietyApp::update()
{
}

void TheRoyalSocietyApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( TheRoyalSocietyApp, RendererGl )
