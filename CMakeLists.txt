cmake_minimum_required(VERSION 3.28)
project(wars-sdk VERSION 0.0.1
                   DESCRIPTION "An SDK for Sonic Forces"
                   LANGUAGES CXX ASM_MASM)

add_library(wars-sdk STATIC)
target_compile_features(wars-sdk PUBLIC cxx_std_17)
target_link_libraries(wars-sdk PUBLIC eigen)
target_include_directories(wars-sdk PUBLIC wars-api)
target_sources(wars-sdk
    PRIVATE
        src/thunks.asm
    PUBLIC FILE_SET HEADERS BASE_DIRS include FILES
        include/wars-sdk.h
)

add_subdirectory(vendor EXCLUDE_FROM_ALL)
