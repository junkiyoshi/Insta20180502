#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofSetColor(39);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	int radius = 300;
	int deg_span = 15;
	for (int deg = 0; deg < 360; deg += deg_span) {

		ofRotateX(ofGetFrameNum() * 0.25);
		ofRotateY(ofGetFrameNum() * 0.25);

		vector<ofPoint> vertices;
		vertices.push_back(ofPoint(0, 0));
		vertices.push_back(ofPoint(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD)));
		vertices.push_back(ofPoint(radius * cos((deg + deg_span) * DEG_TO_RAD), radius * sin((deg + deg_span) * DEG_TO_RAD)));

		deg % (deg_span * 2) == 0 ? ofSetColor(239, 39, 39) : ofSetColor(239);
		ofFill();
		ofBeginShape();
		ofVertices(vertices);
		ofEndShape(true);		

		ofSetColor(39);
		ofNoFill();
		ofBeginShape();
		ofVertices(vertices);
		ofEndShape(true);
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}