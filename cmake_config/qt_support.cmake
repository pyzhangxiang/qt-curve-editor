include(FindQt4)

# --------------------------------------------------------------------------- #
# Qt support
macro(compileWithQt)
    #find_package(Qt4 COMPONENTS QtCore QtGui QtOpenGL QtSql QtSvg Phonon REQUIRED)
    find_package(Qt4 REQUIRED)
    set(QT_USE_QTOPENGL 1)
    #set(QT_USE_QTSQL 1)
    #set(QT_USE_QTSVG 1)
    #set(QT_USE_PHONON 1)
    include(${QT_USE_FILE})
endmacro(compileWithQt)

macro(doQtClassMOC sourceFileList moc_files_var)
    set(do_qt_moc_macro_files_to_moc)
    filterFilesContain(".*Q_OBJECT.*" do_qt_moc_macro_files_to_moc ${sourceFileList})
    QT4_WRAP_CPP(${moc_files_var} ${do_qt_moc_macro_files_to_moc})
    source_group("Qt Class MOC Generated" FILES ${${moc_files_var}})
endmacro(doQtClassMOC)

macro(linkWithQt projectName)
    target_link_libraries(${projectName} ${QT_LIBRARIES})
endmacro(linkWithQt)

macro(doQtUiMoc uiFileList moc_files_var)
    QT4_WRAP_UI(${moc_files_var} ${${uiFileList}})
    source_group("Qt UI MOC Generated" FILES ${${moc_files_var}})
endmacro(doQtUiMoc)

macro(addQtResources uiFileList res_file_var)
    QT4_ADD_RESOURCES(${res_file_var} ${${uiFileList}})
    source_group("Qt Resources" FILES ${${res_files_var}})
endmacro(addQtResources)
