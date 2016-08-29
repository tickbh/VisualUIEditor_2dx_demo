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

int UIUtils::CalcWidth(cocos2d::Node* node, std::string& width, cocos2d::Node* parent)
{
	if (width.length() == 0 && node != nullptr) {
		width = 
	}
	/*local isWidthPer = false;
	if not width and node then
		width = node:getContentSize().width
		end

		width = tostring(width or 0)
		local index = string.find(width, "%%")
		if not parent or not index then
			return tonumber(width), isWidthPer
			end

			isWidthPer = true
			local str = string.sub(width, 1, index - 1)
			width = parent:getContentSize().width * tonumber(string.sub(width, 1, index - 1)) / 100
			return width, isWidthPer*/
}

