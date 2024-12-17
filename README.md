# Motion Matching for Godot 4.4
[![Build GDExtension](https://github.com/GuilhermeGSousa/godot-motion-matching/actions/workflows/builds.yml/badge.svg?branch=master)](https://github.com/GuilhermeGSousa/godot-motion-matching/actions/workflows/builds.yml) [![Demo](https://img.shields.io/badge/Extension-Demo-blue)](https://github.com/GuilhermeGSousa/godot-motion-matching-demo)

![](https://github.com/GuilhermeGSousa/godot-motion-matching/blob/master/motion_matching_demo.gif)

Motion Matching is an animation technique that allows you to easily setup character movement animations from large amounts of unlabeled animation data, without requiring any blend trees or state machines.

This extension is fully integrated into Godot's `AnimationTree` system, and can be used in tandem with more traditional animation techniques.

### :gear: How it Works
Motion Matching uses a set of animations contained in an animation library to build a **pose database**, which contains **features** that describe different animation frames in different ways. At runtime, these **features** are periodically compared against what the character is doing, and the animation that best matches those **features** is played.

The only requirement for all this to work is to have animations with both root motion, and a root bone at the foot level.

You can find more on how to set all this up on the wiki [here!](https://github.com/GuilhermeGSousa/godot-motion-matching/wiki)


### :raised_hands: Credits
I want to thank all the contributors that made this project possible!

[Fire](https://github.com/fire)
[GeorgeS](https://github.com/GeorgeS2019)
[Remi](https://github.com/Remi123)
[Roberts Kalnins](https://github.com/rkalnins)

### Sources

- [Road to Next Gen Animation - GDC Talk](https://www.gdcvault.com/play/1023280/Motion-Matching-and-The-Road)
- [Simon Clavet's implementation video](https://www.youtube.com/watch?v=jcpIrw38E-s&ab_channel=SimonClavet)
- [Orange Duck's Blog](https://theorangeduck.com/)
- [Remi's Motion Matching implementation](https://github.com/Remi123/MotionMatching)
- Demo data taken from [O3DE Motion Matching Implementation](https://github.com/o3de/o3de/tree/development/Gems/MotionMatching)

A motion matching implementation in Godot 4.4, implemented following [Dan Holden's article](https://www.theorangeduck.com/page/code-vs-data-driven-displacement).
