#ifndef _VISUALUI_UI_UILAYER_H_
#define _VISUALUI_UI_UILAYER_H_

#include "cocos2d.h"
//#include "cocos-ext.h"
#include "ui/CocosGUI.h"

class UILayer : cocos2d::Layer {
public:
	static UILayer* create(std::string data, cocos2d::Node* parent);

public:
	UILayer(std::string data, cocos2d::Node* parent);
	
	void AddEventListener(std::string name, cocos2d::ui::Widget::ccWidgetTouchCallback callback);
	void RemoveEventListener(std::string name);
	cocos2d::ui::Widget::ccWidgetTouchCallback GetEventListener(std::string name);
	void eventListener(Ref *sender, cocos2d::ui::Widget::TouchEventType controlEvent);
	std::string path;
private:
	std::map<std::string, cocos2d::ui::Widget::ccWidgetTouchCallback> listeners;
};

#endif