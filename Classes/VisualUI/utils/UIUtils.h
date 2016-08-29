#ifndef _VISUALUI_UTILS_UITUILS_H_
#define _VISUALUI_UTILS_UITUILS_H_

#include "../ui/UILayer.h"
#include "json/json.h"

class UIUtils {
public:
	UIUtils* GetInstance();

	std::function<UILayer*(std::string, cocos2d::Node*)>* GetPathTemple(std::string path);
	void RegisterPathTemple(std::string path, std::function<UILayer*(std::string, cocos2d::Node*)> func);
private:
	std::map<std::string, std::function<UILayer*(std::string, cocos2d::Node*)>> temples;
public:

	static bool CheckPathRepeat(cocos2d::Node* node, std::string path);
	Json::Value& GetCurJsonData(std::string path);
	cocos2d::Color3B CovertToColor(Json::Value& value, bool* isSuccess);

	int CalcWidth(cocos2d::Node* node, std::string& width, cocos2d::Node* parent);

#endif