#!/bin/bash
#mover a la carpeta raiz de so_long

# Directorio que contiene los archivos de mapa
MAP_DIR="maps_bad"

# Nombre del programa a ejecutar
PROGRAM="./so_long"

# Número máximo de mapas
MAX_MAPS=18

# Iterar sobre el rango de 00 a MAX_MAPS
for i in $(seq -w 0 $MAX_MAPS); do
    MAP_FILE="${MAP_DIR}/${i}map.ber"
    echo -e "\n"
	echo -e "\n"
    # Verificar si el archivo existe
    if [[ -f "$MAP_FILE" ]]; then
        # Ejecutar el programa con el archivo de mapa como argumento
		echo "MAPA -> ${i}map.ber"
        $PROGRAM "$MAP_FILE"
    fi
done
