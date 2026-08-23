#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */
void test_compra_con_descuento(void){
    printf("\n[Compra con descuento]\n");
    Carrito c;
    carrito_init(&c);
    Producto p1 = {"Pan", 200, 3};
    Producto p2 = {"Leche", 350, 2};
    carrito_agregar(&c, p1);
    carrito_agregar(&c, p2);
    int total = carrito_total(&c);
    int total_descuento = carrito_descuento(total, 10);
    ASSERT_IGUAL(total_descuento,  1170);
}


/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_agregar_hasta_llenar(void){
    printf("\n[Agregar hasta llenar]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Juego ps4", 600, 1};
    for(int i=0; i<MAX_ITEMS; i++){
        carrito_agregar(&c, p);
        printf("\n[Producto agregado]\n");
    }
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
    ASSERT_IGUAL(0, carrito_agregar(&c, p)); // No se puede agregar más
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento(); 
    test_agregar_hasta_llenar();  
    RESUMEN();
    return EXIT_CODE();
}
