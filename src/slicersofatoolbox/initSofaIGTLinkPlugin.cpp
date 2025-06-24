#include <sofa/core/ObjectFactory.h>
#include <sofa/helper/system/PluginManager.h>
#include <string>
#include <slicersofatoolbox/config.h>

namespace slicersofatoolbox
{
extern void registerEngineToMState(sofa::core::ObjectFactory* factory);
extern void registerPickingInteractor(sofa::core::ObjectFactory* factory);
extern void registerUserInteractionController(sofa::core::ObjectFactory* factory);

extern "C"
{

    SLICERSOFATOOLBOX_API void initExternalModule()
    {
        static bool first = true;
        if (first)
        {
            sofa::helper::system::PluginManager::getInstance().registerPlugin(MODULE_NAME);
            first = false;
        }
    }

    SLICERSOFATOOLBOX_API const char* getModuleName() { return MODULE_NAME; }

    SLICERSOFATOOLBOX_API const char* getModuleVersion() { return "0.0"; }

    SLICERSOFATOOLBOX_API const char* getModuleLicense() { return "Private"; }

    SLICERSOFATOOLBOX_API const char* getModuleDescription() { return "Toolbox for SlicerSOFA"; }

    SLICERSOFATOOLBOX_API const char* getModuleComponentList()
    {
        static std::string classes = sofa::core::ObjectFactory::getInstance()->listClassesFromTarget(sofa_tostring(SOFA_TARGET));
        return classes.c_str();
    }

    SLICERSOFATOOLBOX_API void registerObjects(sofa::core::ObjectFactory* factory)
    {
        registerEngineToMState(factory);
        registerPickingInteractor(factory);
        registerUserInteractionController(factory);
    }

}  // extern "C"

}  // namespace slicersofatoolbox
