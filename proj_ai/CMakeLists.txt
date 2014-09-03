project ( ai1 )
aux_source_directory( src/. src_list )
add_library( ai1 SHARED ${src_list} )
