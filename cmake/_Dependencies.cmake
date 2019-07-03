#
# cmake/_Dependencies.cmake is generated by `mulle-sde`. Edits will be lost.
#
if( MULLE_TRACE_INCLUDE)
   message( STATUS "# Include \"${CMAKE_CURRENT_LIST_FILE}\"" )
endif()

# sourcetree: GLFW3;no-all-load,no-import;glfw3
if( NOT GLFW3_LIBRARY)
   find_library( GLFW3_LIBRARY NAMES ${CMAKE_STATIC_LIBRARY_PREFIX}glfw3${CMAKE_STATIC_LIBRARY_SUFFIX} glfw3 NO_CMAKE_SYSTEM_PATH)
   message( STATUS "GLFW3_LIBRARY is ${GLFW3_LIBRARY}")
   #
   # the order looks ascending, but due to the way this file is read
   # it ends up being descending, which is what we need
   if( GLFW3_LIBRARY)
      #
      # Add to GLFW3_LIBRARY list.
      # Disable with: `mark no-cmakeadd`
      #
      set( DEPENDENCY_LIBRARIES
         ${DEPENDENCY_LIBRARIES}
         ${GLFW3_LIBRARY}
         CACHE INTERNAL "need to cache this"
      )
      #
      # Inherit ObjC loader and link dependency info.
      # Disable with: `mark no-cmakeinherit`
      #
      # // temporarily expand CMAKE_MODULE_PATH
      get_filename_component( _TMP_GLFW3_ROOT "${GLFW3_LIBRARY}" DIRECTORY)
      get_filename_component( _TMP_GLFW3_ROOT "${_TMP_GLFW3_ROOT}" DIRECTORY)
      #
      #
      # Search for "DependenciesAndLibraries.cmake" to include.
      # Disable with: `mark no-cmakedependency`
      #
      foreach( _TMP_GLFW3_NAME "glfw3")
         set( _TMP_GLFW3_DIR "${_TMP_GLFW3_ROOT}/include/${_TMP_GLFW3_NAME}/cmake")
         # use explicit path to avoid "surprises"
         if( EXISTS "${_TMP_GLFW3_DIR}/DependenciesAndLibraries.cmake")
            unset( GLFW3_DEFINITIONS)
            list( INSERT CMAKE_MODULE_PATH 0 "${_TMP_GLFW3_DIR}")
            # we only want top level INHERIT_OBJC_LOADERS, so disable them
            if( NOT NO_INHERIT_OBJC_LOADERS)
               set( NO_INHERIT_OBJC_LOADERS OFF)
            endif()
            list( APPEND _TMP_INHERIT_OBJC_LOADERS ${NO_INHERIT_OBJC_LOADERS})
            set( NO_INHERIT_OBJC_LOADERS ON)
            #
            include( "${_TMP_GLFW3_DIR}/DependenciesAndLibraries.cmake")
            #
            list( GET _TMP_INHERIT_OBJC_LOADERS -1 NO_INHERIT_OBJC_LOADERS)
            list( REMOVE_AT _TMP_INHERIT_OBJC_LOADERS -1)
            #
            list( REMOVE_ITEM CMAKE_MODULE_PATH "${_TMP_GLFW3_DIR}")
            set( INHERITED_DEFINITIONS
               ${INHERITED_DEFINITIONS}
               ${GLFW3_DEFINITIONS}
               CACHE INTERNAL "need to cache this"
            )
            break()
         else()
            message( STATUS "${_TMP_GLFW3_DIR}/DependenciesAndLibraries.cmake not found")
         endif()
      endforeach()
   else()
      message( FATAL_ERROR "GLFW3_LIBRARY was not found")
   endif()
endif()
