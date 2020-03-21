function(qt_auto_source SourceLst_)
    source_group("Generated Files" FILES "${CMAKE_BINARY_DIR}/${PROJECT_NAME}_autogen/mocs_compilation.cpp" ${SourceLst_})
endfunction()