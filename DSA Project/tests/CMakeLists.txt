# Simple test setup - not using a fancy framework
add_executable(test_linked_lists test_linked_lists.cpp)
target_link_libraries(test_linked_lists my_data_structures)

add_executable(test_stack_queue test_stack_queue.cpp)
target_link_libraries(test_stack_queue my_data_structures)

add_executable(test_hash_table test_hash_table.cpp)
target_link_libraries(test_hash_table my_data_structures) 