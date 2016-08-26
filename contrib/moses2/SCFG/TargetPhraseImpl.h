/*
 * TargetPhraseImpl.h
 *
 *  Created on: 23 Oct 2015
 *      Author: hieu
 */

#pragma once

#include <iostream>
#include "../Phrase.h"
#include "../PhraseImplTemplate.h"
#include "../TargetPhrase.h"
#include "../MemPool.h"
#include "../SubPhrase.h"
#include "../AlignmentInfoCollection.h"
#include "Word.h"

namespace Moses2
{
class Scores;
class Manager;
class System;
class PhraseTable;
class AlignmentInfo;

namespace SCFG
{

class TargetPhraseImpl: public Moses2::TargetPhrase<SCFG::Word>
{
public:
  SCFG::Word lhs;

  static TargetPhraseImpl *CreateFromString(MemPool &pool,
      const PhraseTable &pt, const System &system, const std::string &str);

  TargetPhraseImpl(MemPool &pool, const PhraseTable &pt, const System &system,
      size_t size);
  //TargetPhraseImpl(MemPool &pool, const System &system, const TargetPhraseImpl &copy);

  virtual ~TargetPhraseImpl();

  // ALNREP = alignment representation,
  // see AlignmentInfo constructors for supported representations
  template<typename ALNREP>
  void
  SetAlignTerm(const ALNREP &coll) {
    m_alignTerm = AlignmentInfoCollection::Instance().Add(coll);
  }

  const AlignmentInfo &GetAlignTerm() const {
    return *m_alignTerm;
  }
  const AlignmentInfo &GetAlignNonTerm() const {
    return *m_alignNonTerm;
  }

  void SetAlignTerm(const AlignmentInfo &alignInfo) {
    m_alignTerm = &alignInfo;
  }

  void SetAlignNonTerm(const AlignmentInfo &alignInfo) {
	m_alignNonTerm = &alignInfo;
  }

  void SetAlignmentInfo(const std::string &alignString);

  SCORE GetFutureScore() const
  {  return m_scores->GetTotalScore() + m_estimatedScore; }

  virtual SCORE GetScoreForPruning() const
  { return GetFutureScore(); }

  void SetEstimatedScore(const SCORE &value)
  {  m_estimatedScore = value; }

  std::string Debug(const System &system) const;

  size_t GetNumNonTerms() const;

  //mutable void *chartState;
protected:
  SCORE m_estimatedScore;

  const AlignmentInfo* m_alignTerm, *m_alignNonTerm;

  // ALNREP = alignment representation,
  // see AlignmentInfo constructors for supported representations
  template<typename ALNREP>
  void
  SetAlignNonTerm(const ALNREP &coll) {
    m_alignNonTerm = AlignmentInfoCollection::Instance().Add(coll);
  }

};


}
}
