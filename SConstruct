#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

env.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp")
sources.extend(Glob("src/test/*.cpp"))

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "proj/bin/libgdpubcrawler.{}.{}.framework/libgdpubcrawler.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
else:
    library = env.SharedLibrary(
        "proj/bin/libgdpubcrawler{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources
    )

Default(library)