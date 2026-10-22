/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2026-2027
 * Práctica 6: Simulador de DFAs
 * 
 * @file main.cc
 * @brief Programa principal para la simulación de autómatas finitos deterministas.
 */

#include <iostream>
#include <fstream>
#include <string>

#include "dfa.h"

/**
 * @brief Muestra la ayuda de uso del programa en consola.
 */
void ShowHelp() {
  std::cout << "p06_DFA_simulator - Simulador de Autómatas Finitos Deterministas (DFA)\n\n" << "Modo de empleo:\n" << "  ./p06_DFA_simulator input.dfa input.txt\n\n"
            << "Parámetros:\n" << "  input.dfa  Fichero de texto con la especificación formal del DFA.\n" << "  input.txt  Fichero de texto con las cadenas a evaluar (una por línea, '&' para vacía).\n";
}

/**
 * @brief Función principal que coordina la carga del autómata y la simulación.
 * @param argc Número de argumentos de la línea de comandos.
 * @param argv Vector con los argumentos de la línea de comandos.
 * @return 0 si la ejecución es correcta, 1 si ocurre algún error.
 */
int main(int argc, char* argv[]) {
  // Comprobar si el usuario pide la ayuda
  if (argc == 2 && std::string(argv[1]) == "--help") {
    ShowHelp();
    return 0;
  }
  // Verificar que se hayan pasado los dos archivos
  if (argc != 3) {
    std::cout << "Modo de empleo: ./p06_DFA_simulator input.dfa input.txt\n" << "Pruebe './p06_DFA_simulator --help' para más información.\n";
    return 1;
  }
  std::string dfa_filename = argv[1];
  std::string input_filename = argv[2];
  try {
    // 1. Cargar el autómata desde el archivo .dfa
    DFA dfa;
    dfa.LoadFromFile(dfa_filename);
    // 2. Abrir el archivo de cadenas de prueba
    std::ifstream input_file(input_filename);
    if (!input_file.is_open()) {
      std::cerr << "Error: No se pudo abrir el fichero de entradas: " << input_filename << std::endl;
      return 1;
    }
    // 3. Procesar cada cadena línea a línea
    std::string input_chain;
    int chain_number = 1;
    while (std::getline(input_file, input_chain)) {
      // Limpiar retornos de carro en Windows (\r) si existen
      if (!input_chain.empty() && input_chain.back() == '\r') {
        input_chain.pop_back();
      }
      std::cout << "\n--------------------------------------------------" << std::endl;
      std::cout << "Cadena [" << chain_number++ << "]: \"" << input_chain << "\"" << std::endl;
      std::cout << "--------------------------------------------------" << std::endl;
      dfa.Simulate(input_chain);
    }
    input_file.close();
  } catch (const std::exception& e) {
    std::cerr << "\n[ERROR] " << e.what() << std::endl;
    return 1;
  }
  return 0;
}