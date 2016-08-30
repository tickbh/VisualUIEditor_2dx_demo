#include "UILayer.h"
#include <functional>

UILayer::UILayer(std::string data, cocos2d::Node* parent)
{

}

UILayer* UILayer::create(std::string data, cocos2d::Node* parent)
{
	auto layer = new UILayer(data, parent);
	return layer;
}

void UILayer::eventListener(UIEvent& event)
{

}

void UILayer::AddEventListener(std::string name, const eventCallback& callback)
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

const eventCallback& UILayer::GetEventListener(std::string name)
{
	auto iter = listeners.find(name);
	if (iter != listeners.end()) {
		return iter->second;
	}
	
	return std::bind(&UILayer::eventListener, this, std::placeholders::_1);
}

