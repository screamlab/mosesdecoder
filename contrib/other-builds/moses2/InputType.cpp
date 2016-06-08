/*
 * InputType.cpp
 *
 *  Created on: 14 Dec 2015
 *      Author: hieu
 */

#include "InputType.h"

namespace Moses2
{
InputType::InputType(long translationId, MemPool &pool)
:m_translationId(translationId)
,m_reorderingConstraint(pool)
{
}

InputType::~InputType()
{
  // TODO Auto-generated destructor stub
}

void InputType::Init(size_t size, int max_distortion)
{
  m_reorderingConstraint.InitializeWalls(size, max_distortion);

}

} /* namespace Moses2 */