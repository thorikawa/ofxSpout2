#pragma once

#include "ofMain.h"

#ifdef TARGET_WIN32

#include "Spout.h"

namespace ofxSpout2 {
	class Receiver {
	public:
		Receiver();

		void setup();

		void set(std::string senderName);

		// show the panel for possible senders and select one
		void showSenders();

		void updateTexture();

		// call updateTexture() in a draw() call before (not in update())
		ofTexture &getTexture() { return mTexture; }

		// call in ofApp::exit()
		void exit();

		void bind();

		void unbind();

		void draw(float x, float y);

		float getWidth() {
			return mTexture.getWidth();
		}

		float getHeight() {
			return mTexture.getHeight();
		}

	private:
		SpoutReceiver *mReceiver;
		bool mbInitialized; ;
		char senderName[256];
		ofTexture mTexture;
	};
}

#endif
