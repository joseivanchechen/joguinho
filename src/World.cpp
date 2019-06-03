#include "World.hpp"

void World::update(){
    engine->setView();
    collisionManager();
    draw();
    for(auto itr = entities.entity_list.getFirst(); itr != NULL; itr = itr->getNext()){
        cout << itr->getData() << endl;
        itr->getData()->update();
    }
}

void World::setAllEngine(Engine* _engine){
    engine = _engine;
    for(auto itr = entities.entity_list.getFirst(); itr != NULL; itr = itr->getNext()){
        itr->getData()->setEngine(_engine);
    }
}

void World::draw(){
    engine->draw(*background);
}

void World::gravity(){
    for(auto obj1 = objects.begin(); obj1 != objects.end(); ++obj1){
        if(!(*obj1)->isCollidingDown()){
            (*obj1)->fall();
        }
    }
}

void World::collisionManager(){
    for(auto obj1 = objects.begin(); obj1 != objects.end(); ++obj1){
        (*obj1)->setCollidingUp(false);
        (*obj1)->setCollidingRight(false);
        (*obj1)->setCollidingLeft(false);
        (*obj1)->setCollidingDown(false);
    }
    for(auto obj1 = objects.begin(); obj1 != objects.end(); ++obj1){
        for(auto obj2 = obj1; obj2 != objects.end(); ++obj2){
            if(obj1 == obj2) continue;
            if(Intersect::intersectsUp((*obj1)->getRect(), (*obj2)->getRect())){
                (*obj1)->setCollidingUp(true);
                (*obj2)->setCollidingDown(true);
            }else if(Intersect::intersectsDown((*obj1)->getRect(), (*obj2)->getRect())){
                (*obj1)->setCollidingDown(true);
                (*obj2)->setCollidingUp(true);
            }
            if(Intersect::intersectsRight((*obj1)->getRect(), (*obj2)->getRect())){
                (*obj1)->setCollidingRight(true);
                (*obj2)->setCollidingLeft(true);
            }else if(Intersect::intersectsLeft((*obj1)->getRect(), (*obj2)->getRect())){
                (*obj1)->setCollidingLeft(true);
                (*obj2)->setCollidingRight(true);
            }
        }
    }
}
