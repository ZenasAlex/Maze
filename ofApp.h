#pragma once

#include "ofMain.h"
#include "TMXLoader.h"
#include "TMXMapRenderer.h"

class ofApp : public ofBaseApp{

	public:
		TMXLoader mapLoader;
		TMXMapRenderer map;
		TMXLayer *maze;

		int posx;
		int posy;

		int prex;
		int prey;

		TMXLayer *floor;

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
