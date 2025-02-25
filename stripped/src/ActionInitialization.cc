#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"


namespace B1
{


void ActionInitialization::BuildForMaster() const
{
}


void ActionInitialization::Build() const
{
  SetUserAction(new PrimaryGeneratorAction);
}


}  
