#ifndef POINT_RECORDER_H
#define POINT_RECORDER_H

#include "ofMain.h"


// ---------------------------
// this is like an old school class, a "struct"
// it doesn't have functions, just data...
// it's C style -
//
// typedef 
// http://bytes.com/forum/thread620088.html
// http://en.wikipedia.org/wiki/Typedef
// struct
// http://www.itee.uq.edu.au/~comp2303/Leslie_C_ref/C/SYNTAX/struct.html
// http://en.wikipedia.org/wiki/C%2B%2B_structures_and_classes


typedef struct {
	ofPoint		pos;
	float		time; // from the start, what time does this pt occur at	
} timePt;



class pointRecorder {

	public:
	
        pointRecorder();
	
		void addPoint(ofPoint pt);
		void draw();
		void reset( int beatMod );
		float getDuration();
		void applyOffset(); 
	
		ofPoint getPointForTime(float time);
		ofPoint getVelocityForTime(float time);
		
		
		float				startTime;
		int					maxNumPts;
		vector <timePt>		pts;
	
		bool				bAmRecording;			// we don't playback when we are recording...
		
		int beatMod; 
		float volume;
		
		vector <pointRecorder*> kids;
		vector <int> kidPointNr; // at which point of the line do we attach? 
	
		int offsetX; 
		int offsetY; 
		int soundShape; 
	
};

#endif // POINT_RECORDER_H