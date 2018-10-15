// Spout : http://spout.zeal.co/

#pragma once

#include "ofMain.h"

#ifdef TARGET_WIN32

#include "Spout.h"

namespace ofxSpout2 {
	class Sender
	{
	public:
		Sender();
		void sendTexture(ofTexture& t, string senderName);
		void exit();


	private:

		//SENDER
		vector<SpoutSender*> spoutSenderList;		// A sender object
		vector<string>		senderNameList;
		vector<int>			senderWidthList;
		vector<int>			senderHeightList;
		vector<ofFbo>		senderFboList;


	};
}

#endif
