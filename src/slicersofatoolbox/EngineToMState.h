#pragma once

#include <sofa/type/Mat.h>
#include <sofa/defaulttype/RigidTypes.h>
#include <sofa/type/Vec.h>
#include <sofa/defaulttype/VecTypes.h>

#include <sofa/simulation/AnimateBeginEvent.h>
#include <sofa/simulation/AnimateEndEvent.h>

#include <sofa/core/topology/TopologyChange.h>
#include <sofa/core/topology/TopologyData.h>
#include <sofa/core/topology/TopologicalMapping.h>

#include <sofa/core/behavior/MechanicalState.h>
#include <sofa/core/objectmodel/DataCallback.h>
#include <SlicerSofaToolbox/slicersofatoolbox/config.h>

namespace slicersofatoolbox {

template<class DataTypes>
class SLICERSOFATOOLBOX_API EngineToMState : public sofa::core::objectmodel::BaseObject {
public :

    typedef typename DataTypes::Coord Coord;
    typedef typename DataTypes::VecCoord VecCoord;

    SOFA_CLASS(SOFA_TEMPLATE(EngineToMState, DataTypes), sofa::core::objectmodel::BaseObject);

    sofa::Data<sofa::type::vector<Coord> > d_positions;
    sofa::Data<double > d_scale;
    sofa::Data<bool > d_eachStep;
    sofa::core::objectmodel::DataCallback c_positions;
    sofa::core::objectmodel::SingleLink<EngineToMState<DataTypes>,sofa::core::behavior::MechanicalState<DataTypes>,sofa::BaseLink::FLAG_STRONGLINK|sofa::BaseLink::FLAG_STOREPATH> l_state;

    EngineToMState();

    void applyTopologyChanges();
    void inputChanged();
    void handleEvent(sofa::core::objectmodel::Event *event);

    bool m_isDirty;
};

}

