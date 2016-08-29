#ifndef _VISUALUI_UI_UILAYER_H_
#define _VISUALUI_UI_UILAYER_H_

#include "cocos2d.h"

class UILayer : cocos2d::Layer {
public:
	UILayer(std::string data, cocos2d::Node* parent);
	std::string path;
};

#endif