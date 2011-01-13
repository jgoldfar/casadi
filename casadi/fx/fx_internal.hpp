/*
 *    This file is part of CasADi.
 *
 *    CasADi -- A symbolic framework for dynamic optimization.
 *    Copyright (C) 2010 by Joel Andersson, Moritz Diehl, K.U.Leuven. All rights reserved.
 *
 *    CasADi is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    CasADi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with CasADi; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef FX_INTERNAL_HPP
#define FX_INTERNAL_HPP

#include "fx.hpp"
#include <set>

namespace CasADi{
  
/** \brief Internal class for FX
  \author Joel Andersson 
  \date 2010
 A regular user should never work with any Node class. Use FX directly.
*/
class FXInternal : public OptionsFunctionalityNode{
  friend class FX;

  protected:
  /** \brief  Default constructor (accessable from the FX class and derived classes) */
  FXInternal();
  
  public:
  /** \brief  Destructor */
  virtual ~FXInternal() = 0;

  /** \brief  Evaluate */
  virtual void evaluate(int fsens_order, int asens_order) = 0;

  /** Initialize and make the object ready for setting arguments and evaluation. This method is typically called after setting options but before evaluating. 
      If passed to another class (in the constructor), this class should invoke this function when initialized. */
  virtual void init();

  /** \brief Jacobian of output oind with respect to input iind */
  virtual FX jacobian(int iind=0, int oind=0);

  /** \brief Hessian of output oind with respect to input iind */
  virtual FX hessian(int iind=0, int oind=0);

  /** \brief  Access an input */
  FunctionIO& input(int i=0);

  /** \brief  Const access an input */
  const FunctionIO& input(int i=0) const;
  
  /** \brief  Access an output*/
  FunctionIO& output(int i=0);

  /** \brief  Const access an output*/
  const FunctionIO& output(int i=0) const;
    
  /** \brief  Print */
  virtual void print(std::ostream &stream) const;
 
  /** \brief  Inputs of the function */
  std::vector<FunctionIO> input_;

  /** \brief  Output of the function */
  std::vector<FunctionIO> output_;

  /// Assert that the function has been initialized
  void assertInit() const;

  /// Verbose mode?
  bool verbose() const;
  
  /// Is function fcn being monitored
  bool monitored(const std::string& mod) const;
  
    /// Access input argument
  Matrix<double>& argument(int iind=0);
    
  /// Const access input argument
  const Matrix<double>& argument(int iind=0) const;

  /// Access input argument
  Matrix<double>& result(int oind=0);
    
  /// Const access input argument
  const Matrix<double>& result(int oind=0) const;

  /// Access forward seed
  Matrix<double>& fwdSeed(int iind=0, int dir=0);
    
  /// Const access forward seed
  const Matrix<double>& fwdSeed(int iind=0, int dir=0) const;

  /// Access forward sensitivity
  Matrix<double>& fwdSens(int oind=0, int dir=0);
    
  /// Const access forward sensitivity
  const Matrix<double>& fwdSens(int oind=0, int dir=0) const;

  /// Access adjoint seed
  Matrix<double>& adjSeed(int oind=0, int dir=0);
    
  /// Const access adjoint seed
  const Matrix<double>& adjSeed(int oind=0, int dir=0) const;

  /// Access forward sensitivity
  Matrix<double>& adjSens(int iind=0, int dir=0);
    
  /// Const access forward sensitivity
  const Matrix<double>& adjSens(int iind=0, int dir=0) const;

  protected:

  /** \brief  Has the function been initialized? */
  bool is_init_;
    
  int ad_order_;

  /** \brief  Number of forward and adjoint derivatives */
  int nfdir_, nadir_;

  /** \brief  Verbose -- for debugging purposes */
  bool verbose_;
  
  /** \brief  Log the status of the solver */
  void log(const std::string& msg) const;

  /// Set of module names which are extra monitored
  std::set<std::string> monitors_;
  
  
  
};


} // namespace CasADi


#endif // FX_INTERNAL_HPP
