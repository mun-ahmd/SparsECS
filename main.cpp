#include "ECS/ECS.hpp"

struct Position{
    float x;
    float y;
    float z;
};

int main(){
    ECSmanager ecs;
    ecs.register_component<Position>();

    for(float x = -10; x < 10; ++x)
        for(float y = -10; y < 10; ++y)
            for(float z = -10; z < 10; ++z)
                ecs.new_entity(Position{x, y, z});

    ecs.get_components_of_type<Position>().iterate([](Position& pos) 
            {
                pos.x /= 10;
                pos.y /= 10;
                pos.z /= 10;
                std::cout << pos.x << ", " << pos.y << ", " << pos.z << std::endl;
            } );

}
