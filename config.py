def can_build(env, platform):
    return True


def configure(env):
    pass


def get_doc_classes():
    return [
        "DampedSkeletonModifier",
        "MMAnimationLibrary",
        "MMBoneDataFeature",
        "MMCharacter",
        "MMClampSynchronizer",
        "MMFeature",
        "MMRootMotionSynchronizer",
        "MMSynchronizer",
        "MMTrajectoryFeature",
        "MMAnimationNode",
        "MMQueryInput",
    ]


def get_doc_path():
    return "doc_classes"
