#include "TextObject.h"
#include "TextureManager.h"

TextObject::TextObject(const char* name, const char* textContent, int x, int y, char const* fontFilePath)
	: name(name), textContent(textContent), xPos(x), yPos(y)
{
	t_FilePath = (fontFilePath == "" || fontFilePath == NULL) ? "" : fontFilePath;

	t_Texture = TextureManager::loadRenderedText(textContent, t_FilePath);
	t_OriginalWidth = TextureManager::getWidth(t_Texture);
	t_OriginalHeight = TextureManager::getHeight(t_Texture);
	t_ModifiedWidth = 0;
	t_ModifiedHeight = 0;

	activeFont = nullptr;
		
	destRect = { xPos, yPos, t_OriginalWidth, t_OriginalHeight };

	setRenderDest(destRect);
	setRenderTexture(t_Texture);
}

TextObject::~TextObject(){
}

void TextObject::setTextContent(const char* newText)
{
	if (newText != nullptr)
		textContent = newText;
}

int TextObject::getTextWidth()
{
	return t_ModifiedWidth;
}

int TextObject::getTextHeight()
{
	return t_ModifiedHeight;
}