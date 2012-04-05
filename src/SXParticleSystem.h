//
//  SXParticleEmitter.h
//  Sparrow Particle System Extension
//
//  Created by Daniel Sperl on 02.06.11.
//  Copyright 2011 Gamua. All rights reserved.
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the Simplified BSD License.
//

#import <Foundation/Foundation.h>
#import "Sparrow.h"

// --- structs & enums -----------------------------------------------------------------------------

typedef enum 
{
    SXParticleEmitterTypeGravity,
    SXParticleEmitterTypeRadial
} SXParticleEmitterType;

typedef struct {
    float red;
    float green;
    float blue;
    float alpha;
} SXColor4f;

typedef struct 
{
    float x, y;
    float size;
    uint color;
} SXPointSprite;

typedef struct
{
    SXColor4f color, colorDelta;
    float x, y;
    float startX, startY;
    float velocityX, velocityY;
    float radialAcceleration;
    float tangentialAcceleration;
    float radius, radiusDelta;
    float rotation, rotationDelta;
    float size, sizeDelta;    
    float timeToLive;
} SXParticle;

/** ------------------------------------------------------------------------------------------------
 
 This class provices an easy way to display particle systems.

 Particle Systems can be used to create special effects like explosions, smoke, snow, fire, etc. 
 The system is controlled by a configuration file in the format that is created by 
 [Particle Designer](http://particledesigner.71squared.com). While you don't need that tool to 
 create particle systems, it makes designing them much easier.

------------------------------------------------------------------------------------------------- */

@interface SXParticleSystem : SPDisplayObject <SPAnimatable, NSXMLParserDelegate>
{
  @private                                          // .pex element name
     
    SPTexture *mTexture;
    NSString *mPath;            
    double mBurstTime;
    double mFrameTime;
    int mNumParticles;
    float mScaleFactor;
    
    uint mVertexBuffer;
    SXParticle *mParticles;
    SXPointSprite *mPointSprites;
    
    // emitter configuration
    SXParticleEmitterType mEmitterType;             // emitterType
    float mEmitterX;                                // sourcePosition x (ignored)
    float mEmitterY;                                // sourcePosition y (ignored)
    float mEmitterXVariance;                        // sourcePositionVariance x
    float mEmitterYVariance;                        // sourcePositionVariance y
    
    // particle configuration
    int mMaxNumParticles;                           // maxParticles
    float mLifespan;                                // particleLifeSpan
    float mLifespanVariance;                        // particleLifeSpanVariance
    float mStartSize;                               // startParticleSize
    float mStartSizeVariance;                       // startParticleSizeVariance
    float mEndSize;                                 // finishParticleSize
    float mEndSizeVariance;                         // finishParticleSize
    float mEmitAngle;                               // angle
    float mEmitAngleVariance;                       // angleVariance
    // [rotation not supported!]
    
    // gravity configuration
    float mSpeed;                                   // speed
    float mSpeedVariance;                           // speedVariance
    float mGravityX;                                // gravity x
    float mGravityY;                                // gravity y
    float mRadialAcceleration;                      // radialAcceleration
    float mRadialAccelerationVariance;              // radialAccelerationVariance
    float mTangentialAcceleration;                  // tangentialAcceleration
    float mTangentialAccelerationVariance;          // tangentialAccelerationVariance
    
    // radial configuration 
    float mMaxRadius;                               // maxRadius
    float mMaxRadiusVariance;                       // maxRadiusVariance
    float mMinRadius;                               // minRadius
    float mRotatePerSecond;                         // rotatePerSecond
    float mRotatePerSecondVariance;                 // rotatePerSecondVariance
    
    // color configuration
    SXColor4f mStartColor;                          // startColor
    SXColor4f mStartColorVariance;                  // startColorVariance
    SXColor4f mEndColor;                            // finishColor
    SXColor4f mEndColorVariance;                    // finishColorVariance

    // blend function
    int mBlendFuncSource;                           // blendFuncSource
    int mBlendFuncDestination;                      // blendFuncDestination
}

/// ------------------
/// @name Initializers
/// ------------------

/// Initialize a particle system with a specific texture. Set up reasonable properties manually.
/// _Designated Initializer_.
- (id)initWithTexture:(SPTexture *)texture;

/// Initialize a particle system from a configuration file, using a specific texture. 
- (id)initWithContentsOfFile:(NSString *)filename texture:(SPTexture *)texture;

