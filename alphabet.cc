/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2026-2027
 * Práctica 6: Simulador de DFAs
 * 
 * @file Alphabet.cpp
 * @brief Implementación de la clase Alphabet.
 */

#include "alphabet.h"

/**
 * @brief Añade un símbolo al alfabeto.
 * @param symbol Carácter a añadir.
 */
void Alphabet::AddSymbol(char symbol) {
  symbols_.insert(symbol);
}

/**
 * @brief Comprueba si un símbolo pertenece al alfabeto.
 * @param symbol Carácter a verificar.
 * @return true si pertenece, false en caso contrario.
 */
bool Alphabet::Contains(char symbol) const {
  return symbols_.find(symbol) != symbols_.end();
}

/**
 * @brief Obtiene el conjunto de símbolos del alfabeto.
 * @return Referencia constante al conjunto de caracteres.
 */
const std::set<char>& Alphabet::get_symbols() const { return symbols_; }