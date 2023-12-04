# Install script for directory: F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "F:/cpp_projects/games/Glitter/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libassimp5.2.5-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "F:/cpp_projects/games/Glitter/out/build/x64-Debug/Glitter/Vendor/assimp/lib/assimp-vc143-mtd.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/anim.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/aabb.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/ai_assert.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/camera.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/color4.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/color4.inl"
    "F:/cpp_projects/games/Glitter/out/build/x64-Debug/Glitter/Vendor/assimp/code/../include/assimp/config.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/ColladaMetaData.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/commonMetaData.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/defs.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/cfileio.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/light.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/material.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/material.inl"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/matrix3x3.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/matrix3x3.inl"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/matrix4x4.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/matrix4x4.inl"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/mesh.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/ObjMaterial.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/pbrmaterial.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/GltfMaterial.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/postprocess.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/quaternion.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/quaternion.inl"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/scene.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/metadata.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/texture.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/types.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/vector2.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/vector2.inl"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/vector3.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/vector3.inl"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/version.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/cimport.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/AssertHandler.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/importerdesc.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/Importer.hpp"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/DefaultLogger.hpp"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/ProgressHandler.hpp"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/IOStream.hpp"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/IOSystem.hpp"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/Logger.hpp"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/LogStream.hpp"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/NullLogger.hpp"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/cexport.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/Exporter.hpp"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/DefaultIOStream.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/DefaultIOSystem.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/ZipArchiveIOSystem.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/SceneCombiner.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/fast_atof.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/qnan.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/BaseImporter.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/Hash.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/MemoryIOWrapper.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/ParsingUtils.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/StreamReader.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/StreamWriter.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/StringComparison.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/StringUtils.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/SGSpatialSort.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/GenericProperty.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/SpatialSort.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/SkeletonMeshBuilder.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/SmallVector.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/SmoothingGroups.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/SmoothingGroups.inl"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/StandardShapes.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/RemoveComments.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/Subdivision.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/Vertex.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/LineSplitter.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/TinyFormatter.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/Profiler.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/LogAux.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/Bitmap.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/XMLTools.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/IOStreamBuffer.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/CreateAnimMesh.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/XmlParser.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/BlobIOSystem.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/MathFunctions.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/Exceptional.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/ByteSwapper.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/Base64.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/Compiler/pushpack1.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/Compiler/poppack1.h"
    "F:/cpp_projects/games/Glitter/Glitter/Vendor/assimp/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "F:/cpp_projects/games/Glitter/out/build/x64-Debug/Glitter/Vendor/assimp/code/assimp-vc143-mtd.pdb")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "F:/cpp_projects/games/Glitter/out/build/x64-Debug/Glitter/Vendor/assimp/code/assimp-vc143-mt.pdb")
  endif()
endif()

