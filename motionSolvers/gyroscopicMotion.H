#ifndef gyroscopicMotion_H
#define gyroscopicMotion_H

#include "solidBodyMotionFunction.H"
#include "primitiveFields.H"
#include "omega1.H"

namespace Foam
{
namespace solidBodyMotionFunctions
{

class gyroscopicMotion : public solidBodyMotionFunction
{
    // Private Data

        //- Origin of the axis
        const vector origin_;

        //- Global axis vector (fixed)
        const vector globalAxis_;

        //- Local axis vector (rotates with respect to the global axis)
        const vector localAxis_;

        //- Angular velocities for both axes
        autoPtr<Function1s::omega> omegaGlobal_;
        autoPtr<Function1s::omega> omegaLocal_;

public:

    //- Runtime type information
    TypeName("gyroscopicMotion");

    // Constructors
    gyroscopicMotion(const dictionary& SBMFCoeffs, const Time& runTime);

    //- Disallow default bitwise copy construction
    gyroscopicMotion(const gyroscopicMotion&) = delete;

    //- Construct and return a clone
    virtual autoPtr<solidBodyMotionFunction> clone() const
    {
        return autoPtr<solidBodyMotionFunction>
        (
            new gyroscopicMotion(SBMFCoeffs_, time_)
        );
    }

    //- Destructor
    virtual ~gyroscopicMotion();

    // Member Functions
    virtual septernion transformation() const;
    virtual bool read(const dictionary& SBMFCoeffs);

    // Member Operators
    void operator=(const gyroscopicMotion&) = delete;
};

} // End namespace solidBodyMotionFunctions
} // End namespace Foam

#endif
