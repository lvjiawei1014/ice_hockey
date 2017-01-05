#include"psyentity.h"

PsyEntity::PsyEntity(int type, b2Body* body){
    this->type=type;
    this->body=body;
}

PsyEntity::PsyEntity(){

}
PsyEntity::~PsyEntity(){

}
