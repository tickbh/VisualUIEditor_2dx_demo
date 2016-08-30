#include "UILayer.h"

UILayer::UILayer(std::string data, cocos2d::Node* parent)
{
	this->AddEventListener("eventListener", CC_CALLBACK_2(UILayer::eventListener, this));
}

UILayer* UILayer::create(std::string data, cocos2d::Node* parent)
{
	auto layer = new UILayer(data, parent);
	return layer;
}

void UILayer::eventListener(Ref *sender, cocos2d::ui::Widget::TouchEventType controlEvent)
{

}

void UILayer::AddEventListener(std::string name, cocos2d::ui::Widget::ccWidgetTouchCallback callback)
{
	listeners[name] = callback;
}

void UILayer::RemoveEventListener(std::string name)
{
	auto iter = listeners.find(name);
	if (iter != listeners.end()) {
		listeners.erase(iter);
	}
}

cocos2d::ui::Widget::ccWidgetTouchCallback UILayer::GetEventListener(std::string name)
{
	auto iter = listeners.find(name);
	if (iter != listeners.end()) {
		return iter->second;
	}
	return CC_CALLBACK_2(UILayer::eventListener, this);
}

