macro(add_program PROGRAM)
  # create an exectuable with project-defined flags
  add_executable(${PROGRAM} ${ARGN})

  target_compile_definitions(${PROGRAM}
    PRIVATE
      ${clientserver_config_defines}
  )

  target_link_libraries(${PROGRAM}
    PUBLIC
      server
      disk_database
      prime_database
  )
endmacro()

add_program(primeServer primeServer.cc)
add_program(diskServer diskServer.cc)
add_program(client client.cc)

install(TARGETS primeServer diskServer client)