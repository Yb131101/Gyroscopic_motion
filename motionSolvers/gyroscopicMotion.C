#include "gyroscopicMotion.H"
#include "addToRunTimeSelectionTable.H"
#include "mathematicalConstants.H"

using namespace Foam::constant::mathematical;

namespace Foam
{
namespace solidBodyMotionFunctions
{
    defineTypeNameAndDebug(gyroscopicMotion, 0);
    addToRunTimeSelectionTable(solidBodyMotionFunction, gyroscopicMotion, dictionary);
}

}

// Constructors
Foam::solidBodyMotionFunctions::gyroscopicMotion::gyroscopicMotion
(
    const dictionary& SBMFCoeffs,
    const Time& runTime
)
:
    solidBodyMotionFunction(SBMFCoeffs, runTime),
    origin_(SBMFCoeffs_.lookup("origin")),
    globalAxis_(SBMFCoeffs_.lookup("globalAxis")),
    localAxis_(SBMFCoeffs_.lookup("localAxis")),
    omegaGlobal_(new Function1s::omega(runTime, SBMFCoeffs_.subDict("globalOmega"))),
    omegaLocal_(new Function1s::omega(runTime, SBMFCoeffs_.subDict("localOmega")))
{}

// Destructor
Foam::solidBodyMotionFunctions::gyroscopicMotion::~gyroscopicMotion()
{}

// Member Functions
Foam::septernion Foam::solidBodyMotionFunctions::gyroscopicMotion::transformation() const
{
    // Calculate global axis rotation
    const scalar globalAngle = omegaGlobal_->integral(0, time_.value());
    const quaternion R_global(globalAxis_, globalAngle);

    // Calculate local axis rotation (after global rotation)
    const scalar localAngle = omegaLocal_->integral(0, time_.value());
    const quaternion R_local(localAxis_, localAngle);

    // Combine rotations
    const quaternion R_combined = R_global * R_local;

    const septernion TR(septernion(-origin_) * R_combined * septernion(origin_));

    DebugInFunction << "Time = " << time_.value() << " transformation: " << TR << endl;

    return TR;
}

bool Foam::solidBodyMotionFunctions::gyroscopicMotion::read(const dictionary& SBMFCoeffs)
{
    solidBodyMotionFunction::read(SBMFCoeffs);

    omegaGlobal_.reset(new Function1s::omega(time_, SBMFCoeffs_.subDict("globalOmega")));
    omegaLocal_.reset(new Function1s::omega(time_, SBMFCoeffs_.subDict("localOmega")));

    return true;
}
