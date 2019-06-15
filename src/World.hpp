#pragma once
#include "includes.hpp"
#include "Engine.hpp"
#include "Entity.hpp"
#include "Thing.hpp"
#include "Music.hpp"
#include "CollisionManager.hpp"
#include "List/LinkedList.hpp"
#include "List/EntityList.hpp"
#include "List/CharacterList.hpp"
#include "List/ThingsList.hpp"

class World : public Entity {
    protected:
        sf::Sprite* background;
        EntityList entities;
        ThingsList things;
        CharacterList characters;
        CollisionManager col_mngr;
        
        float getDistance(sf::Vector2f p1, sf::Vector2f p2);

    public:
        World();
        ~World();
        void setBackground(sf::Sprite* _bg) { background = _bg; }
        sf::Sprite* getBackground() { return background; }
        void update(); // Atualizar a lista de entidades dentro do mundo
        void draw(Engine* engine);
        void drawAll(Engine* engine);
        void gravity();
        
        void addEntity(Entity* _e) { entities.add(static_cast<Entity*>(_e)); }
        void addThing(Thing* _thing) { things.add(_thing); addEntity(static_cast<Entity*>(_thing)); }
        void addCharacter(Character* _char){ characters.add(_char); addThing(static_cast<Thing*>(_char)); }
};
