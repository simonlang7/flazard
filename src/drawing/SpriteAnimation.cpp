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

#include "SpriteAnimation.h"
#include <utility>

SpriteAnimation::SpriteAnimation(AnimationData& data,
                                 std::shared_ptr<SpriteSheet> spriteSheet)
        : data(data), spriteSheet(std::move(spriteSheet)), currentFrame(0), timeSinceLastFrameChange(0),
          pause(false), pauseRequested(false) {
}

void SpriteAnimation::update(double elapsedTime) {
    timeSinceLastFrameChange += elapsedTime;
    updateAnimation();
}

void SpriteAnimation::draw(const Renderer& renderer, Vector2& position) {
    spriteSheet->draw(renderer, data.frames[currentFrame], position);
}

void SpriteAnimation::requestPause() {
    pauseRequested = true;
}

bool SpriteAnimation::forcePause() {
    requestPause();

    size_t startFrame = currentFrame;
    double currentTimeSinceLastFrameChange = timeSinceLastFrameChange;

    while (!isAtLastFrameAndNonLooped() && !data.pausableFrames[currentFrame]) {
        if ((currentFrame + 1) % data.frames.size() == startFrame) {
            // We failed, revert state
            currentFrame = startFrame;
            timeSinceLastFrameChange = currentTimeSinceLastFrameChange;
            return false;
        }

        nextFrame();
    }

    if (isAtLastFrameAndNonLooped() && !data.pausableFrames[currentFrame])
        finish();

    update(0);
    return true;
}

void SpriteAnimation::resume() {
    pauseRequested = false;
    pause = false;

    // This is to prevent the animation from skipping lots of frames
    // after being paused for a while
    float durationAtThisFrame = durationAtCurrentFrame();
    if (timeSinceLastFrameChange > durationAtThisFrame)
        timeSinceLastFrameChange = durationAtThisFrame;
    update(0);
}

void SpriteAnimation::nextFrame() {
    if (data.loop || currentFrame < data.frames.size() - 1) {
        ++currentFrame;
        currentFrame = currentFrame % data.frames.size();
        timeSinceLastFrameChange = 0;
    }
}

void SpriteAnimation::reset() {
    currentFrame = 0;
    timeSinceLastFrameChange = 0;
    pause = false;
    pauseRequested = false;
}

bool SpriteAnimation::isPaused() {
    return pause;
}

bool SpriteAnimation::finish() {
    if (data.loop)
        return false;

    currentFrame = data.frames.size() - 1;
    timeSinceLastFrameChange = durationAtCurrentFrame();
    update(0);
    return true;
}

bool SpriteAnimation::isFinished() {
    return isAtLastFrameAndNonLooped()
            && timeSinceLastFrameChange >= durationAtCurrentFrame();
}

bool SpriteAnimation::isAtLastFrameAndNonLooped() {
    return !data.loop && currentFrame == data.frames.size() - 1;
}

void SpriteAnimation::updateAnimation() {
    if (pause)
        return;

    // This also skips frames in case of a lag (so the animation can catch up with the game)
    float durationAtThisFrame;
    do {
        // Pause?
        if (pauseRequested && data.pausableFrames[currentFrame]) {
            pause = true;
            return;
        }

        // Animation almost finished?
        if (isAtLastFrameAndNonLooped())
            return;

        // Change frame?
        durationAtThisFrame = durationAtCurrentFrame();
        if (timeSinceLastFrameChange >= durationAtThisFrame) {
            ++currentFrame;
            currentFrame = currentFrame % data.frames.size();
            timeSinceLastFrameChange -= durationAtThisFrame;
        }
    } while (timeSinceLastFrameChange >= durationAtThisFrame);
}

float SpriteAnimation::durationAtCurrentFrame() {
    // Specific duration for current frame?
    if (!data.frameDurationOverrides.empty()
            && data.frameDurationOverrides.size() > currentFrame
            && data.frameDurationOverrides[currentFrame] > 0)
        return data.frameDurationOverrides[currentFrame];
    else
        return data.frameDuration;
}

const std::string& SpriteAnimation::getName() const {
    return data.name;
}

