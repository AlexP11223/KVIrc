#ifndef _KVI_OPTIONSWIDGET_H_
#define _KVI_OPTIONSWIDGET_H_

//=============================================================================
//
//   File : kvi_optionswidget.h
//   Creation date : Mon Jun 10 2000 17:47:33 by Szymon Stefanek
//
//   This file is part of the KVirc irc client distribution
//   Copyright (C) 2000 Szymon Stefanek (pragma at kvirc dot net)
//
//   This program is FREE software. You can redistribute it and/or
//   modify it under the terms of the GNU General Public License
//   as published by the Free Software Foundation; either version 2
//   of the License, or (at your opinion) any later version.
//
//   This program is distributed in the HOPE that it will be USEFUL,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//   See the GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with this program. If not, write to the Free Software Foundation,
//   Inc. ,59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
//
//=============================================================================

#include "kvi_settings.h"

#include <qframe.h>
#include <qlayout.h>
#include "kvi_list.h"
#include <qlineedit.h>
#include <kvi_tal_groupbox.h>
#include <qtabwidget.h>
#include "kvi_tal_groupbox.h"
#include "kvi_selectors.h"

class KVIRC_API KviOptionsWidget : public QFrame, public KviSelectorInterface
{
	Q_OBJECT
public:
	KviOptionsWidget(QWidget * parent,const char * name = 0,bool bSunken = true);
	~KviOptionsWidget();
private:
	QGridLayout                      * m_pLayout;
	QTabWidget                       * m_pTabWidget;
	int                                m_iResetFlags;
	int                                m_iSelectors;
	KviPtrList<KviSelectorInterface> * m_pSelectorInterfaceList;
	static QString                     m_szBasicTipStart;
	static QString                     m_szBasicTipEnd;
public:
	void mergeResetFlag(int flag){ m_iResetFlags |= flag; };
	void createLayout(int rows,int columns);
	QGridLayout * layout(){ return m_pLayout; };
protected:
	void commitSelectors();
	void commitOptionsReset();
public:
	void mergeTip(QWidget * w,const QString &tip);

	// tabbed page paradigm
	void createTabbedPage();
	void addOptionsWidget(const QString &szText,const QIconSet &iconSet,KviOptionsWidget * pWidget);
	QTabWidget * tabWidget(){ return m_pTabWidget; };

	// non tabbed page paradigm
	KviBoolSelector       * addBoolSelector(int x1,int y1,int x2,int y2,const QString & txt,bool * pOption,bool bEnabled = true);
	KviBoolSelector       * addBoolSelector(QWidget * pParent,const QString & txt,bool * pOption,bool bEnabled = true);
	KviBoolSelector       * addBoolSelector(int x1,int y1,int x2,int y2,const QString & txt,int optId,bool bEnabled = true);
	KviBoolSelector       * addBoolSelector(QWidget * pParnt,const QString & txt,int optId,bool bEnabled = true);

	KviColorSelector      * addColorSelector(int x1,int y1,int x2,int y2,const QString & txt,QColor * pOption,bool bEnabled = true);
	KviColorSelector      * addColorSelector(QWidget * pParent,const QString & txt,QColor * pOption,bool bEnabled = true);
	KviColorSelector      * addColorSelector(int x1,int y1,int x2,int y2,const QString & txt,int optId,bool bEnabled = true);
	KviColorSelector      * addColorSelector(QWidget * pParent,const QString & txt,int optId,bool bEnabled = true);

	KviMircTextColorSelector * addMircTextColorSelector(int x1,int y1,int x2,int y2,const QString & txt,unsigned int *uFore,unsigned int *uBack,bool bEnabled = true);
	KviMircTextColorSelector * addMircTextColorSelector(QWidget * pParent,const QString & txt,unsigned int *uFore,unsigned int *uBack,bool bEnabled = true);
	KviMircTextColorSelector * addMircTextColorSelector(int x1,int y1,int x2,int y2,const QString & txt,int optForeId,int optBackId,bool bEnabled = true);
	KviMircTextColorSelector * addMircTextColorSelector(QWidget * pParent,const QString & txt,int optForeId,int optBackId,bool bEnabled = true);

	KviDirectorySelector  * addDirectorySelector(int x1,int y1,int x2,int y2,const QString & txt,QString * pOption,bool bEnabled = true);
	KviDirectorySelector  * addDirectorySelector(QWidget * pParent,const QString & txt,QString * pOption,bool bEnabled = true);
	KviDirectorySelector  * addDirectorySelector(int x1,int y1,int x2,int y2,const QString & txt,int optId,bool bEnabled = true);
	KviDirectorySelector  * addDirectorySelector(QWidget * pParent,const QString & txt,int optId,bool bEnabled = true);

	KviFileSelector       * addFileSelector(int x1,int y1,int x2,int y2,const QString & txt,QString * pOption,bool bEnabled = true);
	KviFileSelector       * addFileSelector(QWidget * pParent,const QString & txt,QString * pOption,bool bEnabled = true);
	KviFileSelector       * addFileSelector(int x1,int y1,int x2,int y2,const QString & txt,int optId,bool bEnabled = true);
	KviFileSelector       * addFileSelector(QWidget * pParent,const QString & txt,int optId,bool bEnabled = true);

