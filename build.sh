# executavel - mac os
# clear && gcc ./src/file.c ./src/cliutil.c ./src/lajes.c ./src/tabelas.c ./src/fundacoes.c ./src/main.c ./src/algebra.c -o rsdt-v1.0.0 -lssl -lcrypto

# executavel - windows
# clear && gcc ./src/fundacoes/fundacoes.c ./src/main.c ./src/util/algebra.c -o rsdt.exe -lssl -lcrypto

# lib shared
# clear && gcc -shared ./src/fundacoes/fundacoes.c ./src/main.c ./src/util/algebra.c -o teste.so -fPIC -lssl -lcrypto

clear && make clean && make -j 3