#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
//#include "ofAddons.h"
#include <algorithm>

#include "pointRecorder.h"
#include "pointPlayer.h" 
#include "Tones.h"

#define RECORDERS 200
#define PLAYERS 200
#define SHAPE_FLAT 0
#define SHAPE_SINUS 1
#define SHAPE_SAWTOOTH 2
#define SHAPE_RECTANGLE 3

class testApp : public ofSimpleApp{

	public:
	
		void setup();
		void update();
		void draw();
	
		void keyPressed  (int key);
		void keyReleased (int key);

		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased();
		void pairUpWithAnyPlayer( pointRecorder * pr ); 
		void deleteRecorder( int rec ); 
		void deleteRecordersKids( int rec ); 
		void moveRecorder( int rec, int dx, int dy, bool moveKids ); 
		void drawImage( ofImage * img, float x, float y, bool selected = false, float overlay = 0 );
	
		bool inRect( float pX, float pY, float x, float y, float width, float height ); 
		bool inPoly( ofPoint *polygon, int N, ofPoint p ); 
	
		float triggerAlpha[6]; 
	
		float			timeCounter;
		float			timeOfLastFrame;
	
		
		// --------------- for the audio
		void audioRequested(float * input, int bufferSize, int nChannels); 

		float 	pan;
		int		sampleRate;
		bool 	bNoise;
		float 	volume;

		float 	lAudio[256];
		float   rAudio[256];
		bool	showAudio; 
	
		//------------------- for the simple sine wave synthesis
		float 	targetFrequency;
		float 	phase;
		float 	phaseAdder;
		float 	phaseAdderTarget;
	
		pointRecorder recorders[RECORDERS];
		pointPlayer players[PLAYERS];
		
		int whichRecorder; 
		int beatMod; 
		int soundShape; 
		
		
		// variables to get the mouse position from the previous frame... 
		int cmouseX; // current mouseX
		int cmouseY; // current mouseY
		int pmouseX; // previous mouseX
		int pmouseY; // previous mouseY
	
		// mouse focus? 
		int spawnFocusRecorder; 
		int spawnFocusPoint; 
	
	
		ofImage beatImgs[6];
		ofImage shapeImgs[4]; 
		ofImage envelopeImg; 
		ofImage selectionImg; 
		
		// some modes... 
		bool  	bFullscreen;
		bool useEnvelope; 
		bool chromaticMode; 
		bool selectionMode;	
		int lineHovered; 
	
	
		// selection mode: 
		ofPoint selection[1000]; 
		int selectionLength;
		vector <int> selectedRecorders; 
	
		float lastMousePressed; 
	
		// glut keyboard modifiers (case glutGetModifiers() can't be called from within mouseDragged() )
		int glutModifiers; 
	
	
		bool toConsole; 
		bool holdNeighbour; 
};


#endif

