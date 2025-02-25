#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"


namespace example
{


void ActionInitialization::BuildForMaster() const
{
}


void ActionInitialization::Build() const
{
  SetUserAction(new PrimaryGeneratorAction);
}


}  
