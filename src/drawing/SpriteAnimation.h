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

#ifndef FLAZARD_SPRITEANIMATION_H
#define FLAZARD_SPRITEANIMATION_H


#include <vector>
#include <string>
#include <cstdio>
#include "SpriteSheet.h"
#include "Renderer.h"

/**
 * Defines the data needed to construct an animation.
 */
struct AnimationData {
    /** Name of the animation (must be unique among all animations with the same sprite sheet) */
    std::string name;
    /** Identifier of the sprite sheet to be used for this animation */
    std::string spriteSheetName;
    /** Specifies the frames of this animation using indices on the SpriteSheet */
    std::vector<unsigned> frames;
    /** Specifies at which frames pausing is allowed */
    std::vector<bool> pausableFrames;
    /** Whether this animation goes back to the first frame after leaving the last */
    bool loop;
    /** Default duration of every frame */
    unsigned frameDuration;
    /** Overrides default frame duration per frame */
    std::vector<unsigned> frameDurationOverrides;
};

/**
 * The actual in-memory sprite animation that can be played, paused, drawn, etc.
 * Should not be serialized.
 */
class SpriteAnimation {
public:
    SpriteAnimation(AnimationData& data, std::shared_ptr<SpriteSheet> spriteSheet);

    /**
     * Updates this animation (should be called on each global update unless the game is paused)
     * @param elapsedTime   Elapsed time in milliseconds since the last update
     */
    void update(double elapsedTime);

    /**
     * Draws the current animation frame
     */
    void draw(const Renderer& renderer, Vector2& position);

    /**
     * Requests pausing this animation. It will pause as soon as it reaches a frame at which pausing
     * is allowed.
     */
    void requestPause();

    /**
     * Forces this animation to skip to the next pauseable frame and then pause. If no such frame
     * exists, it will not pause and remain unchanged. If the animation does not loop and there is
     * no pauseable frame between the current and the last one, the animation will finish immediately.
     * @return true if the animation could be paused, false otherwise.
     */
    bool forcePause();

    /**
     * Resumes the animation if paused, removes the pause request if unpaused
     */
    void resume();

    /**
     * Switches to the next frame immediately (if one exists), ignoring this frame's duration
     */
    void nextFrame();

    /**
     * Resets the animation to the first frame and unpauses it
     */
    void reset();

    /**
     * @return true if the animation is currently paused, false otherwise
     */
    bool isPaused();

    /**
     * Immediately skips to the last frame and sets the time spent to the duration at this
     * frame, if the animation is non-looped. Does nothing if the animation is looped.
     * @return true if the animation is finished, false if it is looped.
     */
    bool finish();

    /**
     * @return true if the animation is non-looped, has reached the last frame, and
     *         has stayed there for the previously defined time (frameDuration).
     */
    bool isFinished();

    /**
     * @return the animation's name (unique among all animations with the same sprite sheet)
     */
    const std::string& getName() const;

private:
    AnimationData data;
    std::shared_ptr<SpriteSheet> spriteSheet;
    size_t currentFrame;
    double timeSinceLastFrameChange;
    bool pause;
    bool pauseRequested;

    /**
     * Like isFinished, but does not consider the time spent at this frame (and will
     * even output true if there is time left at the last frame).
     * @return true if the animation is non-looped and has reached the last frame
     */
    bool isAtLastFrameAndNonLooped();

    /**
     * Internal function for updating the animation, takes care of changing frames at the right time
     */
    void updateAnimation();

    /**
     * @return the duration of the current frame
     */
    float durationAtCurrentFrame();
};


#endif //FLAZARD_SPRITESHEETANIMATION_H
