//=============================================================================
//
//   File : optw_avatar.cpp
//   Creation date : Wed Nov 19 09:25:16 2005 GMT by Grifisx & Noldor
//
//   This file is part of the KVirc irc client distribution
//   Copyright (C) 2003-2006 Szymon Stefanek (pragma at kvirc dot net)
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

#include "optw_avatar.h"

#include "kvi_locale.h"
#include "kvi_selectors.h"
#include "kvi_options.h"

#include <qtooltip.h>

KviAvatarAdvancedOptionsWidget::KviAvatarAdvancedOptionsWidget(QWidget * parent)
: KviOptionsWidget(parent,"avatar_advanced_options_widget")
{
	createLayout(3,1);
	// AVATAR

	// 1st Box
	KviTalGroupBox *g = addGroupBox(0,0,0,0,1,KviTalGroupBox::Horizontal,__tr2qs_ctx("Scaling","options"));
	KviBoolSelector *b = addBoolSelector(g,__tr2qs_ctx("Scale avatar images (recommended)","options"),KviOption_boolScaleAvatars);
#ifdef COMPILE_INFO_TIPS	
	QToolTip::add(b,__tr2qs_ctx("<center>This option will force KVIrc to scale avatars" \
			" shown in the userlist.<br>" \
			"Avatars will be scaled to fit the " \
			"constraints set below. Better keep this option on. :)</center>","options"));
#endif	
	addBoolSelector(g,__tr2qs_ctx("Do not scale avatar if it is less than required size","options"),KviOption_boolDoNotStretchAvatars);
	
	KviUIntSelector *u = addUIntSelector(g,__tr2qs_ctx("Image width:","options"),KviOption_uintAvatarScaleWidth,0,512,80,KVI_OPTION_BOOL(KviOption_boolScaleAvatars));
	connect(b,SIGNAL(toggled(bool)),u,SLOT(setEnabled(bool)));
	u = addUIntSelector(g,__tr2qs_ctx("Image height:","options"),KviOption_uintAvatarScaleHeight,0,512,80,KVI_OPTION_BOOL(KviOption_boolScaleAvatars));
	connect(b,SIGNAL(toggled(bool)),u,SLOT(setEnabled(bool)));

	// 2st Box
	KviTalGroupBox *gs = addGroupBox(0,1,0,1,1,KviTalGroupBox::Horizontal,__tr2qs_ctx("Request CTCP","options"));
	KviBoolSelector * bs = addBoolSelector(g,__tr2qs_ctx("Request missing avatars","options"),KviOption_boolRequestMissingAvatars);
	KviUIntSelector * us = addUIntSelector(g,__tr2qs_ctx("Maximum requested file size:","options"),KviOption_uintMaximumRequestedAvatarSize,0,1048576,102400,KVI_OPTION_BOOL(KviOption_boolRequestMissingAvatars));

#ifdef COMPILE_INFO_TIPS
	mergeTip(bs,
		__tr2qs_ctx("<center>This option will cause KVIrc to send a DCC GET request " \
			"when someone sets an avatar and there is no cached copy available.</center>","options"));
#endif
	us->setSuffix(__tr2qs_ctx(" bytes","options"));
#ifdef COMPILE_INFO_TIPS
	mergeTip(us,
		__tr2qs_ctx("<center>This is the maximum size for avatar images that " \
			"will be automatically requested.<br>" \
			"A reasonable value might be 102400 bytes (100 K).</center>","options"));
#endif
	connect(bs,SIGNAL(toggled(bool)),us,SLOT(setEnabled(bool)));

	bs = addBoolSelector(gs,__tr2qs_ctx("Automatically accept incoming avatars","options"),KviOption_boolAutoAcceptIncomingAvatars);
#ifdef COMPILE_INFO_TIPS
	mergeTip(
		bs,
		__tr2qs_ctx("<center>This option will cause KVIrc to auto-accept " \
			"DCC SEND requests for incoming avatars.<br>" \
			"If you're using the \"Request missing avatars\" option " \
			"above, enabling this may by useful.<br>" \
			"Avatars will be saved in the local KVIrc directory.</center>","options"));
#endif

	bs = addBoolSelector(gs,__tr2qs_ctx("Remember avatars for registered users","options"),KviOption_boolSetLastAvatarAsDefaultForRegisteredUsers);

#ifdef COMPILE_INFO_TIPS
	mergeTip(
		bs,
		__tr2qs_ctx("<center>Use a user's last known avatar by default " \
			"(only for users that are registered).</center>","options"));
#endif

	us = addUIntSelector(gs,__tr2qs_ctx("Avatar offer timeout:","options"),KviOption_uintAvatarOfferTimeoutInSecs,1,99999,60);
	us->setSuffix(__tr2qs_ctx(" sec","options"));
#ifdef COMPILE_INFO_TIPS
	mergeTip(us,
		__tr2qs_ctx("<center>This is the amount of time to make an avatar available for transfer when requested.<br>" \
			"When someone sends a CTCP AVATAR request, " \
			"KVIrc will reply with a CTCP AVATAR message containing the name and size " \
			"of your avatar image.<br>" \
			"A time-limited file offer is added for the image file " \
			"to the requesting user.</center>","options"));
#endif

	bs = addBoolSelector(gs,__tr2qs_ctx("Ignore requests if no avatar is set","options"),KviOption_boolIgnoreChannelAvatarRequestsWhenNoAvatarSet);
#ifdef COMPILE_INFO_TIPS
	mergeTip(bs,
		__tr2qs_ctx("This option will cause KVIrc to ignore channel CTCP AVATAR requests " \
			"when you have no avatar set. This is usually a good practice since " \
			"it helps in reducing traffic by not sending a reply that would be empty.","options"));
#endif

	addRowSpacer(0,2,0,2);
}

KviAvatarAdvancedOptionsWidget::~KviAvatarAdvancedOptionsWidget()
{
}


#include "m_optw_avatar.moc"
