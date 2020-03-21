function(auto_source SourceLst_)
    foreach(f ${SourceLst_})
        get_filename_component(dir ${f} DIRECTORY)
        file(RELATIVE_PATH dirRelative "${CMAKE_CURRENT_SOURCE_DIR}" ${dir})
        if(NOT dirRelative STREQUAL "")
            string(REPLACE "/" "\\" dirFixed ${dirRelative})
		else()
			set(dirFixed "Source Files")
        endif()

        source_group("${dirFixed}" FILES ${f})
    endforeach()
endfunction()