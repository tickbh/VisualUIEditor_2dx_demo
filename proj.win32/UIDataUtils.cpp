#include "UIDataUtils.h"

UIDataUtils* UIDataUtils::GetInstance()
{
	static UIDataUtils instance;
	return &instance;
}

void UIDataUtils::GetJsonDataFromUI(std::string name, std::string fullpath)
{
	rapidjson::Document document;

	document.get
	//document.Parse<0>(result.c_str()).HasParseError()
}

