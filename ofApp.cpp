#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	map.loadMap("Mapa.tmx");
	ofBackground(0);
	ofSetFrameRate(60);
	maze = map.map->getLayer("Pared");
}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
	map.draw();
	ofDrawBitmapString(ofToString(ofGetFrameRate()), 255, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	TMXLayer *layer = map.map->getLayer("Maze");
	if (layer != NULL) 
	{
		TMXCell *cell = layer->getCell(x, y);
		if (cell != NULL) 
		{
			cout << "cell gid:" << cell->gid << endl;
			TMXTile*tile = map.map->getTile(cell->gid);
			if (tile != NULL) 
			{
				cout << tile->getProperty("type") << endl;
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{ 

}
