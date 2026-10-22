/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2026-2027
 * Práctica 6: Simulador de DFAs
 * 
 * @file State.cc
 * @brief Implementación de la clase State.
 */

#include "state.h"

/**
 * @brief Constructor por defecto. Inicializa el estado como no válido y no final.
 */
State::State() : id_(-1), is_accepting_(false) {}

/**
 * @brief Constructor parametrizado.
 * @param id Identificador entero del estado.
 * @param is_accepting Booleano que indica si el estado es de aceptación/final.
 */
State::State(int id, bool is_accepting) : id_(id), is_accepting_(is_accepting) {}

/**
 * @brief Obtiene el identificador del estado.
 * @return Identificador entero del estado.
 */
int State::get_id() const {
  return id_;
}

/**
 * @brief Comprueba si el estado es de aceptación.
 * @return true si es estado final, false en caso contrario.
 */
bool State::is_accepting() const {
  return is_accepting_;
}

/**
 * @brief Establece el identificador del estado.
 * @param id Nuevo identificador entero para el estado.
 */
void State::set_id(int id) {
  id_ = id;
}

/**
 * @brief Establece si el estado es de aceptación.
 * @param is_accepting Booleano que indica si el estado pasa a ser de aceptación.
 */
void State::set_accepting(bool is_accepting) {
  is_accepting_ = is_accepting;
}

/**
 * @brief Añade una transición desde este estado.
 * @param symbol Símbolo del alfabeto asociado a la transición.
 * @param target_state Identificador del estado destino.
 * @return true si la transición se añadió con éxito, false si ya existía una transición para dicho símbolo.
 */
bool State::AddTransition(char symbol, int target_state) {
  if (transitions_.find(symbol) != transitions_.end()) {
    return false;
  }
  transitions_[symbol] = target_state;
  return true;
}

/**
 * @brief Obtiene el estado siguiente dado un símbolo de entrada.
 * @param symbol Símbolo de entrada a evaluar.
 * @param next_state Parámetro de salida que almacenará la ID del estado destino.
 * @return true si existe una transición definida para el símbolo, false en caso contrario.
 */
bool State::GetNextState(char symbol, int& next_state) const {
  auto iterator = transitions_.find(symbol);
  if (iterator != transitions_.end()) {
    next_state = iterator->second;
    return true;
  }
  return false;
}

/**
 * @brief Comprueba si el estado tiene una transición definida para un símbolo.
 * @param symbol Símbolo de entrada a comprobar.
 * @return true si el símbolo está presente en la tabla de transiciones, false en caso contrario.
 */
bool State::HasTransition(char symbol) const {
  return transitions_.find(symbol) != transitions_.end();
}

/**
 * @brief Obtiene la tabla de transiciones del estado.
 * @return Referencia constante al mapa de transiciones (símbolo -> estado destino).
 */
const std::map<char, int>& State::get_transitions() const {
  return transitions_;
}