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
    BOOL mActive;    
    
    float mEmitCounter;
    int mNumParticles;    
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
    SXColor4f mStartColor;                               // startColor
    SXColor4f mStartColorVariance;                       // startColorVariance
    SXColor4f mEndColor;                                 // finishColor
    SXColor4f mEndColorVariance;                         // finishColorVariance

    // blend function
    int mBlendFuncSource;                           // blendFuncSource
    int mBlendFuncDestination;                      // blendFuncDestination
}

/// Initialize a particle system from a configuration file, using a specific texture. 
/// _Designated Initializer_.
- (id)initWithContentsOfFile:(NSString*)filename texture:(SPTexture *)texture;

/// Initialize a particle system from a configuration file, using the texture specified in the file.
- (id)initWithContentsOfFile:(NSString*)filename;

/// Factory method.
+ (id)particleSystemWithContentsOfFile:(NSString *)filename;

/// Starts emitting particles.
- (void)start;

/// Stops emitting particles.
- (void)stop;

/// The current number of particles.
@property (nonatomic, readonly) int numParticles;

/// The position (x) where particles are emitted in the local coordinate system.
@property (nonatomic, assign) float emitterX;

/// The position (y) where particles are emitted in the local coordinate system.
@property (nonatomic, assign) float emitterY;

@end
