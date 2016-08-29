#include "UIUtils.h"

UIUtils* UIUtils::GetInstance()
{
	static UIUtils instance;
	return &instance;
}

std::function<UILayer*(std::string, cocos2d::Node*)>* UIUtils::GetPathTemple(std::string, cocos2d::Node*) > GetPathTemple(std::string path)
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

