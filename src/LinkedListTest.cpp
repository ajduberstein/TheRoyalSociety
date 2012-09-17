#include <iostream>
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Resources.h"
#include <vector>
//#include "TheRoyalSocietyApp.h"

using namespace ci;
using namespace ci::app;
using namespace std;

int main(){
	int length = 5;
	int arr[] = {1, 4, 56, 10, 11};
	for (int i = 0; i < length; i++){
		console() << arr[i] << endl;
	}
}
