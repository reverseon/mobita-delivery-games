build : main.c map/mapfn.c configuration_c/loadData.c configuration_c/konfigurasi_c.c configuration_c/charmachine.c configuration_c/wordmachine.c configuration_c/listdin.c configuration_c/point.c 
		gcc -o main main.c configuration_c/loadData.c configuration_c/konfigurasi_c.c configuration_c/charmachine.c configuration_c/wordmachine.c configuration_c/listdin.c configuration_c/point.c map/mapfn.c -g -Wall 