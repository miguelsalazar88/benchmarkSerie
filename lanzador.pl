#!/usr/bin/perl

=begin comment
Fecha: 23 de agosto del 2022
Autor: Diego Bermudez, Jesus Chaves, Miguel Salazar
Tema: Ejecucion automatizada de Benchmarks
=cut

#Vector para los benchmarks
@Benchmarks = ("bench_project_int","bench_project_int_rmd","bench_project_double","bench_project_double_rmd");
#Vector para las cargas
@Cargas = ("280","691","1102","1513","1924","2335","2746","3157","3568","3979","4390","4800");
# Número de repeticiones
$n = 30;
#Se almacena la ubicación
$Path = "/Users/miguelsalazar/Desktop/Benchmark_Serie/";

# Se itera sobre la cantidad de ejecutables, sobre la cantidad de cargas y la cantidad de repeticiones

foreach $exes (@Benchmarks){
    foreach $carga (@Cargas){
        # Se crea fichero para almacenar los datos
        $file = "Soluciones/".$exes."-size-".$carga.".txt";
        # printf("$Path$file\n");
        for ($i = 0; $i < $n; $i++){
            system("$Path$exes $carga >> $file");
            # printf("$Path$exes $carga\n");
        }
        close($file);
    }
}
