#pragma once
#include "rfg/xtbl/XtblNodes.h"
#include "Common/Typedefs.h"
#include "XtblDescription.h"
#include "IXtblNode.h"
#include "XtblType.h"
#include "imgui.h"
#include "render/imgui/imgui_ext.h"
#include "render/imgui/ImGuiConfig.h"

//Flag node. Contained by FlagsXtblNode
class FlagXtblNode : public IXtblNode
{
public:
    virtual void DrawEditor(GuiState* guiState, Handle<XtblFile> xtbl, IXtblNode* parent, const char* nameOverride = nullptr)
    {

    }

    virtual void InitDefault()
    {

    }

    virtual bool WriteModinfoEdits(tinyxml2::XMLElement* xml)
    {
        //Handled by FlagsXtblNode
        return true;
    }

    virtual bool WriteXml(tinyxml2::XMLElement* xml, bool writeNanoforgeMetadata)
    {
        //Handled by FlagsXtblNode
        return true;
    }
};