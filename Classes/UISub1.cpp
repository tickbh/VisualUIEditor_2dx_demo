#include "UISub1.h"

UISub1* UISub1::create(std::string data, cocos2d::Node* parent)
{
	return new UISub1(data, parent);
}

UISub1::UISub1(std::string data, cocos2d::Node* parent)
	:UILayer(data, parent)
{
	this->AddEventListener("sub1listener", CC_CALLBACK_1(UISub1::sub1listener, this));
}

void UISub1::sub1listener(UIEvent& event)
{
	cocos2d::log("sub1listener event is %s", event.name.c_str());
}
