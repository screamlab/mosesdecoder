/*
 * HypothesisColl.h
 *
 *  Created on: 26 Feb 2016
 *      Author: hieu
 */
#pragma once
#include <boost/unordered_set.hpp>
#include "HypothesisBase.h"
#include "MemPool.h"
#include "legacy/Util2.h"

namespace Moses2 {

class ManagerBase;

typedef Array<const HypothesisBase*>  Hypotheses;

class HypothesisColl
{
public:
	typedef boost::unordered_set<const HypothesisBase*,
			  UnorderedComparer<HypothesisBase>,
			  UnorderedComparer<HypothesisBase>,
			  MemPoolAllocator<const HypothesisBase*>
			   > _HCType;

	HypothesisColl(const ManagerBase &mgr);

	StackAdd Add(const HypothesisBase *hypo);

	_HCType &GetColl()
	{ return m_coll; }

	const _HCType &GetColl() const
	{ return m_coll; }

	void Clear();

	Hypotheses &GetSortedAndPruneHypos(const ManagerBase &mgr) const;

protected:
	_HCType m_coll;
	mutable Hypotheses *m_sortedHypos;

	void SortAndPruneHypos(const ManagerBase &mgr) const;

};

} /* namespace Moses2 */
