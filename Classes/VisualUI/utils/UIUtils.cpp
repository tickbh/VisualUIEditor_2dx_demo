#include "UIUtils.h"
#include "UIDataUtils.h"

UIUtils* UIUtils::GetInstance()
{
	static UIUtils instance;
	return &instance;
}

std::function<UILayer*(std::string, cocos2d::Node*)>* UIUtils::GetPathTemple(std::string path)
{
	if (temples.find(path) == temples.end()) {
		return nullptr;
	}
	return &temples[path];
}

void UIUtils::RegisterPathTemple(std::string path, std::function<UILayer*(std::string, cocos2d::Node*)> func)
{
	temples.insert(make_pair(path, func));
}

void UIUtils::AddTouchEvent(cocos2d::Node* node, UILayer* controlNode, std::string baseFunc)
{
	if (!controlNode) {
		return;
	}
	auto listener = controlNode->GetEventListener(baseFunc);
	//this->addTouchEventListener(CC_CALLBACK_2(EditBox::touchDownAction, this));

}

bool UIUtils::CheckPathRepeat(cocos2d::Node* node, std::string path)
{
	auto parent = node;
	while (parent) {
		auto layer = dynamic_cast<UILayer*>(parent);
		if (layer && layer->path == path) {
			return true;
		}
		parent = parent->getParent();
	}
	return false;
}

Json::Value& UIUtils::GetCurJsonData(std::string path)
{
	return UIDataUtils::GetInstance()->GetJsonDataFromUI(path);
}

cocos2d::Color3B UIUtils::CovertToColor(Json::Value& value, bool* isSuccess)
{
	cocos2d::Color3B ret = cocos2d::Color3B::BLACK;
	if (value.isNull() || value[0].isNull() || value[1].isNull() || value[2].isNull()) {
		if (isSuccess) { *isSuccess = false; }
	} else {
		ret.r = value[0].asInt();
		ret.g = value[1].asInt();
		ret.b = value[2].asInt();
		if (isSuccess) { *isSuccess = true; }
	}
	return ret;
}

std::string UIUtils::IntToString(int value)
{
	std::ostringstream out;
	out << value;
	return out.str();
}

int UIUtils::CalcWidth(cocos2d::Node* node, std::string& width, cocos2d::Node* parent)
{
	if (width.length() == 0 && node != nullptr) {
		width = IntToString(node->getContentSize().width);
	}
	auto index = width.find("%");
	if (!parent || index == std::string::npos) {
		return atoi(width.c_str());
	}
	auto convert = atoi(width.c_str());
	return parent->getContentSize().width * atoi(width.c_str()) / 100;
}

int UIUtils::CalcHeight(cocos2d::Node* node, std::string& height, cocos2d::Node* parent)
{
	if (height.length() == 0 && node != nullptr) {
		height = IntToString(node->getContentSize().height);
	}
	auto index = height.find("%");
	if (!parent || index == std::string::npos) {
		return atoi(height.c_str());
	}
	auto convert = atoi(height.c_str());
	return parent->getContentSize().height * atoi(height.c_str()) / 100;

}

cocos2d::Node* UIUtils::CocosGenBaseNodeByData(Json::Value& data, cocos2d::Node* parent, UILayer* controlNode)
{
	if (data.isNull()) {
		return nullptr;
	}
	cocos2d::Node* node = nullptr;
	auto type = data["type"].asString();
	if (data["path"].isString()) {
		if (CheckPathRepeat(parent, data["path"].asString())) {
			return nullptr;
		}
		auto& temple = *UIUtils::GetInstance()->GetPathTemple(data["path"].asString());
		if (temple) {
			node = (cocos2d::Node*)temple(data["path"].asString(), parent);
		} else {
			node = (cocos2d::Node*)UILayer::create(data["path"].asString(), parent);
		}
	} else if (type == "Sprite") {
		node = cocos2d::Sprite::create();
	} else if (type == "Scale9") {
		node = cocos2d::ui::Scale9Sprite::create();
	} else if (type == "LabelTTF") {
		node = cocos2d::LabelTTF::create();
	} else if (type == "Input") {
		auto spriteBg = data["spriteBg"].asString();
		auto width = CalcWidth(node, data["width"].asString(), parent);
		auto height = CalcHeight(node, data["height"].asString(), parent);
		auto frame = GetSpriteFrameForName(spriteBg);
		if (!frame) {
			node = cocos2d::ui::EditBox::create(cocos2d::Size(width, height), cocos2d::ui::Scale9Sprite::create());
		} else {
			node = cocos2d::ui::EditBox::create(cocos2d::Size(width, height), spriteBg, cocos2d::ui::Widget::TextureResType::PLIST);
		}
	} else if (type == "Slider") {

	} else if (type == "CheckBox") {

	} else if (type == "Button") {

	} else {

	}
}

cocos2d::SpriteFrame* UIUtils::GetSpriteFrameForName(std::string name)
{
	if (name.length() == 0) {
		return nullptr;
	}
	auto frame = cocos2d::SpriteFrameCache::getInstance()->spriteFrameByName(name);
	if (frame) {
		return frame;
	}
	auto filePath = cocos2d::FileUtils::getInstance()->fullPathForFilename(name);
	if (filePath.length() == 0) {
		return nullptr;
	}
	auto sprite = cocos2d::Sprite::create(filePath);
	if (!sprite) {
		return nullptr;
	}
	frame = cocos2d::SpriteFrame::createWithTexture(sprite->getTexture(), sprite->getTextureRect());
	cocos2d::SpriteFrameCache::getInstance()->addSpriteFrame(frame, name);
	return frame;
}

