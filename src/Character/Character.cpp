#include "Character.hpp"

Character::Character(){
    currentState = NULL;
}

Character::~Character(){

}

bool Character::setState(const CharacterState::State _newState){
    if(currentState != NULL){
        if(_newState == currentState->getState()) return true; // Não há necessidade de "renovar" o estado
        if(anim->isLocked()) return false; // Personagem ocupado com uma animação, não sobrepor
        //delete currentState; -> Movido para respectiva função
    }else{
        currentState = new IdleState();
    }
    switch (_newState){
        case CharacterState::STATE_IDLE:
            return currentState->idle(this);
        case CharacterState::STATE_WALKING:
            return currentState->walking(this);
        case CharacterState::STATE_JUMPING:
            return currentState->jumping(this);
        case CharacterState::STATE_FALLING:
            return currentState->falling(this);
        case CharacterState::STATE_ATTACKING:
            return currentState->attacking(this);
        default:
            return currentState->idle(this);
    }
}

const sf::Vector2f Character::Character::getSize() const {
    return sf::Vector2f(getRect().width, getRect().height);
}

const float Character::getDamage() const {
    return damage;
}

const float Character::getAttackSpeed() const {
    return attackSpeed;
}

sf::Clock* Character::getAttackClock(){
    return &attackTimer;
}

const float Character::getRange() const {
    return range;
}

const float Character::getHealth() const {
    return health;
}

const short Character::getType() const {
    return type;
}

const short Character::getSubType() const {
    return 0;
}

const CharacterState::State Character::getState() const {
    return currentState->getState();
}

const CharacterState* Character::getCharacterState() const {
    return currentState;
}

void Character::setCharacterState(CharacterState* _newState){
    currentState = _newState;
}

void Character::setFacingRight(bool _facingRight){
    facingRight = _facingRight;
}

const bool Character::isFacingRight() const {
    return facingRight;
}

void Character::setHealth(const float& _health){
    health = _health;
}