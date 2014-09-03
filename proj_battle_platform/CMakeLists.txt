project( hanafuda )

aux_source_directory( src/. src_list )
link_directories ( ai/ai1/lib )
add_executable( hanafuda ${src_list} )
target_link_libraries ( hanafuda ai1 )

