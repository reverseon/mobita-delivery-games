build : main.c map/mapfn.c configuration_c/loadData.c configuration_c/konfigurasi_c.c configuration_c/charmachine.c configuration_c/wordmachine.c configuration_c/listdin.c configuration_c/point.c sorted_queue/sorted_queue.c linked_list/todolist.c linked_list/node.c
		gcc -o main main.c configuration_c/loadData.c configuration_c/konfigurasi_c.c configuration_c/charmachine.c configuration_c/wordmachine.c configuration_c/listdin.c configuration_c/point.c map/mapfn.c linked_list/todolist.c sorted_queue/sorted_queue.c linked_list/node.c -g -Wall 
