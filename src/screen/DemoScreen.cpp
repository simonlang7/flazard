/* ==================================================================== *
 *
 * Flazard Game Engine
 * Copyright (C) 2018 Simon Lang
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * ==================================================================== */

#include "DemoScreen.h"
#include "../drawing/Renderer.h"
#include "../utility/collection_util.h"
#include "../input/mapping/InputMapping.h"

void DemoScreen::handleInput(const PlayerActions& actions, const PlayerStates& states) {
    for (const PlayerActionInput& playerAction : actions) {
        switch (playerAction.action) {
            default:
                break;
        }
    }

    InputState newMovementDirection = STATE_NONE;
    for (const PlayerStateInput& playerState : states) {
        switch (playerState.state) {
            case STATE_WALK_UP:
            case STATE_WALK_DOWN:
            case STATE_WALK_LEFT:
            case STATE_WALK_RIGHT:
                newMovementDirection = playerState.state;
                break;
            default:
                break;
        }
    }

    if (movementDirection != newMovementDirection) {
        movementDirection = newMovementDirection;
        updatePlayerAnimation();
    }
}

void DemoScreen::update(double elapsedTime) {
    switch (movementDirection) {
        case STATE_WALK_UP:
            position->y -= elapsedTime / 32;
            break;
        case STATE_WALK_DOWN:
            position->y += elapsedTime / 32;
            break;
        case STATE_WALK_LEFT:
            position->x -= elapsedTime / 32;
            break;
        case STATE_WALK_RIGHT:
            position->x += elapsedTime / 32;
            break;
        default:
            break;
    }

    currentAnimation->update(elapsedTime);
}

void DemoScreen::draw(const Renderer& renderer) {
    currentAnimation->draw(renderer, *position);
}

DemoScreen::DemoScreen(std::shared_ptr<Renderer> renderer) {
    ErrorContext errorContext("When initializing DemoScreen", "");

    movementDirection = STATE_NONE;

    // TODO: Integrate SpriteSheet and SpriteAnimation (de)serialization

    const Texture& hello = renderer->loadTexture(getResourcePath(""), "flinn_walk_animation.png");
    Dimension dim(16, 24);
    SpriteSheetData ssData;
    ssData.name = "flinn_walk_animation";
    ssData.frameSize = dim;
    ssData.framesPerRow = 3;
    ssData.framesPerCol = 4;
    ssData.initialHOffset = 0;
    ssData.initialVOffset = 0;
    ssData.hSpaceBetweenFrames = 0;
    ssData.vSpaceBetweenFrames = 8;
    std::shared_ptr<SpriteSheet> sprite = std::make_shared<SpriteSheet>(
            ssData, hello);

    position = std::make_unique<Vector2>(150, 150);

    AnimationData dataUp;
    dataUp.name = "walk_up";
    dataUp.spriteSheetName = "flinn_walk_animation";
    dataUp.frames = {1, 0, 1, 2};
    dataUp.frameDuration = 200;
    dataUp.loop = true;
    dataUp.pausableFrames = {true, false, true, false};
    animations[STATE_WALK_UP] = std::make_shared<SpriteAnimation>(dataUp, sprite);

    AnimationData dataRight;
    dataRight.name = "walk_right";
    dataRight.spriteSheetName = "flinn_walk_animation";
    dataRight.frames = {4, 3, 4, 5};
    dataRight.frameDuration = 200;
    dataRight.loop = true;
    dataRight.pausableFrames = {true, false, true, false};
    animations[STATE_WALK_RIGHT] = std::make_shared<SpriteAnimation>(dataRight, sprite);

    AnimationData dataDown;
    dataDown.name = "walk_down";
    dataDown.spriteSheetName = "flinn_walk_animation";
    dataDown.frames = {7, 6, 7, 8};
    dataDown.frameDuration = 200;
    dataDown.loop = true;
    dataDown.pausableFrames = {true, false, true, false};
    animations[STATE_WALK_DOWN] = std::make_shared<SpriteAnimation>(dataDown, sprite);

    AnimationData dataLeft;
    dataLeft.name = "walk_left";
    dataLeft.spriteSheetName = "flinn_walk_animation";
    dataLeft.frames = {10, 9, 10, 11};
    dataLeft.frameDuration = 200;
    dataLeft.loop = true;
    dataLeft.pausableFrames = {true, false, true, false};
    animations[STATE_WALK_LEFT] = std::make_shared<SpriteAnimation>(dataLeft, sprite);

    currentAnimation = this->animations[STATE_WALK_UP];
    currentAnimation->forcePause();

//    std::ofstream inputMappingFile(getResourcePath("controls/templates/") + "default.json");
//    inputMappingFile << std::setw(4) << j;
//    inputMappingFile.close();
}

DemoScreen::~DemoScreen() = default;

void DemoScreen::updatePlayerAnimation() {
    if (movementDirection == STATE_NONE)
        currentAnimation->forcePause();
    else {
        currentAnimation = animations.at(movementDirection);
        currentAnimation->resume();
    }
}
