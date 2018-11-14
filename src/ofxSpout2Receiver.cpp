#pragma once

#include "ofxSpout2Receiver.h"

#ifdef TARGET_WIN32

using namespace ofxSpout2;

Receiver::Receiver() {
	;
}

void Receiver::setup() {
	mReceiver = new SpoutReceiver;
	mbInitialized = false;
}

void Receiver::set(std::string senderNameStr) {
	std::char_traits<char>::copy(senderName, senderNameStr.c_str(), senderNameStr.size() + 1);
	unsigned int width, height;
	if (mReceiver->CreateReceiver(senderName, width, height, true)) {
		mTexture.allocate(width, height, GL_RGBA);
		mbInitialized = true;
		return;
	}
	else {
		ofLogWarning("ofxSpout", "No sender detected");
	}
}

void Receiver::showSenders() {
	mReceiver->SelectSenderPanel();
}

void Receiver::updateTexture() {
	assert(mTexture.isAllocated() && "Texture not allocated but receiver initialized!");
	unsigned int preWidth = mTexture.getWidth();
	unsigned int preHeight = mTexture.getHeight();

	unsigned int width, height;
	if (mReceiver->ReceiveTexture(senderName, width, height, mTexture.getTextureData().textureID, mTexture.getTextureData().textureTarget)) {
		if (width != preWidth || height != preHeight) { // in case of size change, reallocate
			mTexture.allocate(width, height, GL_RGBA);
			return;
		}
	}
	else {
		// receiving failed
		ofLogWarning() << "spout failed to receive texture";
		mReceiver->ReleaseReceiver();
	}
}

void Receiver::bind() {
	mTexture.bind();
}

void Receiver::unbind() {
	mTexture.unbind();
}

void Receiver::exit() {
	if(mReceiver != NULL && mbInitialized)
		mReceiver->ReleaseReceiver();
}

#endif
