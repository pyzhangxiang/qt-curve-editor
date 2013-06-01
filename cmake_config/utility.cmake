macro(source_group_by_dir source_files)
    set(sgbd_cur_dir ${CMAKE_CURRENT_SOURCE_DIR})
    foreach(sgbd_file ${${source_files}})
        string(REGEX REPLACE ${sgbd_cur_dir}/\(.*\) \\1 sgbd_fpath ${sgbd_file})
        string(REGEX REPLACE "\(.*\)/.*" \\1 sgbd_group_name ${sgbd_fpath})
        string(COMPARE EQUAL ${sgbd_fpath} ${sgbd_group_name} sgbd_nogroup)
        string(REPLACE "/" "\\" sgbd_group_name ${sgbd_group_name})
        if(sgbd_nogroup)
            set(sgbd_group_name "\\")
        endif(sgbd_nogroup)
        source_group(${sgbd_group_name} FILES ${sgbd_file})
    endforeach(sgbd_file)
endmacro(source_group_by_dir)

# parse files
macro(filterFilesContain pattern out_var in_var)
    set(${out_var})
    foreach(file_name ${${in_var}})
        set(z_filter_file_contain_content)
        file(READ ${file_name} z_filter_file_contain_content)
        if(z_filter_file_contain_content MATCHES ${pattern})
            list(APPEND ${out_var} ${file_name})
        endif(z_filter_file_contain_content MATCHES ${pattern})
    endforeach(file_name)
endmacro(filterFilesContain)

# Copy files from source directory to destination directory, substituting any
# variables.  Create destination directory if it does not exist.

macro(copyDirectory srcDir destDir)
    message(STATUS "Configuring directory ${destDir}")
    file(MAKE_DIRECTORY ${destDir})

    file(GLOB templateFiles RELATIVE ${srcDir} *.*)
    foreach(templateFile ${templateFiles})
        set(srcTemplatePath ${srcDir}/${templateFile})
        if(NOT IS_DIRECTORY ${srcTemplatePath})
            message(STATUS "Configuring file ${templateFile}")
            configure_file(
                    ${srcTemplatePath}
                    ${destDir}/${templateFile}
                    copyonly)
        endif(NOT IS_DIRECTORY ${srcTemplatePath})
    endforeach(templateFile)
endmacro(copyDirectory)

