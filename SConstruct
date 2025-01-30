#!/usr/bin/env python
import os
import sys
from pathlib import Path
from methods import print_error

from SCons.Environment import Environment
from SCons.Variables import Variables
from SCons.Script import ARGUMENTS

libname = "gdmotionmatching"
projectdir = "addons/motion_matching"
double_api_file = "godot-cpp/gdextension/extension_api_double.json"

if ARGUMENTS.get("precision", "single") == "double":
    ARGUMENTS["custom_api_file"] = double_api_file
    print("Using double precision API file: {}".format(double_api_file))
    
localEnv = Environment(tools=["default"], PLATFORM="")

customs = ["custom.py"]
customs = [os.path.abspath(path) for path in customs]

opts = Variables(customs, ARGUMENTS)
opts.Update(localEnv)

Help(opts.GenerateHelpText(localEnv))

env = localEnv.Clone()

submodule_initialized = False
dir_name = 'godot-cpp'
if os.path.isdir(dir_name):
    if os.listdir(dir_name):
        submodule_initialized = True

if not submodule_initialized:
    print_error("""godot-cpp is not available within this folder, as Git submodules haven't been initialized.
Run the following command to download godot-cpp:

    git submodule update --init --recursive""")
    sys.exit(1)

env = SConscript("godot-cpp/SConstruct", {"env": env, "customs": customs})

env.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp")
sources += Glob("src/algo/*.cpp")
sources += Glob("src/editor/*.cpp")
sources += Glob("src/features/*.cpp")
sources += Glob("src/math/*.cpp")
sources += Glob("src/modifiers/*.cpp")
sources += Glob("src/synchronizers/*.cpp")

if env["target"] in ["editor", "template_debug"]:
    try:
        doc_data = env.GodotCPPDocData("src/gen/doc_data.gen.cpp", source=Glob("doc_classes/*.xml"))
        sources.append(doc_data)
    except AttributeError:
        print("Not including class reference as we're targeting a pre-4.3 baseline.")

suffix = env["suffix"].replace(".dev", "")
file = "{}{}{}".format(libname, suffix, env["SHLIBSUFFIX"])
filepath = ""

if env["platform"] == "macos" or env["platform"] == "ios":
    filepath = "{}.framework/".format(env["platform"])
    file = "{}.{}.{}".format(libname, env["platform"], env["target"])

libraryfile = "bin/{}/{}lib{}".format(env["platform"], filepath, file)
library = env.SharedLibrary(
    libraryfile,
    source=sources,
)

copy = env.InstallAs("{}/bin/{}/{}lib{}".format(projectdir, env["platform"], filepath, file), library)

default_args = [library, copy]
Default(*default_args)
