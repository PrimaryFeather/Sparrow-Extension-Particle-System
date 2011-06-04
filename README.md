Sparrow Extension: Particle System
==================================

The Sparrow Extension class "SXParticleSystem" provides an easy way to display particle systems from within the [Sparrow Framework][1]. That way, adding special effects like explosions, smoke, snow, fire, etc. is very easy to do.

The particle system is controlled by a configuration file in the format that is created by [Particle Designer][2]. While you don't need that tool to create particle systems, it makes designing them much easier.

Installation
------------

In the `src`-directory, you will find 2 classes - the SXParticleSystem and a helper class. Add those classes directly to your Sparrow-powered game.

Demo-Project
------------

The `demo`-directory contains a sample project. If you have configured your system for Sparrow, the project should compile and run out of the box. 

The project contains 4 sample configurations. Switch between configurations in `Game.m` by 
changing the init-method:

    mParticleSystem = [[SXParticleSystem alloc] initWithContentsOfFile:@"sun.pex"];
    
The following configurations are available:

- drugs.pex
- fire.pex
- sun.pex
- waterfall.pex

Sample Code
-----------

This is all you have to do to create a particle system. The class `SXParticleSystem` is a subclass of `SPDisplayObject` and behaves as such. You can add it as a child to the stage or to any other
container. As usual, you have to add it to a juggler (or call its `advanceTime:` method once per frame) to animate it.

    // create particle system
    SXParticleSystem *ps = [[SXParticleSystem alloc] initWithContentsOfFile:@"sun.pex"];    
    ps.x = 160.0f;
    ps.y = 240.0f;
  
    // add it to the stage and the juggler
    [self addChild:ps];
    [self.juggler addObject:ps];
    [ps release];
    
    // stop emitting particles
    [ps stop];
    
    // start emitting particles
    [ps start];

More information
----------------

Find more information about this extension on the [Sparrow Wiki][3].

[1]: http://www.sparrow-framework.org
[2]: http://particledesigner.71squared.com
[3]: http://wiki.sparrow-framework.org/extensions/sxparticlesystem