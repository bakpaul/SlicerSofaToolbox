#include <slicersofatoolbox/PickingInteractor.inl>
#include <sofa/core/ObjectFactory.h>

namespace slicersofatoolbox {

SOFA_DECL_CLASS(PickingInteractor)

void registerPickingInteractor(sofa::core::ObjectFactory* factory)
{
    factory->registerObjects(sofa::core::ObjectRegistrationData("PickingInteractor used to enable random point picking given an input position")
                              .add<PickingInteractor<sofa::defaulttype::Vec3Types>>(true));
}

}