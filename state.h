/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2026-2027
 * Práctica 6: Simulador de DFAs
 * 
 * @file State.h
 * @brief Declaración de la clase State para los estados del autómata.
 */

#pragma once

#include <map>
#include <iostream>

/**
 * @class State
 * @brief Representa un estado dentro del DFA con sus transiciones deterministas.
 */
class State {
 public:
  /**
   * @brief Constructor por defecto.
   */
  State();

  /**
   * @brief Constructor parametrizado.
   */
  State(int id, bool is_accepting);

  /**
   * @brief Destructor por defecto.
   */
  ~State() = default;

  /**
   * @brief Obtiene el identificador del estado.
   */
  int get_id() const;

  /**
   * @brief Comprueba si el estado es de aceptación.
   */
  bool is_accepting() const;

  /**
   * @brief Establece el identificador del estado.
   */
  void set_id(int id);

  /**
   * @brief Establece si el estado es de aceptación.
   */
  void set_accepting(bool is_accepting);

  /**
   * @brief Añade una transición desde este estado.
   */
  bool AddTransition(char symbol, int target_state);

  /**
   * @brief Obtiene el estado siguiente dado un símbolo.
   */
  bool GetNextState(char symbol, int& next_state) const;

  /**
   * @brief Comprueba si el estado tiene transición para un símbolo.
   */
  bool HasTransition(char symbol) const;

  /**
   * @brief Obtiene la tabla de transiciones del estado.
   */
  const std::map<char, int>& get_transitions() const;

 private:
  int id_;
  bool is_accepting_;
  std::map<char, int> transitions_;
};
