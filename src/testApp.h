#ifndef _TEST_APP
#define _TEST_APP

#define RECORDERS 200
#define PLAYERS 200
#define SHAPE_FLAT 0
#define SHAPE_SINUS 1
#define SHAPE_SAWTOOTH 2
#define SHAPE_RECTANGLE 3


#include "ofMain.h"

//#include "ofAddons.h"
#include <algorithm>
#include <fstream>

#include "pointRecorder.h"
#include "pointPlayer.h" 
#include "Tones.h"



class pointRecorder; 
class pointPlayer; 

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
		void deleteRecorder( pointRecorder * rec ); 
		void deleteRecordersKids( pointRecorder * rec ); 
		void moveRecorder( pointRecorder * rec, int dx, int dy, bool moveKids ); 
		void drawImage( ofImage * img, float x, float y, bool selected = false, float overlay = 0 );
	
		bool inRect( float pX, float pY, float x, float y, float width, float height ); 
		bool inPoly( ofPoint *polygon, int N, ofPoint p ); 
		void save();
		void load();
		bool save( string filename ); 
		bool load( string filename ); 
	
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
	
		pointRecorder recorders[200];
		pointPlayer players[200];
		vector<pointPlayer *> playersOfRecorders[RECORDERS]; 
		
		int beatMod; 
		int soundShape; 
		
		
		// mouse focus? 
		int spawnFocusRecorder; 
		int spawnFocusPoint; 
	
	
		ofImage beatImgs[6];
		ofImage shapeImgs[4]; 
		ofImage envelopeImg; 
		ofImage selectionImg; 
		ofImage triggerAlwaysImg; 
		ofImage triggerOnceImg; 
		
		// some modes... 
		bool  	bFullscreen;
		bool useEnvelope; 
		bool chromaticMode; 
		bool selectionMode;	
		bool holdSpawnMode; // "hold spawn" mode
		bool triggerAlwaysMode; // always trigger? 
	
		// which recorder are we currently hovering over, or null
		pointRecorder * hovering; 
	
		// which recorder are we currently recording into, or null
		pointRecorder * recording; 
		
		// selection mode: 
		ofPoint selectionPoly[1000]; 
		int selectionPolyLength;
		vector <pointRecorder *> selection; 
	
		// When was the mouse last pressed, and where? 
		float lastMousePressed; 
	
		// glut keyboard modifiers (case glutGetModifiers() can't be called from within mouseDragged() )
		int glutModifiers; 
	
		// Outputs generated sound-waves to console! 
		bool toConsole; 
	
	
		// bpm rates
		int bpmRates[6];
		float bpmLastTriggered[6]; 
		bool bpmTriggerNow[6]; 
	
	
		// sets... 
		vector<pointRecorder *> sets[12]; 
		bool setEnabled[12];
};


#endif