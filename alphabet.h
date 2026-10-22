/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2026-2027
 * Práctica 6: Simulador de DFAs
 * 
 * @file Alphabet.h
 * @brief Declaración de la clase Alphabet para gestionar el alfabeto del DFA.
 */

#pragma once

#include <set>
#include <iostream>

/**
 * @class Alphabet
 * @brief Representa el alfabeto de entrada Sigma para un autómata finito.
 */
class Alphabet {
 public:
  Alphabet() = default;
  ~Alphabet() = default;

  /**
   * @brief Añade un símbolo al alfabeto.
   */
  void AddSymbol(char symbol);

  /**
   * @brief Comprueba si un símbolo pertenece al alfabeto.
   */
  bool Contains(char symbol) const;

  /**
   * @brief Obtiene el conjunto de símbolos del alfabeto.
   */
  const std::set<char>& get_symbols() const;

 private:
  std::set<char> symbols_;
};