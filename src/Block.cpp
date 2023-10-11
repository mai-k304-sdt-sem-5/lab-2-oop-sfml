#include "Block.h"

Block::Block() {
    // Связываем текстуру и спрайт
    m_Texture.loadFromFile("block.png");
    m_Sprite.setTexture(m_Texture); 
};