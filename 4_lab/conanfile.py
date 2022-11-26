from conans import ConanFile, CMake

class lab4(ConanFile):
    name = "lab4"
    version = "1.0"
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake", "cmake_find_package"
    requires = [("sfml/2.5.1")]