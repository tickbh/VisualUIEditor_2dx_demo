#ifndef _VISUALUI_UTILS_UITUILS_H_
#define _VISUALUI_UTILS_UITUILS_H_

#include "json/rapidjson.h"
#include "json/document.h"
#include "json/stringbuffer.h"
#include "json/writer.h"

class UIDataUtils {

public:
	static UIDataUtils* GetInstance();

	void GetJsonDataFromUI(std::string name, std::string fullpath);

};

#endif