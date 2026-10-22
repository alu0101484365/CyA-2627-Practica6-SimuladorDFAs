/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2026-2027
 * Práctica 6: Simulador de DFAs
 * Nombre: DFA.cc
 * Descripcion Implementación de la clase DFA.
 */

#include "dfa.h"

#include <fstream>
#include <sstream>

DFA::DFA() : initial_state_id_(-1) {}

/**
 * @brief Carga fichero
 * 
 */
void DFA::LoadFromFile(const std::string& filename) {
  std::ifstream file(filename);
  std::string line;

  // 1. Leer el Alfabeto (saltando comentarios '//' o líneas vacías)
  while (std::getline(file, line)) {
    if (line.empty() || line[0] == '/' || line[0] == '\r') continue;
    std::istringstream ss(line);
    std::string simbolos;
    ss >> simbolos;
    for (char c : simbolos) {
      alphabet_.AddSymbol(c);
    }
    break;
  }

  // 2. Leer el número de estados
  int num_estados = 0;
  while (std::getline(file, line)) {
    if (line.empty() || line[0] == '/' || line[0] == '\r') continue;
    std::istringstream ss(line);
    ss >> num_estados;
    break;
  }

  // 3. Leer el estado inicial
  while (std::getline(file, line)) {
    if (line.empty() || line[0] == '/' || line[0] == '\r') continue;
    std::istringstream ss(line);
    ss >> initial_state_id_;
    break;
  }

  // 4. Leer cada uno de los estados y sus transiciones
  for (int i = 0; i < num_estados; ++i) {
    while (std::getline(file, line)) {
      if (line.empty() || line[0] == '/' || line[0] == '\r') continue;
      std::istringstream ss(line);

      int id, es_aceptacion;
      ss >> id >> es_aceptacion;

      State estado(id, es_aceptacion == 1);

      // Leemos los pares: simbolo destino
      char simbolo;
      int destino;
      while (ss >> simbolo >> destino) {
        estado.AddTransition(simbolo, destino);
      }
      states_[id] = estado;
      break;
    }
  }

  file.close();
}

/**
 * 
 */
bool DFA::Simulate(const std::string& input_string) const {
  int estado_actual = initial_state_id_;

  std::cout << "Est. Actual\tEntrada\tNuevo Est." << std::endl;

  // Si es la cadena vacía '&'
  if (input_string == "&" || input_string.empty()) {
    bool aceptada = states_.at(estado_actual).is_accepting();
    std::cout << (aceptada ? "Cadena ACEPTADA." : "Cadena RECHAZADA.") << std::endl;
    return aceptada;
  }

  // Procesar letra por letra
  for (char c : input_string) {
    int siguiente_estado;
    bool existe_transicion = states_.at(estado_actual).GetNextState(c, siguiente_estado);

    if (!existe_transicion) {
      std::cout << "Cadena RECHAZADA." << std::endl;
      return false;
    }

    // Imprimimos la fila con tabuladores simples (\t)
    std::cout << estado_actual << "\t\t" << c << "\t" << siguiente_estado << std::endl;
    estado_actual = siguiente_estado;
  }

  bool aceptada = states_.at(estado_actual).is_accepting();
  std::cout << (aceptada ? "Cadena ACEPTADA." : "Cadena RECHAZADA.") << std::endl;
  return aceptada;
}