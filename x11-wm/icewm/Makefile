# New ports collection makefile for:	icewm
# Version required:	0.9.38
# Date created:		10 August 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.34 1999/03/28 19:42:21 dirk Exp $
#

DISTNAME=	icewm-0.9.38
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.kiss.uni-lj.si/~k4fr0235/icewm/devel/ \
		http://www.physik.TU-Berlin.DE/~ibex/ports/distfiles/icewm/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	nacai@iname.com

.if defined(GNOME)
LIB_DEPENDS=	gnome.1:${PORTSDIR}/x11/gnomelibs
.endif
LIB_DEPENDS+=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_GMAKE=	yes
USE_X_PREFIX=	yes

ICEOPTION=	--with-shape
.if defined(USE_I18N)
ICEOPTION+=	--with-i18n
.endif
.if defined(XLOCALE)
ICEOPTION+=	--with-xlocale
.endif
.if defined(GNOME)
ICEOPTION+=	--with-imlib --with-gnome --with-sm
.endif

pre-patch:
.if defined(TITLE_BOTTOM)
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-titlebottom
.else
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-titletop
.endif
.if defined(GNOME)
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-gnome
.endif

do-configure:
	( cd ${WRKSRC}; env  X11BASE="${X11BASE}" CXX="${CXX}" \
			CXXFLAGS="${CXXFLAGS}" \
			${SH} config ${ICEOPTION} )

post-install:
	${INSTALL_DATA} ${FILESDIR}/bsd-daemon.xpm ${PREFIX}/share/icewm/taskbar
	strip ${PREFIX}/bin/icewm
	strip ${PREFIX}/bin/icewmbg
	strip ${PREFIX}/bin/icewmhint

.include <bsd.port.mk>
