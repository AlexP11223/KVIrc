#ifndef _KVI_KVS_TREENODE_SINGLEPARAMETERIDENTIFIER_H_
#define _KVI_KVS_TREENODE_SINGLEPARAMETERIDENTIFIER_H_
//=============================================================================
//
//   File : KviKvsTreeNodeSingleParameterIdentifier.h
//   Creation date : Tue 07 Oct 2003 03:47:11 by Szymon Stefanek
//
//   This file is part of the KVIrc IRC client distribution
//   Copyright (C) 2003-2010 Szymon Stefanek <pragma at kvirc dot net>
//
//   This program is FREE software. You can redistribute it and/or
//   modify it under the terms of the GNU General Public License
//   as published by the Free Software Foundation; either version 2
//   of the License, or (at your option) any later version.
//
//   This program is distributed in the HOPE that it will be USEFUL,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//   See the GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with this program. If not, write to the Free Software Foundation,
//   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
//
//=============================================================================

#include "kvi_settings.h"
#include "KviKvsTreeNodeData.h"


class KviKvsRunTimeContext;
class KviKvsVariant;

class KVIRC_API KviKvsTreeNodeSingleParameterIdentifier : public KviKvsTreeNodeData
{
public:
	KviKvsTreeNodeSingleParameterIdentifier(const QChar * pLocation,int iStart);
	~KviKvsTreeNodeSingleParameterIdentifier();
protected:
	int m_iStart; // the index of the parameter wanted (always >= 0)
public:
	virtual void contextDescription(QString &szBuffer);
	virtual void dump(const char * prefix);

	virtual bool canEvaluateToObjectReference();
	virtual bool evaluateReadOnly(KviKvsRunTimeContext * c,KviKvsVariant * pBuffer);
};


#endif //!_KVI_KVS_TREENODE_SINGLEPARAMETERIDENTIFIER_H_
