#include <slicersofatoolbox/EngineToMState.inl>
#include <sofa/core/ObjectFactory.h>

namespace slicersofatoolbox {

SOFA_DECL_CLASS(EngineToMState)

void registerEngineToMState(sofa::core::ObjectFactory* factory)
{
    factory->registerObjects(sofa::core::ObjectRegistrationData("Engine to store data in mstate while dealing with correct resizing")
        .add<EngineToMState<sofa::defaulttype::Vec3Types> >(true)
        .add<EngineToMState<sofa::defaulttype::Rigid3dTypes> >());
}

}


