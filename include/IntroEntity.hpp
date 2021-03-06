#ifndef             ENTITY_HPP
#define             ENTITY_HPP

#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

//TODO Make a flag to say if this entity is displayed or not.
namespace intro{
  namespace moving_scene{
    /*Two typedefs to define the scale and position of the sprite.*/
    typedef sf::Vector2f Scale;
    typedef sf::Vector2f Position;
   
    /******************************************************************
     * The IntroEntity is a class that provides functionality to handle 
     * sprite in a scripted way for a sequenced scene. Weather its a 
     * static house or a moving monster this class will handle
     * all actions related to them. 
     *
     * Author: David Baas
     * Version: 1.0 10/4/2018
     * Since: 1.0 10/4/2018
     *****************************************************************/
    class IntroEntity{
      public:
        /**************************************************************
         * The constructor initalizes the texture, sprite, and sets
         * the scale of the entity 
         *
         * Param: filename The name of the image file being used for
         * this entity.
         * Param: scale: gives the size of the sprite
         * Param: x The x coordinate of this entity
         * Param: y The y coordinate of this entity
         *************************************************************/
        IntroEntity(std::string filename, Scale scale, int x, int y);

        /**************************************************************
         * Updates the entity's position and returns the sprite
         * The inputs should be increments in a range from -1 to 1 to
         * ensure smooth transition across the screen. The direction
         * the sprite is facing changes if the movement goes either 
         * left or right. For entities that stay in the same spot 
         * for an entire scene, the function should be called with 
         * no parameters(eg enitity.getSprite()).
         *
         * Param deltaX Integer value for the changing x coordinate.
         * Param deltaY Integer value for the changing y coordinate.
         * Return: Sprite for this entity.
         *************************************************************/
        sf::Sprite getSprite();

        void moveSprite( int deltaX, int deltaY);
        void setPosition(int x, int y);
        bool isEnabled() const;
        void setEnabled(bool enabled);
      private:
        /*A Sprite variable to hold a sprite.*/
        sf::Sprite sprite;

        /*A Texture variable to hold the texture for the sprite.*/
        sf::Texture texture;

        /*A Vector to hold the scale of the object.*/
        Scale scale;

        int x;

        int y;

        /* A flag to say if this entity is enabled or not */
        bool enabled{true};
    };
  }
}
#endif
