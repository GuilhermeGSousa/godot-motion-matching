# #!/usr/bin/env python
# import os
# import sys
# from glob import glob
# from pathlib import Path

# env = SConscript("godot-cpp/SConstruct")

# # For reference:
# # - CCFLAGS are compilation flags shared between C and C++
# # - CFLAGS are for C-specific compilation flags
# # - CXXFLAGS are for C++-specific compilation flags
# # - CPPFLAGS are for pre-processor flags
# # - CPPDEFINES are for pre-processor defines
# # - LINKFLAGS are for linking flags

# (extension_path,) = glob("addons/*/*.gdextension")

# addon_path = Path(extension_path).parent

# project_name = Path(extension_path).stem

# debug_or_release = "release" if env["target"] == "template_release" else "debug"

# # tweak this if you want to use different folders, or more folders, to store your source code in.
# env.Append(CPPPATH=["src/"])
# sources = Glob("src/*.cpp")
# sources += Glob("src/editor/*.cpp")
# sources += Glob("src/features/*.cpp")
# sources += Glob("src/math/*.cpp")
# sources += Glob("src/modifiers/*.cpp")
# sources += Glob("src/synchronizers/*.cpp")

# if env["platform"] == "macos":
#     library = env.SharedLibrary(
#         "{0}/bin/lib{1}.{2}.{3}.framework/{1}.{2}.{3}".format(
#             addon_path,
#             project_name,
#             env["platform"],
#             debug_or_release,
#         ),
#         source=sources,
#     )
# else:
#     library = env.SharedLibrary(
#         "{}/bin/lib{}.{}.{}.{}{}".format(
#             addon_path,
#             project_name,
#             env["platform"],
#             debug_or_release,
#             env["arch"],
#             env["SHLIBSUFFIX"],
#         ),
#         source=sources,
#     )


# Default(library)


#!/usr/bin/env python
import os
import sys

from methods import print_error


libname = "gdmotionmatching"
projectdir = "addons/motion_matching"

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

libraryfile = "bin/{}/{}{}".format(env["platform"], filepath, file)
library = env.SharedLibrary(
    libraryfile,
    source=sources,
)

copy = env.InstallAs("{}/bin/{}/{}lib{}".format(projectdir, env["platform"], filepath, file), library)

default_args = [library, copy]
Default(*default_args)
