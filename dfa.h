/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2026-2027
 * Práctica 6: Simulador de DFAs
 * 
 * @file DFA.h
 * @brief Declaración de la clase DFA para representar y simular el autómata.
 */

#pragma once

#include <string>
#include <map>
#include <iostream>

#include "alphabet.h"
#include "state.h"

/**
 * @class DFA
 * @brief Modela un Autómata Finito Determinista.
 */
class DFA {
 public:
  /**
   * @brief Constructor por defecto.
   */
  DFA();

  /**
   * @brief Destructor por defecto.
   */
  ~DFA() = default;

  /**
   * @brief Carga la especificación del DFA desde un fichero .dfa.
   */
  void LoadFromFile(const std::string& filename);

  /**
   * @brief Simula el procesamiento de una cadena en el DFA.
   */
  bool Simulate(const std::string& input_string) const;

 private:
  Alphabet alphabet_;
  std::map<int, State> states_;
  int initial_state_id_;
};