#ifndef JETUNCERTAINTIES_PTMASSUNCERTAINTYCOMPONENT_H
#define JETUNCERTAINTIES_PTMASSUNCERTAINTYCOMPONENT_H

#include "JetUncertainties/UncertaintyComponent.h"

namespace jet
{

class PtMassUncertaintyComponent : public UncertaintyComponent
{
    public:
        // Constructor/destructor/initialization
        PtMassUncertaintyComponent(const ComponentHelper& component);
        PtMassUncertaintyComponent(const PtMassUncertaintyComponent& toCopy);
        virtual PtMassUncertaintyComponent* clone() const;
        virtual ~PtMassUncertaintyComponent() {}

    protected:

        // Uncertainty/validity retrieval helper methods
        virtual bool   getValidityImpl(const xAOD::Jet& jet, const xAOD::EventInfo& eInfo)    const;
        virtual double getUncertaintyImpl(const xAOD::Jet& jet, const xAOD::EventInfo& eInfo) const;

    private:
        PtMassUncertaintyComponent(const std::string& name = "");
};

} // end jet namespace

#endif

