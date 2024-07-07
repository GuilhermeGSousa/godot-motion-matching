#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(
    CPPPATH=[
        "src/",
        "third-party/imgui/",
        "third-party/imgui/backends/",
        ])
sources = Glob("src/*.cpp")
sources += Glob("src/features/*.cpp")
sources += Glob("src/math/*.cpp")
sources += Glob("third-party/imgui/*.cpp")
sources += Glob("third-party/imgui/backends/imgui_impl_dx*.cpp")
sources += Glob("third-party/imgui/backends/imgui_impl_win*.cpp")


library = env.SharedLibrary(
    "addons/motion_matching/bin/libgdmotionmatching{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
    source=sources,
)

Default(library)
