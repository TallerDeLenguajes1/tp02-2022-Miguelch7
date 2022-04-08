#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct compu {
    int velocidad;
    int anio;
    int cantidad;
    char *tipo_cpu;
} typedef computadora;

void cargarCompus( computadora listaCompus[5], char tiposCPU[6][10] );
void mostrarCompu( computadora pc );
computadora masVieja( computadora listaCompus[5] );
computadora masVeloz( computadora listaCompus[5] );

int main() {
    srand((int)time(NULL));

    char tiposCPU[6][10] = { "Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium" };
    computadora listaCompus[5];

    cargarCompus(listaCompus, tiposCPU);

    printf("========== Listado de PCS ==========\n");
    
    for (int i = 0; i < 5; i++) {
        printf("\n========== PC %d ==========\n", i + 1);
        mostrarCompu(listaCompus[i]);
    };

    printf("\n========== PC mas vieja ==========\n");
    mostrarCompu( masVieja(listaCompus) );

    printf("\n========== PC mas veloz ==========\n");
    mostrarCompu( masVeloz(listaCompus) );

    return 0;
};

void cargarCompus( computadora listaCompus[5], char tiposCPU[6][10] ) {
    for (int i = 0; i < 5; i++) {
        listaCompus[i].velocidad = 1 + (rand() % 3);
        listaCompus[i].anio = 2015 + (rand() % 8);
        listaCompus[i].cantidad = 1 + (rand() % 8);
        listaCompus[i].tipo_cpu = &tiposCPU[rand() % 6][0];
    };
};

void mostrarCompu( computadora pc ) {
    printf("Velocidad: %d GHz\n", pc.velocidad);
    printf("Anio: %d\n", pc.anio);
    printf("Cantidad: %d\n", pc.cantidad);
    printf("Tipo de CPU: ");
    puts(pc.tipo_cpu);
};

computadora masVieja( computadora listaCompus[5] ) {
    computadora pcMasVieja = listaCompus[0];

    for (int i = 0; i < 5; i++) {
        if ( listaCompus[i].anio < pcMasVieja.anio ) {
            pcMasVieja = listaCompus[i];
        };
    };

    return pcMasVieja;
};

computadora masVeloz( computadora listaCompus[5] ) {
    computadora pcMasVeloz = listaCompus[0];

    for (int i = 0; i < 5; i++) {
        if ( listaCompus[i].velocidad > pcMasVeloz.velocidad ) {
            pcMasVeloz = listaCompus[i];
        };
    };

    return pcMasVeloz;
};