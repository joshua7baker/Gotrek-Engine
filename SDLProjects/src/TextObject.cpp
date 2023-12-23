#include "TextObject.h"
#include "TextureManager.h"

TextObject::TextObject(const char* name, const char* textContent, int x, int y, char const* filePath)
	: name(name), textContent(textContent), xPos(x), yPos(y), t_FilePath(filePath)
{
	t_Texture = TextureManager::loadRenderedText(textContent, t_FilePath);
	t_OriginalWidth = TextureManager::getWidth(t_Texture);
	t_OriginalHeight = TextureManager::getHeight(t_Texture);
	t_ModifiedWidth = 0;
	t_ModifiedHeight = 0;

	activeFont = nullptr;
	
	destRect = new SDL_Rect({ xPos, yPos, t_OriginalWidth, t_OriginalHeight });

	renderInfo = new TextRenderData { t_Texture, destRect };
}

TextObject::~TextObject()
{
	delete renderInfo;
}

int TextObject::getTextWidth()
{
	return t_ModifiedWidth;
}

int TextObject::getTextHeight()
{
	return t_ModifiedHeight;
}

TextRenderData* TextObject::getRenderInfo()
{
	if (renderInfo != NULL)
	{
		return renderInfo;
	}
	else
	{
		Output::PrintMessage("Error getting render info from TextObject, variable TextRenderData* renderInfo cannot be NULL");
		return nullptr;
	}
}
