# Motion Matching for Godot 4.3

![](https://github.com/GuilhermeGSousa/godot-motion-matching/motion_matching_demo.gif)

A very simple motion matching implementation example in Godot 4.3, that allows for both strafe and non strafe movement, implemented following [Dan Holden's article](https://www.theorangeduck.com/page/code-vs-data-driven-displacement). 

### Implementation
- `MMAnimationLibrary`: a **Resource** that holds not only a list of animations, but also all the extracted features data for every frame, as well as their statistics data.
- `MMFeature`: an **Resource** that describes data used to match movement to a specific animation frame. You can find implementation examples `src/features`.
- `MMAnimationPlayer`: an animation player that supports inertialization to transition between animations. Its it also used to make queries to a `MMAnimationLibrary`.
- `MMController`: A simple 3rd person controller, that also generates trajectories used for motion matching queries.
- `MotionMatcher`: Coordinates fetching query information from `MMController` and transitioning to the resulting animation.


### Todo
- Implement better debugging tools
- Use a KD Tree to accelerate queries
- Finish implementing `MMBoneDataFeature`
- Get more complete animation data
- Support jumping, crouching, and parkour movements

### Credits

- [Road to Next Gen Animation - GDC Talk](https://www.gdcvault.com/play/1023280/Motion-Matching-and-The-Road)
- [Simon Clavet's implementation video](https://www.youtube.com/watch?v=jcpIrw38E-s&ab_channel=SimonClavet)
- [Orange Duck's Blog](https://theorangeduck.com/)
- [Remi's Motion Matching implementation](https://github.com/Remi123/MotionMatching)
- Demo data taken from [O3DE Motion Matching Implementation](https://github.com/o3de/o3de/tree/development/Gems/MotionMatching)
