//
//  Game.m
//  Particle System Demo
//

#import "Game.h" 

@implementation Game

- (id)initWithWidth:(float)width height:(float)height
{
    if ((self = [super initWithWidth:width height:height]))
    {
        // create particle system
        mParticleSystem = [[SXParticleSystem alloc] initWithContentsOfFile:@"sun.pex"];    
        mParticleSystem.x = width / 2.0f;
        mParticleSystem.y = height / 2.0f;
        
        // add it to the stage and the juggler
        [self addChild:mParticleSystem];
        [self.juggler addObject:mParticleSystem];
        [mParticleSystem release];

        // register touch event for emitter manipulation
        [self addEventListener:@selector(onTouch:) atObject:self forType:SP_EVENT_TYPE_TOUCH];        
    }
    return self;
}

- (void)onTouch:(SPTouchEvent *)event
{
    SPTouch *touch = [[event touchesWithTarget:self] anyObject];
    if (touch)
    {
        SPPoint *emitterPos = [touch locationInSpace:mParticleSystem];
        mParticleSystem.emitterX = emitterPos.x;
        mParticleSystem.emitterY = emitterPos.y;
    }
}

@end
