// Copirtight Funny Ltd.

#include "BattleTanks.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
    LeftTrack  = LeftTrackToSet;
    RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
    if (!ensure(LeftTrack))  { return; }
    if (!ensure(RightTrack)) { return; }

    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
    if (!ensure(LeftTrack))  { return; }
    if (!ensure(RightTrack)) { return; }

    LeftTrack->SetThrottle(-Throw);
    RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
    FVector TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
    FVector AIForwardIntention = MoveVelocity.GetSafeNormal();
 
    // Thanks to comment from Ethan from Lection 158.
    FVector CrossProduct = FVector::CrossProduct(TankForward, AIForwardIntention);
    float SteeringMagnitude = CrossProduct.Size();
    float ZSign = FMath::Abs(CrossProduct.Z)/CrossProduct.Z;

    IntendMoveForward(FVector::DotProduct(TankForward, AIForwardIntention));
    IntendTurnRight(SteeringMagnitude * ZSign);
}
