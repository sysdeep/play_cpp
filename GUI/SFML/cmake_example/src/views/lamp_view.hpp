#pragma once
#include <SFML/Graphics.hpp>
// #include "ui/core/update_ctx.hpp"
#include "../ui/core/update_ctx.hpp"
#include "../ui/core/ani_timer.hpp"

class LampView : public sf::CircleShape
// class LampView : public sf::Transformable,
//                  public sf::Drawable,
//                  private sf::NonCopyable
{
public:
    LampView(float size);

    void update(UpdateCtx *ctx);

private:
    AniTimer *timer;
    bool light_state = false;

    sf::CircleShape *inner;
    sf::CircleShape *outer;

    // virtual void draw(
    //     sf::RenderTarget &target,
    //     sf::RenderStates states) const;
};