	KviSoundSelector       * addSoundSelector(int x1,int y1,int x2,int y2,const QString & txt,QString * pOption,bool bEnabled = true);
	KviSoundSelector       * addSoundSelector(QWidget * pParent,const QString & txt,QString * pOption,bool bEnabled = true);
	KviSoundSelector       * addSoundSelector(int x1,int y1,int x2,int y2,const QString & txt,int optId,bool bEnabled = true);
	KviSoundSelector       * addSoundSelector(QWidget * pParent,const QString & txt,int optId,bool bEnabled = true);


	KviFontSelector       * addFontSelector(int x1,int y1,int x2,int y2,const QString & txt,QFont * pOption,bool bEnabled = true);
	KviFontSelector       * addFontSelector(QWidget * pParent,const QString & txt,QFont * pOption,bool bEnabled = true);
	KviFontSelector       * addFontSelector(int x1,int y1,int x2,int y2,const QString & txt,int optId,bool bEnabled = true);
	KviFontSelector       * addFontSelector(QWidget * pParent,const QString & txt,int optId,bool bEnabled = true);

	KviPasswordSelector   * addPasswordSelector(int x1,int y1,int x2,int y2,const QString & txt,QString * pOption,bool bEnabled = true);
	KviPasswordSelector   * addPasswordSelector(QWidget * pParent,const QString & txt,QString * pOption,bool bEnabled = true);
	KviPasswordSelector   * addPasswordSelector(int x1,int y1,int x2,int y2,const QString & txt,int optId,bool bEnabled = true);
	KviPasswordSelector   * addPasswordSelector(QWidget * pParent,const QString & txt,int optId,bool bEnabled = true);
	
	KviPixmapSelector     * addPixmapSelector(int x1,int y1,int x2,int y2,const QString & txt,int optId,bool bEnabled = true);
	KviPixmapSelector     * addPixmapSelector(int x1,int y1,int x2,int y2,const QString & txt,KviPixmap * pOption,bool bEnabled = true);

	KviStringListSelector * addStringListSelector(int x1,int y1,int x2,int y2,const QString & txt,QStringList * pOption,bool bEnabled = true);
	KviStringListSelector * addStringListSelector(int x1,int y1,int x2,int y2,const QString & txt,int optId,bool bEnabled = true);

	KviStringSelector     * addStringSelector(int x1,int y1,int x2,int y2,const QString & txt,QString * pOption,bool bEnabled = true);
	KviStringSelector     * addStringSelector(QWidget * pParent,const QString & txt,QString * pOption,bool bEnabled = true);
	KviStringSelector     * addStringSelector(int x1,int y1,int x2,int y2,const QString & txt,int optId,bool bEnabled = true);
	KviStringSelector     * addStringSelector(QWidget * pParent,const QString & txt,int optId,bool bEnabled = true);

	KviUIntSelector       * addUIntSelector(int x1,int y1,int x2,int y2,const QString & txt,unsigned int * pOption,
								unsigned int uLowBound,unsigned int uHighBound,unsigned int uDefault,bool bEnabled = true);
	KviUIntSelector       * addUIntSelector(QWidget * pParent,const QString & txt,unsigned int * pOption,
								unsigned int uLowBound,unsigned int uHighBound,unsigned int uDefault,bool bEnabled = true);
	KviUIntSelector       * addUIntSelector(int x1,int y1,int x2,int y2,const QString & txt,int optId,
				unsigned int uLowBound,unsigned int uHighBound,unsigned int uDefault,bool bEnabled = true);
	KviUIntSelector       * addUIntSelector(QWidget * pParent,const QString & txt,int optId,
				unsigned int uLowBound,unsigned int uHighBound,unsigned int uDefault,bool bEnabled = true);


	KviUIntSelector       * addUShortIntSelector(int x1,int y1,int x2,int y2,const QString & txt,unsigned short int * pOption,
							unsigned int uLowBound,unsigned int uHighBound,unsigned int uDefault,bool bEnabled = true);

	QLabel * addLabel(int x1,int y1,int x2,int y2,const QString & text,bool bEnabled = true);
	QLabel * addLabel(QWidget * pParent,const QString & text,bool bEnabled = true);
	QLineEdit * addLineEdit(int x1,int y1,int x2,int y2,bool bEnabled = true);
#ifdef COMPILE_USE_QT4
	KviTalGroupBox * addGroupBox(int x1,int y1,int x2,int y2,int nStrips,Qt::Orientation o,const QString &txt,bool bEnabled = true);
#else
	KviTalGroupBox * addGroupBox(int x1,int y1,int x2,int y2,int nStrips,KviTalGroupBox::Orientation o,const QString &txt,bool bEnabled = true);
#endif
	QFrame * addSeparator(int x1,int y1,int x2,int y2);
	void addRowSpacer(int x1,int y1,int x2,int y2);

	void addWidgetToLayout(QWidget * w,int x1,int y1,int x2,int y2);

	// this does NOT add the advanced button if this page is not inside a KviGeneralOptionsDialog
	// this is because nobody listens to the "switchToAdvancedPage" requests....
	void addAdvancedButton(int x1,int y1,int x2,int y2);

	virtual void commit();
protected slots:
	// this is internal to the options dialog (options module)
	// it attempts to show all the hidden subitems (usually the "Advanced...") page
	// and switch to the first of them
	void switchToAdvancedPage();
signals:
	// internal signal used for the stuff above
	void wantToSwitchToAdvancedPage(KviOptionsWidget *);
};


#endif //!_KVI_OPTIONSWIDGET_H_
