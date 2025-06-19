from SCons.Script import ARGUMENTS

env = Environment()

env.VariantDir("build", ".", duplicate=0)

SConsignFile("build/build.dblite")

env.Program("build/chapter_code.cpp")
env.Program("build/exercises.cpp")