/// Initialize a particle system from a configuration file, using the texture specified in the file.
- (id)initWithContentsOfFile:(NSString *)filename;

/// Factory method.
+ (id)particleSystemWithContentsOfFile:(NSString *)filename;

/// ----------------------
/// @name Playback methods
/// ----------------------

/// Starts emitting particles.
- (void)start;

/// Emits particles for a certain time
- (void)startBurst:(double)duration;

/// Stops emitting particles.
- (void)stop;

/// ----------------------
/// @name General Settings
/// ----------------------

/// The current number of particles.
@property (nonatomic, readonly) int numParticles;

/// The particle texture.
@property (nonatomic, readonly) SPTexture *texture;

/// The scale factor of the particles. Default: normal displays: 1, retina displays: 2.
@property (nonatomic, assign) float scaleFactor;

/// -------------------------
/// @name Color configuration
/// -------------------------

/// The start color of new particles.
@property (nonatomic, assign) SXColor4f startColor;

/// The color variance of the start color.
@property (nonatomic, assign) SXColor4f startColorVariance;

/// The end color of particles.
@property (nonatomic, assign) SXColor4f endColor;

/// The color variance of the end color.
@property (nonatomic, assign) SXColor4f endColorVariance;

/// ---------------------------
/// @name Emitter configuration
/// ---------------------------

/// The emitter type (supported types: Radial or Gravity).
@property (nonatomic, assign) SXParticleEmitterType emitterType;

/// The position (x) where particles are emitted in the local coordinate system.
@property (nonatomic, assign) float emitterX;

/// The position (y) where particles are emitted in the local coordinate system.
@property (nonatomic, assign) float emitterY;

/// The variance of the position where particles are emitted, along the x axis.
@property (nonatomic, assign) float emitterXVariance;

/// The variance of the position where particles are emitted, along the y axis.
@property (nonatomic, assign) float emitterYVariance;

/// ----------------------------
/// @name Particle configuration
/// ----------------------------

/// The maximum number of particles (capacity) of the system.
@property (nonatomic, assign) int maxNumParticles; 

/// The life span of a particle in seconds.
@property (nonatomic, assign) float lifespan;

/// The variance of the life span of a particle in seconds.
@property (nonatomic, assign) float lifespanVariance;

/// The start size of a particle in points.
@property (nonatomic, assign) float startSize;

/// The variance of the start size of a particle in points.
@property (nonatomic, assign) float startSizeVariance;

/// The end size of a particle in points.
@property (nonatomic, assign) float endSize;

/// The variance of the end size of a particle in points.
@property (nonatomic, assign) float endSizeVariance; 

/// The angle in which new particles are emitted in radians.
@property (nonatomic, assign) float emitAngle;

/// The variance of the engle in which new particles are emitted in radians.
@property (nonatomic, assign) float emitAngleVariance;

/// ---------------------------
/// @name Gravity configuration
/// ---------------------------

/// The speed of a particle in points per second.
@property (nonatomic, assign) float speed;

/// The variance of the speed of a particle.
@property (nonatomic, assign) float speedVariance;

/// The gravity force along the x axis.
@property (nonatomic, assign) float gravityX;

/// The gravity force along the y axis.
@property (nonatomic, assign) float gravityY;

/// The radial acceleration of a particle.
@property (nonatomic, assign) float radialAcceleration;

/// The variance of the radial acceleration of a particle.
@property (nonatomic, assign) float radialAccelerationVariance;

/// The tangential acceleration of a particle.
@property (nonatomic, assign) float tangentialAcceleration;

/// The variance of the radial acceleration of a particle.
@property (nonatomic, assign) float tangentialAccelerationVariance;

/// --------------------------
/// @name Radial configuration
/// --------------------------

/// The maximum radius of the radial emission.
@property (nonatomic, assign) float maxRadius;

/// The variance of the maximum radius of the radial emission.
@property (nonatomic, assign) float maxRadiusVariance;

/// The minimum radius of the radial emission.
@property (nonatomic, assign) float minRadius;

/// The rotation per second (in radians) of the radial emission.
@property (nonatomic, assign) float rotatePerSecond;

/// The variance of the rotation per second (in radians) of the radial emission.
@property (nonatomic, assign) float rotatePerSecondVariance;

/// --------------
/// @name Blending
/// --------------

/// The source factor of the blending function.
@property (nonatomic, assign) int blendFuncSource;

/// The destination factor of the blending function.
@property (nonatomic, assign) int blendFuncDestination;

@end
