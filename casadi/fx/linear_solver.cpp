/*
 *    This file is part of CasADi.
 *
 *    CasADi -- A minimalistic computer algebra system with automatic differentiation 
 *    and framework for dynamic optimization.
 *    Copyright (C) 2010 by Joel Andersson, Moritz Diehl et al., K.U.Leuven. All rights reserved.
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

#include "linear_solver.hpp"

using namespace std;
namespace CasADi{

LinearSolverInternal* LinearSolver::operator->(){
  return static_cast<LinearSolverInternal*>(FX::operator->());
}

const LinearSolverInternal* LinearSolver::operator->() const{
    return static_cast<const LinearSolverInternal*>(FX::operator->());
}

LinearSolverInternal::~LinearSolverInternal(){
}
 
void LinearSolverInternal::evaluate(int fsens_order, int asens_order){
/*  Factorization fact;
  if(called_once){
    // Check if any element has changed
    bool any_change = false;
    const vector<double>& val = input(0).data();
    for(int i=0; i<val.size(); ++i){
      if(val[i] != a[i]){
        any_change = true;
        break;
      }
    }
    
    // Reuse factored matrix if matrix hasn't changed
    fact = any_change ? SAMEPATTERN : FACTORED;
  } else {
    fact = DOFACT;
    called_once = true;
  }*/
  
  // Call the solve routine
  prepare();
  solve();
}
 
 
void LinearSolver::prepare(){
  (*this)->prepare();
}

void LinearSolver::solve(){
  (*this)->solve();
}
 
  
} // namespace CasADi

  


