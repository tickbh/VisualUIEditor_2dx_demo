#ifndef _VISUALUI_UISUB1_H_
#define _VISUALUI_UISUB1_H_

#include "VisualUI/ui/UILayer.h"


class UISub1 : public UILayer {
public:
	static UISub1* create(std::string data, cocos2d::Node* parent);

public:
	UISub1(std::string data, cocos2d::Node* parent);
	
	void sub1listener(UIEvent& event);
	std::string path;
private:
	std::map<std::string, eventCallback> listeners;
};

#endif